#include <clang/AST/RecursiveASTVisitor.h>

/**
 * El siguiente paso es implementar RecursiveASTVisitor para extraer
 * información relevante del AST. El RecursiveASTVisitor provee acceso
 * mediante bool VisitNodeType(NodeType *) para la mayoría de los nodos del AST;
 * las excepciones son los nodos TypeLoc que se pasan por valor. Se va a implementar
 * los métodos para los tipos de nodos más relevantes.
 */
class cFindNamedClassVisitor
  : public clang::RecursiveASTVisitor<cFindNamedClassVisitor> {

	public:
	  explicit cFindNamedClassVisitor(clang::ASTContext *Context) : Context(Context) {}

	  bool VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration) {
		if (Declaration->getQualifiedNameAsString() == "n::m::C") {
		  clang::FullSourceLoc FullLocation = Context->getFullLoc(Declaration->getLocStart());
		  if (FullLocation.isValid())
			llvm::outs() << "Found declaration at "
						 << FullLocation.getSpellingLineNumber() << ":"
						 << FullLocation.getSpellingColumnNumber() << "\n";
		}
		return true;
	  }

	private:
	 clang::ASTContext *Context;
};
