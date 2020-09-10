#include <svLogger.h>
#include <svPort.h>
#include <svNet.h>
#include <svReg.h>
#include <svInteger.h>
#include <svTime.h>


svPort::tOpMap svPort::opMap_ = {     
	{ WANDNET_PORT,  "wand"   },  
	{ UWIRE_PORT,    "uwire"   },  
	{ WIRE_PORT,     "wire"   },   
	{ WORNET_PORT,   "wor"   }, 
	{ SUPPLY_0NET_PORT, "supply0"   },    
	{ SUPPLY_1NET_PORT, "supply1"   },    
	{ TRINET_PORT,    "tri"   },    
	{ TRIANDNET_PORT, "triand"   },   
	{ TRIORNET_PORT,  "trior"   },  
	{ TRI0NET_PORT,   "tri0"   },    
	{ TRI1NET_PORT,   "tri1"   },   
	{ TRIREG_PORT,   "trireg"   },
	{ REG_PORT,      "reg"   },
	{ INTEGER_PORT,  "integer" },   
	{ TIME_PORT,     "time"   }    
};      

svPort::svPort(const std::string& s, const ePortDirection d)
    : svDeclBase(s)
    , direction_(d)
{
    setDeclBaseType(PORT);
}

svPort::svPort(const svDeclBase& b, const ePortType e)
    : svDeclBase(b)
    , portType_(e)
{
    setDeclBaseType(PORT);
    svDeclBase::EDeclType t = getDeclType();    
    if(svDeclBase::EDeclType::REG == t) 
    {    
	    portType_ = REG_PORT;    
    }  
    if (svDeclBase::EDeclType::NET == t) {
           portType_ = UWIRE_PORT;
    }
}

/*svPort& svPort::operator=(const svWire& w)
{
    setRange(w.getRange());
    return *this;
}
*/
bool svPort::update(const svBase* b)
{
    if(svBase::eNodeType::DECL != b->getType()) return false;

    const svDeclBase* declB = static_cast<const svDeclBase*>(b);

    bool ret = svDeclBase::update(declB);

    svDeclBase::EDeclType t = declB->getDeclType();

    if(svDeclBase::EDeclType::REG  == t)    
    {
        const svReg* p = dynamic_cast<const svReg*>(b);
        if(p == NULL) return ret;
        portType_ = REG_PORT;
	range_ = p->getRange();
	isSigned_ = p->isSigned_;
	ret = true;  
    }	
    if(svDeclBase::EDeclType::INTEGER  == t)    
    {
        const svInteger* p = dynamic_cast<const svInteger*>(b);
        if(p == NULL) return ret;
        portType_ = INTEGER_PORT;
	ret = true;  
    }	
    if(svDeclBase::EDeclType::TIME  == t)    
    {
        const svTime* p = dynamic_cast<const svTime*>(b);
        if(p == NULL) return ret;
        portType_ = TIME_PORT;
	ret = true;  
    }	
    if(svDeclBase::EDeclType::NET  == t)    
    {
        const svNet* p = dynamic_cast<const svNet*>(b);
        if(p == NULL) return ret;
        switch ( p->netType_)
	{
           case WIRE :
		    portType_ = WIRE_PORT;
		    break;
           case UWIRE :
		    portType_ = UWIRE_PORT;
		    break;
           case WORNET :
		    portType_ = WORNET_PORT;
		    break;
           case WANDNET :
		    portType_ = WANDNET_PORT;
		    break;
           case SUPPLY_0NET :
		    portType_ = SUPPLY_0NET_PORT;
		    break;
           case SUPPLY_1NET :
		    portType_ = SUPPLY_1NET_PORT;
		    break;
           case TRI1NET :
		    portType_ = TRI1NET_PORT;
		    break;
           case TRI0NET :
		    portType_ = TRI0NET_PORT;
		    break;
           case TRINET :
		    portType_ = TRINET_PORT;
		    break;
           case TRIANDNET :
		    portType_ = TRIANDNET_PORT;
		    break;
           case TRIORNET :
		    portType_ = TRIORNET_PORT;
		    break;
           case TRIREG :
		    portType_ = TRIREG_PORT;
		    break;
           case UNDEFINE :
		    portType_ = UNDEFINE_PORT;
		    break;

	}
	range_ = p->getRange();
	isSigned_ = p->isSigned_;
	ret = true;  
    }	
    if(svDeclBase::EDeclType::PORT == t) {
        const svPort* p = dynamic_cast<const svPort*>(b);
        if(p == NULL) return ret;
        
        direction_ = p->direction_;
	range_ = p->range_;
	isSigned_ = p->isSigned_;
        portType_ = p->portType_;
        ret = true;
    }

    return ret;
}

void svPort::portDecompile(std::ostream& os) const
{
    switch(direction_)
    {
        case INPUT : os << "input ";  break;
        case OUTPUT: os << "output "; break;
        case INOUT : os << "inout ";  break;
	case UNDEF : if (portType_ == UNDEFINE_PORT) {
			os << "ERROR ::" <<getName()<<" is not declared as input or output or inout"<<std::endl;
		        exit(1);
		     }
        default    : break;
    }
    if ( portType_ != UNDEFINE_PORT ) {
      os << opMap_[portType_] << " ";
    } 
    if (isSigned_ == true)    
      os << "signed"; 
    const svDeclRange* r = getRange();
    if(r)
    {
        os << ' ';
	r->decompile();
        os << ' ';
    }

    os << getName() << ';' << std::endl;
}
/*
void svPort::decompile(std::ostream& os) const
{
    bool valid = true;

    switch(portType_)
    {
        case svDeclBase::EDeclType::NET: os << "wire "; break;
        case svDeclBase::EDeclType::REG:  os << "reg "; break;
        case svDeclBase::EDeclType::TRI:  os << "tri "; break;
        default: break;
    }

    if(valid)
    {
        svDeclBase::decompile(os);
        os << ";" << std::endl;
    }
}*/
