#pragma once

#define _MACRO_CONCAT2(prefix, suffix) prefix##suffix
#define _MACRO_CONCAT(prefix, suffix) _MACRO_CONCAT2(prefix, suffix)
#define _MACRO_DISCARD_IMPL(n) _MACRO_CONCAT(_discarded_val, n)
#define _ _MACRO_DISCARD_IMPL(__COUNTER__)

