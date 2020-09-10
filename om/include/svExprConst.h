#pragma once

#include <svExprBase.h>

class svExprConst : public svExprBase
{
    private:
        svExprBase* val_;

    public:
        svExprConst(const string&, svExprBase*);

        virtual ~svExprConst() {};

        virtual void decompile(std::ostream& os = std::cout) const;
};

