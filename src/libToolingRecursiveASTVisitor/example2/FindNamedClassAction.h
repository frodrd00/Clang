#include <clang/Frontend/FrontendAction.h>

/**
 * Es una interfaz para permitir la ejecución de unas acciones
 * especificas de usuario como parte de la compilación.
 * Para ejecutar herramientas bajo AST, clang provee la interfaz ASTFrontedAction,
 * que es encargada de ejecutar las acciones. El siguiente paso es implementar el
 * método CreateASTConsumer que retorna ASTConsumer.
 */
class cFindNamedClassAction : public clang::ASTFrontendAction {

public:
  virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
    clang::CompilerInstance &Compiler, llvm::StringRef InFile);
};
