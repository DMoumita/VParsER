#include "svInstExpr.h"

svInstExpr::svInstExpr( const string& className
                      , svExprVar*    rhs)
    : svExprBase(className, INSTANCE)
    , paramList_()
    , portList_()
{
    setChild(rhs);
}

svExprBase* svInstExpr::getInstance(void)
{
    if(getSubExprs().empty()) return NULL;
    return getSubExprs()[0];
}

const svExprBase* svInstExpr::getInstance(void) const
{
    if(getSubExprs().empty()) return NULL;
    return getSubExprs()[0];
}

void svInstExpr::setPortParamMap(svBase* actParam, svBase* port)
{
    paramList_.push_back(actParam);
    portList_.push_back(port);
}

void svInstExpr::decompile(std::ostream& os) const
{
    getInstance()->decompile(os);
    os << ' ' << getName() << '(';

    vector<svBase*>::const_iterator paramIt = paramList_.begin();
    vector<svBase*>::const_iterator portIt  = portList_.begin();

    if((paramIt != paramList_.end()) && (portIt != portList_.end()))
    {
        if((*portIt) != NULL)
        {
            os << '.';
            (*paramIt)->decompile(os);
            os << '(' << (*portIt) << ")";
        }
        else  (*paramIt)->decompile(os);
    }

    for(++paramIt, ++portIt; (paramIt != paramList_.end()) && (portIt != portList_.end());
        ++paramIt, ++portIt)
    {
        os << ", ";
        if((*portIt) != NULL)
        {
            os << '.';
            (*paramIt)->decompile(os);
            os << '(' << (*portIt) << ")";
        }
        else  (*paramIt)->decompile(os);
    }
    os << ')' << ";" << std::endl;
}
