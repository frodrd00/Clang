#include "FindNamedClassConsumer.h"

void cFindNamedClassConsumer::HandleTranslationUnit(clang::ASTContext &Context)
{
    // Traversing the translation unit decl via a RecursiveASTVisitor
    // will visit all nodes in the AST.
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
}
