#include "svRoot.h"

svRoot::svRoot()
    : svBase(svBase::eNodeType::ROOT)
    , fileList_()
{
}

void svRoot::init(void)
{
    fileList_.clear();
}

void svRoot::finalize(void)
{
    for(TFileList::iterator it = fileList_.begin();
        it != fileList_.end(); ++it)
    {
        (*it).finalize();
    }
}

svModule* svRoot::find(const string& modName)
{
    svModule* mod =  NULL;

    if(!fileList_.empty())
    {
        for(TFileList::iterator it = fileList_.begin();
            it != fileList_.end(); ++it)
        {
            mod = dynamic_cast<svModule*>((*it).stabFind(modName));
            if(mod) break;
        }
    }

    return mod;
}

svFile& svRoot::add(const svFile& f)
{
    fileList_.push_back(f);
    return fileList_.back();
}

void svRoot::add(svModule* m)
{
    if(!fileList_.empty())
    {
        fileList_.back().add(m);
    }
}

void svRoot::decompile(std::ostream& os) const
{
    if(!fileList_.empty())
    {
         for(TFileList::const_iterator it = fileList_.begin();
             it != fileList_.end(); ++it)
         {
             (*it).decompile(os);
         }
    }
}
