#include <svNet.h>

svNet::tOpMap svNet::opMap_ = {
       { WIRE,     "wire"   },
       { UWIRE,    "uwire"   },
       { WANDNET,  "wand"   },
       { WORNET,   "wor"   },
       { SUPPLY_0NET, "supply0"   },
       { SUPPLY_1NET, "supply1"   },
       { TRINET,    "tri"   },
       { TRIANDNET, "triand"   },
       { TRIORNET,  "trior"   },
       { TRI0NET,   "tri0"   },
       { TRI1NET,   "tri1"   },
       { TRIREG,   "trireg"   }
};

svNet::tdriveMap svNet::driveStrengthMap_ = {
       { STRONG_0,   "strong0"   },          
       { STRONG_1,   "strong1"   },          
       { SUPPLY_0,   "supply0"   },          
       { SUPPLY_1,   "supply1"   },          
       { WEAK_0,     "weak0"     },          
       { WEAK_1,     "weak1"     },          
       { PULL_0,     "pull0"     },          
       { PULL_1,     "pull1"     },         
       { HIGHZ_0,    "highz0"    },         
       { HIGHZ_1,    "highz1"    }         
};

svNet::svNet(const svDeclBase& b, const eNetType e)
    : svDeclBase(b)
    , _strengthItem0(UNSET_STRENGTH)
    , _strengthItem1(UNSET_STRENGTH)
    , netType_(e)
{
setDeclBaseType(NET); 
}


void svNet::decompile(std::ostream& os) const
{
    os << opMap_[netType_] << " ";
    if (_strengthItem0 !=  UNSET_STRENGTH  && _strengthItem1 != UNSET_STRENGTH ) 
    {
      os << "( " << driveStrengthMap_[_strengthItem0] << " , " 
	      << driveStrengthMap_[_strengthItem1] << " ) ";

    }
    if (isVector_ == true)
	  os << "vectored ";

    if (isScalar_ == true)
	  os << "scalared ";

    if (isSigned_ == true)
	    os << "signed";

    if (range_) range_->decompile(os);

    if (!_delayList.empty()) {
	os<<" #";
        for(vector<svExprBase*>::const_iterator it = _delayList.begin(); 
			it != _delayList.end(); ++it)   
	{  
		(*it)->decompile(os);
	}
    }
    svDeclBase::decompile(os);    os << ';'<<std::endl;   
}
