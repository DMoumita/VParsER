#include <svDeclRange.h>

svDeclRange::svDeclRange( svExprBase* l
                        , svExprBase* r)
    : lRange(l)
    , rRange(r)
{ }

void svDeclRange::decompile(std::ostream& os) const
{
    if((NULL == lRange) && (NULL == rRange)) return;

    os <<"[";
    if(lRange != NULL) lRange->decompile(os);
    if(rRange != NULL) 
    {
	if(lRange != NULL) os << ':';
        rRange->decompile(os);
    }
    os <<"]";
}
