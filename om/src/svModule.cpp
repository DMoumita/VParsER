#include <svModule.h>
#include <string.h>
#include <svPort.h>
#include <svNet.h>
#include <singleton.h>
#include <svTypes.h>
#include <svAlways.h>

svModule::svModule(const std::string& s, svBlockContext* p)
    : svBlockContext(p)
    , svBase(s, svBase::eNodeType::MODULE)
    , _portList()
    , _netList()
    , _regList()
    , _assignList()
    , _intVarList()
{
}

svModule::~svModule()
{
    svBlockContext::finalize();
}

void svModule::add(svDeclBase* p)
{
    const svDeclBase::EDeclType t = p->getDeclType();
    const string& name = p->getName();

    svBase* ref = stabFind(name);

    if(ref == NULL)
    {
        svBlockContext::stabAdd(p);
    }
    else
    {
        if(!ref->update(p))
        {
            SVLOG(SEM, ERR) << "\"" << name << "\" already declared." << std::endl;
        }
    }

    switch(t)
    {
        case svDeclBase::EDeclType::PORT:
            if(ref == NULL) {
		    _portList.push_back(name);
	    }
            else
            {
                svDeclBase* dRef = dynamic_cast<svDeclBase*>(ref);
                if((NULL != dRef) && (dRef->getDeclType() == svDeclBase::EDeclType::PORT))
                       dRef->update(p);
            }
            break;

        case svDeclBase::EDeclType::NET:
	    if ( ref == NULL)
               _netList.push_back(name);
	    else {
		svDeclBase* dRef = dynamic_cast<svDeclBase*>(ref);
		if((NULL != dRef) && (dRef->getDeclType() == svDeclBase::EDeclType::NET))
			       dRef->update(p);
	    }
            break;

        case svDeclBase::EDeclType::INTEGER:
	    if ( ref == NULL)
               _intVarList.push_back(name);
	    break;
        case svDeclBase::EDeclType::REAL:
            _realVarList.push_back(name);
	    break;
        case svDeclBase::EDeclType::REALTIME:
            _realTimeVarList.push_back(name);
	    break;
        case svDeclBase::EDeclType::TIME:
	    if ( ref == NULL)
               _timeVarList.push_back(name);
	    break;
        case svDeclBase::EDeclType::REG:
        case svDeclBase::EDeclType::TRI:
	    if ( ref == NULL)
               _regList.push_back(name);
            break;

        default: break;
    }
}

void svModule::decompile(std::ostream& os) const
{
    const svBase* obj = NULL;

    os << "module " << getName();
    if(!_portList.empty())
    {
        os << "(";
        vector<string>::const_iterator it = _portList.begin();
        os << (*it);
        it++;
        while(it != _portList.end())
        {
            os << ", " << (*it);
            it++;
        }
        os << ")";
    }
    os << "; " << std::endl;

    for(vector<svExprBase*>::const_iterator it = _assignList.begin();
        it != _assignList.end(); ++it)
    {
        if(svExprBase::eExprType::CONST == (*it)->getExprType())
            (*it)->decompile(os);
    }

    // Decompile ports
    for(vector<string>::const_iterator it = _portList.begin();
        it != _portList.end(); ++it)
    {
        if(NULL != (obj = stabFind(*it)))
        {
            const svPort* p = dynamic_cast<const svPort*>(obj);
            if(p != NULL) p->portDecompile(os);
        }
    }

    // Decompile NET
    for(vector<string>::const_iterator it = _netList.begin();
        it != _netList.end(); ++it)
    {
        if(NULL != (obj = stabFind(*it)))
        {
            obj->decompile(os);
        }
    }

    // Decompile reg
    for(vector<string>::const_iterator it = _regList.begin();
        it != _regList.end(); ++it)
    {
        if(NULL != (obj = stabFind(*it)))
        {
            obj->decompile(os);
        }
    }
    // Decompile integer
    for(vector<string>::const_iterator it = _intVarList.begin();
        it != _intVarList.end(); ++it)
    {
        if(NULL != (obj = stabFind(*it)))
        {
            obj->decompile(os);
        }
    }
    // Decompile Real
    for(vector<string>::const_iterator it = _realVarList.begin();
        it != _realVarList.end(); ++it)
    {
        if(NULL != (obj = stabFind(*it)))
        {
            obj->decompile(os);
        }
    }
    // Decompile realtime
    for(vector<string>::const_iterator it = _realTimeVarList.begin();
        it != _realTimeVarList.end(); ++it)
    {
        if(NULL != (obj = stabFind(*it)))
        {
            obj->decompile(os);
        }
    }
    // Decompile time
    for(vector<string>::const_iterator it = _timeVarList.begin();
        it != _timeVarList.end(); ++it)
    {
        if(NULL != (obj = stabFind(*it)))
        {
            obj->decompile(os);
        }
    }
    // Decompile assigns
    for(vector<svExprBase*>::const_iterator it = _assignList.begin();
        it != _assignList.end(); ++it)
    {
        if(svExprBase::eExprType::CONST != (*it)->getExprType())
            (*it)->decompile(os);
    }

    // Decompile always     
    for(vector<svAlways*>::const_iterator it = _alwaysStmtList.begin();
        it != _alwaysStmtList.end(); ++it)
    {
            (*it)->decompile(os);
    }

    os << "endmodule" << std::endl;
}
