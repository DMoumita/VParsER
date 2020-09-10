#include <svExprOp.h>

svExprOp::tOpMap svExprOp::opMap_ = {
       { CONDITIONAL,   "?"   },          
       { LAND,          "&&"  },          
       { LOR,           "||"  },
       { BAND,          "&"   },
       { BOR,           "|"   },
       { BXOR,          "^"   },
       { BXNOR,         "~^"  },
       { RNOR,          "~|"  },
       { LT,            "<"   },
       { LE,            "<="  },
       { GT,            ">"   },
       { GE,            ">="  },
       { EQUAL,         "=="  },
       { NOT_EQ,        "!="  },
       { EQ_CASE,       "===" },
       { NOT_EQ_CASE,   "!==" },
       { PLUS,          "+"   },
       { MINUS,         "-"   },
       { SL,            "<<"  },
       { SR,            ">>"  },
       { MULT,          "*"   },
       { DIV,           "/"   },
       { MOD,           "%"   },
       { BNOT,          "~"   },
       { LNOT,          "!"   }
};

svExprOp::svExprOp(const eExprOpType e)
    : svExprBase(OP)
    , opType_(e)
{ }

void svExprOp::decompile(std::ostream& os) const
{
    const svExprBase::TChildList& ops = getSubExprs();

    os << '(';
    
    if ( opType_ == BNOT ) {
         os << opMap_[opType_] << "(";
	 if(ops[0]) ops[0]->decompile(os);
         os << ')';
    } else {
	 if(ops[0]) ops[0]->decompile(os);
	 os << " " << opMap_[opType_] << " ";

	 if(ops[1]) ops[1]->decompile(os); 

	 if(opType_ == CONDITIONAL)
	 {
	    os << " : ";
	    if(ops[2]) ops[2]->decompile(os);
	 }
     }
    os << ')';
}
