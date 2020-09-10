#pragma once

#include <vector>
#include <svBlockContext.h>
#include <svBlock.h>
#include <svExprBase.h>

class svSensitivity
{
    public:
        enum eSensType { NONE, POSEDGE, NEGEDGE, ALL };

    private:
        eSensType   type_;
        std::string name_;

    public:
        svSensitivity(const eSensType t, const std::string& n= "")
           : type_(t)
           , name_(n)
        { }

        inline const std::string& getName(void) const { return name_; }
        inline const eSensType    getType(void) const { return type_; }

        void decompile(std::ostream& os = std::cout) const
	{
	    switch (getType())
	    {
		case POSEDGE: os << "posedge "; break;
		case NEGEDGE: os << "negedge "; break;
		case ALL: os << "*"; break;
		default: break;
	    }
	    os << getName();
	}
};

class svAlways : public svBase
{
    public:
       typedef std::vector<svSensitivity> TSensList;

    private:
       TSensList sensList_;
       svBase* stmtOrBlock_;

    public:
        svAlways();
        svAlways(const TSensList&);

        virtual ~svAlways() { }

        const TSensList& getSensList(void) const { return sensList_; }
        const svBase* getStmtOrBlock(void) const { return stmtOrBlock_; }
        void setStmtOrBlock(svBase* stmt) { stmtOrBlock_ = stmt; }

        virtual void decompile(std::ostream& os = std::cout) const;
};
