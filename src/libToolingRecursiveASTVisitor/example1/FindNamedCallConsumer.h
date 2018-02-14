
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/ASTContext.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include "FindNamedCallVisitor.h"

class cFindNamedCallConsumer : public clang::ASTConsumer
{
public:
    explicit cFindNamedCallConsumer(clang::ASTContext *Context, std::string fName) :
        Visitor(Context, fName){};

    virtual void HandleTranslationUnit(clang::ASTContext &Context);

private:
    cFindNamedCallVisitor Visitor;
};