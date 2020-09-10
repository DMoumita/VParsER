#include "svAssignExpr.h"
#include "svContAssign.h"

svContAssign::svContAssign
    (svAssignExpr* expr)
    : svExprBase(CONTASSIGN)
{
   setChild(expr);
}

void svContAssign::decompile(std::ostream& os) const
{
    os << "assign ";
    getSubExprs()[0]->decompile(os);
}
