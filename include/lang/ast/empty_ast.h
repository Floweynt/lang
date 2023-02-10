#include "lang/ast/base_ast.h"
#include "lang/sema/types.h"

class emtpy_ast : public base_ast
{
public:
    inline emtpy_ast(code_location start, code_location end) : base_ast(start, end, EMPTY_STMT) {}
    inline void visit_children(const std::function<void(const base_ast&)>& f) const override {}
    inline semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override { return {c.langtype(primitive_type::UNIT), true}; }
};
