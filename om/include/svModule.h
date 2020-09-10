#pragma once

// System Headers
#include <iostream>
#include <vector>

// OM Headers
#include <svBlockContext.h>
#include <svDeclBase.h>
#include <svExprBase.h>
#include <svAlways.h>

using namespace std;

class svModule : public svBlockContext
               , public svBase
{
    private:
        vector<string>       _portList;
        vector<string>       _netList;
        vector<string>       _regList;
        vector<svExprBase*>  _assignList;
        vector<svAlways*>  _alwaysStmtList;
        vector<string>       _intVarList;
        vector<string>       _realVarList;
        vector<string>       _realTimeVarList;
        vector<string>       _timeVarList;

    public:
        svModule(const std::string& name="", svBlockContext* p = NULL);

        virtual ~svModule();

        void add(svDeclBase*);
        void add(svExprBase* p) { _assignList.push_back(p); }
        void add(svAlways* p) { _alwaysStmtList.push_back(p); }

        virtual void decompile(std::ostream& os = std::cout) const;
};
