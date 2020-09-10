#pragma once

// System Headers
#include <iostream>

#include <svExprBase.h>

class svDeclRange
{
    private:
        svExprBase* lRange;
        svExprBase* rRange;

    public:
        svDeclRange( svExprBase* l=NULL
                   , svExprBase* r=NULL);

        virtual ~svDeclRange() { }

        inline const svExprBase* getLrange() const
            { return lRange; }

        inline svExprBase* getLrange() { return lRange; }

        inline const svExprBase* getRrange() const
            { return rRange; }

        inline svExprBase* getRrange() { return rRange; }

        virtual void decompile(std::ostream& os = std::cout) const;
};
