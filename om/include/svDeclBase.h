#pragma once

// System Headers
#include <iostream>

// OM Headers
#include <svTypes.h>
#include <svDeclRange.h>
#include <svExprBase.h>

using namespace std;

class svDeclBase : public svBase
{
    public:
        enum EDeclType { NONE, PORT, NET, REG, TRI, INTEGER, REAL, TIME, REALTIME };

    private:
        EDeclType    declType_ = NONE;
        svDeclRange* range_;
        svDeclRange* dim_;
        svExprBase*  init_     = NULL;
        //quad         pull_     = UNDEF;
        //quad         strength_ = UNDEF;

    protected:
        void setDeclBaseType(const EDeclType t)
        { declType_ = t; }

    public:
        svDeclBase(const string&, const EDeclType=NONE);

        virtual ~svDeclBase() {}

        const EDeclType getDeclType(void) const { return declType_; }


        //inline const int getSize(void) const                   
        //   { return abs(getRange()->getRrange()->toInt()
         //                 - getRange()->getLrange()->toInt()) + 1; }

        svDeclRange* getRange(void) const     { return range_;    }
        svDeclRange* getDim(void) const     { return dim_;    }
        //const quad getPull(void) const        { return pull_;       }
        //const quad getStrength(void) const    { return strength_;   }
        const svExprBase* getInit(void) const { return init_;       }

        void setRange(svDeclRange* r)         { range_ = r;         }
        void setDim(svDeclRange* r)         { dim_ = r;         }
        void setInit(svExprBase* e)           { init_ = e;          }
        //void setPull(const quad v)            { pull_ = v;          }
        //void setStrength(const quad v)        { strength_ = v;      }

        virtual bool update(const svDeclBase*);

        virtual void decompile(std::ostream& os = std::cout) const;
};
