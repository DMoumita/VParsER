#pragma once

#include <svExprBase.h>

class svExprVar : public svExprBase
{
    private:
        svExprVar()
            : svExprBase(VAR)
        { }

    public:
        svExprVar(const string& v)
            : svExprBase(v, VAR)
        { }

        virtual ~svExprVar() {};

        virtual void decompile(std::ostream& os = std::cout) const
        {
            os << getName();
        }
};

