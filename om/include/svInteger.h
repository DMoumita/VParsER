#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svDeclBase.h>

using namespace std;

class svInteger : public svDeclBase
{
    public:
        svInteger(const string& pName = "");
        svInteger(const svDeclBase&);

        virtual ~svInteger() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
