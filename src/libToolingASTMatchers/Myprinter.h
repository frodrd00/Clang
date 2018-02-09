#include <clang/ASTMatchers/ASTMatchFinder.h>

class cMyPrinter :
    public clang::ast_matchers::MatchFinder::MatchCallback
{
	public:
    	void run(const clang::ast_matchers::MatchFinder::MatchResult&);
    	//virtual ~cMyPrinter();

};