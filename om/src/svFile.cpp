#include <svTypes.h>
#include <svFile.h>

svFile::svFile(const std::string& s)
    : svBase(s, svBase::eNodeType::FILE)
    , svBlockContext()
    , _modList()
{
}

void svFile::add(svModule* m)
{
    if(!m) return;
    
    if(svBlockContext::stabFind(m->getName()) == NULL)
    {
        _modList.push_back(m->getName());
        svBlockContext::stabAdd(m);
    }
    else
    {
        SVLOG(SEM, ERR) << "Module " <<  m->getName()
	                << "\" already declared." << std::endl;
    }
}

void svFile::decompile(std::ostream& os) const
{
    string ln = "";

    os << "//# File = \"" << getName() << "\"" << std::endl;
    if(!_modList.empty())
    {
        for(vector<string>::const_iterator it = _modList.begin();
            it != _modList.end(); ++it)
        {
            const svModule* m = dynamic_cast<const svModule*>(stabFind(*it));
            os << ln;  ln = "\n";
            if(m) m->decompile(os);
        }
    }
}
