#include <svBlockContext.h>

svBlockContext::svBlockContext(svBlockContext* p)
    : symTab_()
    , parentCtx_(p)
{ }

void svBlockContext::finalize(void)
{
    for(TSymTable::iterator it = symTab_.begin();
        it != symTab_.end(); ++it)
    {
         delete (it->second).getRef();
    }

    symTab_.clear();
}

void svBlockContext::stabAdd(svBase* b)
{
    symTab_[b->getName()] = b;
}

svBase* svBlockContext::stabFind(const string& s)
{
    // Searching ......
    TSymTable::iterator it = symTab_.find(s);

    // Found in the present context
    if(it != symTab_.end()) return (it->second).getRef();

    // FAILED in present context -> search in context above
    if(parentCtx_ != NULL) return parentCtx_->stabFind(s);

    // FAILED FINALLY !!!!
    return NULL;
}

const svBase* svBlockContext::stabFind(const string& s) const
{
    // Searching ......
    TSymTable::const_iterator it = symTab_.find(s);

    // Found in the present context
    if(it != symTab_.end()) return (it->second).getRef();

    // FAILED in present context -> search in context above
    if(parentCtx_ != NULL) return parentCtx_->stabFind(s);

    // FAILED FINALLY !!!!
    return NULL;
}
