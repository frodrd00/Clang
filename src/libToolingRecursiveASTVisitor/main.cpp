#include "cFindNamedCallConsumer.h"
#include "cFindNamedCallAction.h"
#include <clang/Tooling/Tooling.h>
#include <clang/Tooling/CommonOptionsParser.h>

static llvm::cl::OptionCategory MyToolCategory("my-tool options");

int main(int argc, const char **argv)
{
    const std::string fName = "doSomething";

    clang::tooling::CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
    OptionsParser.getSourcePathList());

    // run the Clang Tool, creating a new FrontendAction (explained below)
    int result =
        Tool.run(clang::tooling::newFrontendActionFactory<cFindNamedCallAction>().get());
    return result;
}