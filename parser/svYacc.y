%{

// System Headers
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

// OM Headers
#include <svTypes.h>
#include <svBlockContext.h>
#include <svPort.h>
#include <svReg.h>
#include <svInteger.h>
#include <svRealTime.h>
#include <svReal.h>
#include <svTime.h>
#include <svInteger.h>
#include <svTri.h>
#include <svNet.h>
#include <svRoot.h>
#include <svExprOp.h>
#include <svExprConst.h>
#include <svSelectOp.h>
#include <svExprNum.h>
#include <svExprVar.h>
#include <svExprVarConcat.h>
#include <svAssignCombo.h>
#include <svAlways.h>
#include <svInstExpr.h>
#include <svContAssign.h>
#include <svNonBlkAssignExpr.h>
#include <svMinTypMax.h>
#include <svRangeExpr.h>
#include<svGlobals.h>

using namespace std;
double gLineNo;
double gColNo;

extern char*                        yytext;
extern double                       yyColNo, yylineno;
extern FILE*                        yyin;

int                                 yylex();
void                                yyerror(const char*);
void                                yyfinalize();

extern svFile _DEFAULTFILE_;
extern svFile& LexFile;  // The corresponding file object under parse

%}

%union
{
  string*                           name;
  void*                             holder;  // placeholder for all types of pointer

  svBase*                           base;
  svModule*                         mod;
  svPort::ePortDirection            direction;
  svPort*                           port;
  svDeclBase*                       var;
  svExprBase*                       expr;
  svSensitivity*                    sens;
  vector<svBase*>*                  baseList;
  vector<svExprBase*>*              exprList;
  vector<string>*                   idList;
  vector<svPort*>*                  portList;
  vector<svSensitivity>*            sensList;
  vector<svDeclBase>*               varList;
  svDeclRange*                      range;
  bool                              boolType;

  svDriveStrengthType               driveStrengthType ;
  eNetType                          netType;
  ePortType                         portType;
  vector<svDriveStrengthType>*      strengthList ;
}

%token <name>                       IDENTIFIER
%token <name>                       SYSTEM_TASK_NAME
%token <name>                       ESCAPED_IDENTIFIER
%token <name>                       STRING
%token <name>                       NUMBER

%token                              AT
%token                              COLON
%token                              Key_PLUSCOLON
%token                              Key_MINUSCOLON
%token                              COMMA
%token                              DOT
%token                              EQ_CASE
%token                              EQUAL
%token                              PPATH
%token                              ASSIGN
%token                              TRIGGER
%token                              MINUS
%token                              LCURLY
%token                              RCURLY
%token                              LBRACK
%token                              RBRACK
%nonassoc                           LPAREN
%token                              RPAREN
%token                              POUND
%left                               QUESTION
%token                              SEMI
%token                              PLUS
%token                              NOT_EQ_CASE
%token                              NOT_EQ
%token                              LNOT
%token                              RNOR
%token                              RNAND
%token                              BNOT
%token                              LAND
%token                              BAND
%token                              LOR
%token                              BOR
%token                              BXNOR
%token                              BXOR
%token                              DIV
%token                              MOD
%token                              LE
%token                              SL
%token                              LT
%token                              GE
%token                              SR
%token                              GT
%token                              FPATH
%token                              STAR
%token                              DEFINE
%token                              PARSE_ERROR
%token                              BOROP
%token                              SIGNED
%token                              VECTORED
%token                              SCALARED

%token                              Key_ASSIGN
%token                              Key_ALWAYS
%token                              Key_BEGIN
%token                              Key_DEFINE
%token                              Key_END
%token                              Key_ENDMODULE
%token                              Key_INTEGER
%token                              Key_INCLUDE
%token                              Key_INOUT
%token                              Key_INPUT
%token                              Key_MODULE
%token                              Key_NEGEDGE
%token                              Key_OUTPUT
%token                              Key_PARAMETER
%token                              Key_POSEDGE
%token                              Key_PULL0
%token                              Key_PULL1
%token                              Key_SUPPLY0
%token                              Key_SUPPLY1
%token                              Key_WEAK0
%token                              Key_WEAK1
%token                              Key_REAL
%token                              Key_REG
%token                              Key_TIME
%token                              Key_REALTIME
%token                              Key_STRONG0
%token                              Key_STRONG1
%token                              Key_TRIREG
%token                              Key_WIRE
%token                              Key_UWIRE
%token                              Key_WAND
%token                              Key_WOR
%token                              Key_TRI
%token                              Key_TRIAND
%token                              Key_TRIOR
%token                              Key_TRI0
%token                              Key_TRI1
%token                              Key_HIGHZ0
%token                              Key_HIGHZ1

%type<holder>                       _placeHolder_
%type<base>                         alwaysStmt 
%type<expr>                         assignExpr
%type<expr>                         assignExprList
%type<base>                         assignStmt   
%type<base>                         block
%type<base>                         stmtOrBlock
%type<expr>                         cExpression
%type<direction>                    direction
%type<expr>                         expression
%type<expr>                         exprVar
%type<expr>                         factor
%type<base>                         instanceStmt 
%type<baseList>                     integerDecl
%type<expr>                         lExpression
%type<idList>                       lIdList
%type<idList>                       localIdList
%type<name>                         localIdentifier
%type<name>                         localVar
%type<baseList>                     modItem   
%type<portList>                     modPortList
%type<port>                         modPortName
%type<baseList>                     modPortAssign
%type<baseList>                     modPortAssignList
%type<mod>                          module
%type<name>                         moduleName
%type<base>                         nonblkAssignStmt
%type<base>                         blkAssignStmt
%type<expr>                         optBitSel
%type<baseList>                     optModuleItemList 
%type<portList>                     optModPortList
%type<range>                        optRange
%type<baseList>                     portDecl   
%type<baseList>                     netDecl   
%type<name>                         portName
%type<baseList>                     procStmtList
%type<base>                         procStmt
%type<range>                        range
%type<baseList>                     regDecl  
%type<baseList>                     realDecl   
%type<baseList>                     realTimeDecl   
%type<baseList>                     timeDecl   
%type<expr>                         redExpression
%type<expr>                         relExpression
%type<sens>                         sensitivity
%type<sensList>                     sensitivityList
%type<baseList>                     stmtList
%type<base>                         stmt
%type<expr>                         term
%type<name>                         variableName
%type<var>                          varWtInit
%type<varList>                      variableList
%type<varList>                      netItemDeclList
%type<varList>                      netItemAssignDeclList
%type<varList>                      netItemOrAssignDeclList
%type<var>                          netIdentifier
%type<var>                          netAssignExpr
%type<boolType>                     signedOrNull
%type<boolType>                     vectoredOrScalared
%type<driveStrengthType>            strength0
%type<driveStrengthType>            strength1
%type<strengthList>                 strengthList
%type<netType>                      netTypeDecl
%type<baseList>                     delayOrNull
%type<baseList>                     delay1
%type<baseList>                     delay2
%type<expr>                         minTypMaxExpr

%start                              program

%%

program : descriptionList
        ;

descriptionList : descriptionList description
                | 
                ;

description : module
            ;

module : _placeHolder_ Key_MODULE moduleName optModPortList SEMI
         {
             $<holder>1 = NULL;
             const string& modName = (*$<name>3);

             if (SINGLETON<svRoot>::getInstance().find(modName) == NULL)
             { // modName not in Symbol-Table
                  svModule* mdl = new svModule(modName);
                  $<holder>1 = mdl;
                  SINGLETON<svRoot>::getInstance().add(mdl);

                  if($<portList>4 != NULL)
                  {
                     for(vector<svPort*>::iterator it = $<portList>4->begin();
                         it != $<portList>4->end(); it++)
                           mdl->add(*it);
                  }
                  
                  SVLOG(SEM, INFO) << "Creating Module: \"" << modName << "\"" << std::endl;
             }
             else
             {
                  SVLOG(SEM, ERR) << "Module " <<  modName <<"\" already declared." << std::endl;
             }
             
             delete $<name>3;
             if($<portList>4 != NULL) delete $<portList>4;
         }
         optModuleItemList
         {
             svModule* mdl = static_cast<svModule*>($<holder>1);
             if((mdl != NULL) && ($<baseList>7 != NULL))
             {
                  for(vector<svBase*>::const_iterator it = $<baseList>7->begin();
                     it != $<baseList>7->end(); ++it)
                  {
                      if(NULL != (*it))
                      {
                          if((*it)->getType() == svBase::eNodeType::DECL)
                          {
                              mdl->add(static_cast<svDeclBase*>(*it));
                          }
                          else if((*it)->getType() == svBase::eNodeType::EXPR)
                          {
                              mdl->add(static_cast<svExprBase*>(*it));
                          }
                          else if((*it)->getType() == svBase::eNodeType::ALWAYS) //Moumita
                          {
                              mdl->add(static_cast<svAlways*>(*it));
                          }
                          
                          else { }
                      }
                      else { }
                  }
             }
         }
         Key_ENDMODULE
         {
             $<mod>$ = static_cast<svModule*>($<holder>1);
         }
       ;

optModPortList : { $<portList>$ = NULL; }
               | LPAREN RPAREN { $<portList>$ = NULL; }
               | LPAREN modPortList RPAREN
                 { $<portList>$ = $<portList>2; }
               ;

modPortList : modPortList COMMA modPortName
              { $<portList>1->push_back($<port>3);
                $<portList>$ =  $<portList>1;
              }
            | modPortName
              { $<portList>$ = new vector<svPort*>();
                $<portList>$->push_back($<port>1);
              }
            ;

modPortName : direction portName
              { $<port>$ = new svPort(*$<name>2, $<direction>1);
                delete $<name>2;
              }
            | portName
              { $<port>$ = new svPort(*$<name>1, svPort::ePortDirection::UNDEF);
                delete $<name>1;
              }
            ;

optModuleItemList : optModuleItemList modItem
                    {
                        if($<baseList>1 != NULL)
                        {
                            if($<baseList>2 != NULL)
                            {
                              $<baseList>1->insert( $<baseList>1->end()
                                                  , $<baseList>2->begin()
                                                  , $<baseList>2->end());
                              delete $<baseList>2;
                            }
                            $<baseList>$ = $<baseList>1;
                        }
                        else
                        {
                            $<baseList>$ = $<baseList>2;
                        }
                    }
                  | { $<baseList>$ = NULL; }
                  ;

modItem : portDecl     { $<baseList>$ = $<baseList>1; }
        | netDecl     { $<baseList>$ = $<baseList>1; }
        | regDecl      { $<baseList>$ = $<baseList>1; }
        //| triDecl      { $<baseList>$ = $<baseList>1; }
        | integerDecl  { $<baseList>$ = $<baseList>1; }
        | realDecl     { $<baseList>$ = $<baseList>1; }
        | constDecl    { $<baseList>$ = $<baseList>1; }
        | stmtList     { $<baseList>$ = $<baseList>1; }
        | realTimeDecl { $<baseList>$ = $<baseList>1; }
        | timeDecl     { $<baseList>$ = $<baseList>1; }
        ;

portDecl : direction portTypeDeclOrNull signedOrNull rangeOrNull variableList SEMI
           {  vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>5->begin();
                  it != $<varList>5->end(); ++it)
              {
                 svPort* p = new svPort(*it,$<portType>2);
                 p->setDirection($<direction>1);
                 p->setIsSigned($<boolType>3);
                 p->setRange($<range>4);
                 l->push_back(p);
              }
              delete $<varList>5;
              $<baseList>$ = l;
           }
           |Key_OUTPUT Key_REG signedOrNull rangeOrNull variableList SEMI  
           {  vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>5->begin();
                  it != $<varList>5->end(); ++it)
              {
                 svPort* p = new svPort(*it,REG_PORT);
                 p->setDirection(svPort::ePortDirection::OUTPUT);
                 p->setIsSigned($<boolType>3);
                 p->setRange($<range>4);
                 l->push_back(p);
              }
              delete $<varList>5;
              $<baseList>$ = l;
           }
           |Key_OUTPUT outputVariable  variableList SEMI  
           {  vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>3->begin();
                  it != $<varList>3->end(); ++it)
              {
                 svPort* p = new svPort(*it,$<portType>2);
                 p->setDirection(svPort::ePortDirection::OUTPUT);
                 l->push_back(p);
              }
              delete $<varList>3;
              $<baseList>$ = l;
           }
         ;

outputVariable: Key_TIME
	     {
               $<portType>$ = TIME_PORT;
             }
	     |Key_INTEGER
	     {
               $<portType>$ = INTEGER_PORT;
             }
;

portTypeDeclOrNull: Key_WIRE
	     {
               $<portType>$ = WIRE_PORT;
             }
	     |Key_UWIRE
	     {
               $<portType>$ = UWIRE_PORT;
             }
             |Key_WAND
	     {
               $<portType>$ = WANDNET_PORT;
             }
	     |Key_WOR
	     {
               $<portType>$ = WORNET_PORT;
             }
	     |Key_TRI
	     {
               $<portType>$ = TRINET_PORT;
             }
             |Key_TRI0
	     {
               $<portType>$ = TRI0NET_PORT;
             }
             |Key_TRI1
	     {
               $<portType>$ = TRI1NET_PORT;
             }
 	     |Key_TRIAND
	     {
               $<portType>$ = TRIANDNET_PORT;
             }
	     |Key_TRIOR
	     {
               $<portType>$ = TRIORNET_PORT;
             }
	     |Key_SUPPLY0
	     {
               $<portType>$ = SUPPLY_0NET_PORT;
             }
	     |Key_SUPPLY1
	     {
               $<portType>$ = SUPPLY_1NET_PORT;
             }
	     |Key_TRIREG
	     {
               $<portType>$ = TRIREG_PORT;
             }
	     |Key_REG
	     {
               $<portType>$ = REG_PORT;
             }
             | { $<portType>$ = UNDEFINE_PORT;}
;
rangeOrNull : range 
	     {$<range>$ = $<range>1;}
             | { $<range>$ = NULL;}
;
netDecl : netTypeDecl signedOrNull  delayOrNull netItemOrAssignDeclList SEMI
           {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>4->begin();
                 it != $<varList>4->end(); ++it)
              {
                svNet * w = new svNet(*it,$<netType>1);
                w->setIsSigned($<boolType>2);
                if($<baseList>3 != NULL)
                {
                   for(vector<svBase*>::iterator it = $<baseList>3->begin(); it != $<baseList>3->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete $<varList>4;
              $<baseList>$ = l;
           }
           | netTypeDecl vectoredOrScalared signedOrNull range delayOrNull netItemOrAssignDeclList SEMI
           {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>6->begin();
                 it != $<varList>6->end(); ++it)
              {
                svNet * w = new svNet(*it,$<netType>1);
                w->setIsSigned($<boolType>3);
                w->setRange($<range>4);
                if($<baseList>5 != NULL)
                {
                   for(vector<svBase*>::iterator it = $<baseList>5->begin(); it != $<baseList>5->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                if ( $<boolType>2 == true ) {
                   w->setIsVector(true);
                   w->setIsScalar(false);
                } else {
                   w->setIsVector(false);
                   w->setIsScalar(true);
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete $<varList>6;
              $<baseList>$ = l;
           }
           | netTypeDecl  signedOrNull range delayOrNull netItemOrAssignDeclList SEMI
           {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>5->begin();
                 it != $<varList>5->end(); ++it)
              {
                svNet * w = new svNet(*it,$<netType>1);
                if($<baseList>4 != NULL)
                {
                   for(vector<svBase*>::iterator it = $<baseList>4->begin(); it != $<baseList>4->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                w->setIsSigned($<boolType>2);
                w->setRange($<range>3);
                l->push_back(static_cast<svBase*>(w));
              }
              delete $<varList>5;
              $<baseList>$ = l;
           }
           | netTypeDecl  strengthList signedOrNull delayOrNull netItemAssignDeclList SEMI
           {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>5->begin();
                 it != $<varList>5->end(); ++it)
              {
                svNet * w = new svNet(*it,$<netType>1);
                w->setIsSigned($<boolType>3);
                if($<baseList>4 != NULL)
                {
                   for(vector<svBase*>::iterator it = $<baseList>4->begin(); it != $<baseList>4->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                if (  $<strengthList>2 != NULL ) 
                {
                   svDriveStrengthType it1 = $<strengthList>2->front();
                   svDriveStrengthType it2 = $<strengthList>2->back();
                    w->setStrength0(it1);
                    w->setStrength1(it2);
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete $<varList>5;
              $<baseList>$ = l;
           }
           | netTypeDecl strengthList vectoredOrScalared signedOrNull range delayOrNull netItemAssignDeclList SEMI
           {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>7->begin();
                 it != $<varList>7->end(); ++it)
              {
                svNet * w = new svNet(*it,$<netType>1);
                w->setIsSigned($<boolType>4);
                w->setRange($<range>5);
                if($<baseList>6 != NULL)
                {
                   for(vector<svBase*>::iterator it = $<baseList>6->begin(); it != $<baseList>6->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                if ( $<boolType>3 == true ) {
                   w->setIsVector(true);
                   w->setIsScalar(false);
                } else {
                   w->setIsVector(false);
                   w->setIsScalar(true);
                }
                if (  $<strengthList>2 != NULL ) 
                {
                   svDriveStrengthType it1 = $<strengthList>2->front();
                   svDriveStrengthType it2 = $<strengthList>2->back();
                    w->setStrength0(it1);
                    w->setStrength1(it2);
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete $<varList>7;
              $<baseList>$ = l;
           }
           | netTypeDecl  strengthList signedOrNull range delayOrNull netItemAssignDeclList SEMI
           {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = $<varList>6->begin();
                 it != $<varList>6->end(); ++it)
              {
                svNet * w = new svNet(*it,$<netType>1);
                if($<baseList>5 != NULL)
                {
                   for(vector<svBase*>::iterator it = $<baseList>5->begin(); it != $<baseList>5->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                w->setIsSigned($<boolType>3);
                w->setRange($<range>4);
                if (  $<strengthList>2 != NULL ) 
                {
                   svDriveStrengthType it1 = $<strengthList>2->front();
                   svDriveStrengthType it2 = $<strengthList>2->back();
                    w->setStrength0(it1);
                    w->setStrength1(it2);
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete $<varList>6;
              $<baseList>$ = l;
           }
         ;

delayOrNull : delay1
	   {
             $<baseList>$ = $1;
           }
           |delay2
           { 
             $<baseList>$ = $1;
           }
           |
           {
              $<base>$ = NULL;
           }
;


delay1: POUND NUMBER
       {
              svExprNum<string>* n = new svExprNum<string>(*$<name>2);
              $<baseList>$ = new vector<svBase*>();
              $<baseList>$->push_back(n);
              delete $<name>2;
       }
      |POUND IDENTIFIER
      {
              svExprNum<string>* n = new svExprNum<string>(*$<name>2);
              $<baseList>$ = new vector<svBase*>();
              $<baseList>$->push_back(n);
              delete $<name>2;
      }
;

delay2 : POUND LPAREN minTypMaxExpr RPAREN
        {
              $<baseList>$ = new vector<svBase*>();
              $<baseList>$->push_back($<expr>3);
        }
       | POUND LPAREN minTypMaxExpr COMMA minTypMaxExpr RPAREN
       {
              $<baseList>$ = new vector<svBase*>();
              $<baseList>$->push_back($<expr>3);
              $<baseList>$->push_back($<expr>5);
       }
       | POUND LPAREN minTypMaxExpr COMMA minTypMaxExpr COMMA minTypMaxExpr RPAREN
       {
              $<baseList>$ = new vector<svBase*>();
              $<baseList>$->push_back($<expr>3);
              $<baseList>$->push_back($<expr>5);
              $<baseList>$->push_back($<expr>7);
       }

;

minTypMaxExpr : cExpression
	        {
                    $<expr>$ = $<expr>1;
                }
	       | cExpression COLON cExpression COLON cExpression
               {
                 $<expr>$ = new svMinTypMax($<expr>1, $<expr>3, $<expr>5);
               }
;

vectoredOrScalared :  VECTORED
		   {
                      $<boolType>$ = true;
                   }
		   |SCALARED
                   {
                      $<boolType>$ = false;
                   }
;
netTypeDecl: Key_WIRE
	     {
               $<netType>$ = WIRE;
             }
	     |Key_UWIRE
	     {
               $<netType>$ = UWIRE;
             }
             |Key_WAND
	     {
               $<netType>$ = WANDNET;
             }
	     |Key_WOR
	     {
               $<netType>$ = WORNET;
             }
	     |Key_TRI
	     {
               $<netType>$ = TRINET;
             }
             |Key_TRI0
	     {
               $<netType>$ = TRI0NET;
             }
             |Key_TRI1
	     {
               $<netType>$ = TRI1NET;
             }
 	     |Key_TRIAND
	     {
               $<netType>$ = TRIANDNET;
             }
	     |Key_TRIOR
	     {
               $<netType>$ = TRIORNET;
             }
	     |Key_SUPPLY0
	     {
               $<netType>$ = SUPPLY_0NET;
             }
	     |Key_SUPPLY1
	     {
               $<netType>$ = SUPPLY_1NET;
             }
	     |Key_TRIREG
	     {
               $<netType>$ = TRIREG;
             }


;
strengthList :  LPAREN strength0 COMMA strength1 RPAREN
                   { 
                     $<strengthList>$ = new vector<svDriveStrengthType>();
                     $<strengthList>$->push_back($<driveStrengthType>2);
                     $<strengthList>$->push_back($<driveStrengthType>4);

                   }
                   | LPAREN strength1  COMMA strength0  RPAREN
                   { 
                     $<strengthList>$ = new vector<svDriveStrengthType>();
                     $<strengthList>$->push_back($<driveStrengthType>2);
                     $<strengthList>$->push_back($<driveStrengthType>4);
                    }
                   | LPAREN Key_HIGHZ1  COMMA strength0  RPAREN
                   { 
                     $<strengthList>$ = new vector<svDriveStrengthType>();
                     $<strengthList>$->push_back(HIGHZ_1);
                     $<strengthList>$->push_back($<driveStrengthType>4);
                    }
                   | LPAREN Key_HIGHZ0  COMMA strength1  RPAREN
                   { 
                     $<strengthList>$ = new vector<svDriveStrengthType>();
                     $<strengthList>$->push_back(HIGHZ_0);
                     $<strengthList>$->push_back($<driveStrengthType>4);
                    }
                   | LPAREN strength1  COMMA Key_HIGHZ0  RPAREN
                   { 
                     $<strengthList>$ = new vector<svDriveStrengthType>();
                     $<strengthList>$->push_back($<driveStrengthType>2);
                     $<strengthList>$->push_back(HIGHZ_0);
                    }
                   | LPAREN strength0  COMMA Key_HIGHZ1  RPAREN
                   { 
                     $<strengthList>$ = new vector<svDriveStrengthType>();
                     $<strengthList>$->push_back($<driveStrengthType>2);
                     $<strengthList>$->push_back(HIGHZ_1);
                    }
               //``    | {  $<strengthList>$ = NULL;}
             ;

strength0 : Key_STRONG0 
	  { 
            $<driveStrengthType>$ = STRONG_0;
          }
         | Key_SUPPLY0 
	  { 
            $<driveStrengthType>$ = SUPPLY_0;
          }
         | Key_PULL0   
          {
            $<driveStrengthType>$ = PULL_0;
          }
         | Key_WEAK0
	  { 
            $<driveStrengthType>$ = WEAK_0;
          }
         ;

strength1 : Key_STRONG1 
	  { 
            $<driveStrengthType>$ = STRONG_1;
          }
         | Key_SUPPLY1
	  { 
            $<driveStrengthType>$ = SUPPLY_1;
          }
         | Key_PULL1   
	  { 
            $<driveStrengthType>$= PULL_1;
          }
         | Key_WEAK1
	  { 
            $<driveStrengthType>$ = WEAK_1;
          }
         ;
regDecl : Key_REG signedOrNull optRange variableList SEMI
          {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = $<varList>4->begin();
                it != $<varList>4->end(); ++it)
             {
                 it->setRange($<range>3);
                 svReg* r = new svReg(*it);
                 r->setIsSigned($<boolType>2);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete $<varList>4;
             $<baseList>$ = l;
          }
        ;
signedOrNull : SIGNED 
	      { $<boolType>$ = true;}
	     |
	      { $<boolType>$ = false;}
;
/*triDecl : Key_TRIREG variableList SEMI
          {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = $<varList>2->begin();
                it != $<varList>2->end(); ++it)
             {
                 svTri* r = new svTri(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete $<varList>2;
             $<baseList>$ = l;
          }
        ;
*/
integerDecl : Key_INTEGER variableList SEMI
	    {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = $<varList>2->begin();
                it != $<varList>2->end(); ++it)
             {
                 svInteger* r = new svInteger(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete $<varList>2;
             $<baseList>$ = l;
             }
            ;

realDecl : Key_REAL variableList SEMI
	   {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = $<varList>2->begin();
                it != $<varList>2->end(); ++it)
             {
                 svReal* r = new svReal(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete $<varList>2;
             $<baseList>$ = l;
             }
         ;
realTimeDecl : Key_REALTIME variableList SEMI
	   {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = $<varList>2->begin();
                it != $<varList>2->end(); ++it)
             {
                 svRealTime* r = new svRealTime(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete $<varList>2;
             $<baseList>$ = l;
             }
         ;

timeDecl : Key_TIME variableList SEMI
	   {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = $<varList>2->begin();
                it != $<varList>2->end(); ++it)
             {
                 svTime* r = new svTime(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete $<varList>2;
             $<baseList>$ = l;
             }
         ;


constDecl : Key_PARAMETER localIdentifier ASSIGN NUMBER SEMI
            {  svExprNum<string>* n = new svExprNum<string>(*$<name>4);
               svExprConst* c = new svExprConst(*$<name>2, n);
               delete $<name>2;
               delete $<name>4;

               vector<svBase*>* l = new vector<svBase*>();
               l->push_back(c);
               $<baseList>$ = l;
            }
          ;

assignStmt : Key_ASSIGN assignExprList SEMI
             { 
               svContAssign* c = new svContAssign(static_cast<svAssignExpr*>$<expr>2);
               $<base>$ = c;
             }
           ;

blkAssignStmt : assignExprList SEMI
                   {  $<base>$ = $<expr>1; }
                 ;

nonblkAssignStmt : exprVar LE cExpression SEMI //Moumita
                   { 
                     svNonBlkAssignExpr* s = new svNonBlkAssignExpr($<expr>1, static_cast<svExprBase*>($<expr>3));
                     $<base>$ = s;
                   }
;
assignExprList : assignExprList COMMA assignExpr
                 { svAssignCombo& r = *(static_cast<svAssignCombo*>($<expr>3));
                   static_cast<svAssignCombo*>($<expr>1)->append(r);
                   $<expr>$ = $<expr>1;
                 }
               | assignExpr
                 {  $<expr>$ = $<expr>1; }
               ;

assignExpr : localIdList ASSIGN cExpression
             {  vector<string>::const_iterator it = $<idList>1->begin();
                svExprVar* var = new svExprVar(*it); ++it;
                svExprVarConcat* varConcat = new svExprVarConcat(var);
                for(; it != $<idList>1->end(); ++it)
                {
                    svExprVar* var = new svExprVar(*it);
                    varConcat->append(var);
                }
                delete $<idList>1;

                svAssignExpr* s = new svAssignExpr(
                   varConcat, dynamic_cast<svExprBase*>($<expr>3));

                svAssignCombo* C = new svAssignCombo(s);

                $<expr>$ = C;
              }
           ;

localIdList : localIdentifier
               { $<idList>$ = new vector<string>();
                 $<idList>$->push_back(*$<name>1);
                 delete $<name>1;
               }
            | LCURLY lIdList RCURLY
              { $<idList>$ = $<idList>2; }
            ;

lIdList : lIdList COMMA localIdentifier
          { $<idList>1->push_back(*$<name>3);
            delete $<name>3;
            $<idList>$ = $<idList>1;
          }
        | localIdentifier
          { $<idList>$ = new vector<string>();
            $<idList>$->push_back(*$<name>1);
            delete $<name>1;
          }
        ;

instanceStmt : localIdentifier localIdentifier LPAREN modPortAssignList RPAREN SEMI
               {  svExprVar* iVar = new svExprVar(*$<name>2);
                  svInstExpr* instStmt = new svInstExpr(*$<name>1, iVar);
                  for(vector<svBase*>::iterator it = $<baseList>4->begin();
                      it != $<baseList>4->end(); ++it)
                  {
                      svBase* param = (*it); ++it;
                      svBase* port = (*it);
                      instStmt->setPortParamMap(param, port);
                  }

                  $<base>$ = static_cast<svBase*>(instStmt);

                  delete $<name>1;
                  delete $<name>2;
                  delete $<baseList>4;
               }
             ;

modPortAssignList : modPortAssignList COMMA modPortAssign
                    { $<baseList>1->insert($<baseList>1->end(), $<baseList>3->begin(), $<baseList>3->end());
                      delete $<baseList>3;
                      $<baseList>$ = $<baseList>1;
                    }
                  | modPortAssign
                    { $<baseList>$ = $<baseList>1; }
                  ;

modPortAssign : DOT localVar LPAREN localIdentifier RPAREN
                { $<baseList>$ = new vector<svBase*>();
                  $<baseList>$->push_back($<expr>2);
                  $<baseList>$->push_back(new svExprVar(*$<name>4));
                }
              | localVar
                { $<baseList>$ = new vector<svBase*>();
                  $<baseList>$->push_back($<expr>1);
                  $<baseList>$->push_back(NULL);
                }
              ;

localVar : localIdentifier optBitSel
            {  if($<expr>2 == NULL)
               {
                 svExprVar* v = new svExprVar(*$<name>1);
                 $<expr>$ = v;
               }
               else
               {
                 svSelectOp* s = new svSelectOp(*$<name>1, dynamic_cast<svExprBase*>($<expr>2));
                 $<expr>$ = s;
               }
               delete $<name>1;
            }
         ;

variableList : variableList COMMA varWtInit
               { $<varList>1->push_back(*$<var>3);
                 delete $<var>3;
                 $<varList>$ = $<varList>1;
               }
             | varWtInit
               { $<varList>$ = new vector<svDeclBase>();
                 $<varList>$->push_back(*$<var>1);
                 delete $<var>1;
               }
             ;

varWtInit :  variableName ASSIGN cExpression
            { $<var>$ = new svDeclBase(*$<name>1);
              delete $<name>1;
              $<var>$->setInit(dynamic_cast<svExprBase*>($<expr>3));
              $<var>$->setDim(NULL);
            }
            | variableName optRange
            { $<var>$ = new svDeclBase(*$<name>1);
              delete $<name>1;
              $<var>$->setDim($<range>2);
            }
          ;
netItemOrAssignDeclList : netItemAssignDeclList 
			  {
                            $<varList>$ = $<varList>1;
                          }
			  |netItemDeclList
			  {
                            $<varList>$ = $<varList>1;
                          }
;
netItemAssignDeclList : netItemAssignDeclList COMMA netAssignExpr
               { $<varList>1->push_back(*$<var>3);
                 delete $<var>3;
                 $<varList>$ = $<varList>1;
               }
             | netAssignExpr
               { $<varList>$ = new vector<svDeclBase>();
                 $<varList>$->push_back(*$<var>1);
                 delete $<var>1;
               }
             ;

netAssignExpr :  variableName ASSIGN cExpression
            { $<var>$ = new svDeclBase(*$<name>1);
              delete $<name>1;
              $<var>$->setInit(dynamic_cast<svExprBase*>($<expr>3));
            }
          ;
netItemDeclList : netItemDeclList COMMA netIdentifier
               { $<varList>1->push_back(*$<var>3);
                 delete $<var>3;
                 $<varList>$ = $<varList>1;
               }
             | netIdentifier
               { $<varList>$ = new vector<svDeclBase>();
                 $<varList>$->push_back(*$<var>1);
                 delete $<var>1;
               }
             ;

netIdentifier :  variableName optRange
            { $<var>$ = new svDeclBase(*$<name>1);
              delete $<name>1;
              $<var>$->setDim($<range>2);
            }
          ;

alwaysStmt : Key_ALWAYS AT LPAREN sensitivityList RPAREN stmtOrBlock
             {  svAlways * b = new svAlways(*$<sensList>4);
                b->setStmtOrBlock($<base>6);
                delete $<sensList>4;
                $<base>$ = b;
             }
           ;


sensitivityList: sensitivityList BOROP sensitivity
                  {  $<sensList>1->push_back(*$<sens>3);
                     delete $<sens>3;
                     $<sensList>$ = $<sensList>1;
                  }
                 | sensitivityList COMMA sensitivity
                  {  $<sensList>1->push_back(*$<sens>3);
                     delete $<sens>3;
                     $<sensList>$ = $<sensList>1;
                  }
                | sensitivity 
                  {  $<sensList>$ = new vector<svSensitivity>(); 
                     $<sensList>$->push_back(*$<sens>1);
                  }
                ;

sensitivity : STAR { $<sens>$ = new svSensitivity(svSensitivity::eSensType::ALL); }
            | Key_POSEDGE variableName
              { $<sens>$ = new svSensitivity
                    (svSensitivity::eSensType::POSEDGE, *$<name>2);
                delete $<name>2;
              }
            | Key_NEGEDGE variableName
              { $<sens>$ = new svSensitivity
                    (svSensitivity::eSensType::NEGEDGE, *$<name>2);
                delete $<name>2;
              }
            | variableName
              { $<sens>$ = new svSensitivity
                    (svSensitivity::eSensType::NONE, *$<name>1);
                delete $<name>1;
              }
            ;

stmtOrBlock: procStmt
	     {
                $$=$1;
             }
	    |block
	     {
                $$=$1;
             }
;
block : Key_BEGIN procStmtList Key_END
        {  svBlock* b = new svBlock();
           b->add(*$<baseList>2);
           $<base>$ = b;
        }
      ;

stmtList : stmtList stmt
           {  $<baseList>1->push_back($<base>2);
              $<baseList>$ = $<baseList>1;
           }
         | 
           {  $<baseList>$ = new vector<svBase*>();
           }
         ;

procStmtList : procStmtList procStmt
               {  $<baseList>1->push_back($<base>2);
                  $<baseList>$ = $<baseList>1;
               }
             | 
               {  $<baseList>$ = new vector<svBase*>();
               }
             ;
stmt : assignStmt   { $<base>$ = $<base>1; }
     | instanceStmt { $<base>$ = $<base>1; }
     | alwaysStmt   { $<base>$ = $<base>1; }
     ;

procStmt : nonblkAssignStmt { $<base>$ = $<base>1; }
         | blkAssignStmt    { $<base>$ = $<base>1; }
         | instanceStmt     { $<base>$ = $<base>1; }
         | alwaysStmt       { $<base>$ = $<base>1; }
         ;

_placeHolder_ : { $<holder>$ = NULL; }
              ;


//----------------------------------------------------------------------------
// Expressions
//----------------------------------------------------------------------------

cExpression: lExpression QUESTION cExpression COLON cExpression
             { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::CONDITIONAL);
               expr->setChild($<expr>1);
               expr->setChild($<expr>3);
               expr->setChild($<expr>5);
               $<expr>$ = expr;
             }
           | lExpression { $<expr>$ = $<expr>1; }
           ;

lExpression : lExpression LAND redExpression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::LAND);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
            | lExpression LOR  redExpression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::LOR);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
            | redExpression { $<expr>$ = $<expr>1; }
            ;

redExpression : redExpression BAND  relExpression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BAND);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | redExpression BOR   relExpression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BOR);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | redExpression BXOR  relExpression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BXOR);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | redExpression BXNOR relExpression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BXNOR);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | redExpression RNOR  relExpression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::RNOR);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | BNOT  relExpression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BNOT);
                  expr->setChild($<expr>2);
                  $<expr>$ = expr;
                }
              | relExpression { $<expr>$ = $<expr>1; }
              ;

relExpression : relExpression     LT      expression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::LT);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | relExpression     LE      expression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::LE);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | relExpression     GT      expression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::GT);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | relExpression     GE      expression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::GE);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | relExpression    EQUAL    expression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::EQUAL);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | relExpression   NOT_EQ    expression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::NOT_EQ);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | relExpression   EQ_CASE   expression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::EQ_CASE);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | relExpression NOT_EQ_CASE expression { $<expr>$ = NULL; }
                { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::NOT_EQ_CASE);
                  expr->setChild($<expr>1);
                  expr->setChild($<expr>3);
                  $<expr>$ = expr;
                }
              | expression { $<expr>$ = $<expr>1; }
              ;

expression : expression  PLUS term
             { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::PLUS);
               expr->setChild($<expr>1);
               expr->setChild($<expr>3);
               $<expr>$ = expr;
             }
           | expression MINUS term
             { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::MINUS);
               expr->setChild($<expr>1);
               expr->setChild($<expr>3);
               $<expr>$ = expr;
             }
           | expression SL term
             { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::SL);
               expr->setChild($<expr>1);
               expr->setChild($<expr>3);
               $<expr>$ = expr;
             }
           | expression SR term
             { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::SR);
               expr->setChild($<expr>1);
               expr->setChild($<expr>3);
               $<expr>$ = expr;
             }
           | term { $<expr>$ = $<expr>1; }
           ;

term : term STAR factor
       { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::MULT);
         expr->setChild($<expr>1);
         expr->setChild($<expr>3);
         $<expr>$ = expr;
       }
     | term DIV factor
       { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::DIV);
         expr->setChild($<expr>1);
         expr->setChild($<expr>3);
         $<expr>$ = expr;
       }
     | term MOD factor  { $<expr>$ = NULL; }
     | term BNOT factor { $<expr>$ = NULL; }
     | term LNOT factor { $<expr>$ = NULL; }
     | factor { $<expr>$ = $<expr>1; }
     ;

factor : LPAREN cExpression RPAREN { $<expr>$ = $<expr>2; }
       | exprVar { $<expr>$ = $<expr>1; }
       ;

exprVar : NUMBER
          { $<expr>$ = new svExprNum<string>(*$<name>1);
            delete $<name>1;
          }
        | variableName optBitSel
          { $<expr>$ = new svSelectOp(*$<name>1, dynamic_cast<svExprBase*>($<expr>2));
            delete $<name>1;
          }
        ;

optBitSel : { $<expr>$ = NULL; }
          | LBRACK cExpression RBRACK 
          {  
              $<expr>$ = new svRangeExpr($<expr>2, NULL, NOTSET);
              gLineNo = yylineno;
              gColNo = yyColNo;
          }
          | LBRACK cExpression COLON cExpression  RBRACK 
          { 
              $<expr>$ = new svRangeExpr($<expr>2, $<expr>4, ONLYCOLON);
              gLineNo = yylineno;
              gColNo = yyColNo;
          }
          | LBRACK cExpression Key_PLUSCOLON cExpression  RBRACK 
          { 
              $<expr>$ = new svRangeExpr($<expr>2, $<expr>4, PLUSCOLON);
              gLineNo = yylineno;
              gColNo = yyColNo;
          }
          | LBRACK cExpression Key_MINUSCOLON cExpression  RBRACK 
          { 
              $<expr>$ = new svRangeExpr($<expr>2, $<expr>4, MINUSCOLON);
              gLineNo = yylineno;
              gColNo = yyColNo;
          }
 ;

//----------------------------------------------------------------------------
// Identifiers
//----------------------------------------------------------------------------

moduleName      :   localIdentifier { $<name>$ = $<name>1; } ;
portName        :   localIdentifier { $<name>$ = $<name>1; } ;
variableName    :   localIdentifier { $<name>$ = $<name>1; } ;


//----------------------------------------------------------------------------
// General
//----------------------------------------------------------------------------

// identifier : identifierPath { $<name>$ = $<name>1; }
//     ;

// identifierPath  : identifierPath DOT localIdentifier
//           {
//           $<name>$ = new string((*$<name>1) + (*$<name>3));
//           delete $<name>1; delete $<name>3;
//           }
//         | localIdentifier { $<name>$ = $<name>1; }
//         ;

localIdentifier : IDENTIFIER         { $<name>$ = $<name>1; }
                | ESCAPED_IDENTIFIER { $<name>$ = $<name>1; }
                ;

direction : Key_INPUT  { $<direction>$ = svPort::ePortDirection::INPUT;   }
          | Key_INOUT  { $<direction>$ = svPort::ePortDirection::INOUT;   }
          | Key_OUTPUT { $<direction>$ = svPort::ePortDirection::OUTPUT;  }
          ;

optRange : range { $<range>$ = $<range>$; }
         |   { $<range>$ = new svDeclRange(); }
         ;

range : LBRACK cExpression tail_range
        { $<range>$ = new svDeclRange($<expr>2, $<expr>3); }
      ;

tail_range : COLON cExpression RBRACK { $<expr>$ = $<expr>2; }
           | RBRACK { $<expr>$ = NULL; }
           ;

%%

int svParse(const int argc, const char* argv[])
{
  int ret = 0;

  yylineno = yyColNo = 0;

  for (int i = 1; i < argc; i++)
  {
      svFile curFile = _DEFAULTFILE_;
      if(argv[i] == NULL)
      {
          yyin = stdin;
      }
      else
      {
          curFile = svFile(argv[i]);
          yyin = fopen(argv[i], "r");
      }
      
      LexFile = SINGLETON<svRoot>::getInstance().add(curFile);
      
      if (yyin == NULL)
      {
          SVLOG(GEN, ERR) << "Can't open file \"" << argv[i] << "\" to read .... skipping." << endl;
      }
      else
      {
          yylineno = yyColNo = 0;
          if (yyparse() != 0) { ret = 1; break; }
          fclose(yyin);
      }
  }

  yyfinalize();

  return ret;
}

void yyfinalize()
{
}
