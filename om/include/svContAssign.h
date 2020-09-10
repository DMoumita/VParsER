#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svExprBase.h>
#include <svAssignExpr.h>

using namespace std;

class svContAssign : public svExprBase
{
    public:
        svContAssign(svAssignExpr* expr);

        virtual ~svContAssign() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
