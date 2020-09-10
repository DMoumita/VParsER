#include <svSelectOp.h>

svSelectOp::svSelectOp(const string& v, svExprBase* b)
    : svExprBase(SELECT)
    , var_(v)
{
   setChild(b);
}

void svSelectOp::decompile(std::ostream& os) const
{
    const svExprBase::TChildList& ops = getSubExprs();

    os << var_;
    if(!ops.empty())
    {
       os << "[";
       ops[0]->decompile(os);
       os << "]";
    }
}
