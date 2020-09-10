#pragma once

#include <vector>
#include <svAssignExpr.h>

class svAssignCombo : public svExprBase
{
    private:
        svAssignCombo();

    public:
        svAssignCombo(svAssignExpr*);
        virtual ~svAssignCombo();

        svAssignCombo& append(svAssignExpr*);
        svAssignCombo& append(svAssignCombo&);

        virtual void decompile(std::ostream& os = std::cout) const;
};
