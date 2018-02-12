#include <clang/ASTMatchers/ASTMatchFinder.h>

class cMyPrinter :
    public clang::ast_matchers::MatchFinder::MatchCallback
{
	public:
    	virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &Result);
    	virtual ~cMyPrinter(){};
};
