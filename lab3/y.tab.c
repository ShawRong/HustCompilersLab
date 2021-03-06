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
#line 3 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "def.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char*);
void display(struct node *,int);

#line 78 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    T_IntConstant = 258,
    T_Identifier = 259,
    T_Int = 260,
    T_StringConstant = 261,
    T_Print = 262,
    T_ReadInt = 263,
    T_Return = 264,
    T_Void = 265,
    T_While = 266,
    T_If = 267,
    T_Else = 268,
    T_Break = 269,
    T_Continue = 270,
    T_Le = 271,
    T_Ge = 272,
    T_Eq = 273,
    T_Ne = 274,
    T_And = 275,
    T_Or = 276
  };
#endif
/* Tokens.  */
#define T_IntConstant 258
#define T_Identifier 259
#define T_Int 260
#define T_StringConstant 261
#define T_Print 262
#define T_ReadInt 263
#define T_Return 264
#define T_Void 265
#define T_While 266
#define T_If 267
#define T_Else 268
#define T_Break 269
#define T_Continue 270
#define T_Le 271
#define T_Ge 272
#define T_Eq 273
#define T_Ne 274
#define T_And 275
#define T_Or 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "parser.y" /* yacc.c:355  */

	int    type_int;
	char   type_id[32];
        char*   type_string;
	struct node *ptr;

#line 167 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,    29,     2,     2,
      31,    32,    27,    25,    35,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      23,    22,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    58,    61,    64,    67,    70,    73,    74,
      77,    80,    81,    84,    85,    88,    91,    92,    95,    98,
     101,   102,   105,   110,   111,   114,   115,   116,   117,   118,
     119,   120,   121,   124,   127,   130,   133,   136,   137,   140,
     141,   144,   145,   148,   151,   154,   155,   158,   159,   162,
     163,   166,   169,   172,   175,   178,   181,   184,   187,   190,
     193,   196,   199,   202,   205,   208,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   233,   236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IntConstant", "T_Identifier", "T_Int",
  "T_StringConstant", "T_Print", "T_ReadInt", "T_Return", "T_Void",
  "T_While", "T_If", "T_Else", "T_Break", "T_Continue", "T_Le", "T_Ge",
  "T_Eq", "T_Ne", "T_And", "T_Or", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'('", "')'", "'{'", "'}'", "','", "';'",
  "$accept", "Program", "FuncDecl", "FuncSign", "FuncBlock", "FuncRet",
  "RetType", "FuncName", "Args", "_Args", "Arg", "VarDecls", "VarDecl",
  "Specifier", "DecList", "ID", "Stmts", "Stmt", "AssignStmt",
  "T_Identifier_NonT", "PrintStmt", "String", "PActuals", "ExpList",
  "ReturnStmt", "Ret", "CallStmt", "CallExpr", "Actuals", "IfStmt",
  "IfTest", "TestExpr", "StmtsBlock", "If", "Then", "EndThen", "Else",
  "EndIf", "WhileStmt", "WhileTest", "While", "Do", "EndWhile",
  "BreakStmt", "ContinueStmt", "Exp", "ReadInt", "ReadInt_NotT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    61,    60,    62,    43,    45,    42,    47,    37,
      33,    40,    41,   123,   125,    44,    59
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -75,   -75,     7,     1,     4,   -75,   -75,   -75,   -75,
     -21,   -18,   -75,    15,   -75,    15,   -75,   224,   -15,     4,
      -9,   -75,   -11,     4,    11,     3,   -75,   -75,   -75,     2,
       5,    21,    19,   224,   -75,    13,   -75,   -75,     6,   -75,
      18,   -75,   -75,    42,   -75,   -75,    42,   -75,   -75,    15,
     -75,    50,   -75,    15,   -75,    80,   -75,   -75,    14,   -75,
     -75,    66,   -75,    56,   -75,    66,    66,    66,   -75,   -75,
      82,   -75,    57,   -75,    58,    66,   -75,    58,   -75,   -75,
       4,   -75,   -75,    59,   -75,    61,   110,    96,   -75,   -75,
     150,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,   -75,    80,   224,   -75,   167,   -75,
     -75,    66,    63,   -75,   -75,    66,   -75,   -75,    22,    22,
      55,    55,   198,   184,    22,    22,    -1,    -1,   -75,   -75,
     -75,    72,   106,    77,   -75,   -75,   130,   105,   -75,   -75,
     -75,   -75,    58,   -75,   -75,   -75,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     8,     9,     0,     2,     0,     7,     1,     3,    22,
       0,     0,    10,    16,     4,    11,    19,     0,     0,     0,
       0,    12,    13,     0,    22,     0,    43,    61,    54,     0,
       0,     0,     0,    23,    25,     0,    26,    28,     0,    27,
       0,    29,    55,     0,    30,    62,     0,    31,    32,    16,
      18,    20,     5,     0,    15,     0,    64,    65,     0,     6,
      24,     0,    71,    72,    87,     0,     0,     0,    42,    74,
       0,    85,     0,    44,     0,     0,    51,     0,    60,    17,
       0,    14,    36,    37,    46,     0,    47,     0,    70,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,    56,     0,    63,
      21,     0,     0,    38,    45,     0,    33,    73,    79,    78,
      80,    81,    83,    82,    77,    76,    66,    67,    68,    69,
      75,     0,     0,    58,    52,    59,    39,     0,    48,    86,
      53,    57,     0,    49,    40,    35,    58,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   138,   -75,   -75,   -75,   -75,   -75,   -75,   -75,    90,
     -75,    95,   -75,   -10,    81,    -4,   -29,   -75,   -75,   -75,
     -75,    47,   -75,    24,   -75,   -75,   -75,   -17,    48,   -75,
     -75,   116,   -74,   -75,   -75,   -75,   -75,    26,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -36,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    10,    14,     5,     6,    11,    20,    21,
      22,    17,    18,    19,    50,    31,    32,    33,    34,    35,
      36,    83,   112,   113,    37,    38,    39,    69,    85,    41,
      42,    76,   107,    43,    74,   133,   142,   143,    44,    45,
      46,    77,   135,    47,    48,    86,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    12,    70,   109,    60,    23,     1,     7,     9,    62,
      63,     2,    13,    15,    64,    51,    40,    62,    63,    54,
      16,    49,    64,    52,    53,    87,   101,   102,   103,    88,
      89,    90,    65,   -34,    55,    61,    66,    67,    56,   108,
      65,    57,    68,    23,    66,    67,    84,    99,   100,   101,
     102,   103,    58,    59,    73,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   146,    62,
      63,    91,    92,    75,    64,   136,    51,   132,    97,    98,
      99,   100,   101,   102,   103,    80,    82,   -22,   105,    40,
     141,   106,    65,   114,   111,   137,    66,    67,    91,    92,
      93,    94,    95,    96,   139,    97,    98,    99,   100,   101,
     102,   103,    91,    92,    93,    94,    95,    96,   104,    97,
      98,    99,   100,   101,   102,   103,    91,    92,    93,    94,
      95,    96,   116,    97,    98,    99,   100,   101,   102,   103,
     140,   145,     8,    81,    79,   115,    91,    92,    93,    94,
      95,    96,   131,    97,    98,    99,   100,   101,   102,   103,
     144,   110,    78,   138,     0,   111,    91,    92,    93,    94,
      95,    96,   147,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   117,    91,    92,    93,    94,    95,    96,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,   134,
      91,    92,    93,    94,    95,     0,     0,    97,    98,    99,
     100,   101,   102,   103,    91,    92,    93,    94,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,    24,     0,
       0,    25,     0,    26,     0,    27,    28,     0,    29,    30
};

static const yytype_int16 yycheck[] =
{
      17,     5,    38,    77,    33,    15,     5,     0,     4,     3,
       4,    10,    33,    31,     8,    19,    33,     3,     4,    23,
       5,    36,     8,    32,    35,    61,    27,    28,    29,    65,
      66,    67,    26,    22,    31,    22,    30,    31,    36,    75,
      26,    36,    36,    53,    30,    31,    32,    25,    26,    27,
      28,    29,    31,    34,    36,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   142,     3,
       4,    16,    17,    31,     8,   111,    80,   106,    23,    24,
      25,    26,    27,    28,    29,    35,     6,    31,    31,   106,
      13,    33,    26,    32,    35,    32,    30,    31,    16,    17,
      18,    19,    20,    21,    32,    23,    24,    25,    26,    27,
      28,    29,    16,    17,    18,    19,    20,    21,    36,    23,
      24,    25,    26,    27,    28,    29,    16,    17,    18,    19,
      20,    21,    36,    23,    24,    25,    26,    27,    28,    29,
      34,    36,     4,    53,    49,    35,    16,    17,    18,    19,
      20,    21,   105,    23,    24,    25,    26,    27,    28,    29,
     136,    80,    46,   115,    -1,    35,    16,    17,    18,    19,
      20,    21,   146,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    16,    17,    18,    19,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,     4,    -1,
      -1,     7,    -1,     9,    -1,    11,    12,    -1,    14,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    10,    38,    39,    42,    43,     0,    38,     4,
      40,    44,    52,    33,    41,    31,     5,    48,    49,    50,
      45,    46,    47,    50,     4,     7,     9,    11,    12,    14,
      15,    52,    53,    54,    55,    56,    57,    61,    62,    63,
      64,    66,    67,    70,    75,    76,    77,    80,    81,    36,
      51,    52,    32,    35,    52,    31,    36,    36,    31,    34,
      53,    22,     3,     4,     8,    26,    30,    31,    36,    64,
      82,    83,    84,    36,    71,    31,    68,    78,    68,    48,
      35,    46,     6,    58,    32,    65,    82,    82,    82,    82,
      82,    16,    17,    18,    19,    20,    21,    23,    24,    25,
      26,    27,    28,    29,    36,    31,    33,    69,    82,    69,
      51,    35,    59,    60,    32,    35,    36,    32,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    58,    53,    72,    32,    79,    82,    32,    65,    32,
      34,    13,    73,    74,    60,    36,    69,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    40,    41,    42,    43,    43,
      44,    45,    45,    46,    46,    47,    48,    48,    49,    50,
      51,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    56,    57,    58,    59,    59,    60,
      60,    61,    61,    62,    63,    64,    64,    65,    65,    66,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     4,     4,     1,     1,     1,
       1,     0,     1,     1,     3,     2,     0,     3,     2,     1,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     6,     1,     0,     1,     2,
       3,     3,     2,     1,     2,     4,     3,     1,     3,     5,
       7,     2,     3,     3,     1,     0,     0,     1,     0,     4,
       2,     1,     0,     0,     2,     2,     3,     3,     3,     3,
       2,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     4,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=NULL; }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "parser.y" /* yacc.c:1646  */
    { display((yyvsp[-1].ptr),0); }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(FUNCDECL,(yyvsp[-2].ptr),(yyvsp[-1].ptr),(yyvsp[0].ptr),yylineno); }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 64 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(FUNCSIGN,(yyvsp[-3].ptr),(yyvsp[-1].ptr),NULL,yylineno); }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 67 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(FUNCBLOCK,(yyvsp[-2].ptr),(yyvsp[-1].ptr),NULL,yylineno); }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(FUNCRET,(yyvsp[0].ptr),NULL,NULL,yylineno); }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Int,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"Int"); }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Void,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"Void"); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=NULL; }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(ARGUMENTS,(yyvsp[0].ptr),NULL,NULL,yylineno); }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(',',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(ARGUMENT,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno); }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=NULL; }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 92 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(';',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(VARDECL,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr) = mknode(T_Int,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"Int"); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 101 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(',',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,","); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id)); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(STMTS,(yyvsp[0].ptr),NULL,NULL,yylineno); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(STMTS,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno); }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(ASSIGN,(yyvsp[-3].ptr),(yyvsp[-1].ptr),NULL,yylineno); }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(PRINT,(yyvsp[-3].ptr),(yyvsp[-2].ptr),NULL,yylineno); }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_StringConstant,NULL,NULL,NULL,yylineno); (yyval.ptr)->type_string = (yyvsp[0].type_string); }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=NULL; }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(',',(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,",");}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(RETURN,(yyvsp[-2].ptr),(yyvsp[-1].ptr),NULL,yylineno); }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(RETURN,(yyvsp[-1].ptr),NULL,NULL,yylineno); }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Return,NULL,NULL,NULL,yylineno); }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[-1].ptr); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(CALL,(yyvsp[-3].ptr),(yyvsp[-1].ptr),NULL,yylineno); }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(CALL,(yyvsp[-2].ptr),NULL,NULL,yylineno); }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(',',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,","); }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(IFSTMT,(yyvsp[-4].ptr),(yyvsp[-2].ptr),NULL,yylineno); }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(IFSTMT,(yyvsp[-6].ptr),(yyvsp[-4].ptr),(yyvsp[-1].ptr),yylineno); }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(IFTEST,(yyvsp[0].ptr),NULL,NULL,yylineno); }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[-1].ptr); }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(STMTSBLOCK,(yyvsp[-1].ptr),NULL,NULL,yylineno); }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 175 "parser.y" /* yacc.c:1646  */
    { /* empty */ }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 178 "parser.y" /* yacc.c:1646  */
    { /* empty */ }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 181 "parser.y" /* yacc.c:1646  */
    { /* empty */ }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 184 "parser.y" /* yacc.c:1646  */
    { /* empty */ }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 187 "parser.y" /* yacc.c:1646  */
    { /* empty */ }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(WHILESTMT,(yyvsp[-3].ptr),(yyvsp[-1].ptr),NULL,yylineno); }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(WHILETEST,(yyvsp[0].ptr),NULL,NULL,yylineno); }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 196 "parser.y" /* yacc.c:1646  */
    { /* empty */ }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 199 "parser.y" /* yacc.c:1646  */
    { /* empty */ }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 202 "parser.y" /* yacc.c:1646  */
    { /* empty */ }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Break,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"BREAK"); }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Continue,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"Continue"); }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode('+',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"+"); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode('-',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"-"); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode('*',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"*"); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode('/',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"/"); }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(UMINUS,(yyvsp[0].ptr),NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"UMINUS"); }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_IntConstant,NULL,NULL,NULL,yylineno); (yyval.ptr)->type_int = (yyvsp[0].type_int); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id)); }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[-1].ptr); }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode('%',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"%"); }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode('>',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,">"); }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode('<',(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"<"); }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Ge,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,">="); }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Le,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"<="); }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Eq,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"=="); }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Ne,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"!="); }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_Or,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"OR"); }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_And,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id,"AND"); }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(NOT,(yyvsp[0].ptr),NULL,NULL,yylineno); strcpy((yyval.ptr)->type_id,"NOT"); }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=(yyvsp[0].ptr); }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(READINT,(yyvsp[-3].ptr),(yyvsp[-1].ptr),NULL,yylineno); strcpy((yyval.ptr)->type_id, "READINT"); }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr)=mknode(T_ReadInt,NULL,NULL,NULL,yylineno); }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2008 "y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 239 "parser.y" /* yacc.c:1906  */


int main() {
    return yyparse();
}
