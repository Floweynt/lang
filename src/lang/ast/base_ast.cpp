#include "lang/ast/base_ast.h"
#include "lang/sema/sema_ctx.h"
#include <stdexcept>

auto base_ast::do_consteval(sema_ctx& /* */) const -> ct_value { throw std::runtime_error("cannot do consteval"); }
