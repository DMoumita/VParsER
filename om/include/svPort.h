#pragma once

// System Headers
#include<map>
#include <iostream>

// OM Headers
#include <svDeclBase.h>
#include <svWire.h>
#include <svTypes.h>

using namespace std;

class svPort : public svDeclBase
{
    public:
        enum ePortDirection { UNDEF, INPUT, INOUT, OUTPUT };

    private:
        ePortDirection        direction_ = UNDEF;
	typedef std::map<ePortType, std::string> tOpMap;
	static tOpMap opMap_; 
	ePortType portType_  = UNDEFINE_PORT;
	bool isSigned_;
	svDeclRange* range_;

    public:
        svPort(const string& pName = "", const ePortDirection = UNDEF);
	svPort(const svDeclBase&, const ePortType e = UNDEFINE_PORT);

        virtual ~svPort() {}

       virtual bool update(const svBase*);

        //inline const svDeclBase::EDeclType getType(void) const
        //    { return portType_;      }
        inline const ePortDirection getDirection(void)   const
            { return direction_; }
        inline void  setDirection(const ePortDirection d)
            { direction_ = d; }
	void setRange(svDeclRange* r)         { range_ = r; }
	svDeclRange* getRange(void) const     { return range_;    }
	bool getIsSigned() { return isSigned_; }      
	void setIsSigned (bool b) { isSigned_ = b; } 
	void setPortType (ePortType b) { portType_ = b; } 

        void portDecompile(std::ostream& os = std::cout) const;
//        virtual void decompile(std::ostream& os = std::cout) const;
};
