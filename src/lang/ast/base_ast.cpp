#include "lang/ast/base_ast.h"
#include "lang/sema/sema_ctx.h"
#include <stdexcept>

ct_value base_ast::do_consteval(sema_ctx&) const { throw std::runtime_error("cannot do consteval"); }
