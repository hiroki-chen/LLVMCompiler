/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     ADD = 259,
     MINUS = 260,
     MUL = 261,
     DIV = 262,
     MOD = 263,
     INC = 264,
     DEC = 265,
     EQUAL = 266,
     NEQ = 267,
     GEQ = 268,
     LEQ = 269,
     GT = 270,
     LTT = 271,
     BIT_AND = 272,
     BIT_OR = 273,
     BIT_XOR = 274,
     BIT_NEG = 275,
     LOGIC_AND = 276,
     LOGIC_OR = 277,
     LOGIC_NOT = 278,
     DECIMAL = 279,
     OCTAL = 280,
     HEX = 281,
     STRING = 282,
     INT = 283,
     DOUBLE = 284,
     FLOAT = 285,
     CHAR = 286,
     VOID = 287,
     IF = 288,
     ELSE = 289,
     DO = 290,
     WHILE = 291,
     FOR = 292,
     RETURN = 293,
     BREAK = 294,
     CONTINUE = 295,
     CONST = 296,
     ASSIGN = 297,
     TRUE = 298,
     FALSE = 299,
     LBRACE = 300,
     RBRACE = 301,
     LPARENTHESIS = 302,
     RPARENTHESIS = 303,
     LSQUARE = 304,
     RSQUARE = 305,
     SEMICOLON = 306,
     DOT = 307,
     COMMA = 308
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define ADD 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define INC 264
#define DEC 265
#define EQUAL 266
#define NEQ 267
#define GEQ 268
#define LEQ 269
#define GT 270
#define LTT 271
#define BIT_AND 272
#define BIT_OR 273
#define BIT_XOR 274
#define BIT_NEG 275
#define LOGIC_AND 276
#define LOGIC_OR 277
#define LOGIC_NOT 278
#define DECIMAL 279
#define OCTAL 280
#define HEX 281
#define STRING 282
#define INT 283
#define DOUBLE 284
#define FLOAT 285
#define CHAR 286
#define VOID 287
#define IF 288
#define ELSE 289
#define DO 290
#define WHILE 291
#define FOR 292
#define RETURN 293
#define BREAK 294
#define CONTINUE 295
#define CONST 296
#define ASSIGN 297
#define TRUE 298
#define FALSE 299
#define LBRACE 300
#define RBRACE 301
#define LPARENTHESIS 302
#define RPARENTHESIS 303
#define LSQUARE 304
#define RSQUARE 305
#define SEMICOLON 306
#define DOT 307
#define COMMA 308




/* Copy the first part of user declarations.  */
#line 3 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"

    /*************************************************************
    parser.ypp
    YACC FILE
    Date: 2021/10/18
    Haobin Chen (@Aoyamahiroki) <etyyuiope@gmail.com>
    Jiawei Xu   (@Darren-8)

    Main tokenizer
    **************************************************************/
    #include <llvm/Support/raw_ostream.h>

    #include <common/types.hh>
    #include <runtime/runtime.hh>
    #include <nodes/item_all.hh>
    #include <parser/parser.hh>

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <stdexcept>

    //extern compiler::Symbol_table symbol_table;
    extern uint32_t yylineno;
    extern int yydebug;

    extern std::unique_ptr<compiler::CompilerRuntime> compiler_runtime;

    extern int yylex(void);
    extern int yyget_lineno(void);
    extern int yylex_destroy(void);

    #ifdef YYDEBUG
    #undef YYDEBUG
    #endif
    #define YYDEBUG 1
    # define YYLLOC_DEFAULT(Cur, Rhs, N)                          \
    do {                                                          \
        if (N) {                                                  \
            (Cur).first_line   = YYRHSLOC(Rhs, 1).first_line;     \
            (Cur).first_column = YYRHSLOC(Rhs, 1).first_column;   \
            (Cur).last_line    = YYRHSLOC(Rhs, N).last_line;      \
            (Cur).last_column  = YYRHSLOC(Rhs, N).last_column;    \
        } else {                                                  \
            (Cur).first_line   = (Cur).last_line   =              \
                YYRHSLOC(Rhs, 0).last_line;                       \
            (Cur).first_column = (Cur).last_column =              \
                YYRHSLOC(Rhs, 0).last_column;                     \
        }                                                         \
    } while (0)

    void yyerror(const char* str)
    {
        llvm::errs() << "\033[1;31;490m" << yylloc.first_line << ':'
                     << yylloc.first_column << " : [ERROR]: " << str << "\033[0m\n";
        yylex_destroy();
    }

    extern FILE* yyin;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 64 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
{
    compiler::basic_type                btype;
    compiler::Item_root*                item_root;               // root
    compiler::Item_decl*                item_decl;
    compiler::Item_stmt*                item_stmt;
    compiler::Item_stmt_decl*           item_stmt_decl;
    compiler::Item_func_def*            item_func_def;
    compiler::Item_expr*                item_expr;
    compiler::Item_expr_comma*          item_expr_comma;
    compiler::Item_ident*               item_ident;
    compiler::Item_ident_array*         item_ident_array;
    compiler::Item_decl_array_init*     item_decl_array_init;
    compiler::Item_literal*             item_literal;
    compiler::Item_literal_array_init*  item_literal_array_init;
    compiler::Item_decl_var*            item_decl_var;
    compiler::Item_decl_var_init*       item_decl_var_init;
    compiler::Item_func_def_list*       item_func_def_list;
    compiler::Item_func_def_arg*        item_func_def_arg;
    compiler::Item_func_call_list*      item_func_call_list;
    compiler::Item_block*               item_block;
    std::string*                        raw_string;
    char                                raw_char;
}
/* Line 193 of yacc.c.  */
#line 287 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.cc"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 312 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.cc"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   746

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNRULES -- Number of states.  */
#define YYNSTATES  276

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    15,    17,    20,
      23,    25,    27,    29,    31,    33,    36,    40,    44,    48,
      52,    54,    56,    60,    62,    66,    68,    73,    78,    82,
      86,    90,    93,    95,    97,   101,   105,   112,   119,   125,
     131,   135,   137,   139,   141,   144,   148,   153,   159,   163,
     168,   170,   174,   178,   180,   182,   186,   188,   192,   195,
     199,   201,   204,   206,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   226,   229,   232,   235,   239,   245,   253,
     256,   258,   264,   272,   279,   287,   294,   302,   305,   309,
     312,   315,   318,   321,   323,   325,   330,   335,   337,   339,
     343,   347,   351,   355,   357,   361,   363,   367,   371,   373,
     377,   381,   385,   389,   391,   393,   397,   401,   403,   407,
     411,   413,   417,   421,   423,   427,   431,   433,   437,   441,
     445,   447,   450,   453,   456,   459,   462,   465,   467,   469,
     473,   475,   477,   479,   481,   483,   485,   487,   489,   491,
     493,   497,   502,   506
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    55,    56,    -1,    55,    70,    -1,    56,
      -1,    70,    -1,    57,    -1,    58,    -1,    60,    51,    -1,
      61,    51,    -1,    28,    -1,    29,    -1,    30,    -1,    31,
      -1,    27,    -1,    59,    62,    -1,    60,    53,    62,    -1,
      41,    59,    67,    -1,    61,    53,    67,    -1,    59,    41,
      67,    -1,    63,    -1,    64,    -1,    75,    42,    94,    -1,
      75,    -1,    65,    42,    66,    -1,    65,    -1,    65,    49,
      92,    50,    -1,    75,    49,    92,    50,    -1,    75,    49,
      50,    -1,    65,    49,    50,    -1,    45,    76,    46,    -1,
      45,    46,    -1,    68,    -1,    69,    -1,    75,    42,    94,
      -1,    65,    42,    66,    -1,    59,    75,    47,    71,    48,
      77,    -1,    32,    75,    47,    71,    48,    77,    -1,    59,
      75,    47,    48,    77,    -1,    32,    75,    47,    48,    77,
      -1,    71,    53,    72,    -1,    72,    -1,    73,    -1,    74,
      -1,    59,    75,    -1,    41,    59,    75,    -1,    59,    75,
      49,    50,    -1,    59,    75,    49,    92,    50,    -1,    74,
      49,    50,    -1,    74,    49,    92,    50,    -1,     3,    -1,
      76,    53,    66,    -1,    76,    53,    94,    -1,    66,    -1,
      94,    -1,    94,    53,    66,    -1,    93,    -1,    93,    53,
      66,    -1,    45,    46,    -1,    45,    78,    46,    -1,    79,
      -1,    78,    79,    -1,    56,    -1,    80,    -1,    77,    -1,
      86,    -1,    87,    -1,    84,    -1,    83,    -1,    81,    -1,
      82,    -1,    88,    -1,    85,    -1,    39,    51,    -1,    40,
      51,    -1,    38,    51,    -1,    38,    92,    51,    -1,    33,
      47,    92,    48,    80,    -1,    33,    47,    92,    48,    80,
      34,    80,    -1,    92,    51,    -1,    51,    -1,    36,    47,
      92,    48,    80,    -1,    35,    77,    36,    47,    92,    48,
      51,    -1,    37,    47,    85,    85,    48,    77,    -1,    37,
      47,    85,    85,    92,    48,    77,    -1,    37,    47,    56,
      85,    48,    77,    -1,    37,    47,    56,    85,    92,    48,
      77,    -1,    89,    51,    -1,    90,    42,    92,    -1,    90,
       9,    -1,    90,    10,    -1,     9,    90,    -1,    10,    90,
      -1,    75,    -1,    91,    -1,    90,    49,    92,    50,    -1,
      91,    49,    92,    50,    -1,    94,    -1,    93,    -1,    94,
      53,    94,    -1,    93,    53,    94,    -1,    95,    22,    95,
      -1,    94,    22,    95,    -1,    95,    -1,    95,    21,    98,
      -1,    98,    -1,    97,    11,    97,    -1,    97,    12,    97,
      -1,    97,    -1,    97,    13,    97,    -1,    97,    14,    97,
      -1,    97,    15,    97,    -1,    97,    16,    97,    -1,   102,
      -1,    99,    -1,   100,    18,   100,    -1,    99,    18,   100,
      -1,   100,    -1,   101,    19,   101,    -1,   100,    19,   101,
      -1,   101,    -1,    96,    17,    96,    -1,   101,    17,    96,
      -1,    96,    -1,   102,     4,   103,    -1,   102,     5,   103,
      -1,   103,    -1,   103,     6,   104,    -1,   103,     7,   104,
      -1,   103,     8,   104,    -1,   104,    -1,     4,   104,    -1,
       5,   104,    -1,    23,   104,    -1,    20,   104,    -1,    17,
     104,    -1,     6,   104,    -1,   107,    -1,   105,    -1,    47,
      92,    48,    -1,    90,    -1,   106,    -1,    89,    -1,    26,
      -1,    25,    -1,    24,    -1,    31,    -1,    27,    -1,    43,
      -1,    44,    -1,    75,    47,    48,    -1,    75,    47,   108,
      48,    -1,   108,    53,    98,    -1,    98,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   142,   143,   144,   147,   148,   153,   156,
     159,   160,   161,   162,   163,   166,   167,   170,   171,   172,
     175,   176,   179,   180,   182,   183,   186,   187,   188,   189,
     192,   193,   196,   197,   200,   203,   206,   207,   208,   209,
     212,   213,   216,   217,   220,   221,   224,   229,   234,   235,
     238,   241,   242,   247,   248,   253,   259,   267,   278,   279,
     282,   283,   286,   287,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   301,   304,   307,   308,   311,   316,   322,
     323,   326,   331,   337,   346,   356,   365,   377,   380,   381,
     390,   399,   400,   403,   404,   407,   408,   411,   412,   415,
     416,   419,   420,   421,   424,   425,   428,   429,   430,   433,
     434,   435,   436,   437,   441,   444,   445,   446,   449,   450,
     451,   454,   455,   456,   459,   460,   461,   464,   465,   466,
     467,   470,   471,   472,   473,   474,   475,   476,   477,   480,
     481,   482,   483,   486,   487,   488,   497,   498,   499,   500,
     503,   504,   507,   508
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "ADD", "MINUS", "MUL",
  "DIV", "MOD", "INC", "DEC", "EQUAL", "NEQ", "GEQ", "LEQ", "GT", "LTT",
  "BIT_AND", "BIT_OR", "BIT_XOR", "BIT_NEG", "LOGIC_AND", "LOGIC_OR",
  "LOGIC_NOT", "DECIMAL", "OCTAL", "HEX", "STRING", "INT", "DOUBLE",
  "FLOAT", "CHAR", "VOID", "IF", "ELSE", "DO", "WHILE", "FOR", "RETURN",
  "BREAK", "CONTINUE", "CONST", "ASSIGN", "TRUE", "FALSE", "LBRACE",
  "RBRACE", "LPARENTHESIS", "RPARENTHESIS", "LSQUARE", "RSQUARE",
  "SEMICOLON", "DOT", "COMMA", "$accept", "CompUnit", "Decl",
  "VarDeclStmt", "ConstDeclStmt", "BType", "VarDecl", "ConstDecl",
  "VarDef", "VarDefNormal", "VarDefArray", "ArrayID", "ArrayInitVal",
  "ConstDef", "ConstDefNormal", "ConstDefArray", "FuncDef", "FuncDefList",
  "FuncParam", "FuncParamNormal", "FuncParamArray", "Ident",
  "ArrayInitValHelper", "BLOCK", "BlockItems", "BlockItem", "Stmt",
  "BreakStmt", "ContinueStmt", "ReturnStmt", "eIfStmt", "ExpStmt",
  "WhileStmt", "ForStmt", "AssignStmt", "Assignment", "LVal", "ArrayItem",
  "Exp", "CommaExp", "LOrExp", "LAndExp", "EqExp", "RelExp", "BitExp",
  "BitOrExp", "BitXorExp", "BitAndExp", "AddExp", "MulExp", "UnaryExp",
  "PrimaryExp", "LITERAL", "FunctionCall", "FunctionRParams", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    56,    56,    57,    58,
      59,    59,    59,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    69,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      75,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    87,    88,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    95,    95,    96,    96,    96,    97,
      97,    97,    97,    97,    98,    99,    99,    99,   100,   100,
     100,   101,   101,   101,   102,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     3,
       1,     1,     3,     1,     3,     1,     4,     4,     3,     3,
       3,     2,     1,     1,     3,     3,     6,     6,     5,     5,
       3,     1,     1,     1,     2,     3,     4,     5,     3,     4,
       1,     3,     3,     1,     1,     3,     1,     3,     2,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     3,     5,     7,     2,
       1,     5,     7,     6,     7,     6,     7,     2,     3,     2,
       2,     2,     2,     1,     1,     4,     4,     1,     1,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     2,     2,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,    10,    11,    12,    13,     0,     0,     0,     4,
       6,     7,     0,     0,     0,     5,    50,     0,     0,     1,
       2,     3,     0,    15,    20,    21,    25,    23,     8,     0,
       9,     0,     0,     0,    17,    32,    33,     0,    19,     0,
       0,     0,     0,     0,    16,    23,    18,     0,     0,     0,
       0,    41,    42,    43,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   144,   143,   147,
     146,   148,   149,     0,    29,    93,   142,   140,    94,     0,
      98,    97,   103,   123,   108,   105,   114,   117,   120,   113,
     126,   130,   138,   141,   137,    22,     0,     0,    28,     0,
       0,     0,    39,    44,     0,     0,     0,    35,    34,    31,
      53,     0,    56,    54,   131,   132,   136,    93,    91,    92,
     135,   134,   133,     0,     0,    89,    90,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    27,    45,   147,   146,     0,
       0,     0,     0,     0,     0,     0,    58,    80,    62,     0,
      64,     0,    60,    63,    69,    70,    68,    67,    72,    65,
      66,    71,   142,     0,     0,    37,    40,    48,     0,    30,
       0,     0,     0,   139,   150,   153,     0,    88,     0,     0,
     100,   102,    99,   104,   101,   121,   106,   107,   109,   110,
     111,   112,   116,   115,   119,   122,   118,   124,   125,   127,
     128,   129,    36,     0,     0,     0,     0,    75,     0,    73,
      74,    59,    61,    87,    79,    46,     0,    49,    51,    52,
      57,    55,   151,     0,    95,    96,     0,     0,     0,     0,
       0,    76,    47,   152,     0,     0,     0,     0,     0,    77,
       0,    81,     0,     0,     0,     0,     0,     0,    85,     0,
      83,     0,    78,    82,    86,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,   168,    10,    11,    49,    13,    14,    23,    24,
      25,    26,    57,    34,    35,    36,    15,    50,    51,    52,
      53,    75,   111,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    76,    77,    78,   183,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   196
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -225
static const yytype_int16 yypact[] =
{
     103,  -225,  -225,  -225,  -225,  -225,    19,   264,   123,  -225,
    -225,  -225,     2,    47,    86,  -225,  -225,   -19,    19,  -225,
    -225,  -225,    19,  -225,  -225,  -225,    35,     4,  -225,    19,
    -225,    19,   151,    36,  -225,  -225,  -225,    38,  -225,    -6,
     436,   699,   156,   465,  -225,    57,  -225,   264,    37,    19,
      26,  -225,  -225,    16,    -6,   699,   639,  -225,   699,   699,
     699,    19,    19,   699,   699,   699,  -225,  -225,  -225,  -225,
    -225,  -225,  -225,   699,  -225,    74,  -225,     3,    87,    -1,
      93,    11,   148,   140,   199,  -225,   177,   154,   126,   184,
     120,  -225,  -225,  -225,  -225,   144,    37,    71,  -225,   146,
      19,   231,  -225,   168,    37,   178,   494,  -225,   144,  -225,
    -225,    69,   150,    15,  -225,  -225,  -225,  -225,   171,   171,
    -225,  -225,  -225,   173,   552,  -225,  -225,   699,   699,   699,
    -225,   699,   699,   699,   699,   699,   699,   699,   699,   699,
     699,   699,   699,   699,   699,   699,   699,   699,   699,   699,
     699,   699,   699,  -225,    37,  -225,  -225,    18,    22,   175,
      37,   181,   182,   378,   180,   187,  -225,  -225,  -225,     2,
    -225,   280,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
    -225,  -225,   188,   198,   523,  -225,  -225,  -225,   174,  -225,
     670,   670,   670,  -225,  -225,  -225,    72,  -225,   200,   202,
     144,   232,   144,  -225,   232,  -225,   147,   147,  -225,  -225,
    -225,  -225,   244,   244,   248,  -225,   248,   120,   120,  -225,
    -225,  -225,  -225,   699,   237,   699,    66,  -225,   228,  -225,
    -225,  -225,  -225,  -225,  -225,  -225,   230,  -225,  -225,   144,
    -225,  -225,  -225,   699,  -225,  -225,   233,   240,   250,   407,
     407,  -225,  -225,  -225,   329,   699,   329,   581,   610,   254,
     251,  -225,    37,   253,    37,   266,   329,   245,  -225,    37,
    -225,    37,  -225,  -225,  -225,  -225
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -225,  -225,     1,  -225,  -225,     0,  -225,  -225,   273,  -225,
    -225,    13,   -50,     7,  -225,  -225,   304,   286,   217,  -225,
    -225,     5,  -225,   -46,  -225,   158,  -224,  -225,  -225,  -225,
    -225,  -138,  -225,  -225,  -225,   -98,   129,  -225,   -25,   274,
     -15,  -116,  -122,   105,  -114,  -225,    50,    20,  -225,    53,
      -3,  -225,  -225,  -225,  -225
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int16 yytable[] =
{
      12,     9,   102,   182,   107,    16,   110,    18,    12,    20,
     195,    17,   125,   126,   205,    79,   201,    27,    99,   204,
     203,   -14,    16,    37,   215,   -13,    95,    37,    32,    38,
     259,    33,   261,   132,    45,    33,    37,   132,    46,    56,
     108,   113,   272,    22,    33,   127,    41,   100,   123,   130,
     153,    42,   128,    43,   103,   114,   115,   116,   185,   -14,
     120,   121,   122,   -13,   133,   106,   117,   117,   192,    16,
      58,    59,    60,   182,   104,    61,    62,    39,    54,   105,
      55,   188,   101,    63,    40,    40,    64,    43,   250,    65,
      66,    67,    68,   157,     2,     3,     4,   158,    28,    41,
      29,   169,   197,   198,   199,   156,    43,     7,   222,    71,
      72,   257,   258,    73,   224,   189,   200,   167,   202,   154,
     242,   124,   190,    19,   105,   243,   150,   151,   152,   253,
       1,     2,     3,     4,     5,     6,   129,    30,   228,    31,
     238,   240,   241,   146,     7,   147,   131,   219,   220,   221,
       1,     2,     3,     4,     5,     6,   182,   136,   182,   236,
     139,   140,   141,   142,     7,   214,   132,   216,   182,   134,
     135,   169,   144,   145,    45,   239,   200,   202,     1,     2,
       3,     4,     5,     1,     2,     3,     4,     5,   148,   149,
     118,   119,    47,   212,   213,   143,   155,    47,   246,    48,
     248,   217,   218,   191,    96,     1,     2,     3,     4,     5,
     137,   138,   139,   140,   141,   142,   268,   184,   270,    47,
     128,   193,   223,   274,   237,   275,   169,   249,   225,   226,
     260,   229,   263,   265,    16,    58,    59,    60,   230,   233,
      61,    62,   206,   207,   208,   209,   210,   211,    63,   234,
     244,    64,   245,   134,    65,    66,    67,    68,   157,     2,
       3,     4,   158,   145,   159,   146,   160,   161,   162,   163,
     164,   165,     7,   247,    71,    72,   101,   166,    73,   251,
     252,   254,   167,    16,    58,    59,    60,   255,   266,    61,
      62,     1,     2,     3,     4,     5,   273,    63,   256,   267,
      64,   269,    44,    65,    66,    67,    68,   157,     2,     3,
       4,   158,    21,   159,   271,   160,   161,   162,   163,   164,
     165,     7,   186,    71,    72,   101,   231,    73,    97,   232,
     112,   167,    16,    58,    59,    60,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,    63,     0,     0,    64,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      70,     0,   159,     0,   160,   161,   162,   163,   164,   165,
       0,     0,    71,    72,   101,     0,    73,     0,     0,     0,
     167,    16,    58,    59,    60,     0,     0,    61,    62,     0,
       0,     0,     0,     0,     0,    63,     0,     0,    64,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    70,
      16,    58,    59,    60,     0,     0,    61,    62,     0,     0,
       0,    71,    72,     0,    63,    73,     0,    64,     0,   227,
      65,    66,    67,    68,    69,     0,     0,     0,    70,    16,
      58,    59,    60,     0,     0,    61,    62,     0,     0,     0,
      71,    72,     0,    63,    73,     0,    64,     0,   167,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    16,    58,
      59,    60,     0,     0,    61,    62,     0,     0,     0,    71,
      72,     0,    63,    73,     0,    64,    74,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    70,    16,    58,    59,
      60,     0,     0,    61,    62,     0,     0,     0,    71,    72,
       0,    63,    73,     0,    64,    98,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    70,    16,    58,    59,    60,
       0,     0,    61,    62,     0,     0,     0,    71,    72,     0,
      63,    73,     0,    64,   187,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    16,    58,    59,    60,     0,
       0,    61,    62,     0,     0,     0,    71,    72,     0,    63,
      73,     0,    64,   235,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    16,    58,    59,    60,     0,     0,
      61,    62,     0,     0,     0,    71,    72,     0,    63,    73,
     194,    64,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    70,    16,    58,    59,    60,     0,     0,    61,
      62,     0,     0,     0,    71,    72,     0,    63,    73,   262,
      64,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    16,    58,    59,    60,     0,     0,    61,    62,
       0,     0,     0,    71,    72,     0,    63,    73,   264,    64,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      70,     0,     0,    16,    58,    59,    60,     0,     0,    61,
      62,     0,    71,    72,    56,   109,    73,    63,     0,     0,
      64,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    70,    16,    58,    59,    60,     0,     0,    61,    62,
       0,     0,     0,    71,    72,    56,    63,    73,     0,    64,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,    73
};

static const yytype_int16 yycheck[] =
{
       0,     0,    48,   101,    54,     3,    56,     7,     8,     8,
     124,     6,     9,    10,   136,    40,   132,    12,    43,   135,
     134,     3,     3,    18,   146,     3,    41,    22,    47,    22,
     254,    18,   256,    22,    29,    22,    31,    22,    31,    45,
      55,    56,   266,    41,    31,    42,    42,    47,    73,    50,
      96,    47,    49,    49,    49,    58,    59,    60,   104,    41,
      63,    64,    65,    41,    53,    49,    61,    62,    53,     3,
       4,     5,     6,   171,    48,     9,    10,    42,    42,    53,
      42,   106,    45,    17,    49,    49,    20,    49,   226,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    51,    42,
      53,   101,   127,   128,   129,   100,    49,    41,   154,    43,
      44,   249,   250,    47,   160,    46,   131,    51,   133,    48,
      48,    47,    53,     0,    53,    53,     6,     7,     8,   243,
      27,    28,    29,    30,    31,    32,    49,    51,   163,    53,
     190,   191,   192,    17,    41,    19,    53,   150,   151,   152,
      27,    28,    29,    30,    31,    32,   254,    17,   256,   184,
      13,    14,    15,    16,    41,   145,    22,   147,   266,    21,
      22,   171,    18,    19,   169,   190,   191,   192,    27,    28,
      29,    30,    31,    27,    28,    29,    30,    31,     4,     5,
      61,    62,    41,   143,   144,    18,    50,    41,   223,    48,
     225,   148,   149,    53,    48,    27,    28,    29,    30,    31,
      11,    12,    13,    14,    15,    16,   262,    49,   264,    41,
      49,    48,    47,   269,    50,   271,   226,   226,    47,    47,
     255,    51,   257,   258,     3,     4,     5,     6,    51,    51,
       9,    10,   137,   138,   139,   140,   141,   142,    17,    51,
      50,    20,    50,    21,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    19,    33,    17,    35,    36,    37,    38,
      39,    40,    41,    36,    43,    44,    45,    46,    47,    51,
      50,    48,    51,     3,     4,     5,     6,    47,    34,     9,
      10,    27,    28,    29,    30,    31,    51,    17,    48,    48,
      20,    48,    29,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     8,    33,    48,    35,    36,    37,    38,    39,
      40,    41,   105,    43,    44,    45,    46,    47,    42,   171,
      56,    51,     3,     4,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    33,    -1,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    44,    45,    -1,    47,    -1,    -1,    -1,
      51,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      -1,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    43,    44,    -1,    17,    47,    -1,    20,    -1,    51,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,     3,
       4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,
      43,    44,    -1,    17,    47,    -1,    20,    -1,    51,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,    43,
      44,    -1,    17,    47,    -1,    20,    50,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    -1,    -1,    43,    44,
      -1,    17,    47,    -1,    20,    50,    -1,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    -1,    43,    44,    -1,
      17,    47,    -1,    20,    50,    -1,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,     3,     4,     5,     6,    -1,
      -1,     9,    10,    -1,    -1,    -1,    43,    44,    -1,    17,
      47,    -1,    20,    50,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    -1,    43,    44,    -1,    17,    47,
      48,    20,    -1,    -1,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    43,    44,    -1,    17,    47,    48,
      20,    -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     3,     4,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    -1,    43,    44,    -1,    17,    47,    48,    20,
      -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    43,    44,    45,    46,    47,    17,    -1,    -1,
      20,    -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     3,     4,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    -1,    43,    44,    45,    17,    47,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    28,    29,    30,    31,    32,    41,    55,    56,
      57,    58,    59,    60,    61,    70,     3,    75,    59,     0,
      56,    70,    41,    62,    63,    64,    65,    75,    51,    53,
      51,    53,    47,    65,    67,    68,    69,    75,    67,    42,
      49,    42,    47,    49,    62,    75,    67,    41,    48,    59,
      71,    72,    73,    74,    42,    42,    45,    66,     4,     5,
       6,     9,    10,    17,    20,    23,    24,    25,    26,    27,
      31,    43,    44,    47,    50,    75,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    94,    48,    71,    50,    92,
      59,    45,    77,    75,    48,    53,    49,    66,    94,    46,
      66,    76,    93,    94,   104,   104,   104,    75,    90,    90,
     104,   104,   104,    92,    47,     9,    10,    42,    49,    49,
      50,    53,    22,    53,    21,    22,    17,    11,    12,    13,
      14,    15,    16,    18,    18,    19,    17,    19,     4,     5,
       6,     7,     8,    77,    48,    50,    75,    27,    31,    33,
      35,    36,    37,    38,    39,    40,    46,    51,    56,    59,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    92,    49,    77,    72,    50,    92,    46,
      53,    53,    53,    48,    48,    98,   108,    92,    92,    92,
      94,    95,    94,    98,    95,    96,    97,    97,    97,    97,
      97,    97,   100,   100,   101,    96,   101,   103,   103,   104,
     104,   104,    77,    47,    77,    47,    47,    51,    92,    51,
      51,    46,    79,    51,    51,    50,    92,    50,    66,    94,
      66,    66,    48,    53,    50,    50,    92,    36,    92,    56,
      85,    51,    50,    98,    48,    47,    48,    85,    85,    80,
      92,    80,    48,    92,    48,    92,    34,    48,    77,    48,
      77,    48,    80,    51,    77,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
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
     `$$ = $1'.

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
#line 141 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_root)->add_child((yyvsp[(2) - (2)].item_decl)); ;}
    break;

  case 3:
#line 142 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_root)->add_child((yyvsp[(2) - (2)].item_func_def)); ;}
    break;

  case 4:
#line 143 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->setRoot((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[(1) - (1)].item_decl)); ;}
    break;

  case 5:
#line 144 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->setRoot((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[(1) - (1)].item_func_def)); ;}
    break;

  case 8:
#line 153 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); ;}
    break;

  case 9:
#line 156 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); ;}
    break;

  case 10:
#line 159 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::INT_TYPE; ;}
    break;

  case 11:
#line 160 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; ;}
    break;

  case 12:
#line 161 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; ;}
    break;

  case 13:
#line 162 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::CHAR_TYPE; ;}
    break;

  case 14:
#line 163 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::STR_TYPE; ;}
    break;

  case 15:
#line 166 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(1) - (2)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(2) - (2)].item_decl)); ;}
    break;

  case 16:
#line 167 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 17:
#line 170 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(2) - (3)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 18:
#line 171 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 19:
#line 172 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(1) - (3)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 22:
#line 179 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr), false); ;}
    break;

  case 23:
#line 180 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var(yyget_lineno(), (yyvsp[(1) - (1)].item_ident)); ;}
    break;

  case 24:
#line 182 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_array), (yyvsp[(3) - (3)].item_literal_array_init), false); ;}
    break;

  case 25:
#line 183 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array(yyget_lineno(), (yyvsp[(1) - (1)].item_ident_array)); ;}
    break;

  case 26:
#line 186 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (4)].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 27:
#line 187 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (4)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 28:
#line 188 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (3)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape(nullptr); ;}
    break;

  case 29:
#line 189 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (3)].item_ident_array); (yyval.item_ident_array)->add_shape(nullptr); ;}
    break;

  case 30:
#line 192 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal_array_init) = (yyvsp[(2) - (3)].item_literal_array_init); ;}
    break;

  case 31:
#line 193 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); ;}
    break;

  case 34:
#line 200 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr), true); ;}
    break;

  case 35:
#line 203 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_array), (yyvsp[(3) - (3)].item_literal_array_init), true); ;}
    break;

  case 36:
#line 206 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[(1) - (6)].btype), (yyvsp[(2) - (6)].item_ident), (yyvsp[(4) - (6)].item_func_def_list), (yyvsp[(6) - (6)].item_block)); ;}
    break;

  case 37:
#line 207 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[(2) - (6)].item_ident), (yyvsp[(4) - (6)].item_func_def_list), (yyvsp[(6) - (6)].item_block)); ;}
    break;

  case 38:
#line 208 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[(1) - (5)].btype), (yyvsp[(2) - (5)].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[(5) - (5)].item_block)); ;}
    break;

  case 39:
#line 209 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[(2) - (5)].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[(5) - (5)].item_block)); ;}
    break;

  case 40:
#line 212 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def_list)->add_arg((yyvsp[(3) - (3)].item_func_def_arg)); ;}
    break;

  case 41:
#line 213 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def_list) = new compiler::Item_func_def_list(yyget_lineno()); (yyval.item_func_def_list)->add_arg((yyvsp[(1) - (1)].item_func_def_arg)); ;}
    break;

  case 44:
#line 220 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (2)].btype), (yyvsp[(2) - (2)].item_ident)); ;}
    break;

  case 45:
#line 221 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(2) - (3)].btype), (yyvsp[(3) - (3)].item_ident)); ;}
    break;

  case 46:
#line 224 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(2) - (4)].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (4)].btype), ident);
                                                        ;}
    break;

  case 47:
#line 229 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(2) - (5)].item_ident)->get_name());
                                                            ident->add_shape((yyvsp[(4) - (5)].item_expr));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (5)].btype), ident);
                                                        ;}
    break;

  case 48:
#line 234 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def_arg) = (yyvsp[(1) - (3)].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); ;}
    break;

  case 49:
#line 235 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_def_arg) = (yyvsp[(1) - (4)].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 50:
#line 238 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_ident) = new compiler::Item_ident(yyget_lineno(), *(yyvsp[(1) - (1)].raw_string)); ;}
    break;

  case 51:
#line 241 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal_array_init) = (yyvsp[(1) - (3)].item_literal_array_init); (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init)); ;}
    break;

  case 52:
#line 242 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = (yyvsp[(1) - (3)].item_literal_array_init);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(3) - (3)].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                              ;}
    break;

  case 53:
#line 247 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); (yyval.item_literal_array_init)->add_value((yyvsp[(1) - (1)].item_literal_array_init)); ;}
    break;

  case 54:
#line 248 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(1) - (1)].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init); 
                                                              ;}
    break;

  case 55:
#line 253 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                                (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init));
                                                              ;}
    break;

  case 56:
#line 260 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { 
                    (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                    for (auto expr : (yyvsp[(1) - (1)].item_expr_comma)->get_expressions()) {
                        (yyval.item_literal_array_init)->add_value(new compiler::Item_literal_array_init(yyget_lineno(), expr, true));
                    }
                    delete (yyvsp[(1) - (1)].item_expr_comma);                                                
                  ;}
    break;

  case 57:
#line 268 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
                    (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                    for (auto expr : (yyvsp[(1) - (3)].item_expr_comma)->get_expressions()) {
                        (yyval.item_literal_array_init)->add_value(new compiler::Item_literal_array_init(yyget_lineno(), expr, true));
                    }
                    (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init));
                    delete (yyvsp[(1) - (3)].item_expr_comma);
                  ;}
    break;

  case 58:
#line 278 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); ;}
    break;

  case 59:
#line 279 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_block) = (yyvsp[(2) - (3)].item_block); ;}
    break;

  case 60:
#line 282 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); (yyval.item_block)->add_item((yyvsp[(1) - (1)].item_stmt)); ;}
    break;

  case 61:
#line 283 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_block) = (yyvsp[(1) - (2)].item_block); (yyval.item_block)->add_item((yyvsp[(2) - (2)].item_stmt)); ;}
    break;

  case 62:
#line 286 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 63:
#line 287 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 64:
#line 290 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 73:
#line 301 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_break(yyget_lineno()); ;}
    break;

  case 74:
#line 304 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_continue(yyget_lineno()); ;}
    break;

  case 75:
#line 307 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), nullptr); ;}
    break;

  case 76:
#line 308 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), (yyvsp[(2) - (3)].item_expr)); ;}
    break;

  case 77:
#line 312 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
    compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[(3) - (5)].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), condition, (yyvsp[(5) - (5)].item_stmt), new compiler::Item_stmt_void(yyget_lineno())); 
;}
    break;

  case 78:
#line 317 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[(3) - (7)].item_expr));
  (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), condition, (yyvsp[(5) - (7)].item_stmt), (yyvsp[(7) - (7)].item_stmt)); 
;}
    break;

  case 79:
#line 322 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_eval(yyget_lineno(), (yyvsp[(1) - (2)].item_expr)); ;}
    break;

  case 80:
#line 323 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_void(yyget_lineno()); ;}
    break;

  case 81:
#line 327 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
    compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[(3) - (5)].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[(5) - (5)].item_stmt)); 
;}
    break;

  case 82:
#line 332 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {   compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[(5) - (7)].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[(2) - (7)].item_block), true); 
;}
    break;

  case 83:
#line 338 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
             compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
             block->add_item((yyvsp[(3) - (6)].item_stmt));
             compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[(4) - (6)].item_stmt)));
             compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[(6) - (6)].item_block));
             block->add_item(while_stmt);
             (yyval.item_stmt) = block;
         ;}
    break;

  case 84:
#line 347 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[(3) - (7)].item_stmt));
           (yyvsp[(7) - (7)].item_block)->add_item(static_cast<compiler::Item_stmt*>((yyvsp[(5) - (7)].item_expr)));
           compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[(4) - (7)].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(),condition, (yyvsp[(7) - (7)].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       ;}
    break;

  case 85:
#line 357 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[(3) - (6)].item_stmt_decl));
            compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[(4) - (6)].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[(6) - (6)].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       ;}
    break;

  case 86:
#line 366 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[(3) - (7)].item_stmt_decl));
           (yyvsp[(7) - (7)].item_block)->add_item(static_cast<compiler::Item_stmt*>((yyvsp[(5) - (7)].item_expr)));
        compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[(4) - (7)].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(),condition, (yyvsp[(7) - (7)].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       ;}
    break;

  case 87:
#line 377 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (2)].item_stmt); ;}
    break;

  case 88:
#line 380 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 89:
#line 381 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::ADD_TYPE,
                                                    (yyvsp[(1) - (2)].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (2)].item_ident), expr);
                                      ;}
    break;

  case 90:
#line 390 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::SUB_TYPE,
                                                    (yyvsp[(1) - (2)].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (2)].item_ident), expr);
                                      ;}
    break;

  case 91:
#line 399 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[(2) - (2)].item_ident), compiler::binary_type::ADD_TYPE); ;}
    break;

  case 92:
#line 400 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[(2) - (2)].item_ident), compiler::binary_type::SUB_TYPE); ;}
    break;

  case 94:
#line 404 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_ident) = (yyvsp[(1) - (1)].item_ident); ;}
    break;

  case 95:
#line 407 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (4)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr));;}
    break;

  case 96:
#line 408 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (4)].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 98:
#line 412 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 99:
#line 415 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr_comma) = new compiler::Item_expr_comma(yyget_lineno()); (yyval.item_expr_comma)->add_expression((yyvsp[(1) - (3)].item_expr)); (yyval.item_expr_comma)->add_expression((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 100:
#line 416 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr_comma) = (yyvsp[(1) - (3)].item_expr_comma); (yyval.item_expr_comma)->add_expression((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 101:
#line 419 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 102:
#line 420 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 104:
#line 424 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 106:
#line 428 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::EQ_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 107:
#line 429 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::NEQ_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 109:
#line 433 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::GE_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 110:
#line 434 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LE_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 111:
#line 435 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::G_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 112:
#line 436 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::L_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 115:
#line 444 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 116:
#line 445 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 118:
#line 449 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 119:
#line 450 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 121:
#line 454 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 122:
#line 455 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 124:
#line 459 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::ADD_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 125:
#line 460 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::SUB_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 127:
#line 464 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MUL_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 128:
#line 465 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::DIV_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 129:
#line 466 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MOD_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 131:
#line 470 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UADD_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 132:
#line 471 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UMINUS_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 133:
#line 472 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::LNOT_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 134:
#line 473 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::BITNEG_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 135:
#line 474 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UREF_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 136:
#line 475 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UDEREFER_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 139:
#line 480 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(2) - (3)].item_expr); ;}
    break;

  case 140:
#line 481 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 141:
#line 482 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 142:
#line 483 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 143:
#line 486 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), std::stol(*(yyvsp[(1) - (1)].raw_string))); ;}
    break;

  case 144:
#line 487 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), std::stol(*(yyvsp[(1) - (1)].raw_string))); ;}
    break;

  case 145:
#line 489 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { 
          if (((yyvsp[(1) - (1)].raw_string))->find(".") != std::string::npos) {
            (yyval.item_literal) = new compiler::Item_literal_real(yyget_lineno(), std::stod(*(yyvsp[(1) - (1)].raw_string))); 
          } else {
            (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), std::stol(*(yyvsp[(1) - (1)].raw_string))); 
          }
          
        ;}
    break;

  case 146:
#line 497 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_char(yyget_lineno(), (yyvsp[(1) - (1)].raw_char)); ;}
    break;

  case 147:
#line 498 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_string(yyget_lineno(), *(yyvsp[(1) - (1)].raw_string)); ;}
    break;

  case 148:
#line 499 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 1); ;}
    break;

  case 149:
#line 500 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 0); ;}
    break;

  case 150:
#line 503 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), new compiler::Item_func_call_list(yyget_lineno())); ;}
    break;

  case 151:
#line 504 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[(1) - (4)].item_ident), (yyvsp[(3) - (4)].item_func_call_list)); ;}
    break;

  case 152:
#line 507 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_call_list) = (yyvsp[(1) - (3)].item_func_call_list); (yyvsp[(1) - (3)].item_func_call_list)->add_arg((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 153:
#line 508 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
    { (yyval.item_func_call_list) = new compiler::Item_func_call_list(yyget_lineno()); (yyval.item_func_call_list)->add_arg((yyvsp[(1) - (1)].item_expr)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2597 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 510 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"

