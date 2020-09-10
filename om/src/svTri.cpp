#include "svTri.h"

svTri::svTri(const std::string& s)
    : svDeclBase(s, TRI)
{ }

svTri::svTri(const svDeclBase& b)
    : svDeclBase(b)
{ 
    setDeclBaseType(TRI);
}

void svTri::decompile(std::ostream& os) const
{
    os << "tri ";
    svDeclBase::decompile(os);
    os << ";" << std::endl;
}
