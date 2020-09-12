#pragma once

// System Headers
#include <iostream>

#include <svExprBase.h>
#include <svTypes.h>

class svRangeExpr : public svExprBase
{
    private:
        svExprBase* lRange;
        svExprBase* rRange;
	rangeExprType rType;

    public:
        svRangeExpr( svExprBase* l=NULL , svExprBase* r=NULL, const rangeExprType rT=NOTSET);

        virtual ~svRangeExpr() { }

        inline const svExprBase* getLrange() const
            { return lRange; }

        inline svExprBase* getLrange() { return lRange; }

        inline const svExprBase* getRrange() const
            { return rRange; }

        inline svExprBase* getRrange() { return rRange; }

        virtual void decompile(std::ostream& os = std::cout) const;
};
