%{

// System Headers
#include <map>
#include <cstdlib>
#include <string>

// OM Headers
#include <svRoot.h>

using namespace std;

extern FILE* yyin;
int yylex();
void yyerror(const char*);
void yyfinalize();

map<string, bool> varSymTab;

bool          DEBUG = false;
extern svFile LexFile;    // The corresponding file object under parse
svRoot*       svROOT = NULL;

%}

%union
{
    void*                  holder;    // placeholder for all types of pointer
    string*                name;
    svModule*              mod;
    svPort::ePortDirection direction;
    svPort*                port;
    vector<svPort>*        portList;
    vector<string>*        idList;
}

%token <name>		IDENTIFIER
%token <name>		SYSTEM_TASK_NAME
%token <name>		ESCAPED_IDENTIFIER
%token <name>		STRING

%token			AT
%token			COLON
%token			COMMA
%token			DOT
%token			EQ_CASE
%token			EQUAL
%token			PPATH
%token			ASSIGN
%token			TRIGGER
%token			MINUS
%token			LCURLY
%token			RCURLY
%token			LBRACK
%token			RBRACK
%token			LPAREN
%token			RPAREN
%token			POUND
%token			QUESTION
%token			SEMI
%token			PLUS
%token			NOT_EQ_CASE
%token			NOT_EQ
%token			LNOT
%token			RNOR
%token			RNAND
%token			BNOT
%token			LAND
%token			BAND
%token			LOR
%token			BOR
%token			BXNOR
%token			BXOR
%token			DIV
%token			MOD
%token			LE
%token			SL
%token			LT
%token			GE
%token			SR
%token			GT
%token			FPATH
%token			STAR
%token			DEFINE
%token			ASSIGN
%token			TRIREG
%token			PARSE_ERROR

%token			Key_MODULE
%token			Key_ENDMODULE
%token			Key_REG
%token			Key_INTEGER
%token			Key_REAL
%token			Key_INPUT
%token			Key_INOUT
%token			Key_OUTPUT
%token			Key_DEFINE
%token			Key_INCLUDE


%type <holder>		_placeHolder_
%type <mod>		module
%type <portList>	optPortList
%type <portList>	portList
%type <port>		port
%type <direction>	direction
%type <idList>		variableList
%type <name>		identifier
%type <name>		identifierPath
%type <name>		localIdentifier
%type <name>		moduleName
%type <name>		portName
%type <name>		variableName
%type <name>		udpName
%type <name>		udpInstanceName
%type <name>		eventName
%type <name>		taskName
%type <name>		realIdentifier
%type <name>		memoryName
%type <name>		netIdentifier
%type <name>		functionName
%type <name>		specParamIdentifier
%type <name>		udp_name_of_port
%type <name>		registerName
%type <name>		gateInstanceName
%type <name>		instanceName
%type <name>		blockName
%type <name>		outputTerminalName

%start program

%%

program : descriptionList
        ;

descriptionList : 
                | descriptionList description
		;

description : module
            | udp
	    | directive
            ;

module : _placeHolder_ MODULE moduleName optPortList SEMI
         {
             const string& modName = (*$<name>3);
             $<holder>1 = NULL;
             if (varSymTab.find(modName) == varSymTab.end())
             {
                 varSymTab[modName] = true;
                 $<holder>1 = new svModule(modName);
                 if($<portList>4 != NULL)
                 {
                      // (*((svModule*)$<holder>1)).add(*$<portList>4);
                      for(vector<svPort>::const_iterator it = $<portList>4->begin();
		          it != $<portList>4->end(); it++)
                             ((svModule*)$<holder>1)->add(*it);
                 }
        
                 if (DEBUG)
                 {
                     cout << "> Creating Module: \"" << modName << "\"" << std::endl;
                 }
             }
             else
             {
                 cerr << "Module \""<< modName <<"\" already declared" << std::endl;
             }
        
             delete $<name>3;
         }
         optModuleItemList
         ENDMODULE { svROOT->add(*((svModule*)$<holder>1)); }
       ;

optPortList : { $<portList>$ = NULL; }
            | LPAREN portList RPAREN
               {
                   $<portList>$ = $<portList>2;
               }
            ;

portList :
           { $<portList>$ = NULL; }
         | port
           {
                $<portList>$ = new vector<svPort>();
                $<portList>$->push_back(*$<port>1);
                delete $<port>1;
           }
         | portList COMMA port
           {
                 $<portList>1->push_back(*$<port>3);
                 delete $<port>3;
                 $<portList>$ = $<portList>1;
           }
         ;

port : portName
       {
           $<port>$ = new svPort(*$<name>1);
           delete $<name>1;
       }
     | direction portName
       {
           $<port>$ = new svPort(*$<name>2, $<direction>1);
           delete $<name>2;
       }
     ;


optModItemList : optModItemList modItem
               |
	       ;

modItem : parameterDecl
        | portDecl
        | netDecl
        | regDecl
        | integerDecl
        | realDecl
        | instantiation
        | continuousAssign
        ;

portDecl : direction optRange portList SEMI
           {
              vector<svPort> l = new vector<svPort>();
	      for(vector<string>::iterator it = $<idList>3->begin();
	           it != $<idList>3->end(); ++it)
	      {
	          l->push_back(svPort(*it, $<direction>3));
	      }
	      delete $<string>3;
	      $<idList>$ = l;
	   }
         ;

portList : portList COMMA portName
            { $<idList>1.push_back(*$<name>3);
              delete $<name>3;
            }
          | portName
            { $<idList>$ = new vector<string>(); 
              $<idList>$.push_back(*$<name>1);
              delete $<name>1;
            }
          ;

regDecl : Key_REG optRange regVariableList SEMI
        ;

optRange : range
         |
	 ;

range : LBRACK expression tail_range
      ;

tail_range : COLON expression RBRACK
           | RBRACK
	   ;

integerDecl : Key_INTEGER regVariableList SEMI
            ;

realDecl : Key_REAL variableList SEMI
         ;

instantiation:
	module_instantiation |
	udp_instantiation
	;

_placeHolder_ : { $<holder>$ = NULL; } ;


//----------------------------------------------------------------------------
// UDP specs
//----------------------------------------------------------------------------

udp :
        'primitive' udpName
	LPAREN variableName ( COMMA variableName )* RPAREN SEMI
        (udp_declaration)+
	(udp_initial_statement)?
	table_definition
        'endprimitive'
        ;

udp_port_list :
        udp_name_of_port ( COMMA udp_name_of_port )*
        ;

udp_declaration :
        output_declaration |
        input_declaration |
        regDecl
        ;

udp_initial_statement :
        'initial' outputTerminalName ASSIGN init_val SEMI
        ;

   // Use a semantic predicate to determine whether a matched NUMBER
   // is a valid special value in the given context.
   // This kludge avoids having the special values in the Literals table,
   // thus avoiding a lexical conflict.
init_val :
        '1\'b0' |
        '1\'b1' |
        '1\'bx' |
	n=NUMBER
	{ $n.text=="0" || $n.text=="1"}?
	;

table_definition :
        'table' table_entries 'endtable'
        ;

   // Don't try to parse table entries; just collect them.
   // There are ambiguities between edge_symbol and level_symbol,
   // and textbook Verilog examples don't seem to follow rules
   // completely. For example,
   //	'0    00    :    0;'
   // doesn't match grammar because of '00', but is frequently used.
table_entries :
	//(sequential_entry) => (sequential_entry)+ |
	//(combinational_entry)+
	(( ~(SEMI | 'endtable') )+ SEMI)*
	;


task :
        'task' taskName SEMI
        (tf_declaration)*
        statement_or_null
        'endtask'
        ;

function :
        'function' (range_or_type)? functionName SEMI
        (tf_declaration)+
        statement
        'endfunction'
        ;

range_or_type :
        range |
        'integer' |
        'real'
        ;

tf_declaration :
        parameter_declaration |
        output_declaration |
        input_declaration |
        inout_declaration |
        regDecl |
        time_declaration |
        integerDecl |
        realDecl |
        event_declaration 
        ;


//----------------------------------------------------------------------------
// Declarations
//----------------------------------------------------------------------------

parameter_declaration :
        Key_PARAMETER optRange paramAssignmentList SEMI
        ;

paramAssignmentList :
          paramAssignment COMMA param_assignment
	|
        ;

param_assignment :
        identifier ASSIGN expression
        ;

input_declaration :
        'input' (range)? list_of_variables SEMI
        ;

output_declaration :
        'output' (range)? list_of_variables SEMI
        ;

inout_declaration :
        'inout' (range)? list_of_variables SEMI
        ;

netDecl :
        ( net_type (expandrange)? ) =>
        net_type (expandrange)? (delay)?
           list_of_assigned_variables SEMI |
        KW_TRIREG (charge_strength)? (expandrange)? (delay)?
           list_of_variables SEMI
        ;

net_type :
        'wire' | 
        'tri' |
        'tri1' |
        'supply0' |
        'wand' |
        'triand' |
        'tri0' |
        'supply1' |
        'wor' |
        'trior' |
	    KW_TRIREG
        ;

expandrange :
        'scalared' range |
	'vectored' range |
	range
        ;

time_declaration :
        'time' regVariableList SEMI
        ;

event_declaration :
        'event' eventName ( COMMA eventName )* SEMI
        ;

continuousAssign :
        KW_ASSIGN (drive_strength)? (delay)? list_of_assignments SEMI |
        net_type (drive_strength)? (expandrange)? (delay)?
           list_of_assignments SEMI
        ;

parameter_override :
        'defparam' list_of_param_assignments SEMI
        ;

list_of_variables :
        variableName ( COMMA variableName )*
        ;

list_of_assigned_variables :
        variableName ( ASSIGN expression )?
	( COMMA variableName ( ASSIGN expression )? )*
        ;

regVariableList : regVariable
                | regVariableList COMMA regVariable
                ;

regVariable : registerName
            | memoryName LBRACK expression COLON expression RBRACK
            ;

charge_strength :
        LPAREN 'small'  RPAREN |
        LPAREN 'medium' RPAREN |
        LPAREN 'large'  RPAREN
        ;

drive_strength :
        LPAREN strength0 COMMA strength1 RPAREN |
        LPAREN strength1 COMMA strength0 RPAREN
        ;

strength0 :
        'supply0' |
        'strong0' |
        'pull0' |
        'weak0' |
	'highz0'
        ;

strength1 :
        'supply1' |
        'strong1' |
        'pull1' |
        'weak1' |
	'highz1'
        ;


list_of_assignments :
        assignment ( COMMA assignment )*
        ;


//----------------------------------------------------------------------------
// Primitive Instances
//----------------------------------------------------------------------------

gate_declaration :
	gate_type (drive_strength)? (delay)?
          gate_instance ( COMMA gate_instance )* SEMI
	;

gate_type :
        'and' |
        'nand' |
        'or' |
        'nor' |
        'xor' |
        'xnor' |
        'buf' |
        'bufif0' |
        'bufif1' |
        'not' |
        'notif0' |
        'notif1' |
        'pulldown' |
        'pullup' |
        'nmos' |
        'rnmos' |
        'pmos' |
        'rpmos' |
        'cmos' |
        'rcmos' |
        'tran' |
        'rtran' |
        'tranif0' |
        'rtranif0' |
        'tranif1' |
        'rtranif1'
        ;

delay :
        POUND NUMBER | 
	POUND identifier |
        POUND LPAREN mintypmax_expression
	        ( COMMA mintypmax_expression
		  ( COMMA mintypmax_expression )?
		)?
	      RPAREN
        ;

gate_instance :
        (gateInstanceName)?
	LPAREN terminal ( COMMA terminal )* RPAREN
        ;

udp_instantiation :
	udpName (drive_strength)? (delay)?
          udp_instance ( COMMA udp_instance )* SEMI
	;

udp_instance :
        (udpInstanceName)?
	LPAREN terminal ( COMMA terminal )* RPAREN
        ;

terminal :
        expression
   // | IDENTIFIER
        ;

//----------------------------------------------------------------------------
// Module Instantiations
//----------------------------------------------------------------------------

module_instantiation :
        moduleName (parameter_value_assignment)?
        module_instance ( COMMA module_instance )* SEMI
        ;

parameter_value_assignment :
        POUND LPAREN expression ( COMMA expression )* RPAREN
        ;

module_instance :
        instanceName LPAREN list_of_module_connections RPAREN
        ;

list_of_module_connections :
        module_port_connection ( COMMA module_port_connection )* |
        named_port_connection ( COMMA named_port_connection )*
        ;

module_port_connection :
        expression |
	// NULL
        ;

	// expression below isn't optional according to Palnitkar, but
	// several examples generated by Cadence use this syntax.
named_port_connection :
        DOT IDENTIFIER LPAREN (expression)? RPAREN
        ;

//----------------------------------------------------------------------------
// Behavioral Statements
//----------------------------------------------------------------------------

initial_statement :
        'initial' statement
        ;

always_statement :
        'always' statement
        ;

statement_or_null :
        (statement) => statement |
	SEMI
        ;

statement :
        (lvalue ASSIGN) => blocking_assignment SEMI |
        (lvalue LE) => non_blocking_assignment SEMI |
        conditional_statement |
        case_statement |
        loop_statement |
        procedural_timing_control_statement |
        wait_statement |
        event_trigger |
        seq_block |
        par_block |
        task_enable |
        system_task_enable |
        disable_statement |
        procedural_continuous_assignment
        ;

assignment :
        lvalue ASSIGN expression
        ;

blocking_assignment :
        lvalue ASSIGN ( delay_or_event_control )?  expression
        ;

non_blocking_assignment :
        lvalue LE ( delay_or_event_control )?  expression
        ;

	  // 'else' clause is inherently ambiguous; ANTLR gets it right,
	  // so suppress warning.
conditional_statement :
        'if' LPAREN expression RPAREN statement_or_null
        ( : 'else' statement_or_null)?
        ;

case_statement :
        case_keyword LPAREN expression RPAREN (case_item)+ 'endcase'
        ;

case_keyword :
        'case' | 'casez' | 'casex'
        ;

case_item :
        expression ( COMMA expression )* COLON statement_or_null |
        'default' (COLON)? statement_or_null
        ;

loop_statement :
        'forever' statement |
        'repeat' LPAREN expression RPAREN statement |
        'while' LPAREN expression RPAREN statement |
        'for' LPAREN assignment SEMI expression SEMI assignment RPAREN statement
        ;

procedural_timing_control_statement :
        delay_or_event_control statement_or_null
        ;

wait_statement :
        'wait' LPAREN expression RPAREN statement_or_null
        ;

event_trigger :
        TRIGGER eventName SEMI
        ;

disable_statement :
        'disable' IDENTIFIER SEMI
        ;

seq_block :
        'begin'
        ( COLON blockName (block_declaration)* )?
        (statement)*
	'end'
	;

par_block :
        'fork'
        ( COLON blockName (block_declaration)* )?
        (statement)*
	'join'
        ;

block_declaration :
        parameter_declaration |
        regDecl |
        integerDecl |
        realDecl |
        time_declaration |
        event_declaration 
        ;

task_enable :
        taskName ( LPAREN expression (COMMA (expression)?)* RPAREN )?
	SEMI
        ;

system_task_enable :
        SYSTEM_TASK_NAME ( LPAREN expression (COMMA (expression)?)* RPAREN )?
	SEMI
        ;

procedural_continuous_assignment :
        KW_ASSIGN assignment SEMI |
        'deassign' lvalue SEMI |
        'force' assignment SEMI |
        'release' lvalue SEMI
        ;

delay_or_event_control :
        delay_control |
        event_control
        ;

//----------------------------------------------------------------------------
// Specify Section
//----------------------------------------------------------------------------

specify_block :
        'specify' (specify_item)* 'endspecify'
        ;

specify_item :
        spec_param_declaration |
        (path_declaration) => path_declaration |
        system_timing_check
        | sdpd
        ;

spec_param_declaration :
        'specparam' list_of_specparam_assignments SEMI
        ;

list_of_specparam_assignments :
        specparam_assignment ( COMMA specparam_assignment )*
        ;

specparam_assignment :
        identifier ASSIGN expression
        ;

path_declaration :
        (simple_path_declaration) =>
	   simple_path_declaration SEMI |
        (level_sensitive_path_declaration) =>
	   level_sensitive_path_declaration SEMI |
        edge_sensitive_path_declaration SEMI
        ;

simple_path_declaration :
        (parallel_path_description) =>
	   parallel_path_description ASSIGN path_delay_value |
        full_path_descriptor ASSIGN path_delay_value
        ;

parallel_path_description :
        LPAREN specify_terminal_descriptor PPATH specify_terminal_descriptor RPAREN
        ;

full_path_descriptor :
        LPAREN list_of_path_terminals  FPATH list_of_path_terminals RPAREN
        ;

list_of_path_terminals :
        specify_terminal_descriptor ( COMMA specify_terminal_descriptor )*
        ;

specify_terminal_descriptor :
	(identifier LBRACK expression COLON) =>
           identifier LBRACK expression COLON expression RBRACK |
        (identifier LBRACK) =>
           identifier LBRACK expression RBRACK |
        identifier
        ;

path_delay_value :
        (path_delay_expression) => path_delay_expression |
        LPAREN list_of_path_delay_expressions RPAREN
        ;

list_of_path_delay_expressions :
        path_delay_expression COMMA path_delay_expression
	  ( COMMA path_delay_expression
	    ( COMMA path_delay_expression COMMA
              path_delay_expression COMMA path_delay_expression )? )?
        ; 

path_delay_expression :
        mintypmax_expression
        ;

system_timing_check :
        '$setup' LPAREN timing_check_event COMMA timing_check_event COMMA
            timing_check_limit ( COMMA notify_register )? RPAREN SEMI |
        '$hold' LPAREN timing_check_event COMMA timing_check_event COMMA
            timing_check_limit ( COMMA notify_register )? RPAREN SEMI |
        '$period' LPAREN controlled_timing_check_event COMMA
            timing_check_limit ( COMMA notify_register )? RPAREN SEMI |
        '$width' LPAREN controlled_timing_check_event COMMA
            timing_check_limit ( COMMA expression COMMA notify_register )?
	    RPAREN SEMI |
        '$skew' LPAREN timing_check_event COMMA timing_check_event COMMA 
            timing_check_limit ( COMMA notify_register )? RPAREN SEMI |
        '$recovery' LPAREN controlled_timing_check_event COMMA
            timing_check_event COMMA timing_check_limit
            ( COMMA notify_register )? RPAREN SEMI |
        '$setuphold' LPAREN timing_check_event COMMA timing_check_event COMMA
            timing_check_limit COMMA timing_check_limit
            ( COMMA notify_register )? RPAREN SEMI
        ;

timing_check_event :
        (timing_check_event_control)? specify_terminal_descriptor
        ( '&&&' timing_check_condition )?
        ;

controlled_timing_check_event :
        timing_check_event_control specify_terminal_descriptor
        ( '&&&' timing_check_condition )?
        ;

timing_check_event_control :
        'posedge' |
        'negedge' |
        edge_control_specifier
        ;

edge_control_specifier :
        'edge' LBRACK edge_descriptor ( COMMA edge_descriptor )* RBRACK
        ;

   // Use semantic predicates to determine whether a matched
   // NUMBER or IDENTIFIER is a valid special value in the given context.
   // This kludge avoids having the special values in the Literals table,
   // thus avoiding a lexical conflict.
edge_descriptor :
	'0x' | '1x'
      |
	n=NUMBER
	{ $n.text=="01" || $n.text=="10"}?
      |
	i=IDENTIFIER
	{ $i.text=="x1" || $i.text=="x0"}?
	;

timing_check_condition :
        scalar_timing_check_condition
        ; 
scalar_timing_check_condition :
        expression
        ;

timing_check_limit :
        expression
        ;

notify_register :
        registerName
        ;

level_sensitive_path_declaration :
	(parallel_level_sensitive_path_description) =>
	parallel_level_sensitive_path_description
	     ASSIGN path_delay_value SEMI
      |
	full_level_sensitive_path_description
	     ASSIGN path_delay_value SEMI
        ;

parallel_level_sensitive_path_description :
        'if' LPAREN expression RPAREN
	   LPAREN specify_terminal_descriptor (polarity_operator)?
	          PPATH specify_terminal_descriptor RPAREN
	;

full_level_sensitive_path_description :
        'if' LPAREN expression RPAREN
	   LPAREN list_of_path_terminals (polarity_operator)?
	          FPATH list_of_path_terminals RPAREN
	;

polarity_operator :
	PLUS |
	MINUS
	;

edge_sensitive_path_declaration :
	( 'if' LPAREN expression RPAREN )?
        LPAREN (edge_identifier)? specify_terminal_descriptor
	   ( PPATH | FPATH )
	   LPAREN ( (list_of_path_terminals) => list_of_path_terminals |
	            specify_terminal_descriptor )
	      (polarity_operator)? COLON data_source_expression
	   RPAREN
	RPAREN
	ASSIGN path_delay_value SEMI
        ;

data_source_expression :
        expression
        ;

edge_identifier :
        'posedge' |
        'negedge'
        ;

sdpd :
	'if' LPAREN expression RPAREN
	simple_path_declaration
	SEMI
	;

//----------------------------------------------------------------------------
// Expressions
//----------------------------------------------------------------------------

lvalue :
	(identifier range) =>
        identifier range |
        identifier |
        concatenation
        ;

concatenation :
	(LCURLY expression LCURLY) =>
        LCURLY expression
	       LCURLY expression ( COMMA expression )* RCURLY RCURLY |
        LCURLY expression ( COMMA expression )* RCURLY
        ;

mintypmax_expression :
        expression ( COLON expression COLON expression )?
        ;

exp11 :
        STRING |
	NUMBER |
	(function_call) => function_call |
	lvalue |
	DEFINE
        ;

exp10 :
        exp11 | LPAREN expression RPAREN
        ;

exp9 :
        exp10 | unary_operator exp9
        ;

exp8 :
        exp9 ( binary_operator exp9 )*
        ;

exp7 :
        exp8 ( QUESTION exp7 COLON exp7 )?
        ;

exp0 :
        exp7
        ;

expression :
        exp0
        ;

function_call :
        functionName LPAREN expression_list RPAREN |
        SYSTEM_TASK_NAME ( LPAREN expression_list RPAREN )?
        ;

expression_list :
        expression ( COMMA expression )*
        ;

unary_operator :
        PLUS   |
        MINUS  |
        LNOT   |
        BNOT   |
        BAND   |
        RNAND  |
        BOR    |
        RNOR   |
        BXOR   |
        BXNOR 
        ;

binary_operator :
        PLUS        |
        MINUS       |
        STAR        |
        DIV         |
        MOD         |
        EQUAL       |
        NOT_EQ      |
        EQ_CASE     |
        NOT_EQ_CASE |
        LAND        |
        LOR         |
        LT          |
        LE          |
        GT          |
        GE          |
        BAND        |
        BOR         |
        BXOR        |
        BXNOR       |
        SR          |
        SL 
        ;


KW_ASSIGN	:	'assign'				;
KW_TRIREG	:	'trireg'				;

//----------------------------------------------------------------------------
// Identifiers
//----------------------------------------------------------------------------

moduleName :                localIdentifier { $<name>$ = $<name>1; } ;
portName :                  localIdentifier { $<name>$ = $<name>1; } ;
variableName :              localIdentifier { $<name>$ = $<name>1; } ;
udpName :                   localIdentifier { $<name>$ = $<name>1; } ;
udpInstanceName :           localIdentifier { $<name>$ = $<name>1; } ;
eventName :                 localIdentifier { $<name>$ = $<name>1; } ;
taskName :                  localIdentifier { $<name>$ = $<name>1; } ;
realIdentifier :            identifier       { $<name>$ = $<name>1; } ;
memoryName :                localIdentifier { $<name>$ = $<name>1; } ;
netIdentifier :             identifier       { $<name>$ = $<name>1; } ;
functionName :              localIdentifier { $<name>$ = $<name>1; } ;
specParamIdentifier :       identifier       { $<name>$ = $<name>1; } ;
udp_name_of_port :          identifier       { $<name>$ = $<name>1; } ;
registerName :              localIdentifier { $<name>$ = $<name>1; } ;
gateInstanceName :          localIdentifier { $<name>$ = $<name>1; } ;
instanceName :              localIdentifier { $<name>$ = $<name>1; } ;
blockName :                 localIdentifier { $<name>$ = $<name>1; } ;
outputTerminalName :        localIdentifier { $<name>$ = $<name>1; } ;


//----------------------------------------------------------------------------
// General
//----------------------------------------------------------------------------

identifier : identifierPath { $<name>$ = $<name>1; }
           ;

identifierPath  : identifierPath DOT localIdentifier
                  {
		    $<name>$ = new string((*$<name>1) + (*$<name>3));
		    delete $<name>1; delete $<name>3;
		  }
	        | localIdentifier { $<name>$ = $<name>1; }
		| { $<name>$ = NULL; }
                ;

localIdentifier : IDENTIFIER         { $<name>$ = $<name>1; }
                | ESCAPED_IDENTIFIER { $<name>$ = $<name>1; }
                ;

direction : INPUT  { $<direction>$ = svPort::ePortDirection::INPUT;   }
          | INOUT  { $<direction>$ = svPort::ePortDirection::INOUT;   }
          | OUTPUT { $<direction>$ = svPort::ePortDirection::OUTPUT;  }
          ;

delay_control :
        POUND NUMBER |
        POUND identifier |
        POUND LPAREN mintypmax_expression RPAREN
        ;

event_control :
        AT identifier |
        AT LPAREN event_expression RPAREN
        ;

event_expression :
        sub_event_expression ( 'or' sub_event_expression )*
        ;

sub_event_expression :
        expression |
        'posedge' expression |
        'negedge' expression
        ;

//----------------------------------------------------------------------------
// Compiler directives
//----------------------------------------------------------------------------

directive:
	define_directive |
	include_directive
	;

define_directive : Key_DEFINE IDENTIFIER expression
	         ;

include_directive : Key_INCLUDE ( identifier | STRING )
	          ;

%%

int svParse(const int argc, const char* argv[])
{
    int ret = 0;

    svROOT = new svRoot();

    for (int i = 1; i < argc; i++)
    {
        if(argv[i] == NULL)
        {
            LexFile = svFile("<<STDIN>>");
            yyin = stdin;
        }
        else
        {
            LexFile = svFile(argv[i]);
            yyin = fopen(argv[i], "r");
        }

        svROOT->add(LexFile);

        if (yyin == NULL)
        {
            cout << "Error: Can't open file \"" << argv[i] << "\" ..." << endl;
        }

        if (yyparse() != 0) { ret = 1; break; }

        fclose(yyin);
    }

    yyfinalize();

    return ret;
}

void yyfinalize()
{
    varSymTab.clear();
}
