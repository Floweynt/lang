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

template <>
struct std::hash<binary_operator_signature>
{
    std::size_t operator()(const binary_operator_signature& val) const
    {
        size_t seed = 0;
        seed ^= std::hash<int>{}(std::get<0>(val)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<const type*>{}(std::get<1>(val)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<const type*>{}(std::get<2>(val)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

template <>
struct std::hash<unary_operator_signature>
{
    std::size_t operator()(const unary_operator_signature& val) const
    {
        size_t seed = 0;
        seed ^= std::hash<int>{}(std::get<0>(val)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<const type*>{}(std::get<1>(val)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

template <>
struct std::hash<lambda_signature>
{
    std::size_t operator()(const lambda_signature& val) const
    {
        size_t seed = 0;
        seed ^= std::hash<const type*>{}(std::get<0>(val)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        for (auto i : std::get<1>(val))
            seed ^= std::hash<const type*>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

template <>
struct std::hash<std::pair<type_descriptor, type_descriptor>>
{
    std::size_t operator()(const std::pair<type_descriptor, type_descriptor>& val) const
    {
        size_t seed = 0;
        seed ^= std::hash<const type*>{}(val.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<const type*>{}(val.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

class sema_ctx
{
    std::vector<std::unique_ptr<type>> curr_parsed_types;
    compiler_context& compiler_ctx;

    std::unordered_map<std::string, type_descriptor> lang_types;

    // operator overloads
    std::unordered_map<binary_operator_signature, type_descriptor> declared_binary_operators;
    std::unordered_map<unary_operator_signature, type_descriptor> declared_unary_operators;
    std::unordered_map<lambda_signature, type_descriptor> lambda_types;
    std::unordered_set<std::pair<type_descriptor, type_descriptor>> conversions;

    std::unordered_map<std::string, type_descriptor> known_vars;

    std::vector<std::string> curr_namespace;
    simple_namespace* root_ns;

    // this is the list of current in-scoped variables
    std::deque<std::pair<std::unordered_map<std::string, std::variant<type_descriptor, ct_value>>, bool>> scoped_vars;

public:
    sema_ctx(compiler_context& ctx);
    bool is_function;

    type_descriptor add_type(std::unique_ptr<type> ty);

    constexpr type_descriptor langtype(primitive_type::kind ty) const { return curr_parsed_types[ty].get(); }

    // overload stuff
    void add_binary_operator(binary_op_type op_type, type_descriptor lhs, type_descriptor rhs, type_descriptor ret);
    void add_unary_operator(unary_op_type op_type, type_descriptor operand, type_descriptor ret);
    type_descriptor binary_operator_result(binary_op_type op_type, type_descriptor lhs, type_descriptor rhs);
    type_descriptor unary_operator_result(unary_op_type op_type, type_descriptor operand);

    // type builders
    type_descriptor make_simple_lambda_function(type_descriptor return_ty, const std::vector<type_descriptor> rhs);

    // @lang-id handleing
    type_descriptor query_lang_id_type(const std::string& str);

    // variable handling
    void push_local_stack();
    void pop_local_stack();

    void push_namespace_stack(const std::vector<std::string>& str);
    void pop_namespace_stack(size_t n);

    type_descriptor get_variable(const std::string& str);
    bool add_variable(const std::string& str, type_descriptor desc);
    bool add_comptime_value(const std::string& str, ct_value val);
    ct_value get_comptime_value(const std::string& str);

    // casting stuff
    bool exists_conversion(type_descriptor from, type_descriptor to);
    void add_conversion(type_descriptor from, type_descriptor to);

    constexpr compiler_context& get_compiler_ctx() { return compiler_ctx; }
};

struct semantic_analysis_result
{
    type_descriptor ty;
    bool is_valid;
    bool can_be_constexpr = false;
};
