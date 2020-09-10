#pragma once

#include <svExprBase.h>

class svMinTypMax : public svExprBase
{
    private:
        svExprBase* val1_;
        svExprBase* val2_;
        svExprBase* val3_;

    public:
        svMinTypMax(svExprBase*, svExprBase*, svExprBase*);

        virtual ~svMinTypMax() {};

        virtual void decompile(std::ostream& os = std::cout) const;
};

