#include <filesystem>
#include <fmt/ranges.h>
#include <fstream>
#include <iostream>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/TableGen/Main.h>
#include <llvm/TableGen/Record.h>
#include <llvm/TableGen/TableGenBackend.h>
#include <ranges>

inline constexpr auto REGISTER_OP_CPP_FORMAT = R"(#include "lang/sema/sema_ctx.h"
void register_operators(sema_ctx& ctx)
{{
{}
}}
)";

inline constexpr auto REGISTER_OP_CODEGEN_FORMAT = R"(#include "lang/sema/sema_ctx.h"
void register_binary_operator_codegen(codegen_ctx& ctx)
{{
{}
}}
)";

inline constexpr auto REGISTER_CODEGEN_HANDLER_FORMAT = R"(#include "lang/sema/sema_ctx.h"
#include "lang/sema/register_ops.h"

)";

inline constexpr auto SIMPLE_CODEGEN_HANDLER_FORMAT =
    R"(static llvm::Value* {}(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{{
    {}
}}
)";

template <>
struct fmt::formatter<llvm::StringRef>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const llvm::StringRef& value, FormatContext& ctx)
    {
        return fmt::format_to(ctx.out(), "{}", value.str());
    }
};

auto get_type_enum_name_from_value(llvm::RecordVal* val)
{
    return dynamic_cast<llvm::DefInit*>(val->getValue())->getDef()->getValueAsString("enum_name");
}

auto handler(llvm::raw_ostream& /*ostream*/, llvm::RecordKeeper& records) -> bool
{
    auto binops = records.getAllDerivedDefinitions("binary_operator");
    std::filesystem::create_directories("gen");
    std::ofstream sema_register("gen/register_ops.cpp");
    std::ofstream binop_codegen("gen/binop_codegen.cpp");

    sema_register << fmt::format(REGISTER_OP_CPP_FORMAT,
                                 fmt::join(binops | std::views::transform([](llvm::Record* oper) {
                                               auto op_name = oper->getValueAsString("operator");
                                               auto lhs_type = get_type_enum_name_from_value(oper->getValue("lhs_type"));
                                               auto rhs_type = get_type_enum_name_from_value(oper->getValue("rhs_type"));
                                               auto result_type = get_type_enum_name_from_value(oper->getValue("result_type"));
                                               std::cerr << "adding registration for " << oper->getName().str() << "\n";
                                               return fmt::format("ctx.add_binary_operator({}, ctx.langtype(primitive_type::{}), "
                                                                  "ctx.langtype(primitive_type::{}), ctx.langtype(primitive_type::{}));",
                                                                  op_name, lhs_type, rhs_type, result_type);
                                           }),
                                           "\n"));

    binop_codegen << R"(#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
    )";

    for (auto* oper : records.getAllDerivedDefinitions("arithmetic_binary_operator"))
    {
        auto is_signed = !dynamic_cast<llvm::DefInit*>(oper->getValue("result_type")->getValue())->getDef()->getValueAsBit("is_unsigned");
        auto lhs_width = dynamic_cast<llvm::DefInit*>(oper->getValue("lhs_type")->getValue())->getDef()->getValueAsInt("width");
        auto rhs_width = dynamic_cast<llvm::DefInit*>(oper->getValue("rhs_type")->getValue())->getDef()->getValueAsInt("width");
        auto result_width = dynamic_cast<llvm::DefInit*>(oper->getValue("result_type")->getValue())->getDef()->getValueAsInt("width");
        auto llvm_func_name = oper->getValueAsString("llvm_function_name");

        std::string lhs_value = "lhs.get_value(ctx)";
        std::string rhs_value = "rhs.get_value(ctx)";

        if (lhs_width < result_width)
        {
            lhs_value = std::string("ctx.builder().CreateCast(") + (is_signed ? "llvm::Instruction::SExt" : "llvm::Instruction::ZExt") +
                        ", lhs.get_value(ctx), rhs.get_value(ctx)->getType())";
        }
        else if (rhs_width < result_width)
        {
            rhs_value = std::string("ctx.builder().CreateCast(") + (is_signed ? "llvm::Instruction::SExt" : "llvm::Instruction::ZExt") +
                        ", rhs.get_value(ctx), lhs.get_value(ctx)->getType())";
        }

        binop_codegen << fmt::format(SIMPLE_CODEGEN_HANDLER_FORMAT, oper->getName(),
                                     fmt::format("return ctx.builder().{}({}, {});", llvm_func_name, lhs_value, rhs_value));
    }

    for (auto* oper : records.getAllDerivedDefinitions("predicate_binary_operator"))
    {
        auto is_signed = !dynamic_cast<llvm::DefInit*>(oper->getValue("result_type")->getValue())->getDef()->getValueAsBit("is_unsigned");
        auto lhs_width = dynamic_cast<llvm::DefInit*>(oper->getValue("lhs_type")->getValue())->getDef()->getValueAsInt("width");
        auto rhs_width = dynamic_cast<llvm::DefInit*>(oper->getValue("rhs_type")->getValue())->getDef()->getValueAsInt("width");
        auto llvm_func_name = oper->getValueAsString("llvm_function_name");

        std::string lhs_value = "lhs.get_value(ctx)";
        std::string rhs_value = "rhs.get_value(ctx)";

        if (lhs_width < std::max(lhs_width, rhs_width))
        {
            lhs_value = std::string("ctx.builder().CreateCast(") + (is_signed ? "llvm::Instruction::SExt" : "llvm::Instruction::ZExt") +
                        ", lhs.get_value(ctx), rhs.get_value(ctx)->getType())";
        }
        else if (rhs_width < std::max(lhs_width, rhs_width))
        {
            rhs_value = std::string("ctx.builder().CreateCast(") + (is_signed ? "llvm::Instruction::SExt" : "llvm::Instruction::ZExt") +
                        ", rhs.get_value(ctx), lhs.get_value(ctx)->getType())";
        }

        binop_codegen << fmt::format(SIMPLE_CODEGEN_HANDLER_FORMAT, oper->getName(),
                                     fmt::format("return ctx.builder().{}({}, {});", llvm_func_name, lhs_value, rhs_value));
    }

    for (auto* oper : records.getAllDerivedDefinitions("trivial_assignment_binop"))
    {
        auto is_signed = !dynamic_cast<llvm::DefInit*>(oper->getValue("result_type")->getValue())->getDef()->getValueAsBit("is_unsigned");
        auto lhs_width = dynamic_cast<llvm::DefInit*>(oper->getValue("lhs_type")->getValue())->getDef()->getValueAsInt("width");
        auto rhs_width = dynamic_cast<llvm::DefInit*>(oper->getValue("rhs_type")->getValue())->getDef()->getValueAsInt("width");

        std::string rhs_value = "rhs.get_value(ctx)";

        if (rhs_width < lhs_width)
        {
            rhs_value = std::string("ctx.builder().CreateCast(") + (is_signed ? "llvm::Instruction::SExt" : "llvm::Instruction::ZExt") +
                        ", rhs.get_value(ctx), lhs.get_value(ctx)->getType())";
        }

        binop_codegen << fmt::format(
            SIMPLE_CODEGEN_HANDLER_FORMAT, oper->getName(),
            fmt::format("lhs.store_value(ctx, codegen_value::make_constant(return_ty, {})); return {};", rhs_value, rhs_value));
    }

    for (auto* oper : records.getAllDerivedDefinitions("arithmetic_assignment_binop"))
    {
        auto is_signed = !dynamic_cast<llvm::DefInit*>(oper->getValue("result_type")->getValue())->getDef()->getValueAsBit("is_unsigned");
        auto rhs_width = dynamic_cast<llvm::DefInit*>(oper->getValue("rhs_type")->getValue())->getDef()->getValueAsInt("width");
        auto result_width = dynamic_cast<llvm::DefInit*>(oper->getValue("result_type")->getValue())->getDef()->getValueAsInt("width");
        auto llvm_func_name = oper->getValueAsString("llvm_function_name");

        std::string rhs_value = "rhs.get_value(ctx)";

        if (rhs_width < result_width)
        {
            rhs_value = std::string("ctx.builder().CreateCast(") + (is_signed ? "llvm::Instruction::SExt" : "llvm::Instruction::ZExt") +
                        ", rhs.get_value(ctx), lhs.get_value(ctx)->getType())";
        }

        binop_codegen << fmt::format(
            SIMPLE_CODEGEN_HANDLER_FORMAT, oper->getName(),
            fmt::format("auto value = codegen_value::make_constant(return_ty, ctx.builder().{}({}, {})); lhs.store_value(ctx, "
                        "value); return value.get_value(ctx);",
                        llvm_func_name, "lhs.get_value(ctx)", rhs_value));
    }

    for (auto* oper : records.getAllDerivedDefinitions("custom_binop"))
    {
        binop_codegen << fmt::format(SIMPLE_CODEGEN_HANDLER_FORMAT, oper->getName(), oper->getValueAsString("codegen"));
    }

    binop_codegen << fmt::format(REGISTER_OP_CODEGEN_FORMAT,
                                 fmt::join(binops | std::views::transform([](llvm::Record* oper) {
                                               auto op_name = oper->getValueAsString("operator");
                                               auto lhs_type = get_type_enum_name_from_value(oper->getValue("lhs_type"));
                                               auto rhs_type = get_type_enum_name_from_value(oper->getValue("rhs_type"));

                                               return fmt::format(
                                                   "ctx.register_binary_op_handler({{{}, ctx.get_sema_ctx().langtype(primitive_type::{}), "
                                                   "ctx.get_sema_ctx().langtype(primitive_type::{})}}, {});",
                                                   op_name, lhs_type, rhs_type, oper->getName());
                                           }),
                                           "\n"));

    return false;
}

auto main(int argc, char** argv) -> int
{
    llvm::cl::ParseCommandLineOptions(argc, argv);
    return llvm::TableGenMain(argv[0], &handler);
}
