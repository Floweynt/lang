#include "lang/ast/top_level_blk_ast.h"
#include "lang/sema/types.h"
#include <bits/ranges_algo.h>

semantic_analysis_result top_level_blk::do_semantic_analysis(sema_ctx& c) const
{
    bool is_valid = true;
    for (const auto& i : statements)
        is_valid &= i->semantic_analysis(c).is_valid;
    return {c.langtype(primitive_type::UNIT), is_valid};
}

top_level_blk::top_level_blk(code_location start, code_location end, std::vector<ast_ref> statements)
    : base_ast(start, end, TOP_LEVEL_BLOCK), statements(std::move(statements))
{
}

void top_level_blk::visit_children(const std::function<void(const base_ast&)>& f) const
{
    for (const auto& i : statements)
        f(*i);
}
