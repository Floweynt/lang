#pragma once

constexpr auto codegen_name(const char* name)
{
#ifndef DISABLE_CODEGEN_NAME
    return name;
#else
    return "";
#endif
}
