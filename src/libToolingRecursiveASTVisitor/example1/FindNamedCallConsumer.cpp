
#include "FindNamedCallConsumer.h"


void cFindNamedCallConsumer::HandleTranslationUnit(clang::ASTContext &Context)
{
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
}

