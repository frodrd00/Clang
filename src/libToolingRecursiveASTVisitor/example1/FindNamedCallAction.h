#include <clang/AST/ASTConsumer.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Frontend/CompilerInstance.h>

class cFindNamedCallAction :
    public clang::ASTFrontendAction
{
public:

    virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
        clang::CompilerInstance &Compiler, llvm::StringRef InFile);

};