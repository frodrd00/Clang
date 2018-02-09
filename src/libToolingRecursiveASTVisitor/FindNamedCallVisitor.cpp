

using namespace clang;
using namespace clang::tooling;

class FindNamedCallVisitor :
    public RecursiveASTVisitor<FindNamedCallVisitor>
{
public:
    explicit FindNamedCallVisitor(ASTContext *Context, std::string fName) :
        Context(Context), fName(fName)
    {}

    bool VisitCallExpr(CallExpr *CallExpression)
    {
        QualType q = CallExpression->getType();
        const Type *t = q.getTypePtrOrNull();

        if (t != NULL)
        {
            FunctionDecl *func = CallExpression->getDirectCallee();
            const std::string funcName = func->getNameInfo().getAsString();
            if (fName == funcName)
            {
                FullSourceLoc FullLocation =
                    Context->getFullLoc(CallExpression->getLocStart());
                if (FullLocation.isValid())
                    llvm::outs() << "Found call at "
                         << FullLocation.getSpellingLineNumber() << ":"
                         << FullLocation.getSpellingColumnNumber() << "\n";
            }
        }

        return true;
    }

private:
    ASTContext *Context;
    std::string fName;
};