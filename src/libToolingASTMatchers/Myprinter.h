#include "clang/ASTMatchers/ASTMatchFinder.h"

class MyPrinter : public MatchFinder::MatchCallback
{
public:
    virtual void run(const MatchFinder::MatchResult);
    
};