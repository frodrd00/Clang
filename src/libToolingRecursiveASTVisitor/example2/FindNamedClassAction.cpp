#include <clang/Frontend/CompilerInstance.h>
#include "FindNamedClassAction.h"
#include "FindNamedClassConsumer.h"


std::unique_ptr<clang::ASTConsumer> cFindNamedClassAction::CreateASTConsumer(
    clang::CompilerInstance &Compiler, llvm::StringRef InFile)
{
	 return std::unique_ptr<clang::ASTConsumer>(
	        new cFindNamedClassConsumer(&Compiler.getASTContext()));
}

