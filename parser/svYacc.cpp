/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */



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

using namespace std;

extern char*                        yytext;
extern double                       yyColNo, yylineno;
extern FILE*                        yyin;

int                                 yylex();
void                                yyerror(const char*);
void                                yyfinalize();

extern svFile _DEFAULTFILE_;
extern svFile& LexFile;  // The corresponding file object under parse




# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "svYacc.hpp".  */
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

/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  375

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   244,   244,   247,   248,   251,   255,   283,   254,   317,
     318,   319,   323,   327,   333,   337,   343,   361,   364,   365,
     366,   368,   369,   370,   371,   372,   373,   376,   390,   404,
     418,   422,   428,   432,   436,   440,   444,   448,   452,   456,
     460,   464,   468,   472,   476,   480,   482,   484,   486,   504,
     530,   549,   574,   607,   635,   639,   644,   650,   657,   666,
     671,   677,   687,   691,   697,   701,   706,   710,   714,   718,
     722,   726,   730,   734,   738,   742,   746,   750,   757,   764,
     770,   776,   782,   788,   797,   801,   805,   809,   815,   819,
     823,   827,   832,   847,   850,   866,   880,   893,   907,   922,
     934,   941,   945,   951,   956,   960,   980,   985,   989,   994,
    1001,  1020,  1025,  1029,  1034,  1041,  1056,  1061,  1068,  1074,
    1080,  1084,  1089,  1094,  1101,  1107,  1112,  1119,  1126,  1135,
    1140,  1145,  1151,  1152,  1157,  1162,  1169,  1173,  1178,  1185,
    1190,  1194,  1199,  1202,  1203,  1204,  1207,  1208,  1209,  1210,
    1213,  1221,  1228,  1231,  1231,  1237,  1237,  1243,  1246,  1246,
    1252,  1252,  1258,  1258,  1264,  1264,  1270,  1270,  1276,  1276,
    1281,  1284,  1284,  1290,  1290,  1296,  1296,  1302,  1302,  1308,
    1308,  1314,  1314,  1320,  1320,  1326,  1326,  1332,  1335,  1341,
    1347,  1353,  1359,  1362,  1368,  1374,  1375,  1376,  1377,  1380,
    1381,  1384,  1388,  1394,  1395,  1402,  1403,  1404,  1422,  1423,
    1426,  1427,  1428,  1431,  1432,  1435,  1439,  1440
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "SYSTEM_TASK_NAME",
  "ESCAPED_IDENTIFIER", "STRING", "NUMBER", "AT", "COLON", "COMMA", "DOT",
  "EQ_CASE", "EQUAL", "PPATH", "ASSIGN", "TRIGGER", "MINUS", "LCURLY",
  "RCURLY", "LBRACK", "RBRACK", "LPAREN", "RPAREN", "POUND", "QUESTION",
  "SEMI", "PLUS", "NOT_EQ_CASE", "NOT_EQ", "LNOT", "RNOR", "RNAND", "BNOT",
  "LAND", "BAND", "LOR", "BOR", "BXNOR", "BXOR", "DIV", "MOD", "LE", "SL",
  "LT", "GE", "SR", "GT", "FPATH", "STAR", "DEFINE", "PARSE_ERROR",
  "BOROP", "SIGNED", "VECTORED", "SCALARED", "Key_ASSIGN", "Key_ALWAYS",
  "Key_BEGIN", "Key_DEFINE", "Key_END", "Key_ENDMODULE", "Key_INTEGER",
  "Key_INCLUDE", "Key_INOUT", "Key_INPUT", "Key_MODULE", "Key_NEGEDGE",
  "Key_OUTPUT", "Key_PARAMETER", "Key_POSEDGE", "Key_PULL0", "Key_PULL1",
  "Key_SUPPLY0", "Key_SUPPLY1", "Key_WEAK0", "Key_WEAK1", "Key_REAL",
  "Key_REG", "Key_TIME", "Key_REALTIME", "Key_STRONG0", "Key_STRONG1",
  "Key_TRIREG", "Key_WIRE", "Key_UWIRE", "Key_WAND", "Key_WOR", "Key_TRI",
  "Key_TRIAND", "Key_TRIOR", "Key_TRI0", "Key_TRI1", "Key_HIGHZ0",
  "Key_HIGHZ1", "$accept", "program", "descriptionList", "description",
  "module", "$@1", "$@2", "optModPortList", "modPortList", "modPortName",
  "optModuleItemList", "modItem", "portDecl", "outputVariable",
  "portTypeDeclOrNull", "rangeOrNull", "netDecl", "delayOrNull", "delay1",
  "delay2", "minTypMaxExpr", "vectoredOrScalared", "netTypeDecl",
  "strengthList", "strength0", "strength1", "regDecl", "signedOrNull",
  "integerDecl", "realDecl", "realTimeDecl", "timeDecl", "constDecl",
  "assignStmt", "blkAssignStmt", "nonblkAssignStmt", "assignExprList",
  "assignExpr", "localIdList", "lIdList", "instanceStmt",
  "modPortAssignList", "modPortAssign", "localVar", "variableList",
  "varWtInit", "netItemOrAssignDeclList", "netItemAssignDeclList",
  "netAssignExpr", "netItemDeclList", "netIdentifier", "alwaysStmt",
  "sensitivityList", "sensitivity", "stmtOrBlock", "block", "stmtList",
  "procStmtList", "stmt", "procStmt", "_placeHolder_", "cExpression",
  "lExpression", "@3", "@4", "redExpression", "@5", "@6", "@7", "@8", "@9",
  "@10", "relExpression", "@11", "@12", "@13", "@14", "@15", "@16", "@17",
  "@18", "expression", "term", "factor", "exprVar", "optBitSel",
  "moduleName", "portName", "variableName", "localIdentifier", "direction",
  "optRange", "range", "tail_range", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349
};
# endif

#define YYPACT_NINF -299

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-299)))

#define YYTABLE_NINF -151

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -299,    27,   -23,  -299,  -299,  -299,   -20,   333,  -299,  -299,
      35,  -299,    29,    74,  -299,  -299,  -299,  -299,    68,  -299,
    -299,  -299,   333,  -299,    34,  -299,  -299,  -299,  -299,   165,
     333,   136,   333,  -299,  -299,   333,     7,   333,   333,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,    43,
    -299,  -299,  -299,    61,  -299,  -299,  -299,  -299,  -299,  -299,
      23,   190,    44,  -299,    81,  -299,  -299,     7,  -299,   333,
     103,   123,  -299,   104,   132,   137,  -299,   112,  -299,  -299,
       7,   280,     9,   282,   143,  -299,  -299,  -299,  -299,   333,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,     7,   333,  -299,   124,   124,  -299,  -299,
     104,   164,   127,  -299,   333,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,   134,   158,   162,   179,   104,
       7,     9,   100,   333,  -299,  -299,   183,   333,   166,  -299,
     167,  -299,   178,   209,   104,  -299,  -299,   124,    33,  -299,
     263,   272,   108,   118,   126,  -299,  -299,   208,    47,   333,
    -299,  -299,   220,   170,   219,   221,    97,   128,   183,   104,
     333,   183,  -299,  -299,   124,   232,   225,  -299,   262,  -299,
     306,   333,   129,  -299,   282,  -299,   124,    18,   301,   333,
     243,   108,   124,   124,   124,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,   124,  -299,   124,
    -299,  -299,   185,  -299,  -299,   266,   267,   275,   304,   321,
     322,   333,   183,   206,   332,   333,   115,   340,  -299,   333,
     333,   124,  -299,   324,   333,  -299,  -299,  -299,  -299,   333,
     333,    38,  -299,  -299,   333,   155,  -299,  -299,   208,   210,
    -299,  -299,   342,   272,   272,   108,   108,   108,   108,   108,
     118,   118,   118,   118,   118,   118,   118,   118,   126,   126,
     126,   126,  -299,  -299,  -299,  -299,  -299,   331,   334,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,   327,   333,  -299,   214,
     124,  -299,   124,  -299,  -299,   104,  -299,  -299,  -299,  -299,
    -299,    18,    17,    18,   335,   301,   328,  -299,  -299,   124,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,   215,  -299,
     187,   349,  -299,  -299,  -299,  -299,   257,  -299,  -299,  -299,
    -299,  -299,   317,   256,  -299,   333,  -299,  -299,  -299,  -299,
     124,  -299,   124,    66,  -299,   124,   337,   338,  -299,  -299,
    -299,   336,  -299,  -299,  -299
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     3,     5,     0,     0,   208,   209,
       9,   205,     0,     0,    10,   211,   210,   212,     0,    13,
      15,   206,     0,     6,     0,    11,    14,    17,    12,   140,
       0,   212,     0,    75,    76,     0,    94,     0,     0,    77,
      66,    67,    68,    69,    70,    73,    74,    71,    72,     0,
      16,    18,    19,    94,    20,    21,    22,    25,    26,    23,
      24,    45,     0,   117,   214,   207,    31,    94,    30,     0,
       0,     0,    93,   214,     0,     0,     8,     0,    64,    65,
      94,    94,    56,     0,     0,   143,   144,   145,   139,     0,
      41,    42,    44,    43,    32,    33,    34,    35,    36,    39,
      40,    37,    38,    94,     0,    95,     0,     0,   119,   213,
      47,     0,     0,    96,     0,    98,    97,    86,    90,    85,
      89,    87,    91,    84,    88,     0,     0,     0,     0,     0,
      94,    56,     0,     0,    54,    55,    56,     0,     0,   104,
       0,   106,     0,     0,    47,   116,   201,     0,     0,   118,
     152,   157,   170,   187,   192,   198,   200,   203,     0,     0,
      46,    29,     0,     0,     0,     0,     0,     0,    56,     0,
       0,    56,    58,    57,     0,     0,   120,   123,   121,   126,
     214,     0,     0,   109,     0,   100,     0,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
     217,   215,     0,    99,    92,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,     0,    62,    48,     0,
       0,     0,   127,     0,     0,   107,   103,   105,   132,     0,
       0,     0,   131,   135,     0,     0,   112,   114,   203,     0,
     199,   169,     0,   153,   155,   166,   158,   160,   164,   162,
     183,   179,   185,   181,   173,   171,   177,   175,   189,   188,
     190,   191,   197,   196,   194,   195,   193,     0,     0,    28,
      81,    80,    83,    78,    82,    79,     0,     0,    51,     0,
       0,    59,     0,   122,   125,   214,   124,    50,   108,   134,
     133,     0,     0,     0,     0,     0,     0,   115,    27,     0,
     154,   156,   167,   159,   161,   165,   163,   184,   180,   186,
     182,   174,   172,   178,   176,   204,   216,    49,     0,    53,
       0,     0,   130,   142,   147,   146,     0,   148,   149,   128,
     137,   136,     0,   207,   129,     0,   111,   110,   151,    52,
       0,    60,     0,     0,   101,     0,     0,     0,    63,   138,
     141,     0,   113,    61,   102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,   339,
    -299,  -299,  -299,  -299,  -299,   222,  -299,  -127,  -299,  -299,
    -288,   283,  -299,  -299,   172,   176,  -299,   -22,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,   284,   181,  -299,  -299,
     308,  -299,    54,   117,   -19,   268,  -168,  -169,   131,  -299,
     133,   314,  -299,    30,  -299,  -299,  -299,  -299,  -299,    12,
    -299,  -100,  -299,  -299,  -299,    24,  -299,  -299,  -299,  -299,
    -299,  -299,   -86,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,   113,   114,   116,  -298,   119,  -299,   354,   -27,    -7,
     350,   196,   -80,  -299
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     5,    27,    49,    13,    18,    19,
      29,    50,    51,    69,   103,   159,    52,   133,   134,   135,
     236,    80,    53,    81,   127,   128,    54,    73,    55,    56,
      57,    58,    59,    85,   344,   345,   346,   139,   140,   182,
     347,   255,   256,   257,    62,    63,   175,   176,   177,   178,
     179,   348,   251,   252,   349,   350,    60,   363,    88,   351,
       6,   237,   150,   320,   321,   151,   323,   324,   326,   325,
     322,   261,   152,   332,   331,   334,   333,   328,   330,   327,
     329,   153,   154,   155,   156,   218,    10,    20,   157,    65,
      22,   242,   109,   221
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   233,   136,    64,   170,    21,   149,   158,    64,   181,
      64,    64,   340,   243,   352,    21,    71,    21,    74,    75,
       8,     8,     9,     9,   146,    70,     8,     3,     9,   107,
     160,    82,     8,   132,     9,   137,     8,     8,     9,     9,
     146,   231,    64,  -150,   235,   110,     7,   190,   311,   168,
     111,   171,    14,    89,   104,   147,   219,    12,   129,   131,
      72,   312,   191,   296,   160,   352,   299,   248,   220,     8,
     105,     9,   367,   146,    84,   343,   141,    64,    24,    83,
      84,   144,   143,    77,   137,   249,   247,    64,   250,   232,
     313,    25,   262,    15,    16,   163,   106,    17,    15,    16,
      23,   107,    17,   172,    76,   297,   180,   173,   169,   265,
     266,   267,   268,   269,    72,    78,    79,   287,   112,   288,
     200,   201,   174,    84,   107,   300,   369,     8,   338,     9,
     183,   146,    64,   104,   162,   208,   202,   203,   301,   244,
     222,   306,   104,   234,   164,   209,   147,   104,   245,   113,
     204,   142,   205,   206,   180,   207,   212,   148,   115,   213,
     253,   210,    64,   116,   211,   315,   214,   215,   165,   118,
     259,   120,   166,   122,   104,   216,   184,   141,   316,   124,
     104,   258,   186,   117,   118,   119,   120,   121,   122,   167,
     161,   227,   185,   123,   124,   104,   224,   360,    66,   117,
     187,   119,   341,   121,   180,   125,   126,   132,   234,   123,
     361,   289,   234,   305,    67,    68,   239,   263,   264,   358,
     104,   229,   309,   310,   239,   239,    -7,    30,   217,    15,
      16,   188,   298,    31,    32,   239,   318,   308,    33,    34,
     339,   359,    35,    36,    37,    38,   223,   258,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   238,     8,
     108,     9,   368,    90,    91,   371,   260,   184,    92,   114,
     234,  -106,   240,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   364,   253,     8,   253,     9,   192,   290,
     291,   118,   117,   120,   119,   122,   121,   193,   292,   194,
     137,   124,   123,   195,     8,   353,     9,   196,   258,   197,
     198,   199,   254,   270,   271,   272,   273,   274,   275,   276,
     277,   241,   278,   279,   280,   281,   107,   293,   282,   283,
     284,   285,   286,    72,    78,    79,     8,   226,     9,   230,
     225,   342,   228,   354,   294,   295,   143,   241,   366,   302,
     307,   319,   335,   337,   357,   336,   353,   355,   362,   365,
     372,   373,   374,    28,   130,   246,   189,   138,    86,   356,
     303,   314,   145,   304,    87,   370,    26,   317,     0,    61
};

static const yytype_int16 yycheck[] =
{
       7,   170,    82,    30,   131,    12,   106,   107,    35,   136,
      37,    38,   300,   181,   312,    22,    35,    24,    37,    38,
       3,     3,     5,     5,     7,    32,     3,     0,     5,    20,
     110,    53,     3,    24,     5,    18,     3,     3,     5,     5,
       7,   168,    69,    66,   171,    67,    66,   147,    10,   129,
      69,   131,    23,    60,    10,    22,     9,    22,    80,    81,
      53,    23,   148,   231,   144,   363,   235,    49,    21,     3,
      26,     5,   360,     7,    57,    58,    83,   104,    10,    56,
      57,   103,    89,    22,    18,    67,   186,   114,    70,   169,
      52,    23,   192,    64,    65,   114,    15,    68,    64,    65,
      26,    20,    68,     3,    61,   232,   133,     7,   130,   195,
     196,   197,   198,   199,    53,    54,    55,   217,    15,   219,
      12,    13,    22,    57,    20,    10,    60,     3,   297,     5,
     137,     7,   159,    10,     7,    17,    28,    29,    23,    10,
     159,   241,    10,   170,    10,    27,    22,    10,    19,    26,
      42,     8,    44,    45,   181,    47,    30,    33,    26,    33,
     187,    43,   189,    26,    46,    10,    40,    41,    10,    72,
     189,    74,    10,    76,    10,    49,    10,   184,    23,    82,
      10,   188,    15,    71,    72,    73,    74,    75,    76,    10,
      26,    94,    26,    81,    82,    10,    26,    10,    62,    71,
      22,    73,   302,    75,   231,    93,    94,    24,   235,    81,
      23,    26,   239,   240,    78,    79,    10,   193,   194,   319,
      10,    93,   249,   250,    10,    10,    61,    62,    20,    64,
      65,    22,    26,    68,    69,    10,    26,   244,    73,    74,
      26,    26,    77,    78,    79,    80,    26,   254,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    26,     3,
      64,     5,   362,    73,    74,   365,    23,    10,    78,    73,
     297,    15,    10,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    26,   311,     3,   313,     5,    25,    23,
      23,    72,    71,    74,    73,    76,    75,    34,    23,    36,
      18,    82,    81,    31,     3,   312,     5,    35,   315,    37,
      38,    39,    11,   200,   201,   202,   203,   204,   205,   206,
     207,    15,   208,   209,   210,   211,    20,    23,   212,   213,
     214,   215,   216,    53,    54,    55,     3,   165,     5,   167,
     164,   311,   166,   313,    23,    23,   353,    15,   355,     9,
      26,     9,    21,    26,    26,    21,   363,    22,     9,    42,
      23,    23,    26,    24,    81,   184,   144,    83,    60,   315,
     239,   254,   104,   240,    60,   363,    22,   258,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,    97,     0,    98,    99,   155,    66,     3,     5,
     181,   184,    22,   102,    23,    64,    65,    68,   103,   104,
     182,   184,   185,    26,    10,    23,   182,   100,   104,   105,
      62,    68,    69,    73,    74,    77,    78,    79,    80,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   101,
     106,   107,   111,   117,   121,   123,   124,   125,   126,   127,
     151,   185,   139,   140,   183,   184,    62,    78,    79,   108,
     184,   139,    53,   122,   139,   139,    61,    22,    54,    55,
     116,   118,   122,    56,    57,   128,   135,   146,   153,   184,
      73,    74,    78,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   109,    10,    26,    15,    20,   186,   187,
     122,   139,    15,    26,   186,    26,    26,    71,    72,    73,
      74,    75,    76,    81,    82,    93,    94,   119,   120,   122,
     116,   122,    24,   112,   113,   114,   187,    18,   131,   132,
     133,   184,     8,   184,   122,   140,     7,    22,    33,   156,
     157,   160,   167,   176,   177,   178,   179,   183,   156,   110,
     187,    26,     7,   139,    10,    10,    10,    10,   187,   122,
     112,   187,     3,     7,    22,   141,   142,   143,   144,   145,
     183,   112,   134,   184,    10,    26,    15,    22,    22,   110,
     156,   167,    25,    34,    36,    31,    35,    37,    38,    39,
      12,    13,    28,    29,    42,    44,    45,    47,    17,    27,
      43,    46,    30,    33,    40,    41,    49,    20,   180,     9,
      21,   188,   139,    26,    26,   120,   119,    94,   120,    93,
     119,   112,   187,   142,   183,   112,   115,   156,    26,    10,
      10,    15,   186,   141,    10,    19,   132,   156,    49,    67,
      70,   147,   148,   183,    11,   136,   137,   138,   184,   139,
      23,   166,   156,   160,   160,   167,   167,   167,   167,   167,
     176,   176,   176,   176,   176,   176,   176,   176,   177,   177,
     177,   177,   178,   178,   178,   178,   178,   156,   156,    26,
      23,    23,    23,    23,    23,    23,   141,   112,    26,   142,
      10,    23,     9,   143,   145,   183,   156,    26,   184,   183,
     183,    10,    23,    52,   138,    10,    23,   180,    26,     9,
     158,   159,   165,   161,   162,   164,   163,   174,   172,   175,
     173,   169,   168,   171,   170,    21,    21,    26,   142,    26,
     115,   156,   148,    58,   129,   130,   131,   135,   146,   149,
     150,   154,   179,   184,   148,    22,   137,    26,   156,    26,
      10,    23,     9,   152,    26,    42,   184,   115,   156,    60,
     154,   156,    23,    23,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    97,    97,    98,   100,   101,    99,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     108,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   112,   112,   112,   113,   113,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   120,   120,
     120,   120,   121,   122,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   131,   132,   133,   133,   134,   134,
     135,   136,   136,   137,   137,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   144,   144,   145,   146,   147,
     147,   147,   148,   148,   148,   148,   149,   149,   150,   151,
     151,   152,   152,   153,   153,   153,   154,   154,   154,   154,
     155,   156,   156,   158,   157,   159,   157,   157,   161,   160,
     162,   160,   163,   160,   164,   160,   165,   160,   166,   160,
     160,   168,   167,   169,   167,   170,   167,   171,   167,   172,
     167,   173,   167,   174,   167,   175,   167,   167,   176,   176,
     176,   176,   176,   177,   177,   177,   177,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   182,   183,   184,   184,
     185,   185,   185,   186,   186,   187,   188,   188
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     0,     0,     9,     0,
       2,     3,     3,     1,     2,     1,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     5,     7,
       6,     6,     8,     7,     1,     1,     0,     2,     2,     4,
       6,     8,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     5,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     0,     3,     3,     3,     3,     5,
       3,     2,     4,     3,     1,     3,     1,     3,     3,     1,
       6,     3,     1,     5,     1,     2,     3,     1,     3,     2,
       1,     1,     3,     1,     3,     3,     1,     2,     6,     3,
       3,     1,     1,     2,     2,     1,     1,     1,     3,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     1,     0,     4,     0,     4,     1,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     3,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     1,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       1,     1,     2,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

    {
             (yyvsp[-4].holder) = NULL;
             const string& modName = (*(yyvsp[-2].name));

             if (SINGLETON<svRoot>::getInstance().find(modName) == NULL)
             { // modName not in Symbol-Table
                  svModule* mdl = new svModule(modName);
                  (yyvsp[-4].holder) = mdl;
                  SINGLETON<svRoot>::getInstance().add(mdl);

                  if((yyvsp[-1].portList) != NULL)
                  {
                     for(vector<svPort*>::iterator it = (yyvsp[-1].portList)->begin();
                         it != (yyvsp[-1].portList)->end(); it++)
                           mdl->add(*it);
                  }
                  
                  SVLOG(SEM, INFO) << "Creating Module: \"" << modName << "\"" << std::endl;
             }
             else
             {
                  SVLOG(SEM, ERR) << "Module " <<  modName <<"\" already declared." << std::endl;
             }
             
             delete (yyvsp[-2].name);
             if((yyvsp[-1].portList) != NULL) delete (yyvsp[-1].portList);
         }

    break;

  case 7:

    {
             svModule* mdl = static_cast<svModule*>((yyvsp[-6].holder));
             if((mdl != NULL) && ((yyvsp[0].baseList) != NULL))
             {
                  for(vector<svBase*>::const_iterator it = (yyvsp[0].baseList)->begin();
                     it != (yyvsp[0].baseList)->end(); ++it)
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

    break;

  case 8:

    {
             (yyval.mod) = static_cast<svModule*>((yyvsp[-8].holder));
         }

    break;

  case 9:

    { (yyval.portList) = NULL; }

    break;

  case 10:

    { (yyval.portList) = NULL; }

    break;

  case 11:

    { (yyval.portList) = (yyvsp[-1].portList); }

    break;

  case 12:

    { (yyvsp[-2].portList)->push_back((yyvsp[0].port));
                (yyval.portList) =  (yyvsp[-2].portList);
              }

    break;

  case 13:

    { (yyval.portList) = new vector<svPort*>();
                (yyval.portList)->push_back((yyvsp[0].port));
              }

    break;

  case 14:

    { (yyval.port) = new svPort(*(yyvsp[0].name), (yyvsp[-1].direction));
                delete (yyvsp[0].name);
              }

    break;

  case 15:

    { (yyval.port) = new svPort(*(yyvsp[0].name), svPort::ePortDirection::UNDEF);
                delete (yyvsp[0].name);
              }

    break;

  case 16:

    {
                        if((yyvsp[-1].baseList) != NULL)
                        {
                            if((yyvsp[0].baseList) != NULL)
                            {
                              (yyvsp[-1].baseList)->insert( (yyvsp[-1].baseList)->end()
                                                  , (yyvsp[0].baseList)->begin()
                                                  , (yyvsp[0].baseList)->end());
                              delete (yyvsp[0].baseList);
                            }
                            (yyval.baseList) = (yyvsp[-1].baseList);
                        }
                        else
                        {
                            (yyval.baseList) = (yyvsp[0].baseList);
                        }
                    }

    break;

  case 17:

    { (yyval.baseList) = NULL; }

    break;

  case 18:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 19:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 20:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 21:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 22:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 23:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 24:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 25:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 26:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 27:

    {  vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                  it != (yyvsp[-1].varList)->end(); ++it)
              {
                 svPort* p = new svPort(*it,(yyvsp[-4].portType));
                 p->setDirection((yyvsp[-5].direction));
                 p->setIsSigned((yyvsp[-3].boolType));
                 p->setRange((yyvsp[-2].range));
                 l->push_back(p);
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 28:

    {  vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                  it != (yyvsp[-1].varList)->end(); ++it)
              {
                 svPort* p = new svPort(*it,REG_PORT);
                 p->setDirection(svPort::ePortDirection::OUTPUT);
                 p->setIsSigned((yyvsp[-3].boolType));
                 p->setRange((yyvsp[-2].range));
                 l->push_back(p);
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 29:

    {  vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                  it != (yyvsp[-1].varList)->end(); ++it)
              {
                 svPort* p = new svPort(*it,(yyvsp[-2].portType));
                 p->setDirection(svPort::ePortDirection::OUTPUT);
                 l->push_back(p);
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 30:

    {
               (yyval.portType) = TIME_PORT;
             }

    break;

  case 31:

    {
               (yyval.portType) = INTEGER_PORT;
             }

    break;

  case 32:

    {
               (yyval.portType) = WIRE_PORT;
             }

    break;

  case 33:

    {
               (yyval.portType) = UWIRE_PORT;
             }

    break;

  case 34:

    {
               (yyval.portType) = WANDNET_PORT;
             }

    break;

  case 35:

    {
               (yyval.portType) = WORNET_PORT;
             }

    break;

  case 36:

    {
               (yyval.portType) = TRINET_PORT;
             }

    break;

  case 37:

    {
               (yyval.portType) = TRI0NET_PORT;
             }

    break;

  case 38:

    {
               (yyval.portType) = TRI1NET_PORT;
             }

    break;

  case 39:

    {
               (yyval.portType) = TRIANDNET_PORT;
             }

    break;

  case 40:

    {
               (yyval.portType) = TRIORNET_PORT;
             }

    break;

  case 41:

    {
               (yyval.portType) = SUPPLY_0NET_PORT;
             }

    break;

  case 42:

    {
               (yyval.portType) = SUPPLY_1NET_PORT;
             }

    break;

  case 43:

    {
               (yyval.portType) = TRIREG_PORT;
             }

    break;

  case 44:

    {
               (yyval.portType) = REG_PORT;
             }

    break;

  case 45:

    { (yyval.portType) = UNDEFINE_PORT;}

    break;

  case 46:

    {(yyval.range) = (yyvsp[0].range);}

    break;

  case 47:

    { (yyval.range) = NULL;}

    break;

  case 48:

    {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                 it != (yyvsp[-1].varList)->end(); ++it)
              {
                svNet * w = new svNet(*it,(yyvsp[-4].netType));
                w->setIsSigned((yyvsp[-3].boolType));
                if((yyvsp[-2].baseList) != NULL)
                {
                   for(vector<svBase*>::iterator it = (yyvsp[-2].baseList)->begin(); it != (yyvsp[-2].baseList)->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 49:

    {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                 it != (yyvsp[-1].varList)->end(); ++it)
              {
                svNet * w = new svNet(*it,(yyvsp[-6].netType));
                w->setIsSigned((yyvsp[-4].boolType));
                w->setRange((yyvsp[-3].range));
                if((yyvsp[-2].baseList) != NULL)
                {
                   for(vector<svBase*>::iterator it = (yyvsp[-2].baseList)->begin(); it != (yyvsp[-2].baseList)->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                if ( (yyvsp[-5].boolType) == true ) {
                   w->setIsVector(true);
                   w->setIsScalar(false);
                } else {
                   w->setIsVector(false);
                   w->setIsScalar(true);
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 50:

    {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                 it != (yyvsp[-1].varList)->end(); ++it)
              {
                svNet * w = new svNet(*it,(yyvsp[-5].netType));
                if((yyvsp[-2].baseList) != NULL)
                {
                   for(vector<svBase*>::iterator it = (yyvsp[-2].baseList)->begin(); it != (yyvsp[-2].baseList)->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                w->setIsSigned((yyvsp[-4].boolType));
                w->setRange((yyvsp[-3].range));
                l->push_back(static_cast<svBase*>(w));
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 51:

    {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                 it != (yyvsp[-1].varList)->end(); ++it)
              {
                svNet * w = new svNet(*it,(yyvsp[-5].netType));
                w->setIsSigned((yyvsp[-3].boolType));
                if((yyvsp[-2].baseList) != NULL)
                {
                   for(vector<svBase*>::iterator it = (yyvsp[-2].baseList)->begin(); it != (yyvsp[-2].baseList)->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                if (  (yyvsp[-4].strengthList) != NULL ) 
                {
                   svDriveStrengthType it1 = (yyvsp[-4].strengthList)->front();
                   svDriveStrengthType it2 = (yyvsp[-4].strengthList)->back();
                    w->setStrength0(it1);
                    w->setStrength1(it2);
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 52:

    {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                 it != (yyvsp[-1].varList)->end(); ++it)
              {
                svNet * w = new svNet(*it,(yyvsp[-7].netType));
                w->setIsSigned((yyvsp[-4].boolType));
                w->setRange((yyvsp[-3].range));
                if((yyvsp[-2].baseList) != NULL)
                {
                   for(vector<svBase*>::iterator it = (yyvsp[-2].baseList)->begin(); it != (yyvsp[-2].baseList)->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                if ( (yyvsp[-5].boolType) == true ) {
                   w->setIsVector(true);
                   w->setIsScalar(false);
                } else {
                   w->setIsVector(false);
                   w->setIsScalar(true);
                }
                if (  (yyvsp[-6].strengthList) != NULL ) 
                {
                   svDriveStrengthType it1 = (yyvsp[-6].strengthList)->front();
                   svDriveStrengthType it2 = (yyvsp[-6].strengthList)->back();
                    w->setStrength0(it1);
                    w->setStrength1(it2);
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 53:

    {
              vector<svBase*>* l = new vector<svBase*>();
              for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                 it != (yyvsp[-1].varList)->end(); ++it)
              {
                svNet * w = new svNet(*it,(yyvsp[-6].netType));
                if((yyvsp[-2].baseList) != NULL)
                {
                   for(vector<svBase*>::iterator it = (yyvsp[-2].baseList)->begin(); it != (yyvsp[-2].baseList)->end(); it++)
                        w->add(static_cast<svExprBase*>(*it)); 
                }
                w->setIsSigned((yyvsp[-4].boolType));
                w->setRange((yyvsp[-3].range));
                if (  (yyvsp[-5].strengthList) != NULL ) 
                {
                   svDriveStrengthType it1 = (yyvsp[-5].strengthList)->front();
                   svDriveStrengthType it2 = (yyvsp[-5].strengthList)->back();
                    w->setStrength0(it1);
                    w->setStrength1(it2);
                }
                l->push_back(static_cast<svBase*>(w));
              }
              delete (yyvsp[-1].varList);
              (yyval.baseList) = l;
           }

    break;

  case 54:

    {
             (yyval.baseList) = (yyvsp[0].baseList);
           }

    break;

  case 55:

    { 
             (yyval.baseList) = (yyvsp[0].baseList);
           }

    break;

  case 56:

    {
              (yyval.base) = NULL;
           }

    break;

  case 57:

    {
              svExprNum<string>* n = new svExprNum<string>(*(yyvsp[0].name));
              (yyval.baseList) = new vector<svBase*>();
              (yyval.baseList)->push_back(n);
              delete (yyvsp[0].name);
       }

    break;

  case 58:

    {
              svExprNum<string>* n = new svExprNum<string>(*(yyvsp[0].name));
              (yyval.baseList) = new vector<svBase*>();
              (yyval.baseList)->push_back(n);
              delete (yyvsp[0].name);
      }

    break;

  case 59:

    {
              (yyval.baseList) = new vector<svBase*>();
              (yyval.baseList)->push_back((yyvsp[-1].expr));
        }

    break;

  case 60:

    {
              (yyval.baseList) = new vector<svBase*>();
              (yyval.baseList)->push_back((yyvsp[-3].expr));
              (yyval.baseList)->push_back((yyvsp[-1].expr));
       }

    break;

  case 61:

    {
              (yyval.baseList) = new vector<svBase*>();
              (yyval.baseList)->push_back((yyvsp[-5].expr));
              (yyval.baseList)->push_back((yyvsp[-3].expr));
              (yyval.baseList)->push_back((yyvsp[-1].expr));
       }

    break;

  case 62:

    {
                    (yyval.expr) = (yyvsp[0].expr);
                }

    break;

  case 63:

    {
                 (yyval.expr) = new svMinTypMax((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
               }

    break;

  case 64:

    {
                      (yyval.boolType) = true;
                   }

    break;

  case 65:

    {
                      (yyval.boolType) = false;
                   }

    break;

  case 66:

    {
               (yyval.netType) = WIRE;
             }

    break;

  case 67:

    {
               (yyval.netType) = UWIRE;
             }

    break;

  case 68:

    {
               (yyval.netType) = WANDNET;
             }

    break;

  case 69:

    {
               (yyval.netType) = WORNET;
             }

    break;

  case 70:

    {
               (yyval.netType) = TRINET;
             }

    break;

  case 71:

    {
               (yyval.netType) = TRI0NET;
             }

    break;

  case 72:

    {
               (yyval.netType) = TRI1NET;
             }

    break;

  case 73:

    {
               (yyval.netType) = TRIANDNET;
             }

    break;

  case 74:

    {
               (yyval.netType) = TRIORNET;
             }

    break;

  case 75:

    {
               (yyval.netType) = SUPPLY_0NET;
             }

    break;

  case 76:

    {
               (yyval.netType) = SUPPLY_1NET;
             }

    break;

  case 77:

    {
               (yyval.netType) = TRIREG;
             }

    break;

  case 78:

    { 
                     (yyval.strengthList) = new vector<svDriveStrengthType>();
                     (yyval.strengthList)->push_back((yyvsp[-3].driveStrengthType));
                     (yyval.strengthList)->push_back((yyvsp[-1].driveStrengthType));

                   }

    break;

  case 79:

    { 
                     (yyval.strengthList) = new vector<svDriveStrengthType>();
                     (yyval.strengthList)->push_back((yyvsp[-3].driveStrengthType));
                     (yyval.strengthList)->push_back((yyvsp[-1].driveStrengthType));
                    }

    break;

  case 80:

    { 
                     (yyval.strengthList) = new vector<svDriveStrengthType>();
                     (yyval.strengthList)->push_back(HIGHZ_1);
                     (yyval.strengthList)->push_back((yyvsp[-1].driveStrengthType));
                    }

    break;

  case 81:

    { 
                     (yyval.strengthList) = new vector<svDriveStrengthType>();
                     (yyval.strengthList)->push_back(HIGHZ_0);
                     (yyval.strengthList)->push_back((yyvsp[-1].driveStrengthType));
                    }

    break;

  case 82:

    { 
                     (yyval.strengthList) = new vector<svDriveStrengthType>();
                     (yyval.strengthList)->push_back((yyvsp[-3].driveStrengthType));
                     (yyval.strengthList)->push_back(HIGHZ_0);
                    }

    break;

  case 83:

    { 
                     (yyval.strengthList) = new vector<svDriveStrengthType>();
                     (yyval.strengthList)->push_back((yyvsp[-3].driveStrengthType));
                     (yyval.strengthList)->push_back(HIGHZ_1);
                    }

    break;

  case 84:

    { 
            (yyval.driveStrengthType) = STRONG_0;
          }

    break;

  case 85:

    { 
            (yyval.driveStrengthType) = SUPPLY_0;
          }

    break;

  case 86:

    {
            (yyval.driveStrengthType) = PULL_0;
          }

    break;

  case 87:

    { 
            (yyval.driveStrengthType) = WEAK_0;
          }

    break;

  case 88:

    { 
            (yyval.driveStrengthType) = STRONG_1;
          }

    break;

  case 89:

    { 
            (yyval.driveStrengthType) = SUPPLY_1;
          }

    break;

  case 90:

    { 
            (yyval.driveStrengthType)= PULL_1;
          }

    break;

  case 91:

    { 
            (yyval.driveStrengthType) = WEAK_1;
          }

    break;

  case 92:

    {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                it != (yyvsp[-1].varList)->end(); ++it)
             {
                 it->setRange((yyvsp[-2].range));
                 svReg* r = new svReg(*it);
                 r->setIsSigned((yyvsp[-3].boolType));
                 l->push_back(static_cast<svBase*>(r));
             }
             delete (yyvsp[-1].varList);
             (yyval.baseList) = l;
          }

    break;

  case 93:

    { (yyval.boolType) = true;}

    break;

  case 94:

    { (yyval.boolType) = false;}

    break;

  case 95:

    {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                it != (yyvsp[-1].varList)->end(); ++it)
             {
                 svInteger* r = new svInteger(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete (yyvsp[-1].varList);
             (yyval.baseList) = l;
             }

    break;

  case 96:

    {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                it != (yyvsp[-1].varList)->end(); ++it)
             {
                 svReal* r = new svReal(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete (yyvsp[-1].varList);
             (yyval.baseList) = l;
             }

    break;

  case 97:

    {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                it != (yyvsp[-1].varList)->end(); ++it)
             {
                 svRealTime* r = new svRealTime(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete (yyvsp[-1].varList);
             (yyval.baseList) = l;
             }

    break;

  case 98:

    {
             vector<svBase*>* l = new vector<svBase*>();
             for(vector<svDeclBase>::iterator it = (yyvsp[-1].varList)->begin();
                it != (yyvsp[-1].varList)->end(); ++it)
             {
                 svTime* r = new svTime(*it);
                 l->push_back(static_cast<svBase*>(r));
             }
             delete (yyvsp[-1].varList);
             (yyval.baseList) = l;
             }

    break;

  case 99:

    {  svExprNum<string>* n = new svExprNum<string>(*(yyvsp[-1].name));
               svExprConst* c = new svExprConst(*(yyvsp[-3].name), n);
               delete (yyvsp[-3].name);
               delete (yyvsp[-1].name);

               vector<svBase*>* l = new vector<svBase*>();
               l->push_back(c);
               (yyval.baseList) = l;
            }

    break;

  case 100:

    { 
               svContAssign* c = new svContAssign(static_cast<svAssignExpr*>(yyvsp[-1].expr));
               (yyval.base) = c;
             }

    break;

  case 101:

    {  (yyval.base) = (yyvsp[-1].expr); }

    break;

  case 102:

    { 
                     svNonBlkAssignExpr* s = new svNonBlkAssignExpr((yyvsp[-3].expr), static_cast<svExprBase*>((yyvsp[-1].expr)));
                     (yyval.base) = s;
                   }

    break;

  case 103:

    { svAssignCombo& r = *(static_cast<svAssignCombo*>((yyvsp[0].expr)));
                   static_cast<svAssignCombo*>((yyvsp[-2].expr))->append(r);
                   (yyval.expr) = (yyvsp[-2].expr);
                 }

    break;

  case 104:

    {  (yyval.expr) = (yyvsp[0].expr); }

    break;

  case 105:

    {  vector<string>::const_iterator it = (yyvsp[-2].idList)->begin();
                svExprVar* var = new svExprVar(*it); ++it;
                svExprVarConcat* varConcat = new svExprVarConcat(var);
                for(; it != (yyvsp[-2].idList)->end(); ++it)
                {
                    svExprVar* var = new svExprVar(*it);
                    varConcat->append(var);
                }
                delete (yyvsp[-2].idList);

                svAssignExpr* s = new svAssignExpr(
                   varConcat, dynamic_cast<svExprBase*>((yyvsp[0].expr)));

                svAssignCombo* C = new svAssignCombo(s);

                (yyval.expr) = C;
              }

    break;

  case 106:

    { (yyval.idList) = new vector<string>();
                 (yyval.idList)->push_back(*(yyvsp[0].name));
                 delete (yyvsp[0].name);
               }

    break;

  case 107:

    { (yyval.idList) = (yyvsp[-1].idList); }

    break;

  case 108:

    { (yyvsp[-2].idList)->push_back(*(yyvsp[0].name));
            delete (yyvsp[0].name);
            (yyval.idList) = (yyvsp[-2].idList);
          }

    break;

  case 109:

    { (yyval.idList) = new vector<string>();
            (yyval.idList)->push_back(*(yyvsp[0].name));
            delete (yyvsp[0].name);
          }

    break;

  case 110:

    {  svExprVar* iVar = new svExprVar(*(yyvsp[-4].name));
                  svInstExpr* instStmt = new svInstExpr(*(yyvsp[-5].name), iVar);
                  for(vector<svBase*>::iterator it = (yyvsp[-2].baseList)->begin();
                      it != (yyvsp[-2].baseList)->end(); ++it)
                  {
                      svBase* param = (*it); ++it;
                      svBase* port = (*it);
                      instStmt->setPortParamMap(param, port);
                  }

                  (yyval.base) = static_cast<svBase*>(instStmt);

                  delete (yyvsp[-5].name);
                  delete (yyvsp[-4].name);
                  delete (yyvsp[-2].baseList);
               }

    break;

  case 111:

    { (yyvsp[-2].baseList)->insert((yyvsp[-2].baseList)->end(), (yyvsp[0].baseList)->begin(), (yyvsp[0].baseList)->end());
                      delete (yyvsp[0].baseList);
                      (yyval.baseList) = (yyvsp[-2].baseList);
                    }

    break;

  case 112:

    { (yyval.baseList) = (yyvsp[0].baseList); }

    break;

  case 113:

    { (yyval.baseList) = new vector<svBase*>();
                  (yyval.baseList)->push_back((yyvsp[-3].expr));
                  (yyval.baseList)->push_back(new svExprVar(*(yyvsp[-1].name)));
                }

    break;

  case 114:

    { (yyval.baseList) = new vector<svBase*>();
                  (yyval.baseList)->push_back((yyvsp[0].expr));
                  (yyval.baseList)->push_back(NULL);
                }

    break;

  case 115:

    {  if((yyvsp[0].expr) == NULL)
               {
                 svExprVar* v = new svExprVar(*(yyvsp[-1].name));
                 (yyval.expr) = v;
               }
               else
               {
                 svSelectOp* s = new svSelectOp(*(yyvsp[-1].name), dynamic_cast<svExprBase*>((yyvsp[0].expr)));
                 (yyval.expr) = s;
               }
               delete (yyvsp[-1].name);
            }

    break;

  case 116:

    { (yyvsp[-2].varList)->push_back(*(yyvsp[0].var));
                 delete (yyvsp[0].var);
                 (yyval.varList) = (yyvsp[-2].varList);
               }

    break;

  case 117:

    { (yyval.varList) = new vector<svDeclBase>();
                 (yyval.varList)->push_back(*(yyvsp[0].var));
                 delete (yyvsp[0].var);
               }

    break;

  case 118:

    { (yyval.var) = new svDeclBase(*(yyvsp[-2].name));
              delete (yyvsp[-2].name);
              (yyval.var)->setInit(dynamic_cast<svExprBase*>((yyvsp[0].expr)));
              (yyval.var)->setDim(NULL);
            }

    break;

  case 119:

    { (yyval.var) = new svDeclBase(*(yyvsp[-1].name));
              delete (yyvsp[-1].name);
              (yyval.var)->setDim((yyvsp[0].range));
            }

    break;

  case 120:

    {
                            (yyval.varList) = (yyvsp[0].varList);
                          }

    break;

  case 121:

    {
                            (yyval.varList) = (yyvsp[0].varList);
                          }

    break;

  case 122:

    { (yyvsp[-2].varList)->push_back(*(yyvsp[0].var));
                 delete (yyvsp[0].var);
                 (yyval.varList) = (yyvsp[-2].varList);
               }

    break;

  case 123:

    { (yyval.varList) = new vector<svDeclBase>();
                 (yyval.varList)->push_back(*(yyvsp[0].var));
                 delete (yyvsp[0].var);
               }

    break;

  case 124:

    { (yyval.var) = new svDeclBase(*(yyvsp[-2].name));
              delete (yyvsp[-2].name);
              (yyval.var)->setInit(dynamic_cast<svExprBase*>((yyvsp[0].expr)));
            }

    break;

  case 125:

    { (yyvsp[-2].varList)->push_back(*(yyvsp[0].var));
                 delete (yyvsp[0].var);
                 (yyval.varList) = (yyvsp[-2].varList);
               }

    break;

  case 126:

    { (yyval.varList) = new vector<svDeclBase>();
                 (yyval.varList)->push_back(*(yyvsp[0].var));
                 delete (yyvsp[0].var);
               }

    break;

  case 127:

    { (yyval.var) = new svDeclBase(*(yyvsp[-1].name));
              delete (yyvsp[-1].name);
              (yyval.var)->setDim((yyvsp[0].range));
            }

    break;

  case 128:

    {  svAlways * b = new svAlways(*(yyvsp[-2].sensList));
                b->setStmtOrBlock((yyvsp[0].base));
                delete (yyvsp[-2].sensList);
                (yyval.base) = b;
             }

    break;

  case 129:

    {  (yyvsp[-2].sensList)->push_back(*(yyvsp[0].sens));
                     delete (yyvsp[0].sens);
                     (yyval.sensList) = (yyvsp[-2].sensList);
                  }

    break;

  case 130:

    {  (yyvsp[-2].sensList)->push_back(*(yyvsp[0].sens));
                     delete (yyvsp[0].sens);
                     (yyval.sensList) = (yyvsp[-2].sensList);
                  }

    break;

  case 131:

    {  (yyval.sensList) = new vector<svSensitivity>(); 
                     (yyval.sensList)->push_back(*(yyvsp[0].sens));
                  }

    break;

  case 132:

    { (yyval.sens) = new svSensitivity(svSensitivity::eSensType::ALL); }

    break;

  case 133:

    { (yyval.sens) = new svSensitivity
                    (svSensitivity::eSensType::POSEDGE, *(yyvsp[0].name));
                delete (yyvsp[0].name);
              }

    break;

  case 134:

    { (yyval.sens) = new svSensitivity
                    (svSensitivity::eSensType::NEGEDGE, *(yyvsp[0].name));
                delete (yyvsp[0].name);
              }

    break;

  case 135:

    { (yyval.sens) = new svSensitivity
                    (svSensitivity::eSensType::NONE, *(yyvsp[0].name));
                delete (yyvsp[0].name);
              }

    break;

  case 136:

    {
                (yyval.base)=(yyvsp[0].base);
             }

    break;

  case 137:

    {
                (yyval.base)=(yyvsp[0].base);
             }

    break;

  case 138:

    {  svBlock* b = new svBlock();
           b->add(*(yyvsp[-1].baseList));
           (yyval.base) = b;
        }

    break;

  case 139:

    {  (yyvsp[-1].baseList)->push_back((yyvsp[0].base));
              (yyval.baseList) = (yyvsp[-1].baseList);
           }

    break;

  case 140:

    {  (yyval.baseList) = new vector<svBase*>();
           }

    break;

  case 141:

    {  (yyvsp[-1].baseList)->push_back((yyvsp[0].base));
                  (yyval.baseList) = (yyvsp[-1].baseList);
               }

    break;

  case 142:

    {  (yyval.baseList) = new vector<svBase*>();
               }

    break;

  case 143:

    { (yyval.base) = (yyvsp[0].base); }

    break;

  case 144:

    { (yyval.base) = (yyvsp[0].base); }

    break;

  case 145:

    { (yyval.base) = (yyvsp[0].base); }

    break;

  case 146:

    { (yyval.base) = (yyvsp[0].base); }

    break;

  case 147:

    { (yyval.base) = (yyvsp[0].base); }

    break;

  case 148:

    { (yyval.base) = (yyvsp[0].base); }

    break;

  case 149:

    { (yyval.base) = (yyvsp[0].base); }

    break;

  case 150:

    { (yyval.holder) = NULL; }

    break;

  case 151:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::CONDITIONAL);
               expr->setChild((yyvsp[-4].expr));
               expr->setChild((yyvsp[-2].expr));
               expr->setChild((yyvsp[0].expr));
               (yyval.expr) = expr;
             }

    break;

  case 152:

    { (yyval.expr) = (yyvsp[0].expr); }

    break;

  case 153:

    { (yyval.expr) = NULL; }

    break;

  case 154:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::LAND);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 155:

    { (yyval.expr) = NULL; }

    break;

  case 156:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::LOR);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 157:

    { (yyval.expr) = (yyvsp[0].expr); }

    break;

  case 158:

    { (yyval.expr) = NULL; }

    break;

  case 159:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BAND);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 160:

    { (yyval.expr) = NULL; }

    break;

  case 161:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BOR);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 162:

    { (yyval.expr) = NULL; }

    break;

  case 163:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BXOR);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 164:

    { (yyval.expr) = NULL; }

    break;

  case 165:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BXNOR);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 166:

    { (yyval.expr) = NULL; }

    break;

  case 167:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::RNOR);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 168:

    { (yyval.expr) = NULL; }

    break;

  case 169:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::BNOT);
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 170:

    { (yyval.expr) = (yyvsp[0].expr); }

    break;

  case 171:

    { (yyval.expr) = NULL; }

    break;

  case 172:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::LT);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 173:

    { (yyval.expr) = NULL; }

    break;

  case 174:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::LE);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 175:

    { (yyval.expr) = NULL; }

    break;

  case 176:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::GT);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 177:

    { (yyval.expr) = NULL; }

    break;

  case 178:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::GE);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 179:

    { (yyval.expr) = NULL; }

    break;

  case 180:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::EQUAL);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 181:

    { (yyval.expr) = NULL; }

    break;

  case 182:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::NOT_EQ);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 183:

    { (yyval.expr) = NULL; }

    break;

  case 184:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::EQ_CASE);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 185:

    { (yyval.expr) = NULL; }

    break;

  case 186:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::NOT_EQ_CASE);
                  expr->setChild((yyvsp[-3].expr));
                  expr->setChild((yyvsp[-1].expr));
                  (yyval.expr) = expr;
                }

    break;

  case 187:

    { (yyval.expr) = (yyvsp[0].expr); }

    break;

  case 188:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::PLUS);
               expr->setChild((yyvsp[-2].expr));
               expr->setChild((yyvsp[0].expr));
               (yyval.expr) = expr;
             }

    break;

  case 189:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::MINUS);
               expr->setChild((yyvsp[-2].expr));
               expr->setChild((yyvsp[0].expr));
               (yyval.expr) = expr;
             }

    break;

  case 190:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::SL);
               expr->setChild((yyvsp[-2].expr));
               expr->setChild((yyvsp[0].expr));
               (yyval.expr) = expr;
             }

    break;

  case 191:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::SR);
               expr->setChild((yyvsp[-2].expr));
               expr->setChild((yyvsp[0].expr));
               (yyval.expr) = expr;
             }

    break;

  case 192:

    { (yyval.expr) = (yyvsp[0].expr); }

    break;

  case 193:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::MULT);
         expr->setChild((yyvsp[-2].expr));
         expr->setChild((yyvsp[0].expr));
         (yyval.expr) = expr;
       }

    break;

  case 194:

    { svExprOp* expr = new svExprOp(svExprOp::eExprOpType::DIV);
         expr->setChild((yyvsp[-2].expr));
         expr->setChild((yyvsp[0].expr));
         (yyval.expr) = expr;
       }

    break;

  case 195:

    { (yyval.expr) = NULL; }

    break;

  case 196:

    { (yyval.expr) = NULL; }

    break;

  case 197:

    { (yyval.expr) = NULL; }

    break;

  case 198:

    { (yyval.expr) = (yyvsp[0].expr); }

    break;

  case 199:

    { (yyval.expr) = (yyvsp[-1].expr); }

    break;

  case 200:

    { (yyval.expr) = (yyvsp[0].expr); }

    break;

  case 201:

    { (yyval.expr) = new svExprNum<string>(*(yyvsp[0].name));
            delete (yyvsp[0].name);
          }

    break;

  case 202:

    { (yyval.expr) = new svSelectOp(*(yyvsp[-1].name), dynamic_cast<svExprBase*>((yyvsp[0].expr)));
            delete (yyvsp[-1].name);
          }

    break;

  case 203:

    { (yyval.expr) = NULL; }

    break;

  case 204:

    { (yyval.expr) = (yyvsp[-1].expr); }

    break;

  case 205:

    { (yyval.name) = (yyvsp[0].name); }

    break;

  case 206:

    { (yyval.name) = (yyvsp[0].name); }

    break;

  case 207:

    { (yyval.name) = (yyvsp[0].name); }

    break;

  case 208:

    { (yyval.name) = (yyvsp[0].name); }

    break;

  case 209:

    { (yyval.name) = (yyvsp[0].name); }

    break;

  case 210:

    { (yyval.direction) = svPort::ePortDirection::INPUT;   }

    break;

  case 211:

    { (yyval.direction) = svPort::ePortDirection::INOUT;   }

    break;

  case 212:

    { (yyval.direction) = svPort::ePortDirection::OUTPUT;  }

    break;

  case 213:

    { (yyval.range) = (yyval.range); }

    break;

  case 214:

    { (yyval.range) = new svDeclRange(); }

    break;

  case 215:

    { (yyval.range) = new svDeclRange((yyvsp[-1].expr), (yyvsp[0].expr)); }

    break;

  case 216:

    { (yyval.expr) = (yyvsp[-1].expr); }

    break;

  case 217:

    { (yyval.expr) = NULL; }

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}



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
