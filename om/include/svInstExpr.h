#pragma once

// System Headers
#include <iostream>
#include <vector>

// OM Headers
#include <svModule.h>
#include <svExprVar.h>

using namespace std;

class svInstExpr : public svExprBase
{
    private:
        vector<svBase*> paramList_;
        vector<svBase*> portList_;

    public:
        svInstExpr( const string& className
                  , svExprVar*    instname);

        virtual ~svInstExpr() {}

        void setPortParamMap(svBase* actParam, svBase* port);

        inline const svExprBase* getInstance(void) const;
        inline svExprBase* getInstance(void);

        inline const string& getClassName(void) const { return getName(); }
        inline string& getClassName(void)             { return getName(); }

        virtual void decompile(std::ostream& os = std::cout) const;
};
