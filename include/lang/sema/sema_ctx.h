#pragma once

#include "lang/ast/operator_types.h"
#include "lang/compiler_context.h"
#include "lang/sema/ct_value.h"
#include "lang/sema/simple_namespace.h"
#include "lang/sema/types.h"
#include <memory>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using binary_operator_signature = std::tuple<binary_op_type, type_descriptor, type_descriptor>;
using unary_operator_signature = std::tuple<unary_op_type, type_descriptor>;
using lambda_signature = std::tuple<type_descriptor, std::vector<type_descriptor>>;

inline static constexpr auto HASH_MAGIC = 0x9e3779b9;

template <>
struct std::hash<binary_operator_signature>
{
    auto operator()(const binary_operator_signature& val) const -> std::size_t
    {
        size_t seed = 0;
        seed ^= std::hash<int>{}(std::get<0>(val)) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        seed ^= std::hash<const type*>{}(std::get<1>(val)) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        seed ^= std::hash<const type*>{}(std::get<2>(val)) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        return seed;
    }
};

template <>
struct std::hash<unary_operator_signature>
{
    auto operator()(const unary_operator_signature& val) const -> std::size_t
    {
        size_t seed = 0;
        seed ^= std::hash<int>{}(std::get<0>(val)) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        seed ^= std::hash<const type*>{}(std::get<1>(val)) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        return seed;
    }
};

template <>
struct std::hash<lambda_signature>
{
    auto operator()(const lambda_signature& val) const -> std::size_t
    {
        size_t seed = 0;
        seed ^= std::hash<const type*>{}(std::get<0>(val)) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        for (const auto* entry : std::get<1>(val))
        {
            seed ^= std::hash<const type*>{}(entry) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

template <>
struct std::hash<std::pair<type_descriptor, type_descriptor>>
{
    auto operator()(const std::pair<type_descriptor, type_descriptor>& val) const -> std::size_t
    {
        size_t seed = 0;
        seed ^= std::hash<const type*>{}(val.first) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        seed ^= std::hash<const type*>{}(val.second) + HASH_MAGIC + (seed << 6) + (seed >> 2);
        return seed;
    }
};

class base_ast;

void register_operators(sema_ctx& ctx);

class sema_ctx
{
public:
    class scope
    {
        using value = std::variant<type_descriptor, ct_value>;
        std::unordered_map<std::string, value> vars;
        bool is_ns;

    public:
        inline scope(bool is_ns) : is_ns(is_ns) {}

        [[nodiscard]] constexpr auto is_namespace() const { return is_ns; }
        constexpr auto get_vars() const -> const auto& { return vars; }
        constexpr auto get_vars() -> auto& { return vars; }
    };

private:
    std::vector<std::unique_ptr<type>> curr_parsed_types;
    compiler_context& compiler_ctx;

    std::unordered_map<std::string, type_descriptor> lang_types;

    // operator overloads
    std::unordered_map<binary_operator_signature, type_descriptor> declared_binary_operators;
    std::unordered_map<unary_operator_signature, type_descriptor> declared_unary_operators;
    std::unordered_map<lambda_signature, type_descriptor> lambda_types;
    std::unordered_set<std::pair<type_descriptor, type_descriptor>> conversions;

    std::unordered_map<std::string, type_descriptor> known_vars;

    std::unordered_map<std::string, type_descriptor> literal_string_specifiers;
    std::unordered_map<std::string, type_descriptor> literal_integer_specifiers;
    std::unordered_map<std::string, type_descriptor> literal_floating_specifiers;

    std::vector<std::string> curr_namespace;
    simple_namespace* root_ns;

    // this is the list of current in-scoped variables
    std::deque<scope> scoped_vars;
    std::stack<const base_ast*> ast_stack;
    bool is_func;

public:
    sema_ctx(compiler_context& ctx);

    auto add_type(std::unique_ptr<type> type) -> type_descriptor;

    inline auto langtype(primitive_type::kind type) const -> type_descriptor { return curr_parsed_types[type].get(); }

    // overload stuff
    void add_binary_operator(binary_op_type op_type, type_descriptor lhs, type_descriptor rhs, type_descriptor ret);
    void add_unary_operator(unary_op_type op_type, type_descriptor operand, type_descriptor ret);
    auto binary_operator_result(binary_op_type op_type, type_descriptor lhs, type_descriptor rhs) -> type_descriptor;
    auto unary_operator_result(unary_op_type op_type, type_descriptor operand) -> type_descriptor;

    // type builders
    auto make_simple_lambda_function(type_descriptor return_ty, const std::vector<type_descriptor>& rhs) -> type_descriptor;

    // @lang-id handling
    auto query_lang_id_type(const std::string& str) -> type_descriptor;

    // variable handling
    void push_local_stack();
    void pop_local_stack();

    void push_namespace_stack(const std::vector<std::string>& str);
    void pop_namespace_stack(size_t n);

    auto get_variable(const std::string& str) -> type_descriptor;
    auto add_variable(const std::string& str, type_descriptor desc) -> bool;
    void set_variable(const std::string& str, type_descriptor desc);
    auto add_comptime_value(const std::string& str, ct_value val) -> bool;
    auto get_comptime_value(const std::string& str) -> ct_value;

    // casting stuff
    auto exists_conversion(type_descriptor from, type_descriptor to) -> bool;
    void add_conversion(type_descriptor from, type_descriptor to);

    constexpr auto get_compiler_ctx() -> compiler_context& { return compiler_ctx; }

    auto resolve_attribtue(const std::string& name, const std::vector<type_descriptor>& desc) -> bool;

    auto resolve_literal_string(const std::string& name) const -> type_descriptor;
    auto resolve_literal_integer(const std::string& name) const -> type_descriptor;
    auto resolve_literal_floating(const std::string& name) const -> type_descriptor;

    inline auto get_current_scope() -> auto& { return scoped_vars.back(); }
    inline auto get_current_scope() const -> const auto& { return scoped_vars.back(); }

    constexpr auto is_function() const { return is_func; }
    constexpr void set_function(bool is_fn = true) { is_func = is_fn; }

    [[nodiscard]] constexpr auto get_ast_stack() const -> const auto& { return ast_stack; }
    inline  void push_ast(const base_ast* ast) { ast_stack.push(ast); }
    inline void pop_ast() { ast_stack.pop(); }
};

struct semantic_analysis_result
{
    type_descriptor ty{};
    bool is_valid{};
    bool can_be_constexpr = false;

    enum value_category
    {
        LVALUE,
        RVALUE
    } category = RVALUE;
};
