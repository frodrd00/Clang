
#include "cFindNamedCallConsumer.h"


void cFindNamedCallConsumer::HandleTranslationUnit(clang::ASTContext &Context)
{
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
}

