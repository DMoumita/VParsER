#include "svInteger.h"

svInteger::svInteger(const std::string& s)
    : svDeclBase(s, INTEGER)
{ }

svInteger::svInteger(const svDeclBase& b)
    : svDeclBase(b)
{ 
    setDeclBaseType(INTEGER);
}

void svInteger::decompile(std::ostream& os) const
{
    os << "integer ";
    svDeclBase::decompile(os);
    os << ";" << std::endl;
}
