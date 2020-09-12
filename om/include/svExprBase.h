#pragma once

// System Headers
#include <iostream>
#include <vector>

// OM Headers
#include <svBase.h>

using namespace std;


class svExprBase : public svBase
{
    public:
       enum eExprType {UNDEF, VAR, CONST, SELECT, COMBO, ASSIGN, INSTANCE, OP, CONTASSIGN, NONBLKASSIGN, MINTYPMAX, RANGEEXPR};
       typedef std::vector<svExprBase*> TChildList;

    private:
       eExprType    exprType_;
       TChildList   operand_;

    protected:
        void clearChild(void) { operand_.clear(); }

    public:
        svExprBase(const eExprType);
        svExprBase(const string&, const eExprType);

        virtual ~svExprBase();

        void setChild(svExprBase* c)
        { if(c!=NULL) operand_.push_back(c); }

        const eExprType getExprType(void) const
        { return exprType_; }

        const TChildList& getSubExprs(void) const { return operand_; }
        TChildList& getSubExprs(void)             { return operand_; }

        virtual const int toInt(void) const { return 0; }

        virtual void decompile(std::ostream& os = std::cout) const;
};
