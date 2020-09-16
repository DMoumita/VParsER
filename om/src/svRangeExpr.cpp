#include <svRangeExpr.h>

svRangeExpr::svRangeExpr( svExprBase* l , svExprBase* r, const rangeExprType rt)
    : svExprBase(RANGEEXPR)
    , lRange(l)
    , rRange(r)
    , rType(rt)
{ 
if ( rType == PLUSCOLON || rType == MINUSCOLON)
{
	if (rRange->getExprType() == CONST) {
	   if(rRange->toInt() == 0) {
               cout << "Error :: Line No : "<< gLineNo<<" , Col No : " <<gColNo<<" :: Width must be a postive integer !"<<std::endl;
	       exit(1);
           }
	}
}
}

void svRangeExpr::decompile(std::ostream& os) const
{
    if((NULL == lRange) && (NULL == rRange)) return;

    if(lRange != NULL) lRange->decompile(os);
    if(rRange != NULL) 
    {
	if(lRange != NULL) 
        {
	   switch (rType)
	   {
	      case ONLYCOLON :	  
		   os << ':';
		   break;
	      case PLUSCOLON :	  
		   os << "+:";
		   break;
	      case MINUSCOLON :	  
		   os << "-:";
		   break;
	      default :
		   break;
	   }
	 }
        rRange->decompile(os);
    }
}
