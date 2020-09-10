#include <svMinTypMax.h>

svMinTypMax::svMinTypMax(svExprBase* v1, svExprBase* v2, svExprBase* v3)
    : svExprBase(MINTYPMAX)
{
    setChild(v1);
    setChild(v2);
    setChild(v3);
}

void svMinTypMax::decompile(std::ostream& os) const
{
    const svExprBase::TChildList& l = getSubExprs();

    if(!l.empty())
    {
	os << '(';
        l[0]->decompile(os);
	if (l.size() >2) {
	   os << ':';
           l[1]->decompile(os);
	   os << ':';
           l[2]->decompile(os);
	 }
        os << ")";
    }
}
