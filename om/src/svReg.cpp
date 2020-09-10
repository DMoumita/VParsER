#include "svReg.h"

svReg::svReg(const std::string& s)
    : svDeclBase(s, REG)
{ }

svReg::svReg(const svDeclBase& b)
    : svDeclBase(b)
{ 
    setDeclBaseType(REG);
}

void svReg::decompile(std::ostream& os) const
{
    os << "reg ";
    if (isSigned_ == true)
       os << "signed ";
    svDeclBase::decompile(os);
//    const svExprBase* e = getInit();
//    if(e != NULL)
 //   {
  //     os << " = ";
   //    e->decompile(os);
    //}
    os << ";" << std::endl;
}
