#pragma once

#include <map>
#include <svExprBase.h>

class svExprOp : public svExprBase
{
    public:
       enum eExprOpType { CONDITIONAL,
                          LAND, LOR,
                          BAND, BOR,   BXOR, BXNOR, RNOR,
                          LT,   LE,    GT,   GE,    EQUAL, NOT_EQ, EQ_CASE, NOT_EQ_CASE,
                          PLUS, MINUS, SR,   SL,
                          MULT, DIV,   MOD,  BNOT,  LNOT
                        };

    private:
       eExprOpType opType_;

       typedef std::map<eExprOpType, std::string> tOpMap;
       static tOpMap opMap_;

    public:
        svExprOp(const eExprOpType);
        virtual ~svExprOp() {}

        virtual void decompile(std::ostream& os = std::cout) const;
};
