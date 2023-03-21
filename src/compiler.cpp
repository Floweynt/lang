#include "lang/compiler.h"
#include <llvm/IR/Module.h>
#include <string>
auto compiler::parse_src() -> bool
{
    module = parse(lex, context);
    if (context.get_error_count() == 0)
    {
        stage = AST_PARSED;
        return true;
    }

    stage = ERROR;
    return false;
}

auto compiler::semantic_analysis() -> bool
{
    if (stage != AST_PARSED)
    {
        throw std::runtime_error("parse_src() must be the only pipeline method called before semantic_analysis()");
    }

    if (stage == ERROR)
    {
        throw std::runtime_error("parsing failed, that error must be handled before doing semantic analysis");
    }

    module->semantic_analysis(sema);

    if (context.get_error_count() == 0)
    {
        stage = AST_ANALYZED;
        return true;
    }

    stage = ERROR;
    return false;
}

void compiler::emit_ir()
{
    if (stage != AST_ANALYZED)
    {
        throw std::runtime_error("semantic_analysis() must be the pipeline method called directly before emit_ir()");
    }

    if (stage == ERROR)
    {
        throw std::runtime_error("semantic analysis failed, that error must be handled before doing semantic analysis");
    }

    module->codegen(codegen);
    stage = CODE_GENERATED;
}

void compiler::optimize(llvm::OptimizationLevel level)
{
    if (stage != CODE_GENERATED)
    {
        throw std::runtime_error("emit_ir() must be the pipeline method called directly before optimize()");
    }

    llvm::LoopAnalysisManager loop_analysis;
    llvm::FunctionAnalysisManager function_analysis;
    llvm::CGSCCAnalysisManager scc_analysis;
    llvm::ModuleAnalysisManager module_analysis;
    llvm::PassBuilder builder;

    builder.registerModuleAnalyses(module_analysis);
    builder.registerCGSCCAnalyses(scc_analysis);
    builder.registerFunctionAnalyses(function_analysis);
    builder.registerLoopAnalyses(loop_analysis);
    builder.crossRegisterProxies(loop_analysis, function_analysis, scc_analysis, module_analysis);

    llvm::ModulePassManager pass_mgr = builder.buildPerModuleDefaultPipeline(level);
    pass_mgr.run(codegen.module(), module_analysis);

    stage = CODE_OPTIMIZED;
}

// Not pipeline stages

auto compiler::get_serialized_ast() -> std::string
{
    if (stage < AST_PARSED)
    {
        throw std::runtime_error("serialize_ast must be called after parsing");
    }
    return module->serialize();
}

auto compiler::get_tokens() -> const std::vector<token>&
{
    if (stage < AST_PARSED)
    {
        throw std::runtime_error("get_tokens must be called after parsing");
    }
    return lex.get_prev_tokens();
}

auto compiler::get_raw_ir() -> llvm::Module&
{
    if (stage != CODE_GENERATED)
    {
        throw std::runtime_error("get_raw_ir must be called after codegen");
    }
    return codegen.module();
}

auto compiler::get_optimized_ir() -> llvm::Module&
{
    if (stage != CODE_OPTIMIZED)
    {
        throw std::runtime_error("get_optimized_ir must be called after optimization");
    }
    return codegen.module();
}

