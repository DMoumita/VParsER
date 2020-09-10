#include "svAssignExpr.h"

svAssignExpr::svAssignExpr
    (svExprBase* lhs, svExprBase* rhs)
    : svExprBase(ASSIGN)
{
   setChild(lhs);
   setChild(rhs);
}

void svAssignExpr::decompile(std::ostream& os) const
{
    //os << "assign ";
    getSubExprs()[0]->decompile(os);
    os << " = ";
    getSubExprs()[1]->decompile(os);
    os << ';' << std::endl;
}
