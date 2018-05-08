#include "FindNamedCallVisitor.h"

bool cFindNamedCallVisitor::VisitCallExpr(clang::CallExpr *CallExpression)
{
    clang::QualType q = CallExpression->getType();
    const clang::Type *t = q.getTypePtrOrNull();

    if (t != NULL)
    {
        clang::FunctionDecl *func = CallExpression->getDirectCallee();
        const std::string funcName = func->getNameInfo().getAsString();
        if (fName == funcName)
        {
            clang::FullSourceLoc FullLocation =
                Context->getFullLoc(CallExpression->getLocStart());

            const auto&  parents = Context->getParents(*func);

            if (FullLocation.isValid())
                llvm::outs() << "Found call at "
                     << FullLocation.getSpellingLineNumber() << ":"
                     << FullLocation.getSpellingColumnNumber() << "\n";
        }
    }

    return true;
}

