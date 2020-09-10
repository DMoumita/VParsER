#pragma once

#include <vector>
#include <svBlockContext.h>
#include <svExprBase.h>

class svBlock : public svBase
              , public svBlockContext
{
    private:
        typedef std::vector<const svBase*> TbaseList;

    private:
        TbaseList stmtList_;

    public:
        svBlock();
        svBlock(const svBase&);

        virtual ~svBlock() { }

        void add(const svBase* e)
            { stmtList_.push_back(e); }

        void add(const std::vector<svBase*>& l)
            { stmtList_.insert(stmtList_.end(), l.begin(), l.end()); }

        const TbaseList& getList(void) const { return stmtList_; }

        virtual void decompile(std::ostream& os = std::cout) const;
};
