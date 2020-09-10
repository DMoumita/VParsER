#pragma once

#include <svExprBase.h>

template <typename T>
class svExprNum : public svExprBase
{
    private:
        T         value_;

        svExprNum() { }

    public:
        svExprNum(const T& v)
            : svExprBase(CONST)
            , value_(v)
        { }

        virtual ~svExprNum() {}

        const T& getValue(void) const { return value_; }

        virtual const int toInt(void) const;

        virtual void decompile(std::ostream& os = std::cout) const
        { os << value_; }
};

template<>
svExprNum<int>::svExprNum(const int& v)
    : svExprBase(CONST)
    , value_(v)
{ }

template<>
svExprNum<float>::svExprNum(const float& v)
    : svExprBase(CONST)
    , value_(v)
{ }

template<>
svExprNum<string>::svExprNum(const string& v)
    : svExprBase(CONST)
    , value_(v)
{ }

template<>
const int svExprNum<int>::toInt(void) const
{
    return value_;
}

template<>
const int svExprNum<float>::toInt(void) const
{
    return (int)value_;
}

template<>
const int svExprNum<string>::toInt(void) const
{
    int v = 0;
    for(string::const_iterator it = value_.begin();
        it != value_.end(); ++it)
    {
        if ((*it >= '0') && (*it <= '9'))
        {
                v = (v * 10) + (*it - '0');
        }
        else break;
    }
    return v;
}
