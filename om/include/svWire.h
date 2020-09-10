#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svDeclBase.h>

using namespace std;


class svWire : public svDeclBase
{
    public:
        svWire(const string& pName = "");
        svWire(const svDeclBase& b);

        virtual ~svWire() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
