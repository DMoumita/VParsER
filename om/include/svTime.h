#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svDeclBase.h>

using namespace std;

class svTime : public svDeclBase
{
    public:
        svTime(const string& pName = "");
        svTime(const svDeclBase&);

        virtual ~svTime() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
