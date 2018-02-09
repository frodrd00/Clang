class FindNamedCallVisitor :
    public RecursiveASTVisitor<FindNamedCallVisitor>
{
public:
    explicit FindNamedCallVisitor(ASTContext *, std::string)

    bool VisitCallExpr(CallExpr *CallExpression)

private:
    ASTContext *Context;
    std::string fName;
};