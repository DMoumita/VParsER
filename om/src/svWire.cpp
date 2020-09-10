#include "svWire.h"

svWire::svWire(const std::string& s)
    : svDeclBase(s, WIRE)
{ }

svWire::svWire(const svDeclBase& b)
    : svDeclBase(b)
{
    setDeclBaseType(WIRE);
}

void svWire::decompile(std::ostream& os) const
{
    os << "wire ";
    if((getPull() != UNDEF) || (getStrength() != UNDEF))
    {
        os << '(';
        os << ((getPull() == TRUE) ? "pull1" : "pull0");
        if(getPull() != UNDEF) os << ", ";
        os << ((getStrength() == TRUE) ? "strong1" : "strong0");
        os << ") ";
    }
    svDeclBase::decompile(os);
    os << ";" << std::endl;
}
