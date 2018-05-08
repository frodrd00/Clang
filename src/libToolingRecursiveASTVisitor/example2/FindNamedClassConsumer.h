#include <clang/AST/ASTConsumer.h>
//#include <clang/AST/ASTContext.h>
#include "FindNamedClassVisitor.h"

/**
 * Es una interfaz usada para implementar
 * acciones genéricas en AST, sin importar como AST fue creado.
 * Provee diferentes maneras de puntos de entrada, para este caso
 * solo necesitamos HandleTranslationUnit, que es llamado por ASTContext por la unidad de traducción.
 */
class cFindNamedClassConsumer : public clang::ASTConsumer {

	public:
	 explicit cFindNamedClassConsumer(clang::ASTContext *Context)
	    : Visitor(Context) {}

		virtual void HandleTranslationUnit(clang::ASTContext &Context);

	private:
	  // A RecursiveASTVisitor implementation.
	  cFindNamedClassVisitor Visitor;
};
