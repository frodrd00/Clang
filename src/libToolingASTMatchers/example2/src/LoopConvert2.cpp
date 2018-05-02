// Declares clang::SyntaxOnlyAction.
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/AST/ASTContext.h"

using namespace clang::tooling;
using namespace clang::ast_matchers;
using namespace llvm;
using namespace clang;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static llvm::cl::OptionCategory MyToolCategory("my-tool options");

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
static cl::extrahelp MoreHelp("\nMore help text...\n");

//Matcher
StatementMatcher loopMatcher =
    forStmt(hasLoopInit(declStmt(
                hasSingleDecl(varDecl(hasInitializer(integerLiteral(equals(0))))
                                  .bind("initVarName")))),
            hasIncrement(unaryOperator(
                hasOperatorName("++"),
                hasUnaryOperand(declRefExpr(
                    to(varDecl(hasType(isInteger())).bind("incVarName")))))),
            hasCondition(binaryOperator(
                hasOperatorName("<"),
                hasLHS(ignoringParenImpCasts(declRefExpr(
                    to(varDecl(hasType(isInteger())).bind("condVarName"))))),
                hasRHS(integerLiteral(equals(20)))))).bind("forLoop");

static bool areSameVariable(const ValueDecl *First, const ValueDecl *Second) {
  return First && Second &&
         First->getCanonicalDecl() == Second->getCanonicalDecl();
}

class LoopPrinter : public MatchFinder::MatchCallback {
public:
	virtual void run(const MatchFinder::MatchResult &Result) {
		  ASTContext *Context = Result.Context;
		  const ForStmt *FS = Result.Nodes.getNodeAs<ForStmt>("forLoop");
		  // We do not want to convert header files!
		  if (!FS || !Context->getSourceManager().isWrittenInMainFile(FS->getForLoc()))
		    return;
		  const VarDecl *IncVar = Result.Nodes.getNodeAs<VarDecl>("incVarName");
		  const VarDecl *CondVar = Result.Nodes.getNodeAs<VarDecl>("condVarName");
		  const VarDecl *InitVar = Result.Nodes.getNodeAs<VarDecl>("initVarName");

		  if (!areSameVariable(IncVar, CondVar) || !areSameVariable(IncVar, InitVar))
		    return;
		  llvm::outs() << "Potential array-based loop discovered.\n";
		}
};


int main(int argc, const char **argv) {
  CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
  ClangTool tool(OptionsParser.getCompilations(),
                 OptionsParser.getSourcePathList());

  LoopPrinter printer;
  MatchFinder finder;
  finder.addMatcher(loopMatcher, &printer);

  return tool.run(newFrontendActionFactory(&finder).get());
}
