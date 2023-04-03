#include "lang/ast/base_ast.h"
#include "lang/sema/types.h"

class empty_ast : public base_ast
{
protected:
    inline auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override
    {
        return {context.langtype(primitive_type::UNIT), true};
    }

    inline auto do_codegen(codegen_ctx& context) const -> codegen_value override { return context.get_void_val(); }

public:
    inline empty_ast(code_location start, code_location end) : base_ast(start, end, EMPTY_STMT) {}
    inline void visit_children(const std::function<void(const base_ast&)>& /*consumer*/) const override {}
    inline auto serialize() const -> std::string override { return "(empty_ast)"; }
};
