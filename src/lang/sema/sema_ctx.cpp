#include "lang/sema/sema_ctx.h"
#include "lang/ast/operator_types.h"
#include "lang/sema/simple_namespace.h"
#include "lang/sema/types.h"
#include <algorithm>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <numeric>
#include <ranges>

template <typename T>
constexpr auto first_match(type_descriptor ty1, type_descriptor ty2, const T& arr) -> type_descriptor
{
    for (const auto entry : arr)
    {
        if (ty1 == entry || ty2 == entry)
        {
            return entry;
        }
    }
    return nullptr;
}

template <size_t N>
auto llvm_integral(llvm::LLVMContext& context) -> llvm::Type*
{
    return llvm::IntegerType::get(context, N);
}

sema_ctx::sema_ctx(compiler_context& ctx) : compiler_ctx(ctx)
{
    add_type(std::make_unique<primitive_type>("builtin::int8", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE | type::IS_SIGNED_INTEGRAL_TYPE,
                                              llvm_integral<8>));
    add_type(std::make_unique<primitive_type>("builtin::int16", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE | type::IS_SIGNED_INTEGRAL_TYPE,
                                              llvm_integral<16>));
    add_type(std::make_unique<primitive_type>("builtin::int32", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE | type::IS_SIGNED_INTEGRAL_TYPE,
                                              llvm_integral<32>));
    add_type(std::make_unique<primitive_type>("builtin::int64", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE | type::IS_SIGNED_INTEGRAL_TYPE,
                                              llvm_integral<64>));
    add_type(std::make_unique<primitive_type>("builtin::intmax", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE | type::IS_SIGNED_INTEGRAL_TYPE,
                                              llvm_integral<64>)); // TODO: dynamic
    add_type(std::make_unique<primitive_type>("builtin::uint8", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE, llvm_integral<8>));
    add_type(std::make_unique<primitive_type>("builtin::uint16", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE, llvm_integral<16>));
    add_type(std::make_unique<primitive_type>("builtin::uint32", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE, llvm_integral<32>));
    add_type(std::make_unique<primitive_type>("builtin::uint64", type::IS_INSTANTIABLE_TYPE | type::IS_INTEGRAL_TYPE, llvm_integral<64>));
    add_type(std::make_unique<primitive_type>("builtin::float32", type::IS_INSTANTIABLE_TYPE | type::IS_FLOATING_TYPE, nullptr));
    add_type(std::make_unique<primitive_type>("builtin::float64", type::IS_INSTANTIABLE_TYPE | type::IS_FLOATING_TYPE, nullptr));
    add_type(std::make_unique<primitive_type>("builtin::char8", type::IS_INSTANTIABLE_TYPE | type::IS_CHAR_TYPE, llvm_integral<8>));
    add_type(std::make_unique<primitive_type>("builtin::char16", type::IS_INSTANTIABLE_TYPE | type::IS_CHAR_TYPE, llvm_integral<16>));
    add_type(std::make_unique<primitive_type>("builtin::char32", type::IS_INSTANTIABLE_TYPE | type::IS_CHAR_TYPE, llvm_integral<32>));
    add_type(std::make_unique<primitive_type>("builtin::wchar", type::IS_INSTANTIABLE_TYPE | type::IS_CHAR_TYPE,
                                              llvm_integral<16>)); // TODO: dynamic
    add_type(std::make_unique<primitive_type>("builtin::metatype", type::IS_INSTANTIABLE_TYPE | type::IS_META_TYPE, nullptr));
    add_type(std::make_unique<primitive_type>(
        "builtin::unit", type::IS_INSTANTIABLE_TYPE | type::IS_UNIT_TYPE,
        +[](llvm::LLVMContext& context) { return (llvm::Type*)llvm::StructType::get(context); }));
    add_type(std::make_unique<primitive_type>("builtin::bool", type::IS_INSTANTIABLE_TYPE | type::IS_BOOL_TYPE, llvm_integral<1>));
    add_type(std::make_unique<primitive_type>("<error-type>", type::IS_ERROR_TYPE, nullptr));

    const auto* signed_integrals = add_type(std::make_unique<simple_namespace>(
        "signed", std::unordered_map<std::string, type_descriptor>{{"b8", langtype(primitive_type::INTEGRAL_SIGNED_B8)},
                                                                   {"b16", langtype(primitive_type::INTEGRAL_SIGNED_B16)},
                                                                   {"b32", langtype(primitive_type::INTEGRAL_SIGNED_B32)},
                                                                   {"b64", langtype(primitive_type::INTEGRAL_SIGNED_B64)},
                                                                   {"max", langtype(primitive_type::INTEGRAL_MAX)}}));

    const auto* unsigned_integrals = add_type(std::make_unique<simple_namespace>(
        "unsigned", std::unordered_map<std::string, type_descriptor>{{"b8", langtype(primitive_type::INTEGRAL_UNSIGNED_B8)},
                                                                     {"b16", langtype(primitive_type::INTEGRAL_UNSIGNED_B8)},
                                                                     {"b32", langtype(primitive_type::INTEGRAL_UNSIGNED_B8)},
                                                                     {"b64", langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}}));

    const auto* integrals = add_type(std::make_unique<simple_namespace>(
        "integral", std::unordered_map<std::string, type_descriptor>{{"signed", signed_integrals}, {"unsigned", unsigned_integrals}}));

    const auto* floating = add_type(std::make_unique<simple_namespace>(
        "floating", std::unordered_map<std::string, type_descriptor>{{"b32", langtype(primitive_type::FLOATING_B32)},
                                                                     {"b64", langtype(primitive_type::FLOATING_B64)}}));

    const auto* chars = add_type(
        std::make_unique<simple_namespace>("char", std::unordered_map<std::string, type_descriptor>{{"b8", langtype(primitive_type::CHAR_B8)},
                                                                                                    {"b16", langtype(primitive_type::CHAR_B16)},
                                                                                                    {"b32", langtype(primitive_type::CHAR_B32)},
                                                                                                    {"wide", langtype(primitive_type::CHAR_WIDE)}}));

    const auto* types = add_type(
        std::make_unique<simple_namespace>("types", std::unordered_map<std::string, type_descriptor>{{"integral", integrals},
                                                                                                     {"floating", floating},
                                                                                                     {"char", chars},
                                                                                                     {"meta", langtype(primitive_type::META)},
                                                                                                     {"unit", langtype(primitive_type::UNIT)},
                                                                                                     {"bool", langtype(primitive_type::BOOL)}}));
    auto integral_list = {
        langtype(primitive_type::INTEGRAL_MAX),        langtype(primitive_type::INTEGRAL_SIGNED_B64), langtype(primitive_type::INTEGRAL_SIGNED_B32),
        langtype(primitive_type::INTEGRAL_SIGNED_B16), langtype(primitive_type::INTEGRAL_SIGNED_B8),
    };

    auto unsigned_list = {
        langtype(primitive_type::INTEGRAL_UNSIGNED_B64),
        langtype(primitive_type::INTEGRAL_UNSIGNED_B32),
        langtype(primitive_type::INTEGRAL_UNSIGNED_B16),
        langtype(primitive_type::INTEGRAL_UNSIGNED_B8),
    };

    auto numeric_list = {
        langtype(primitive_type::INTEGRAL_MAX),          langtype(primitive_type::INTEGRAL_SIGNED_B64),
        langtype(primitive_type::INTEGRAL_SIGNED_B32),   langtype(primitive_type::INTEGRAL_SIGNED_B16),
        langtype(primitive_type::INTEGRAL_SIGNED_B8),    langtype(primitive_type::INTEGRAL_UNSIGNED_B64),
        langtype(primitive_type::INTEGRAL_UNSIGNED_B32), langtype(primitive_type::INTEGRAL_UNSIGNED_B16),
        langtype(primitive_type::INTEGRAL_UNSIGNED_B8),
    };

    for (auto op : {OP_ADD, OP_SUB, OP_MUL, OP_DIV})
    {
        for (const auto* rhs : integral_list)
        {
            for (const auto* lhs : integral_list)
            {
                add_binary_operator(op, rhs, lhs, first_match(rhs, lhs, integral_list));
            }
        }
        for (const auto* rhs : unsigned_list)
        {
            for (const auto* lhs : unsigned_list)
            {
                add_binary_operator(op, rhs, lhs, first_match(rhs, lhs, unsigned_list));
            }
        }
    }

    for (auto op : {OP_EQ, OP_NEQ})
    {
        for (const auto* rhs : numeric_list)
        {
            for (const auto* lhs : numeric_list)
            {
                add_binary_operator(op, lhs, rhs, langtype(primitive_type::BOOL));
            }
        }
    }

    for (const auto* ty : numeric_list)
    {
        add_binary_operator(OP_ASSIGN, ty, ty, ty);
    }

    for (const auto* ty : numeric_list)
    {
        add_conversion(ty, langtype(primitive_type::BOOL));
    }

    lang_types["lang"] = add_type(std::make_unique<simple_namespace>("@lang", std::unordered_map<std::string, type_descriptor>{{"types", types}}));
    scoped_vars.push_back({{}, true});
}

auto sema_ctx::add_type(std::unique_ptr<type> ty) -> type_descriptor
{
    curr_parsed_types.push_back(std::move(ty));
    return curr_parsed_types.back().get();
}

auto sema_ctx::query_lang_id_type(const std::string& str) -> type_descriptor
{
    if (lang_types.contains(str))
    {
        return lang_types.at(str);
    }
    return langtype(primitive_type::ERROR);
}

void sema_ctx::add_binary_operator(binary_op_type op_type, type_descriptor lhs, type_descriptor rhs, type_descriptor ret)
{
    declared_binary_operators[{op_type, lhs, rhs}] = ret;
}

void sema_ctx::add_unary_operator(unary_op_type op_type, type_descriptor operand, type_descriptor ret)
{
    declared_unary_operators[{op_type, operand}] = ret;
}

auto sema_ctx::binary_operator_result(binary_op_type op_type, type_descriptor lhs, type_descriptor rhs) -> type_descriptor
{
    if (!declared_binary_operators.contains({op_type, lhs, rhs}))
    {
        return langtype(primitive_type::ERROR);
    }
    return declared_binary_operators.at({op_type, lhs, rhs});
}

auto sema_ctx::unary_operator_result(unary_op_type op_type, type_descriptor operand) -> type_descriptor
{
    if (!declared_unary_operators.contains({op_type, operand}))
    {
        return langtype(primitive_type::ERROR);
    }
    return declared_unary_operators.at({op_type, operand});
}

auto sema_ctx::make_simple_lambda_function(type_descriptor return_ty, const std::vector<type_descriptor> rhs) -> type_descriptor
{
    if (!lambda_types.contains({return_ty, rhs}))
    {
        std::string name;

        if (!rhs.empty())
        {
            name = std::accumulate(rhs.begin() + 1, rhs.end(), rhs.front()->get_name(),
                                   [](const std::string& a, type_descriptor b) { return a + ", " + b->get_name(); });
        }

        lambda_types[{return_ty, rhs}] = add_type(std::make_unique<trivial_function_type>(return_ty->get_name() + "(" + name + ")", return_ty, rhs));
    }

    return lambda_types.at({return_ty, rhs});
}

auto sema_ctx::exists_conversion(type_descriptor from, type_descriptor to) -> bool { return conversions.contains({from, to}); }

void sema_ctx::add_conversion(type_descriptor from, type_descriptor to) { conversions.insert({from, to}); }

void sema_ctx::push_local_stack() { scoped_vars.push_back({{}, false}); }

void sema_ctx::pop_local_stack() { scoped_vars.pop_back(); }

void sema_ctx::push_namespace_stack(const std::vector<std::string>& str)
{
    curr_namespace.insert(curr_namespace.end(), str.begin(), str.end());
    scoped_vars.push_back({{}, true});
}

void sema_ctx::pop_namespace_stack(size_t n)
{
    simple_namespace* curr_ns = root_ns;
    for (const auto& stmt : curr_namespace)
    {
        curr_ns = curr_ns->get_or_create_subnamespace(*this, stmt);
    }
}

auto sema_ctx::get_variable(const std::string& str) -> type_descriptor
{
    for (auto& scoped_var : std::ranges::reverse_view(scoped_vars))
    {
        struct type_getting_visitor
        {
            auto operator()(type_descriptor d) -> type_descriptor { return d; }
            auto operator()(const ct_value& d) -> type_descriptor { return d.get_type(); }
        };

        if (scoped_var.first.contains(str))
        {
            return std::visit(type_getting_visitor(), scoped_var.first.at(str));
        }
    }

    return langtype(primitive_type::ERROR);
}

auto sema_ctx::add_variable(const std::string& str, type_descriptor desc) -> bool
{
    if (get_variable(str) != langtype(primitive_type::ERROR))
    {
        return false;
    }
    scoped_vars.back().first[str] = desc;
    return true;
}

auto sema_ctx::add_comptime_value(const std::string& str, ct_value val) -> bool
{
    if (get_variable(str) != langtype(primitive_type::ERROR))
    {
        return false;
    }
    scoped_vars.back().first[str] = val;
    return true;
}

auto sema_ctx::get_comptime_value(const std::string& str) -> ct_value
{
    for (auto& scoped_var : std::ranges::reverse_view(scoped_vars))
    {
        struct ct_value_getting_visitor
        {
            sema_ctx& s;
            auto operator()(type_descriptor /* desc */) const -> ct_value { return {s.langtype(primitive_type::ERROR), nullptr}; }
            auto operator()(const ct_value& val) -> ct_value { return val; }
        };

        if (scoped_var.first.contains(str))
        {
            return std::visit(ct_value_getting_visitor{*this}, scoped_var.first.at(str));
        }
    }

    return {langtype(primitive_type::ERROR), nullptr};
}

auto sema_ctx::resolve_attribtue(const std::string& /*name*/, const std::vector<type_descriptor>& /*desc*/) -> bool { return false; }
