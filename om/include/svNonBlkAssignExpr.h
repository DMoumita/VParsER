#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svExprBase.h>

using namespace std;

class svNonBlkAssignExpr : public svExprBase
{
    public:
        svNonBlkAssignExpr(svExprBase* lhs, svExprBase* rhs);

        virtual ~svNonBlkAssignExpr() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
