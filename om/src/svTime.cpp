#include "svTime.h"

svTime::svTime(const std::string& s)
    : svDeclBase(s, TIME)
{ }

svTime::svTime(const svDeclBase& b)
    : svDeclBase(b)
{ 
    setDeclBaseType(TIME);
}

void svTime::decompile(std::ostream& os) const
{
    os << "time ";
    svDeclBase::decompile(os);
    os << ";" << std::endl;
}
