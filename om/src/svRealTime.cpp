#include "svRealTime.h"

svRealTime::svRealTime(const std::string& s)
    : svDeclBase(s, REALTIME)
{ }

svRealTime::svRealTime(const svDeclBase& b)
    : svDeclBase(b)
{ 
    setDeclBaseType(REALTIME);
}

void svRealTime::decompile(std::ostream& os) const
{
    os << "realtime ";
    svDeclBase::decompile(os);
    os << ";" << std::endl;
}
