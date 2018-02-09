#include "Myprinter.h"
#include <iostream>


void cMyPrinter::run(const clang::ast_matchers::MatchFinder::MatchResult &Result)
{
    clang::ASTContext *Context = Result.Context;
    if (const clang::CallExpr *E =
        Result.Nodes.getNodeAs<clang::CallExpr>("functions"))
    {
        clang::FullSourceLoc FullLocation = Context->getFullLoc(E->getLocStart());
        if (FullLocation.isValid())
        {
            llvm::outs() << "Found call at "
                         << FullLocation.getSpellingLineNumber() << ":"
                         << FullLocation.getSpellingColumnNumber() << "\n";
        }
    }
}

/*cMyPrinter::~cMyPrinter()
{
    std::cout << "Memoria liberada" << std::endl;
    delete Context;
    delete E;
}*/
