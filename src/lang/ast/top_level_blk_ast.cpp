#include "lang/ast/top_level_blk_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/sema/types.h"
#include <bits/ranges_algo.h>
#include <fmt/ranges.h>
#include <llvm/IR/BasicBlock.h>
#include <ranges>

auto top_level_blk::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    bool is_valid = true;
    for (const auto& stmt : statements)
    {
        is_valid &= stmt->semantic_analysis(context).is_valid;
    }
    return {context.langtype(primitive_type::UNIT), is_valid};
}

top_level_blk::top_level_blk(code_location start, code_location end, std::vector<ast_ref> statements)
    : base_ast(start, end, TOP_LEVEL_BLOCK), statements(std::move(statements))
{
}

void top_level_blk::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& stmt : statements)
    {
        consumer(*stmt);
    }
}

auto top_level_blk::do_codegen(codegen_ctx& context) const -> codegen_value
{
    for (const auto& stmt : statements)
    {
        stmt->codegen(context);
    }
    return codegen_value::make_null();
}

auto top_level_blk::serialize() const -> std::string
{
    return fmt::format("(top_level_block ({}))",
                       fmt::join(statements | std::ranges::views::transform([](const ast_ref& ref) { return ref->serialize(); }), " "));
}
