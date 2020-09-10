#include <svExprConst.h>

svExprConst::svExprConst(const string& n, svExprBase* v)
    : svExprBase(n, CONST)
{
    setChild(v);
}

void svExprConst::decompile(std::ostream& os) const
{
    const svExprBase::TChildList& l = getSubExprs();

    if((!l.empty()) && (l[0]->getExprType() == CONST))
    {
        os << "parameter " << getName() << " = ";
        l[0]->decompile(os);
        os << ";" << std::endl;
    }
}
