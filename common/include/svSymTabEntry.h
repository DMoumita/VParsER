#pragma once

#include <svBase.h>

class svSymTabEntry
{
    public:
       svSymTabEntry(svBase* b = NULL)
          : ref_(b)
       { }

       virtual ~svSymTabEntry() {}

       const svBase::eNodeType getType(void) const
          { return ref_->getType(); }

       svBase* getRef(void) const { return ref_; }

    private:
       svBase*  ref_;
};
