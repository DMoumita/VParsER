#include <svExprBase.h>

svExprBase::svExprBase(const eExprType e)
    : svBase(svBase::eNodeType::EXPR)
    , exprType_(e)
    , operand_()
{ }

svExprBase::svExprBase(const string& n, const eExprType e)
    : svBase(n, svBase::eNodeType::EXPR)
    , exprType_(e)
    , operand_()
{ }

svExprBase::~svExprBase()
{
   for(TChildList::iterator it = operand_.begin();
       it != operand_.end(); ++it)
   {
        if(*it) delete *it;
   }
}

void svExprBase::decompile(std::ostream& os) const
{
    for(TChildList::const_iterator it = operand_.begin();
          it != operand_.end(); ++it)
    {
        if(*it) (*it)->decompile();
    }
}
