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

auto do_build()
{
    std::vector<std::filesystem::path> p;
    auto e = executable("compiler", metabuild::compiler_flags::C11, metabuild::compiler_flags::CXX20,
                        {.cxx = compiler_flags().add_flags("-DFMT_HEADER_ONLY")

                        })
                 .library("m")
                 .include_dir(source_root() / "include/")
                 .include_dir(source_root() / "deps/stacktrace/include")
                 .include_dir(source_root() / "deps/stacktrace/build")
                 .set_build_type(metabuild::DEBUG)
                 .parallelize()
                 .libstdcxx();

    for (const auto& i : std::filesystem::recursive_directory_iterator(source_root() / "src"))
    {
        if (i.path().extension() != ".cpp")
            continue;
        e.add_src(i.path());
    }

    return e.build();
}

auto do_build_san()
{
    std::vector<std::filesystem::path> p;
    auto e = executable("compiler-sanitized", metabuild::compiler_flags::C11, metabuild::compiler_flags::CXX20,
                        {.cxx = compiler_flags().add_flags("-fsanitize=address,undefined")})
                 .library("m")
                 .library("fmt")
                 .include_dir(source_root() / "include/")
                 .set_build_type(metabuild::DEBUG)
                 .library("asan")
                 .library("ubsan")
                 .parallelize()
                 .libstdcxx();

    for (const auto& i : std::filesystem::recursive_directory_iterator(source_root() / "src"))
    {
        if (i.path().extension() != ".cpp")
            continue;
        e.add_src(i.path());
    }

    return e.build();
}

METABUILD_ENTRY void metabuild_register(build_registration& reg)
{
    reg.add("build", [](auto fn) -> int {
        auto o = do_build();
        return 0;
    });

    reg.add("build-san", [](auto fn) -> int {
        auto o = do_build_san();
        return 0;
    });
}
