#include "cFindNamedCallAction.h"
#include "cFindNamedCallConsumer.h"

std::unique_ptr<clang::ASTConsumer> cFindNamedCallAction::CreateASTConsumer(
    clang::CompilerInstance &Compiler, llvm::StringRef InFile)
{
    const std::string fName = "doSomething";
    return std::unique_ptr<clang::ASTConsumer>(
        new cFindNamedCallConsumer(&Compiler.getASTContext(), fName));
}

