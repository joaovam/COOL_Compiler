/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         cool_yyparse
#define yylex           cool_yylex
#define yyerror         cool_yyerror
#define yydebug         cool_yydebug
#define yynerrs         cool_yynerrs
#define yylval          cool_yylval
#define yychar          cool_yychar

/* First part of user prologue.  */
#line 6 "cool.y"

#include <iostream>
#include "cool-tree.h"
#include "stringtab.h"
#include "utilities.h"

extern char *curr_filename;

void yyerror(char *s);        /*  defined below; called for each parse error */
extern int yylex();           /*  the entry point to the lexer  */

/************************************************************************/
/*                DONT CHANGE ANYTHING IN THIS SECTION                  */

Program ast_root;	      /* the result of the parse  */
Classes parse_results;        /* for use in semantic analysis */
int omerrs = 0;               /* number of errors in lexing and parsing */

#line 97 "cool.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cool.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS = 3,                      /* CLASS  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FI = 5,                         /* FI  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_IN = 7,                         /* IN  */
  YYSYMBOL_INHERITS = 8,                   /* INHERITS  */
  YYSYMBOL_LET = 9,                        /* LET  */
  YYSYMBOL_LOOP = 10,                      /* LOOP  */
  YYSYMBOL_POOL = 11,                      /* POOL  */
  YYSYMBOL_THEN = 12,                      /* THEN  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_ESAC = 15,                      /* ESAC  */
  YYSYMBOL_OF = 16,                        /* OF  */
  YYSYMBOL_DARROW = 17,                    /* DARROW  */
  YYSYMBOL_NEW = 18,                       /* NEW  */
  YYSYMBOL_ISVOID = 19,                    /* ISVOID  */
  YYSYMBOL_STR_CONST = 20,                 /* STR_CONST  */
  YYSYMBOL_INT_CONST = 21,                 /* INT_CONST  */
  YYSYMBOL_BOOL_CONST = 22,                /* BOOL_CONST  */
  YYSYMBOL_TYPEID = 23,                    /* TYPEID  */
  YYSYMBOL_OBJECTID = 24,                  /* OBJECTID  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_ERROR = 28,                     /* ERROR  */
  YYSYMBOL_LET_ = 29,                      /* LET_  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '~'  */
  YYSYMBOL_37_ = 37,                       /* '@'  */
  YYSYMBOL_38_ = 38,                       /* '.'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_class_list = 48,                /* class_list  */
  YYSYMBOL_class = 49,                     /* class  */
  YYSYMBOL_feature_list = 50,              /* feature_list  */
  YYSYMBOL_nonempty_feature_list = 51,     /* nonempty_feature_list  */
  YYSYMBOL_feature = 52,                   /* feature  */
  YYSYMBOL_formal_list = 53,               /* formal_list  */
  YYSYMBOL_nonempty_formal_list = 54,      /* nonempty_formal_list  */
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_expression_list = 56,           /* expression_list  */
  YYSYMBOL_let_list = 57,                  /* let_list  */
  YYSYMBOL_case_list = 58,                 /* case_list  */
  YYSYMBOL_case_ = 59,                     /* case_  */
  YYSYMBOL_nonempty_expression_list = 60,  /* nonempty_expression_list  */
  YYSYMBOL_expression_semicolon_list = 61, /* expression_semicolon_list  */
  YYSYMBOL_expression = 62                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    34,    32,    45,    33,    38,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    41,
      31,    30,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,    36,     2,     2,     2,
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
      25,    26,    27,    28,     2,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   110,   113,   119,   122,   129,   130,   134,
     136,   139,   142,   145,   148,   152,   153,   158,   160,   165,
     170,   171,   175,   177,   179,   181,   183,   187,   189,   192,
     196,   198,   202,   205,   210,   212,   215,   218,   221,   224,
     227,   230,   233,   236,   239,   242,   245,   248,   250,   252,
     254,   256,   258,   260,   262,   264,   266,   268,   270,   272,
     274,   276,   278,   280
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "ELSE", "FI",
  "IF", "IN", "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE",
  "ESAC", "OF", "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST",
  "BOOL_CONST", "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR",
  "LET_", "'='", "'<'", "'+'", "'-'", "'*'", "'/'", "'~'", "'@'", "'.'",
  "'{'", "'}'", "';'", "'('", "')'", "':'", "','", "$accept", "program",
  "class_list", "class", "feature_list", "nonempty_feature_list",
  "feature", "formal_list", "nonempty_formal_list", "declaration",
  "expression_list", "let_list", "case_list", "case_",
  "nonempty_expression_list", "expression_semicolon_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,     3,    22,    13,   -99,    -4,   -99,   -99,     4,     5,
     -11,    21,   -23,     9,    10,   -99,     5,   -99,    20,    31,
      24,   -99,    40,    37,    30,   -99,   -99,   -17,   -99,    43,
      62,    44,    20,   284,   -99,   -99,   -99,    64,   -99,    49,
     284,     1,   284,   284,    68,   284,   -99,   -99,   -99,    69,
     284,   284,   284,   284,   410,    56,   284,   375,    51,    55,
     351,   387,   -99,    59,   284,   446,    59,    61,   446,   396,
     284,   284,   284,   284,   284,   284,   284,    76,   -99,   284,
      66,   284,    12,   -99,    82,   284,    86,   446,   112,   -99,
     455,   455,   455,    23,    23,    59,    59,    70,   434,   155,
     325,    51,    67,     8,   366,    83,    -1,   -99,    73,   446,
      50,    79,   284,   -99,   106,   284,   284,   -99,   -99,   114,
     -99,   -99,   198,    92,    95,   446,   -99,   341,    53,   446,
     300,   124,   108,   -99,   284,   -99,   284,   284,   -99,   284,
     -99,   284,   241,   446,   446,   309,   446,   422,   284,   -99,
     -99,   446
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    14,    15,     0,
       0,    10,     0,     0,     0,    16,    17,     0,     5,     0,
       0,     0,     0,     0,    12,     6,    19,     0,    18,     0,
       0,     0,     0,     0,     0,     0,    62,    61,    63,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     0,    58,    54,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,    46,     0,     0,     0,    34,     0,    59,
      56,    57,    55,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    33,
       0,     0,     0,    26,     0,     0,     0,    44,    36,     0,
      47,    28,     0,     0,    21,    30,    11,     0,     0,    42,
       0,     0,     0,    35,     0,    37,     0,     0,    22,     0,
      45,     0,     0,    31,    23,     0,    43,     0,     0,    24,
      29,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   160,   142,   -99,   156,   -99,   -99,   140,
     -99,   -98,   -99,    72,   -99,   -55,   -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    13,    14,    15,    24,    25,    26,
     123,    83,   106,   107,   124,    67,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    80,    58,   113,     8,   117,    11,    57,    33,    60,
      61,    11,    63,   101,   120,   115,     1,    65,    66,    18,
      69,    19,     6,   105,    34,    59,     5,    10,    16,    12,
     138,    87,   140,   116,    12,     9,   102,    90,    91,    92,
      93,    94,    95,    96,    23,    -7,    98,   149,   100,    20,
      -8,    39,   104,    82,    27,   109,    40,    75,    76,    41,
     136,    77,    17,    42,    43,    28,   109,   132,    44,    45,
      46,    47,    48,    31,    49,    32,    50,   125,   137,   127,
      29,    30,   129,   130,    35,    36,    51,    55,    37,    52,
      56,    62,    53,   -20,    64,    79,    82,    77,    82,    84,
      97,   143,    88,   144,   145,   103,   146,    99,   147,   109,
     105,   114,   110,   108,   122,   151,   -38,   -38,    40,   -38,
     126,    41,   -38,   -38,   -38,    42,    43,   119,   -38,   128,
      44,    45,    46,    47,    48,   133,    49,   131,    50,   -38,
     134,   141,   -38,   -38,   -38,   -38,   -38,   -38,    51,   142,
     -38,    52,   -38,   -38,    53,   -38,    39,   -38,    22,   -41,
     -41,    40,   -41,     7,    41,   -41,   -41,   -41,    42,    43,
      21,   -41,    38,    44,    45,    46,    47,    48,   121,    49,
       0,    50,   -41,     0,     0,   -41,   -41,   -41,   -41,   -41,
     -41,    51,     0,   -41,    52,   -41,   -41,    53,   -41,    39,
     -41,     0,   -39,   -39,    40,   -39,     0,    41,   -39,   -39,
     -39,    42,    43,     0,   -39,     0,    44,    45,    46,    47,
      48,     0,    49,     0,    50,   -39,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -39,    51,     0,   -39,    52,   -39,   -39,
      53,   -39,    39,   -39,     0,   -40,   -40,    40,   -40,     0,
      41,   -40,   -40,   -40,    42,    43,     0,   -40,     0,    44,
      45,    46,    47,    48,     0,    49,     0,    50,   -40,     0,
       0,   -40,   -40,   -40,   -40,   -40,   -40,    51,     0,   -40,
      52,   -40,   -40,    53,   -40,    39,   -40,     0,     0,     0,
      40,     0,     0,    41,     0,     0,     0,    42,    43,     0,
       0,     0,    44,    45,    46,    47,    48,   139,    49,     0,
      50,     0,     0,     0,     0,     0,   148,     0,     0,     0,
      51,     0,     0,    52,     0,     0,    53,    70,     0,   112,
      71,    72,    73,    74,    75,    76,    70,     0,    77,    71,
      72,    73,    74,    75,    76,    82,   135,    77,     0,     0,
       0,     0,    70,     0,    82,    71,    72,    73,    74,    75,
      76,    85,     0,    77,     0,     0,     0,     0,    70,     0,
       0,    71,    72,    73,    74,    75,    76,   118,    70,    77,
       0,    71,    72,    73,    74,    75,    76,    81,     0,    77,
       0,     0,     0,    70,     0,     0,    71,    72,    73,    74,
      75,    76,    70,    86,    77,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    70,     0,     0,    71,    72,    73,
      74,    75,    76,    70,     0,    77,    71,    72,    73,    74,
      75,    76,     0,     0,    77,     0,     0,    70,     0,    89,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    70,
       0,    78,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    70,     0,   150,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    70,   111,     0,    71,    72,    73,    74,
      75,    76,   -42,     0,    77,   -42,   -42,    73,    74,    75,
      76,     0,     0,    77
};

static const yytype_int16 yycheck[] =
{
      33,    56,     1,   101,     8,   103,     1,    40,    25,    42,
      43,     1,    45,     1,    15,     7,     3,    50,    51,    42,
      53,    44,     0,    24,    41,    24,    23,    23,    39,    24,
     128,    64,   130,    25,    24,    39,    24,    70,    71,    72,
      73,    74,    75,    76,    24,    40,    79,   145,    81,    40,
      40,     1,    85,    45,    23,    88,     6,    34,    35,     9,
       7,    38,    41,    13,    14,    41,    99,   122,    18,    19,
      20,    21,    22,    43,    24,    45,    26,   110,    25,   112,
      40,    44,   115,   116,    41,    23,    36,    23,    44,    39,
      41,    23,    42,    43,    25,    39,    45,    38,    45,    44,
      24,   134,    41,   136,   137,    23,   139,    41,   141,   142,
      24,    44,    42,     1,    41,   148,     4,     5,     6,     7,
      41,     9,    10,    11,    12,    13,    14,    44,    16,    23,
      18,    19,    20,    21,    22,    43,    24,    23,    26,    27,
      45,    17,    30,    31,    32,    33,    34,    35,    36,    41,
      38,    39,    40,    41,    42,    43,     1,    45,    16,     4,
       5,     6,     7,     3,     9,    10,    11,    12,    13,    14,
      14,    16,    32,    18,    19,    20,    21,    22,   106,    24,
      -1,    26,    27,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,     1,
      45,    -1,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,     1,    45,    -1,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,     1,    45,    -1,    -1,    -1,
       6,    -1,    -1,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,     7,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,
      36,    -1,    -1,    39,    -1,    -1,    42,    27,    -1,     4,
      30,    31,    32,    33,    34,    35,    27,    -1,    38,    30,
      31,    32,    33,    34,    35,    45,     5,    38,    -1,    -1,
      -1,    -1,    27,    -1,    45,    30,    31,    32,    33,    34,
      35,    10,    -1,    38,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    11,    27,    38,
      -1,    30,    31,    32,    33,    34,    35,    12,    -1,    38,
      -1,    -1,    -1,    27,    -1,    -1,    30,    31,    32,    33,
      34,    35,    27,    16,    38,    30,    31,    32,    33,    34,
      35,    -1,    -1,    38,    27,    -1,    -1,    30,    31,    32,
      33,    34,    35,    27,    -1,    38,    30,    31,    32,    33,
      34,    35,    -1,    -1,    38,    -1,    -1,    27,    -1,    43,
      30,    31,    32,    33,    34,    35,    -1,    -1,    38,    27,
      -1,    41,    30,    31,    32,    33,    34,    35,    -1,    -1,
      38,    27,    -1,    41,    30,    31,    32,    33,    34,    35,
      -1,    -1,    38,    27,    40,    -1,    30,    31,    32,    33,
      34,    35,    27,    -1,    38,    30,    31,    32,    33,    34,
      35,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    48,    49,    23,     0,    49,     8,    39,
      23,     1,    24,    50,    51,    52,    39,    41,    42,    44,
      40,    52,    50,    24,    53,    54,    55,    23,    41,    40,
      44,    43,    45,    25,    41,    41,    23,    44,    55,     1,
       6,     9,    13,    14,    18,    19,    20,    21,    22,    24,
      26,    36,    39,    42,    62,    23,    41,    62,     1,    24,
      62,    62,    23,    62,    25,    62,    62,    61,    62,    62,
      27,    30,    31,    32,    33,    34,    35,    38,    41,    39,
      61,    12,    45,    57,    44,    10,    16,    62,    41,    43,
      62,    62,    62,    62,    62,    62,    62,    24,    62,    41,
      62,     1,    24,    23,    62,    24,    58,    59,     1,    62,
      42,    40,     4,    57,    44,     7,    25,    57,    11,    44,
      15,    59,    41,    56,    60,    62,    41,    62,    23,    62,
      62,    23,    61,    43,    45,     5,     7,    25,    57,     7,
      57,    17,    41,    62,    62,    62,    62,    62,     7,    57,
      41,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     8,     0,     1,     1,
       2,    10,     4,     6,     2,     0,     1,     1,     3,     3,
       0,     1,     5,     6,     7,     8,     3,     1,     2,     6,
       1,     3,     1,     3,     3,     6,     5,     7,     3,     5,
       7,     4,     6,     8,     5,     7,     3,     5,     2,     2,
       3,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: class_list  */
#line 106 "cool.y"
                        { ast_root = program((yyvsp[0].classes)); }
#line 1306 "cool.tab.c"
    break;

  case 3: /* class_list: class  */
#line 111 "cool.y"
                { (yyval.classes) = single_Classes((yyvsp[0].class_));
                  parse_results = (yyval.classes); }
#line 1313 "cool.tab.c"
    break;

  case 4: /* class_list: class_list class  */
#line 114 "cool.y"
                { (yyval.classes) = append_Classes((yyvsp[-1].classes),single_Classes((yyvsp[0].class_))); 
                  parse_results = (yyval.classes); }
#line 1320 "cool.tab.c"
    break;

  case 5: /* class: CLASS TYPEID '{' feature_list '}' ';'  */
#line 120 "cool.y"
                { (yyval.class_) = class_((yyvsp[-4].symbol), idtable.add_string("Object"),(yyvsp[-2].features),
			      stringtable.add_string(curr_filename)); }
#line 1327 "cool.tab.c"
    break;

  case 6: /* class: CLASS TYPEID INHERITS TYPEID '{' feature_list '}' ';'  */
#line 123 "cool.y"
                { (yyval.class_) = class_((yyvsp[-6].symbol),(yyvsp[-4].symbol),(yyvsp[-2].features),stringtable.add_string(curr_filename)); }
#line 1333 "cool.tab.c"
    break;

  case 7: /* feature_list: %empty  */
#line 129 "cool.y"
    {  (yyval.features) = nil_Features(); }
#line 1339 "cool.tab.c"
    break;

  case 8: /* feature_list: nonempty_feature_list  */
#line 130 "cool.y"
                        {}
#line 1345 "cool.tab.c"
    break;

  case 9: /* nonempty_feature_list: feature  */
#line 134 "cool.y"
            {(yyval.features) = nil_Features();}
#line 1351 "cool.tab.c"
    break;

  case 10: /* nonempty_feature_list: nonempty_feature_list feature  */
#line 136 "cool.y"
                                {(yyval.features) = append_Features((yyvsp[-1].features), single_Features((yyvsp[0].feature)));}
#line 1357 "cool.tab.c"
    break;

  case 11: /* feature: OBJECTID '(' formal_list ')' ':' TYPEID '{' expression '}' ';'  */
#line 140 "cool.y"
  {(yyval.feature) = method((yyvsp[-9].symbol), (yyvsp[-7].formals), (yyvsp[-4].symbol), (yyvsp[-2].expression));}
#line 1363 "cool.tab.c"
    break;

  case 12: /* feature: OBJECTID ':' TYPEID ';'  */
#line 143 "cool.y"
  {(yyval.feature) = attr((yyvsp[-3].symbol),(yyvsp[-1].symbol), no_expr());}
#line 1369 "cool.tab.c"
    break;

  case 13: /* feature: OBJECTID ':' TYPEID ASSIGN expression ';'  */
#line 146 "cool.y"
  {(yyval.feature) = attr((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression));}
#line 1375 "cool.tab.c"
    break;

  case 14: /* feature: error ';'  */
#line 149 "cool.y"
  {(yyval.feature) = (yyval.feature);}
#line 1381 "cool.tab.c"
    break;

  case 15: /* formal_list: %empty  */
#line 152 "cool.y"
  {(yyval.formals) = nil_Formals();}
#line 1387 "cool.tab.c"
    break;

  case 16: /* formal_list: nonempty_formal_list  */
#line 154 "cool.y"
  {}
#line 1393 "cool.tab.c"
    break;

  case 17: /* nonempty_formal_list: declaration  */
#line 159 "cool.y"
    {(yyval.formals) = single_Formals((yyvsp[0].formal));}
#line 1399 "cool.tab.c"
    break;

  case 18: /* nonempty_formal_list: formal_list ',' declaration  */
#line 161 "cool.y"
    {(yyval.formals) = append_Formals((yyvsp[-2].formals), single_Formals((yyvsp[0].formal)));}
#line 1405 "cool.tab.c"
    break;

  case 19: /* declaration: OBJECTID ':' TYPEID  */
#line 166 "cool.y"
    {(yyval.formal) = formal((yyvsp[-2].symbol), (yyvsp[0].symbol));}
#line 1411 "cool.tab.c"
    break;

  case 20: /* expression_list: %empty  */
#line 170 "cool.y"
  {(yyval.expressions) = nil_Expressions();}
#line 1417 "cool.tab.c"
    break;

  case 21: /* expression_list: nonempty_expression_list  */
#line 172 "cool.y"
  {(yyval.expressions) = Expression()}
#line 1423 "cool.tab.c"
    break;

  case 22: /* let_list: ',' OBJECTID ':' TYPEID let_list  */
#line 176 "cool.y"
      { (yyval.expression) = let((yyvsp[-3].symbol), (yyvsp[-1].symbol), no_expr(), (yyvsp[0].expression)); }
#line 1429 "cool.tab.c"
    break;

  case 23: /* let_list: ',' OBJECTID ':' TYPEID IN expression  */
#line 178 "cool.y"
      { (yyval.expression) = let((yyvsp[-4].symbol), (yyvsp[-2].symbol), no_expr(), (yyvsp[0].expression)); }
#line 1435 "cool.tab.c"
    break;

  case 24: /* let_list: ',' OBJECTID ':' TYPEID ASSIGN expression let_list  */
#line 180 "cool.y"
      { (yyval.expression) = let((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression), (yyvsp[0].expression)); }
#line 1441 "cool.tab.c"
    break;

  case 25: /* let_list: ',' OBJECTID ':' TYPEID ASSIGN expression IN expression  */
#line 182 "cool.y"
      { (yyval.expression) = let((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1447 "cool.tab.c"
    break;

  case 26: /* let_list: ',' error let_list  */
#line 184 "cool.y"
      { (yyval.expression) = (yyval.expression); }
#line 1453 "cool.tab.c"
    break;

  case 27: /* case_list: case_  */
#line 188 "cool.y"
      { (yyval.cases) = single_Cases((yyvsp[0].case_)); /*printf("Single Case\n");*/ }
#line 1459 "cool.tab.c"
    break;

  case 28: /* case_list: case_list case_  */
#line 190 "cool.y"
      { (yyval.cases) = append_Cases((yyvsp[-1].cases), single_Cases((yyvsp[0].case_))); /*printf("Multiple Cases\n");*/ }
#line 1465 "cool.tab.c"
    break;

  case 29: /* case_: OBJECTID ':' TYPEID DARROW expression ';'  */
#line 193 "cool.y"
      { (yyval.case_) = branch((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression)); /*printf("case: ID:Type => expr\n");*/ }
#line 1471 "cool.tab.c"
    break;

  case 30: /* nonempty_expression_list: expression  */
#line 197 "cool.y"
  {(yyval.expressions) = single_Expressions((yyvsp[0].expression));}
#line 1477 "cool.tab.c"
    break;

  case 31: /* nonempty_expression_list: nonempty_expression_list ',' expression  */
#line 199 "cool.y"
  {a(yyval.expressions) = ppend_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression)));}
#line 1483 "cool.tab.c"
    break;

  case 32: /* expression_semicolon_list: expression  */
#line 203 "cool.y"
 {(yyval.expressions) = single_Expressions((yyvsp[0].expression));}
#line 1489 "cool.tab.c"
    break;

  case 33: /* expression_semicolon_list: expression_semicolon_list ';' expression  */
#line 206 "cool.y"
{(yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression)));}
#line 1495 "cool.tab.c"
    break;

  case 34: /* expression: OBJECTID ASSIGN expression  */
#line 211 "cool.y"
  {(yyval.expression) = assign((yyvsp[-2].symbol),(yyvsp[0].expression));}
#line 1501 "cool.tab.c"
    break;

  case 35: /* expression: expression '.' OBJECTID '(' expression_list ')'  */
#line 213 "cool.y"
  {(yyval.expression) = dispatch((yyvsp[-5].expression), (yyvsp[-3].symbol), (yyvsp[-1].expressions));}
#line 1507 "cool.tab.c"
    break;

  case 36: /* expression: WHILE expression LOOP expression POOL  */
#line 216 "cool.y"
  {(yyval.expression) = loop((yyvsp[-3].expression), (yyvsp[-1].expression));}
#line 1513 "cool.tab.c"
    break;

  case 37: /* expression: IF expression THEN expression ELSE expression FI  */
#line 219 "cool.y"
  {(yyval.expression) = cond((yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression));}
#line 1519 "cool.tab.c"
    break;

  case 38: /* expression: '{' expression_semicolon_list ';'  */
#line 222 "cool.y"
  {(yyval.expression) = block((yyvsp[-1].expressions));}
#line 1525 "cool.tab.c"
    break;

  case 39: /* expression: '{' expression_semicolon_list ';' error ';'  */
#line 225 "cool.y"
  {(yyval.expression) = (yyval.expression);}
#line 1531 "cool.tab.c"
    break;

  case 40: /* expression: '{' expression_semicolon_list ';' error ';' expression_semicolon_list ';'  */
#line 228 "cool.y"
  {(yyval.expression) = (yyval.expression);}
#line 1537 "cool.tab.c"
    break;

  case 41: /* expression: error ';' expression_semicolon_list ';'  */
#line 231 "cool.y"
  {(yyval.expression) = (yyval.expression);}
#line 1543 "cool.tab.c"
    break;

  case 42: /* expression: LET OBJECTID ':' TYPEID IN expression  */
#line 234 "cool.y"
  {(yyval.expression) = let((yyvsp[-4].symbol), (yyvsp[-2].symbol), no_expr(), (yyvsp[0].expression));}
#line 1549 "cool.tab.c"
    break;

  case 43: /* expression: LET OBJECTID ':' TYPEID ASSIGN expression IN expression  */
#line 237 "cool.y"
  {(yyval.expression) = let((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1555 "cool.tab.c"
    break;

  case 44: /* expression: LET OBJECTID ':' TYPEID let_list  */
#line 240 "cool.y"
  {(yyval.expression) = let((yyvsp[-3].symbol), (yyvsp[-1].symbol), no_expr(), (yyvsp[0].expression))}
#line 1561 "cool.tab.c"
    break;

  case 45: /* expression: LET OBJECTID ':' TYPEID ASSIGN expression let_list  */
#line 243 "cool.y"
  {(yyval.expression) = let((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression), (yyvsp[0].expression));}
#line 1567 "cool.tab.c"
    break;

  case 46: /* expression: LET error let_list  */
#line 246 "cool.y"
  {(yyval.expression) = (yyval.expression);}
#line 1573 "cool.tab.c"
    break;

  case 47: /* expression: CASE expression OF case_list ESAC  */
#line 249 "cool.y"
  {(yyval.expression) = typcase((yyvsp[-3].expression), (yyvsp[-1].cases));}
#line 1579 "cool.tab.c"
    break;

  case 48: /* expression: NEW TYPEID  */
#line 251 "cool.y"
  {(yyval.expression) = new_((yyvsp[0].symbol));}
#line 1585 "cool.tab.c"
    break;

  case 49: /* expression: ISVOID expression  */
#line 253 "cool.y"
  {(yyval.expression) = isvoid((yyvsp[0].expression));}
#line 1591 "cool.tab.c"
    break;

  case 50: /* expression: expression '+' expression  */
#line 255 "cool.y"
  {(yyval.expression) = plus((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1597 "cool.tab.c"
    break;

  case 51: /* expression: expression '-' expression  */
#line 257 "cool.y"
  {(yyval.expression) = sub((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1603 "cool.tab.c"
    break;

  case 52: /* expression: expression '*' expression  */
#line 259 "cool.y"
  {(yyval.expression) = mul((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1609 "cool.tab.c"
    break;

  case 53: /* expression: expression '/' expression  */
#line 261 "cool.y"
  {(yyval.expression) = divide((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1615 "cool.tab.c"
    break;

  case 54: /* expression: '~' expression  */
#line 263 "cool.y"
  {(yyval.expression) = neg((yyvsp[0].expression));}
#line 1621 "cool.tab.c"
    break;

  case 55: /* expression: expression '<' expression  */
#line 265 "cool.y"
  {(yyval.expression) = lt((yyvsp[-2].expression),(yyvsp[0].expression));}
#line 1627 "cool.tab.c"
    break;

  case 56: /* expression: expression LE expression  */
#line 267 "cool.y"
  {(yyval.expression) = leq((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1633 "cool.tab.c"
    break;

  case 57: /* expression: expression '=' expression  */
#line 269 "cool.y"
  {(yyval.expression) = eq((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1639 "cool.tab.c"
    break;

  case 58: /* expression: NOT expression  */
#line 271 "cool.y"
  {(yyval.expression) = comp((yyvsp[0].expression));}
#line 1645 "cool.tab.c"
    break;

  case 59: /* expression: '(' expression ')'  */
#line 273 "cool.y"
  {(yyval.expression) = (yyvsp[-1].expression);}
#line 1651 "cool.tab.c"
    break;

  case 60: /* expression: OBJECTID  */
#line 275 "cool.y"
  {(yyval.expression) = object((yyvsp[0].symbol));}
#line 1657 "cool.tab.c"
    break;

  case 61: /* expression: INT_CONST  */
#line 277 "cool.y"
  {(yyval.expression) = object((yyvsp[0].symbol));}
#line 1663 "cool.tab.c"
    break;

  case 62: /* expression: STR_CONST  */
#line 279 "cool.y"
  {(yyval.expression) = object((yyvsp[0].symbol));}
#line 1669 "cool.tab.c"
    break;

  case 63: /* expression: BOOL_CONST  */
#line 281 "cool.y"
  {(yyval.expression) = object((yyvsp[0].boolean));}
#line 1675 "cool.tab.c"
    break;


#line 1679 "cool.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 283 "cool.y"


/* This function is called automatically when Bison detects a parse error. */
void yyerror(char *s)
{
  extern int curr_lineno;

  cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
    << s << " at or near ";
  print_cool_token(yychar);
  cerr << endl;
  omerrs++;

  if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
}

