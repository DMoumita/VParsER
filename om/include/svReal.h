#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svDeclBase.h>

using namespace std;

class svReal : public svDeclBase
{
    public:
        svReal(const string& pName = "");
        svReal(const svDeclBase&);

        virtual ~svReal() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
