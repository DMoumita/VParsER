#pragma once

#include <svExprVar.h>

class svExprVarConcat : public svExprBase
{
    private:
        vector<svExprVar*> varList_;

        svExprVarConcat()
            : svExprBase(VAR)
            , varList_()
        { }

    public:
        svExprVarConcat(svExprVar* v)
            : svExprBase(VAR)
            , varList_()
        { varList_.push_back(v); }

        virtual ~svExprVarConcat() {}

        void append(svExprVar* v)
        { varList_.push_back(v); }

        virtual void decompile(std::ostream& os = std::cout) const
        {
            const int sz = varList_.size();
            if(sz == 1)
            {
                varList_[0]->decompile(os);
            }
            else if(sz > 1)
            {
                os << '{';
                bool comma = false;
                for(vector<svExprVar*>::const_iterator it = varList_.begin();
                    it != varList_.end(); ++it)
                {
                    if(comma) os << ", ";
                    (*it)->decompile(os);
                    comma =  true;
                }
                os << '}';
            }
        }
};
