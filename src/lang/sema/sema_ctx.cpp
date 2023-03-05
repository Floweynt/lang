#include "lang/sema/sema_ctx.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/operator_types.h"
#include "lang/compiler_context.h"
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

class comptime_builtin : public type
{
public:
    comptime_builtin(const std::string& name) : type(name, IS_BUILTIN_FUNC_TYPE | IS_COMPTIME_ONLY_BUILTIN_FUNC_TYPE) {}

    auto get_llvm_type(codegen_ctx& context) const -> llvm::Type* override { return context.get_unit_ty(); }
};

class type_dump_builtin : public comptime_builtin
{
public:
    type_dump_builtin() : comptime_builtin("<internal-type-dump>") {}

    auto invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const -> type_descriptor override
    {
        auto name_list = desc | std::views::transform([](type_descriptor desc) {
                             return diagnostic::diagnostic_entry{std::monostate{}, "type is: " + desc->get_name()};
                         });

        ctx.get_compiler_ctx().report_diagnostic({{ctx.get_ast_stack().top()->range(), "dumping types"},
                                                  std::nullopt,
                                                  std::vector<diagnostic::diagnostic_entry>(name_list.begin(), name_list.end()),
                                                  diagnostic::info});

        return ctx.langtype(primitive_type::UNIT);
    }

    auto invoke_codegen(codegen_ctx& ctx, const codegen_value& /*callee*/, const std::vector<codegen_value>& /*desc*/) const -> codegen_value override
    {
        return ctx.get_void_val();
    }
};

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
    add_type(std::make_unique<primitive_type>("<undeduced-type>", 0, nullptr));

    const auto* signed_integrals = add_type(simple_namespace_builder(*this)
                                                .add_type("b8", langtype(primitive_type::INTEGRAL_SIGNED_B8))
                                                .add_type("b16", langtype(primitive_type::INTEGRAL_SIGNED_B16))
                                                .add_type("b32", langtype(primitive_type::INTEGRAL_SIGNED_B32))
                                                .add_type("b64", langtype(primitive_type::INTEGRAL_SIGNED_B64))
                                                .add_type("max", langtype(primitive_type::INTEGRAL_MAX))
                                                .build("signed"));

    const auto* unsigned_integrals = add_type(simple_namespace_builder(*this)
                                                  .add_type("b8", langtype(primitive_type::INTEGRAL_UNSIGNED_B8))
                                                  .add_type("b16", langtype(primitive_type::INTEGRAL_UNSIGNED_B16))
                                                  .add_type("b32", langtype(primitive_type::INTEGRAL_UNSIGNED_B32))
                                                  .add_type("b64", langtype(primitive_type::INTEGRAL_UNSIGNED_B64))
                                                  .build("unsigned"));

    const auto* integrals =
        add_type(simple_namespace_builder(*this).add_type("signed", signed_integrals).add_type("unsigned", unsigned_integrals).build("integral"));

    const auto* floating = add_type(simple_namespace_builder(*this)
                                        .add_type("b32", langtype(primitive_type::FLOATING_B32))
                                        .add_type("b64", langtype(primitive_type::FLOATING_B64))
                                        .build("floating"));

    const auto* chars = add_type(simple_namespace_builder(*this)
                                     .add_type("b8", langtype(primitive_type::CHAR_B8))
                                     .add_type("b16", langtype(primitive_type::CHAR_B16))
                                     .add_type("b32", langtype(primitive_type::CHAR_B32))
                                     .add_type("wide", langtype(primitive_type::CHAR_WIDE))
                                     .build("char"));

    const auto* types = add_type(simple_namespace_builder(*this)
                                     .add_type("integral", integrals)
                                     .add_type("floating", floating)
                                     .add_type("char", chars)
                                     .add_type("meta", langtype(primitive_type::META))
                                     .add_type("unit", langtype(primitive_type::UNIT))
                                     .add_type("bool", langtype(primitive_type::BOOL))
                                     .build("types"));

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

    for (auto oper :
         {OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_EQ, OP_NEQ, OP_LESS, OP_GREATER, OP_GEQ, OP_LEQ, OP_BITWISE_AND, OP_BITWISE_OR, OP_BITWISE_XOR})
    {
        for (const auto* rhs : integral_list)
        {
            for (const auto* lhs : integral_list)
            {
                add_binary_operator(oper, lhs, rhs, first_match(rhs, lhs, integral_list));
            }
        }
        for (const auto* rhs : unsigned_list)
        {
            for (const auto* lhs : unsigned_list)
            {
                add_binary_operator(oper, lhs, rhs, first_match(rhs, lhs, unsigned_list));
            }
        }
    }

    for(const auto *numeric : numeric_list)
    {
        for(const auto *shiftand : unsigned_list)
        {
            add_binary_operator(OP_SHR, numeric, shiftand, numeric);
        }
    }

    for(const auto *type : unsigned_list)
    {
        for(const auto *shiftand : unsigned_list)
        {
            add_binary_operator(OP_SHL, type, shiftand, type);
        }
    }

    for (const auto* type : numeric_list)
    {
        add_binary_operator(OP_ASSIGN, type, type, type);
        add_conversion(type, langtype(primitive_type::BOOL));
        add_unary_operator(OP_INC, type, type);
        add_unary_operator(OP_DEC, type, type);
        add_unary_operator(OP_LOGICAL_NOT, type, type);
        add_unary_operator(OP_BITWISE_NOT, type, type);
        add_unary_operator(OP_NEGATE, type, type);
    }

    lang_types["lang"] = add_type(simple_namespace_builder(*this).add_type("types", types).build("@lang"));
    lang_types["utils"] =
        add_type(simple_namespace_builder(*this).add_value("dump_type", add_type(std::make_unique<type_dump_builtin>())).build("@utils"));

    scoped_vars.emplace_back(true);
    ast_stack.push(nullptr);
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
    binary_operator_signature sig = {op_type, lhs, rhs};
    declared_binary_operators[sig] = ret;
}

void sema_ctx::add_unary_operator(unary_op_type op_type, type_descriptor operand, type_descriptor ret)
{
    unary_operator_signature sig = {op_type, operand};
    declared_unary_operators[sig] = ret;
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

auto sema_ctx::make_simple_lambda_function(type_descriptor return_ty, const std::vector<type_descriptor>& rhs) -> type_descriptor
{
    if (!lambda_types.contains({return_ty, rhs}))
    {
        std::string name;

        if (!rhs.empty())
        {
            name = std::accumulate(rhs.begin() + 1, rhs.end(), rhs.front()->get_name(),
                                   [](const std::string& folder, type_descriptor value) { return folder + ", " + value->get_name(); });
        }

        lambda_types[{return_ty, rhs}] = add_type(std::make_unique<trivial_function_type>(return_ty->get_name() + "(" + name + ")", return_ty, rhs));
    }

    return lambda_types.at({return_ty, rhs});
}

auto sema_ctx::exists_conversion(type_descriptor from, type_descriptor to) -> bool { return from == to || conversions.contains({from, to}); }

void sema_ctx::add_conversion(type_descriptor from, type_descriptor to) { conversions.insert({from, to}); }

void sema_ctx::push_local_stack() { scoped_vars.emplace_back(false); }

void sema_ctx::pop_local_stack() { scoped_vars.pop_back(); }

void sema_ctx::push_namespace_stack(const std::vector<std::string>& str)
{
    curr_namespace.insert(curr_namespace.end(), str.begin(), str.end());
    scoped_vars.emplace_back(true);
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

        if (scoped_var.get_vars().contains(str))
        {
            return std::visit(type_getting_visitor(), scoped_var.get_vars().at(str));
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
    scoped_vars.back().get_vars()[str] = desc;
    return true;
}

void sema_ctx::set_variable(const std::string& str, type_descriptor desc)
{
    if (get_variable(str) == langtype(primitive_type::ERROR))
    {
        throw std::runtime_error("internal error: unknown var");
    }

    scoped_vars.back().get_vars()[str] = desc;
}

auto sema_ctx::add_comptime_value(const std::string& str, ct_value val) -> bool
{
    if (get_variable(str) != langtype(primitive_type::ERROR))
    {
        return false;
    }
    scoped_vars.back().get_vars()[str] = val;
    return true;
}

auto sema_ctx::get_comptime_value(const std::string& str) -> ct_value
{
    for (auto& scoped_var : std::ranges::reverse_view(scoped_vars))
    {
        struct ct_value_getting_visitor
        {
            sema_ctx& sema;
            auto operator()(type_descriptor /* desc */) const -> ct_value { return {sema.langtype(primitive_type::ERROR), nullptr}; }
            auto operator()(const ct_value& val) -> ct_value { return val; }
        };

        if (scoped_var.get_vars().contains(str))
        {
            return std::visit(ct_value_getting_visitor{*this}, scoped_var.get_vars().at(str));
        }
    }

    return {langtype(primitive_type::ERROR), nullptr};
}

auto sema_ctx::resolve_attribtue(const std::string& /*name*/, const std::vector<type_descriptor>& /*desc*/) -> bool { return false; }
