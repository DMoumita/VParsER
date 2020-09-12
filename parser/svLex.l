%{

// System Headers
#include <iostream>
#include <string>

// OM headers
#include <svRoot.h>
#include <svReg.h>
#include <svWire.h>
#include <svPort.h>
#include <svBlock.h>
#include <svTypes.h>
#include <svAlways.h>
#include <svYacc.hpp>

using namespace std;

svFile _DEFAULTFILE_ = svFile("<INPUT>");    // The corresponding file object under parse

void yyerror(const char*);
svFile& LexFile = _DEFAULTFILE_;    // The corresponding file object under parse

double   yyColNo = 0;
double   yyOLDColNo = 0;
double   yyOLDlineno = 0;

void updateCoord(const bool analyze = false);

%}

WS                                  [ \t]
letter                              [a-zA-Z_]
digit                               [0-9]
extDigit                            [0-9_]
hexdigit                            [a-fA-F0-9]
base                                [dDhHoObB]
                                  
sized_digit                         ({hexdigit}|[xXzZ\?])
                                  
size                                {digit}+
                                  
ident                               {letter}({letter}|{digit})*
                                  
exponent                            [eE][+-]?{digit}+
                                  
sized_number                        {size}\'{base}{sized_digit}({sized_digit}\_)*
                                  
unsized_number                      {digit}({extDigit})*(\.{extDigit}+)?({exponent})?

%option nounput
%option yylineno

%%

{WS}                                { updateCoord();      }
\n\r?                               { updateCoord(true);  }

\/\*(.*)\*\/                        { updateCoord(true);  } // Ignore comment of the form /* ... */

\/\/.*(\r)?\n                       { updateCoord(true);  } // Ignore comment of the forme // ......

@                                   { updateCoord(); return AT;            }
:                                   { updateCoord(); return COLON;         }
,                                   { updateCoord(); return COMMA;         }
\.                                  { updateCoord(); return DOT;           }
===                                 { updateCoord(); return EQ_CASE;       }
==                                  { updateCoord(); return EQUAL;         }
=\>                                 { updateCoord(); return PPATH;         }
=                                   { updateCoord(); return ASSIGN;        }
-\>                                 { updateCoord(); return TRIGGER;       }
-                                   { updateCoord(); return MINUS;         }
\{                                  { updateCoord(); return LCURLY;        }
\}                                  { updateCoord(); return RCURLY;        }
\[                                  { updateCoord(); return LBRACK;        }
\]                                  { updateCoord(); return RBRACK;        }
\(                                  { updateCoord(); return LPAREN;        }
\)                                  { updateCoord(); return RPAREN;        }
#                                   { updateCoord(); return POUND;         }
\?                                  { updateCoord(); return QUESTION;      }
;                                   { updateCoord(); return SEMI;          }
\+                                  { updateCoord(); return PLUS;          }
!==                                 { updateCoord(); return NOT_EQ_CASE;   }
!=                                  { updateCoord(); return NOT_EQ;        }
!                                   { updateCoord(); return LNOT;          }
~\|                                 { updateCoord(); return RNOR;          }
~\^                                 { updateCoord(); return BXNOR;         }
\^~                                 { updateCoord(); return BXNOR;         }
~&                                  { updateCoord(); return RNAND;         }
\~                                  { updateCoord(); return BNOT;          }
&&                                  { updateCoord(); return LAND;          }
&                                   { updateCoord(); return BAND;          }
\|\|                                { updateCoord(); return LOR;           }
\|                                  { updateCoord(); return BOR;           }
\^                                  { updateCoord(); return BXOR;          }
\/                                  { updateCoord(); return DIV;           }
\%                                  { updateCoord(); return MOD;           }
\<=                                 { updateCoord(); return LE;            }
\<\<                                { updateCoord(); return SL;            }
\<                                  { updateCoord(); return LT;            }
\>=                                 { updateCoord(); return GE;            }
\>\>                                { updateCoord(); return SR;            }
\>                                  { updateCoord(); return GT;            }
\*\>                                { updateCoord(); return FPATH;         }
\*                                  { updateCoord(); return STAR;          }

or                                  { updateCoord(); return BOROP;         }
signed                              { updateCoord(); return SIGNED;        }
`define                             { updateCoord(); return Key_DEFINE;    }
`include                            { updateCoord(); return Key_INCLUDE;   }
always                              { updateCoord(); return Key_ALWAYS;    }
assign                              { updateCoord(); return Key_ASSIGN;    }
begin                               { updateCoord(); return Key_BEGIN;     }
end                                 { updateCoord(); return Key_END;       }
endmodule                           { updateCoord(); return Key_ENDMODULE; }
inout                               { updateCoord(); return Key_INOUT;     }
input                               { updateCoord(); return Key_INPUT;     }
integer                             { updateCoord(); return Key_INTEGER;   }
macromodule                         { updateCoord(); return Key_MODULE;    }
module                              { updateCoord(); return Key_MODULE;    }
negedge                             { updateCoord(); return Key_NEGEDGE;   }
output                              { updateCoord(); return Key_OUTPUT;    }
parameter                           { updateCoord(); return Key_PARAMETER; }
posedge                             { updateCoord(); return Key_POSEDGE;   }
pull0                               { updateCoord(); return Key_PULL0;     }
pull1                               { updateCoord(); return Key_PULL1;     }
supply0                             { updateCoord(); return Key_SUPPLY0;   }
supply1                             { updateCoord(); return Key_SUPPLY1;   }
weak0                               { updateCoord(); return Key_WEAK0;     }
weak1                               { updateCoord(); return Key_WEAK1;     }
real                                { updateCoord(); return Key_REAL;      }
realtime                            { updateCoord(); return Key_REALTIME;  }
time                                { updateCoord(); return Key_TIME;      }
reg                                 { updateCoord(); return Key_REG;       }
strong0                             { updateCoord(); return Key_STRONG0;   }
strong1                             { updateCoord(); return Key_STRONG1;   }
trireg                              { updateCoord(); return Key_TRIREG;    }
wire                                { updateCoord(); return Key_WIRE;      }
uwire                               { updateCoord(); return Key_UWIRE;     }
wand                                { updateCoord(); return Key_WAND;      }
wor                                 { updateCoord(); return Key_WOR;       }
tri                                 { updateCoord(); return Key_TRI;       }
triand                              { updateCoord(); return Key_TRIAND;    }
trior                               { updateCoord(); return Key_TRIOR;     }
tri0                                { updateCoord(); return Key_TRI0;      }
tri1                                { updateCoord(); return Key_TRI1;      }
highz0                              { updateCoord(); return Key_HIGHZ0;    }
highz1                              { updateCoord(); return Key_HIGHZ1;    }
vectored                            { updateCoord(); return VECTORED;    }
scalared                            { updateCoord(); return SCALARED;    }
\+:                                  { updateCoord(); return Key_PLUSCOLON; }
\-:                                  { updateCoord(); return Key_MINUSCOLON;}

{ident}                             { updateCoord(); yylval.name = new string(yytext); return IDENTIFIER;         }

\${ident}                           { updateCoord(); yylval.name = new string(yytext); return SYSTEM_TASK_NAME;   }

\\^[\u0020]+[\u0020|\t|\n]          { updateCoord(); yylval.name = new string(yytext); return ESCAPED_IDENTIFIER; }

\"(^[\"\n])*\"                      { updateCoord(true); yylval.name = new string(yytext); return STRING; }

\'\${ident}                         { updateCoord(); return DEFINE;  }

{sized_number}                      { updateCoord(); yylval.name = new string(yytext); return NUMBER; }

{unsized_number}                    { updateCoord(); yylval.name = new string(yytext); return NUMBER; }

.                                   { updateCoord(true);
                                      SVLOG(SYN, ERR) << ": Line# " << yylineno << ", Col# " << yyColNo
                                                      << " : unmatch char stream \"" << yytext << "\"" << std::endl;
                                      return PARSE_ERROR;
                                    }

%%

void updateCoord(const bool analyze)
{
    yyOLDlineno = yylineno;
    yyOLDColNo = yyColNo;

    if(analyze)
    {
        for(int i=0; i < yyleng; i++)
        {
            if(yytext[i] == '\n')      { yylineno++; yyColNo = 0; }
            else if(yytext[i] == '\r') { }
            else                       { yyColNo++; }
        }
    }
    else
    {
        yyColNo+=yyleng;
    }
}

int yywrap()
{
    yylineno = 0; yyColNo = 0;
    return 1;
}

void yyerror(const char *str)
{
    SVLOG(SYN, ERR) << ": Line# " << yylineno << ", Col# " << yyColNo << ": "
                    << str << " ..." << std::endl;
}

