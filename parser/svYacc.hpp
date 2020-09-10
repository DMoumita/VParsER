/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SVYACC_HPP_INCLUDED
# define YY_YY_SVYACC_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    SYSTEM_TASK_NAME = 259,
    ESCAPED_IDENTIFIER = 260,
    STRING = 261,
    NUMBER = 262,
    AT = 263,
    COLON = 264,
    COMMA = 265,
    DOT = 266,
    EQ_CASE = 267,
    EQUAL = 268,
    PPATH = 269,
    ASSIGN = 270,
    TRIGGER = 271,
    MINUS = 272,
    LCURLY = 273,
    RCURLY = 274,
    LBRACK = 275,
    RBRACK = 276,
    LPAREN = 277,
    RPAREN = 278,
    POUND = 279,
    QUESTION = 280,
    SEMI = 281,
    PLUS = 282,
    NOT_EQ_CASE = 283,
    NOT_EQ = 284,
    LNOT = 285,
    RNOR = 286,
    RNAND = 287,
    BNOT = 288,
    LAND = 289,
    BAND = 290,
    LOR = 291,
    BOR = 292,
    BXNOR = 293,
    BXOR = 294,
    DIV = 295,
    MOD = 296,
    LE = 297,
    SL = 298,
    LT = 299,
    GE = 300,
    SR = 301,
    GT = 302,
    FPATH = 303,
    STAR = 304,
    DEFINE = 305,
    PARSE_ERROR = 306,
    BOROP = 307,
    SIGNED = 308,
    VECTORED = 309,
    SCALARED = 310,
    Key_ASSIGN = 311,
    Key_ALWAYS = 312,
    Key_BEGIN = 313,
    Key_DEFINE = 314,
    Key_END = 315,
    Key_ENDMODULE = 316,
    Key_INTEGER = 317,
    Key_INCLUDE = 318,
    Key_INOUT = 319,
    Key_INPUT = 320,
    Key_MODULE = 321,
    Key_NEGEDGE = 322,
    Key_OUTPUT = 323,
    Key_PARAMETER = 324,
    Key_POSEDGE = 325,
    Key_PULL0 = 326,
    Key_PULL1 = 327,
    Key_SUPPLY0 = 328,
    Key_SUPPLY1 = 329,
    Key_WEAK0 = 330,
    Key_WEAK1 = 331,
    Key_REAL = 332,
    Key_REG = 333,
    Key_TIME = 334,
    Key_REALTIME = 335,
    Key_STRONG0 = 336,
    Key_STRONG1 = 337,
    Key_TRIREG = 338,
    Key_WIRE = 339,
    Key_UWIRE = 340,
    Key_WAND = 341,
    Key_WOR = 342,
    Key_TRI = 343,
    Key_TRIAND = 344,
    Key_TRIOR = 345,
    Key_TRI0 = 346,
    Key_TRI1 = 347,
    Key_HIGHZ0 = 348,
    Key_HIGHZ1 = 349
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
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


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SVYACC_HPP_INCLUDED  */
