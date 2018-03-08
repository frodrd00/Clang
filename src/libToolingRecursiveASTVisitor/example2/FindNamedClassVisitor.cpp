#include "FindNamedClassVisitor.h"

bool cFindNamedClassVisitor::VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration)
{
	if (Declaration->getQualifiedNameAsString() == "n::m::C") {
	  clang::FullSourceLoc FullLocation = Context->getFullLoc(Declaration->getLocStart());
	  if (FullLocation.isValid())
		llvm::outs() << "Found declaration at "
					 << FullLocation.getSpellingLineNumber() << ":"
					 << FullLocation.getSpellingColumnNumber() << "\n";
	}
	return true;
}
