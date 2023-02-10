#include "lang/sema/types.h"
#include "lang/sema/sema_ctx.h"

type_descriptor type::resolve_name(sema_ctx& ctx, const std::string& name) const { return ctx.langtype(primitive_type::ERROR); }
ct_value type::constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const { return {ctx.langtype(primitive_type::ERROR), nullptr}; }

primitive_type::primitive_type(const std::string& name) : type(name, true) {}

type_descriptor primitive_type::invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const { return ctx.langtype(ERROR); }

trivial_function_type::trivial_function_type(const std::string& name, type_descriptor ret, const std::vector<type_descriptor>& args)
    : type(name, true), args(args), return_ty(ret)
{
}

type_descriptor trivial_function_type::invoke_result(sema_ctx& c, const std::vector<type_descriptor>& desc) const
{
    return desc == args ? return_ty : c.langtype(primitive_type::ERROR);
}
