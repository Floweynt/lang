#pragma once

#include "llvm/ADT/StringRef.h"
#include "llvm/ExecutionEngine/JITSymbol.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/ExecutionUtils.h"
#include "llvm/ExecutionEngine/Orc/ExecutorProcessControl.h"
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"
#include <memory>

class test_jit
{
private:
    std::unique_ptr<llvm::orc::ExecutionSession> session;
    llvm::DataLayout data_layout;
    llvm::orc::MangleAndInterner mangler;
    llvm::orc::RTDyldObjectLinkingLayer object_layer;
    llvm::orc::IRCompileLayer compile_layer;
    llvm::orc::JITDylib& main_jit_dylib;

public:
    test_jit(std::unique_ptr<llvm::orc::ExecutionSession> session, llvm::orc::JITTargetMachineBuilder builder, const llvm::DataLayout& data_layout)
        : session(std::move(session)), data_layout(data_layout), mangler(*this->session, this->data_layout),
          object_layer(*this->session, []() { return std::make_unique<llvm::SectionMemoryManager>(); }),
          compile_layer(*this->session, object_layer, std::make_unique<llvm::orc::ConcurrentIRCompiler>(std::move(builder))),
          main_jit_dylib(this->session->createBareJITDylib("<main>"))
    {
        main_jit_dylib.addGenerator(cantFail(llvm::orc::DynamicLibrarySearchGenerator::GetForCurrentProcess(data_layout.getGlobalPrefix())));
    }

    ~test_jit()
    {
        if (auto Err = session->endSession())
        {
            session->reportError(std::move(Err));
        }
    }

    static auto create() -> llvm::Expected<std::unique_ptr<test_jit>>
    {
        auto control = llvm::orc::SelfExecutorProcessControl::Create();

        if (!control)
        {
            return control.takeError();
        }

        auto session = std::make_unique<llvm::orc::ExecutionSession>(std::move(*control));

        llvm::orc::JITTargetMachineBuilder builder(session->getExecutorProcessControl().getTargetTriple());

        auto dylib = builder.getDefaultDataLayoutForTarget();
        if (!dylib)
        {
            return dylib.takeError();
        }

        return std::make_unique<test_jit>(std::move(session), std::move(builder), std::move(*dylib));
    }

    auto get_data_layout() const -> const llvm::DataLayout& { return data_layout; }

    auto get_main_jit_dylib() -> llvm::orc::JITDylib& { return main_jit_dylib; }

    auto add_module(llvm::orc::ThreadSafeModule module, llvm::orc::ResourceTrackerSP resource_tracker = nullptr) -> llvm::Error
    {
        if (!resource_tracker)
        {
            resource_tracker = main_jit_dylib.getDefaultResourceTracker();
        }
        return compile_layer.add(resource_tracker, std::move(module));
    }

    auto lookup(llvm::StringRef name) -> llvm::Expected<llvm::JITEvaluatedSymbol> { return session->lookup({&main_jit_dylib}, mangler(name.str())); }
};

