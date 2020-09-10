#pragma once

#include <map>
#include <svExprBase.h>

class svSelectOp : public svExprBase
{
    private:
       string var_;

    public:
        svSelectOp(const string& v, svExprBase* b = NULL);
        virtual ~svSelectOp() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
