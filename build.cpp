#include <algorithm>
#include <filesystem>
#include <metabuild/api/build_config.h>
#include <metabuild/api/compiler_flags.h>
#include <metabuild/api/core.h>
#include <metabuild/api/executable.h>
#include <metabuild/api/linker_flags.h>
#include <metabuild/api/log.h>
#include <metabuild/api/plugin.h>

using namespace metabuild;

auto do_operator_tablegen()
{
    auto exec = executable("operator-tblgen", metabuild::compiler_flags::C11, metabuild::compiler_flags::CXX20, {.cxx = compiler_flags().add_flags("-DFMT_HEADER_ONLY")})
                    .library("m")
                    .library("LLVMTableGen")
                    .library("LLVM-16")
                    .set_build_type(RELEASE_DEBUGINFO)
                    .add_src(source_root() / "tools/operator_tablegen.cpp")
                    .parallelize()
                    .libstdcxx();

    if(exec.build().invoke({source_root() / "operators.td"}) != 0)
    {
        fatal("failed to generate");
    }
}

auto do_build(const std::string& postfix, metabuild::build_type type, bool sanitizer = false)
{
    do_operator_tablegen();
    compiler_flags flags;
    flags.add_flags("-DFMT_HEADER_ONLY");
    if (sanitizer)
    {
        flags.add_flags("-fsanitize=address,undefined");
    }

    auto exec = executable("compiler-" + postfix, metabuild::compiler_flags::C11, metabuild::compiler_flags::CXX20, {.cxx = flags})
                    .library("m")
                    .library("LLVM-16")
                    .include_dir(source_root() / "include/")
                    .include_dir(source_root() / "deps/stacktrace/include")
                    .include_dir(source_root() / "deps/magic_enum/include/")
                    .include_dir(source_root() / "deps/stacktrace/build")
                    .include_dir(source_root() / "deps/argparse/include/")
                    .set_build_type(type)
                    .parallelize()
                    .libstdcxx();

    for (const auto& entry : std::filesystem::recursive_directory_iterator(source_root() / "src"))
    {
        if (entry.path().extension() != ".cpp")
        {
            continue;
        }

        exec.add_src(entry.path());
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(source_root() / "gen"))
    {
        if (entry.path().extension() != ".cpp")
        {
            continue;
        }

        exec.add_src(entry.path());
    }

    return exec.build();
}

METABUILD_ENTRY void metabuild_register(build_registration& reg)
{
    reg.add("build", [](auto) -> int {
        (void)do_build("debug", DEBUG, false);
        return 0;
    });

    reg.add("build-san", [](auto) -> int {
        (void)do_build("san", DEBUG, true);
        return 0;
    });

    reg.add("build-release", [](auto) -> int {
        (void)do_build("release", RELEASE, false);
        return 0;
    });
}
