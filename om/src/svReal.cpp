#include "svReal.h"

svReal::svReal(const std::string& s)
    : svDeclBase(s, REAL)
{ }

svReal::svReal(const svDeclBase& b)
    : svDeclBase(b)
{ 
    setDeclBaseType(REAL);
}

void svReal::decompile(std::ostream& os) const
{
    os << "real ";
    svDeclBase::decompile(os);
    os << ";" << std::endl;
}
