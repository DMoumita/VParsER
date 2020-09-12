#pragma once

#include <map>
#include <svDeclBase.h>
#include <svTypes.h>

class svNet : public svDeclBase
{
    private:
       typedef std::map<eNetType, std::string> tOpMap;
       typedef std::map<svDriveStrengthType, std::string> tdriveMap;
       static tOpMap opMap_;
       static tdriveMap driveStrengthMap_;
       svDriveStrengthType _strengthItem0 ;
       svDriveStrengthType _strengthItem1;
       bool isVector_;
       bool isScalar_;
       svDeclRange* range_;    
       vector<svExprBase*>  _delayList;

    public:
       eNetType netType_ ;
       bool isSigned_;
    public:
        svNet(const svDeclBase& b,const eNetType e = UNDEFINE);
        virtual ~svNet() {}
	void setStrength0(svDriveStrengthType s1){_strengthItem0 = s1;};
	void setStrength1(svDriveStrengthType s2){_strengthItem1 = s2;};
	bool getIsSigned() { return isSigned_; }                                                                               void setIsSigned (bool b) { isSigned_ = b; } 
	bool getIsVector() { return isVector_; }  
	bool getIsScalar() { return isScalar_; }  
	void setIsVector (bool b) { isVector_ = b; } 
	void setIsScalar (bool b) { isScalar_ = b; } 
	eNetType getNetType(){return netType_;}
        svDeclRange* getRange(void) const     { return range_;    }     
	void setRange(svDeclRange* r)         { range_ = r;         } 
	void add(svExprBase* p) { _delayList.push_back(p); } 
        virtual void decompile(std::ostream& os = std::cout) const;

};
