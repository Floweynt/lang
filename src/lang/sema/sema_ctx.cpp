#include "lang/sema/sema_ctx.h"
#include "lang/ast/operator_types.h"
#include "lang/sema/simple_namespace.h"
#include "lang/sema/types.h"
#include <algorithm>
#include <numeric>

template <typename T>
constexpr type_descriptor first_match(type_descriptor ty1, type_descriptor ty2, const T& arr)
{
    for (const auto i : arr)
        if (ty1 == i || ty2 == i)
            return i;
    return nullptr;
}

sema_ctx::sema_ctx(compiler_context& ctx) : compiler_ctx(ctx)
{
    add_type(std::make_unique<primitive_type>("builtin::int8"));
    add_type(std::make_unique<primitive_type>("builtin::int16"));
    add_type(std::make_unique<primitive_type>("builtin::int32"));
    add_type(std::make_unique<primitive_type>("builtin::int64"));
    add_type(std::make_unique<primitive_type>("builtin::intmax"));
    add_type(std::make_unique<primitive_type>("builtin::uint8"));
    add_type(std::make_unique<primitive_type>("builtin::uint16"));
    add_type(std::make_unique<primitive_type>("builtin::uint32"));
    add_type(std::make_unique<primitive_type>("builtin::uint64"));
    add_type(std::make_unique<primitive_type>("builtin::float32"));
    add_type(std::make_unique<primitive_type>("builtin::float64"));
    add_type(std::make_unique<primitive_type>("builtin::char8"));
    add_type(std::make_unique<primitive_type>("builtin::char16"));
    add_type(std::make_unique<primitive_type>("builtin::char32"));
    add_type(std::make_unique<primitive_type>("builtin::wchar"));
    add_type(std::make_unique<primitive_type>("builtin::metatype"));
    add_type(std::make_unique<primitive_type>("builtin::unit"));
    add_type(std::make_unique<primitive_type>("builtin::bool"));

    auto signed_integrals = add_type(std::make_unique<simple_namespace>(
        "signed", std::unordered_map<std::string, type_descriptor>{{"b8", langtype(primitive_type::INTEGRAL_SIGNED_B8)},
                                                                   {"b16", langtype(primitive_type::INTEGRAL_SIGNED_B16)},
                                                                   {"b32", langtype(primitive_type::INTEGRAL_SIGNED_B32)},
                                                                   {"b64", langtype(primitive_type::INTEGRAL_SIGNED_B64)},
                                                                   {"max", langtype(primitive_type::INTEGRAL_MAX)}}));

    auto unsigned_integrals = add_type(std::make_unique<simple_namespace>(
        "unsigned", std::unordered_map<std::string, type_descriptor>{{"b8", langtype(primitive_type::INTEGRAL_UNSIGNED_B8)},
                                                                     {"b16", langtype(primitive_type::INTEGRAL_UNSIGNED_B8)},
                                                                     {"b32", langtype(primitive_type::INTEGRAL_UNSIGNED_B8)},
                                                                     {"b64", langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}}));

    auto integrals = add_type(std::make_unique<simple_namespace>(
        "integral", std::unordered_map<std::string, type_descriptor>{{"signed", signed_integrals}, {"unsigned", unsigned_integrals}}));

    auto floating = add_type(std::make_unique<simple_namespace>(
        "floating", std::unordered_map<std::string, type_descriptor>{{"b32", langtype(primitive_type::FLOATING_B32)},
                                                                     {"b64", langtype(primitive_type::FLOATING_B64)}}));

    auto chars = add_type(
        std::make_unique<simple_namespace>("char", std::unordered_map<std::string, type_descriptor>{{"b8", langtype(primitive_type::CHAR_B8)},
                                                                                                    {"b16", langtype(primitive_type::CHAR_B16)},
                                                                                                    {"b32", langtype(primitive_type::CHAR_B32)},
                                                                                                    {"wide", langtype(primitive_type::CHAR_WIDE)}}));

    auto types = add_type(
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
        for (auto rhs : integral_list)
            for (auto lhs : integral_list)
                add_binary_operator(op, rhs, lhs, first_match(rhs, lhs, integral_list));
        for (auto rhs : unsigned_list)
            for (auto lhs : unsigned_list)
                add_binary_operator(op, rhs, lhs, first_match(rhs, lhs, unsigned_list));
    }

    for (auto op : {OP_EQ, OP_NEQ})
    {
        for (auto rhs : numeric_list)
        {
            for (auto lhs : numeric_list)
            {
                add_binary_operator(op, lhs, rhs, langtype(primitive_type::BOOL));
            }
        }
    }

    for (auto ty : numeric_list)
    {
        add_conversion(ty, langtype(primitive_type::BOOL));
    }

    add_type(std::make_unique<primitive_type>("<error_type>"));

    lang_types["lang"] = add_type(std::make_unique<simple_namespace>("@lang", std::unordered_map<std::string, type_descriptor>{{"types", types}}));
    scoped_vars.push_back({{}, true});
}

type_descriptor sema_ctx::add_type(std::unique_ptr<type> ty)
{
    curr_parsed_types.push_back(std::move(ty));
    return curr_parsed_types.back().get();
}

type_descriptor sema_ctx::query_lang_id_type(const std::string& str)
{
    if (lang_types.contains(str))
        return lang_types.at(str);
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

type_descriptor sema_ctx::binary_operator_result(binary_op_type op_type, type_descriptor lhs, type_descriptor rhs)
{
    if (!declared_binary_operators.contains({op_type, lhs, rhs}))
        return langtype(primitive_type::ERROR);
    return declared_binary_operators.at({op_type, lhs, rhs});
}

type_descriptor sema_ctx::unary_operator_result(unary_op_type op_type, type_descriptor operand)
{
    if (!declared_unary_operators.contains({op_type, operand}))
        return langtype(primitive_type::ERROR);
    return declared_unary_operators.at({op_type, operand});
}

type_descriptor sema_ctx::make_simple_lambda_function(type_descriptor return_ty, const std::vector<type_descriptor> rhs)
{
    if (!lambda_types.contains({return_ty, rhs}))
    {
        lambda_types[{return_ty, rhs}] = add_type(std::make_unique<trivial_function_type>(
            return_ty->get_name() + "(" +
                std::accumulate(rhs.begin(), rhs.end(), std::string(""), [](std::string a, type_descriptor b) { return a + ", " + b->get_name(); }) +
                ")",
            return_ty, rhs));
    }

    return lambda_types.at({return_ty, rhs});
}

bool sema_ctx::exists_conversion(type_descriptor from, type_descriptor to) { return conversions.contains({from, to}); }

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
    simple_namespace* ns = root_ns;
    for (const auto& i : curr_namespace)
        ns = ns->get_or_create_subnamespace(*this, i);
}

type_descriptor sema_ctx::get_variable(const std::string& str)
{
    for (auto i = scoped_vars.rbegin(); i != scoped_vars.rend(); i++)
    {
        struct type_getting_visitor
        {
            type_descriptor operator()(type_descriptor d) { return d; }
            type_descriptor operator()(const ct_value& d) { return d.get_type(); }
        };

        if (i->first.contains(str))
            return std::visit(type_getting_visitor(), i->first.at(str));
    }

    return langtype(primitive_type::ERROR);
}

bool sema_ctx::add_variable(const std::string& str, type_descriptor desc)
{
    if (get_variable(str) != langtype(primitive_type::ERROR))
        return false;
    scoped_vars.back().first[str] = desc;
    return true;
}

bool sema_ctx::add_comptime_value(const std::string& str, ct_value val)
{
    if (get_variable(str) != langtype(primitive_type::ERROR))
        return false;
    scoped_vars.back().first[str] = val;
    return true;
}

ct_value sema_ctx::get_comptime_value(const std::string& str)
{
    for (auto i = scoped_vars.rbegin(); i != scoped_vars.rend(); i++)
    {
        struct ct_value_getting_visitor
        {
            sema_ctx& s;
            ct_value operator()(type_descriptor d) { return {s.langtype(primitive_type::ERROR), nullptr}; }
            ct_value operator()(const ct_value& d) { return d; }
        };

        if (i->first.contains(str))
            return std::visit(ct_value_getting_visitor{*this}, i->first.at(str));
    }

    return {langtype(primitive_type::ERROR), nullptr};
}
