#include <svBase.h>

svBase::svBase(const string& s, const eNodeType t)
    : _type(t)
    , _name(s)
{ }

svBase::svBase(const eNodeType t)
    : _type(t)
    , _name("")
{ }
