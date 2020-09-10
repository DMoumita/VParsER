#pragma once

#include <map>
#include <svSymTabEntry.h>

class svBase;

class svBlockContext
{
    public:
        typedef std::map<string, svSymTabEntry> TSymTable;

    private:
        TSymTable        symTab_;
        svBlockContext*  parentCtx_;

    private:
        inline void clean(void) { symTab_.clear(); }

    public:
        svBlockContext(svBlockContext* p = NULL);

        virtual ~svBlockContext() { }

        void finalize(void);

        void stabAdd(svBase*);
        svBase* stabFind(const string&);
        const svBase* stabFind(const string&) const;
};
