#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svDeclBase.h>

using namespace std;

class svRealTime : public svDeclBase
{
    public:
        svRealTime(const string& pName = "");
        svRealTime(const svDeclBase&);

        virtual ~svRealTime() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
