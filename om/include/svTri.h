#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svDeclBase.h>

using namespace std;

class svTri : public svDeclBase
{
    public:
        svTri(const string& pName = "");
        svTri(const svDeclBase&);

        virtual ~svTri() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
