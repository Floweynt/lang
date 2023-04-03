#include "lang/ast/module_ast.h"
#include "lang/ast/base_ast.h"
#include <ranges>
#include <vector>

module_ast::module_ast(code_location start, code_location end, std::vector<std::vector<std::string>> module_imports, ast_ref block)
    : base_ast(start, end, MODULE_AST), module_imports(std::move(module_imports)), block(std::move(block))
{
}

auto module_ast::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result { return block->semantic_analysis(context); }

auto module_ast::do_codegen(codegen_ctx& context) const -> codegen_value { return block->codegen(context); }

void module_ast::visit_children(const std::function<void(const base_ast&)>& consumer) const { consumer(*block); }

auto module_ast::serialize() const -> std::string
{
    return fmt::format("(module_ast ({}) {})",
                       fmt::join(module_imports | std::ranges::views::transform([](const std::vector<std::string>& import) {
                                     return fmt::format("()", fmt::join(import, " "));
                                 }),
                                 " "),
                       block->serialize());
}
