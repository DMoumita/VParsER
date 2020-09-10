#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svExprBase.h>

using namespace std;

class svAssignExpr : public svExprBase
{
    public:
        svAssignExpr(svExprBase* lhs, svExprBase* rhs);

        virtual ~svAssignExpr() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
