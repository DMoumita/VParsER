#include "svNonBlkAssignExpr.h"

svNonBlkAssignExpr::svNonBlkAssignExpr
    (svExprBase* lhs, svExprBase* rhs)
    : svExprBase(NONBLKASSIGN)
{
   setChild(lhs);
   setChild(rhs);
}

void svNonBlkAssignExpr::decompile(std::ostream& os) const
{
    getSubExprs()[0]->decompile(os);
    os << " <= ";
    getSubExprs()[1]->decompile(os);
    os << ';' << std::endl;
}
