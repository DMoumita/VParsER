#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svDeclBase.h>

using namespace std;

class svReg : public svDeclBase
{
    public:
	bool isSigned_ = false;
        svReg(const string& pName = "");
        svReg(const svDeclBase&);

        virtual ~svReg() {}

        virtual void decompile(std::ostream& os = std::cout) const;
	bool getIsSigned() { return isSigned_; }
	void setIsSigned (bool b) { isSigned_ = b; }
};
