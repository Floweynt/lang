#include "lang/ast/lambda_expr_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/codegen/codegen.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/raii_guard.h"
#include "lang/sema/sema.h"
#include "lang/sema/types.h"
#include <fmt/ranges.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <memory>
#include <optional>
#include <ranges>
#include <vector>

lambda_expr::lambda_expr(code_location start, code_location end, std::vector<ast_ref> args, ast_ref return_type, ast_ref body)
    : base_ast(start, end, LAMBDA_EXPR), args(std::move(args)), return_type(std::move(return_type)), body(std::move(body))
{
}

void lambda_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& arg : args)
    {
        consumer(*arg);
    }
    if (return_type)
    {
        consumer(*return_type);
    }
    consumer(*body);
}

auto lambda_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    return do_sema_func(context, args, body, return_type, "");
}

namespace
{
    auto gen_random(size_t len) -> std::string
    {
        std::string tmp_s;
        tmp_s.reserve(len);

        for (int i = 0; i < len; ++i)
        {
            tmp_s += "1234567890abcdef"[rand() % 16];
        }

        return tmp_s;
    }
} // namespace

auto lambda_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    return do_codegen_func(context, llvm::GlobalValue::InternalLinkage, "__lambda_" + gen_random(32), get_sema_result().ty, args, body, true);
}

auto lambda_expr::serialize() const -> std::string
{
    return fmt::format("(lambda_expression ({}) {} {})",
                       fmt::join(args | std::ranges::views::transform([](const ast_ref& entry) { return entry->serialize(); }), " "),
                       return_type ? return_type->serialize() : "null", body ? body->serialize() : "null");
}
