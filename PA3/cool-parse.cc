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
#define yylloc          cool_yylloc

/* First part of user prologue.  */
#line 6 "cool.y"

#include <iostream>
#include "cool-tree.h"
#include "stringtab.h"
#include "utilities.h"

extern char *curr_filename;

/* Locations */
  #define YYLTYPE int              /* the type of locations */
  #define cool_yylloc curr_lineno  /* use the curr_lineno from the lexer for the location of tokens */
    
  extern int node_lineno;          /* set before constructing a tree node
  to whatever you want the line number
  for the tree node to be */


  #define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current = Rhs[1];                             \
  node_lineno = Current;


  #define SET_NODELOC(Current)  \
  node_lineno = Current; 

void yyerror(char *s);        /*  defined below; called for each parse error */
extern int yylex();           /*  the entry point to the lexer  */

/************************************************************************/
/*                DONT CHANGE ANYTHING IN THIS SECTION                  */

Program ast_root;	      /* the result of the parse  */
Classes parse_results;        /* for use in semantic analysis */
int omerrs = 0;               /* number of errors in lexing and parsing */

#line 115 "cool.tab.c"

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
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   476

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

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
       2,     2,     2,     2,     2,     2,     2,     2,    44,    39,
      31,    30,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,    36,     2,     2,     2,
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
       0,   123,   123,   127,   130,   133,   138,   141,   148,   149,
     153,   155,   158,   161,   164,   167,   173,   174,   179,   181,
     186,   191,   192,   196,   198,   200,   202,   204,   208,   210,
     213,   217,   219,   223,   226,   230,   232,   235,   238,   241,
     244,   247,   250,   253,   256,   259,   262,   265,   268,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   288,   290,
     292,   294,   296,   298,   300
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
  "';'", "'{'", "'}'", "'('", "')'", "':'", "','", "$accept", "program",
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

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   -37,   -15,    23,    30,  -101,  -101,    17,  -101,  -101,
      37,     3,    10,    42,   -18,    32,    12,  -101,     3,  -101,
      60,    62,    48,  -101,    47,    45,    35,  -101,  -101,   -11,
    -101,    61,    82,    63,    60,   284,  -101,  -101,  -101,    87,
    -101,    72,   284,    21,   284,   284,    89,   284,  -101,  -101,
    -101,    95,   284,   284,   284,   284,   409,    74,   284,   365,
      84,    83,   351,   374,  -101,    97,   284,   429,    97,    98,
     429,   383,   284,   284,   284,   284,   284,   284,   284,   116,
    -101,   284,   102,   284,    34,  -101,   126,   284,   134,   429,
     112,  -101,   438,   438,   438,    27,    27,    97,    97,   121,
     397,   155,   325,    84,   128,     4,    64,   136,    -9,  -101,
     131,   429,    50,   139,   284,  -101,   160,   284,   284,  -101,
    -101,   161,  -101,  -101,   198,   149,   156,   429,  -101,   341,
       9,   429,   300,   189,   174,  -101,   284,  -101,   284,   284,
    -101,   284,  -101,   284,   241,   429,   429,   309,   429,   419,
     284,  -101,  -101,   429
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     5,     0,     1,     4,
       0,     0,     0,     0,     0,     0,     0,    10,     0,    15,
      16,     0,     0,    11,     0,     0,     0,    17,    18,     0,
       6,     0,     0,     0,     0,     0,    13,     7,    20,     0,
      19,     0,     0,     0,     0,     0,     0,     0,    63,    62,
      64,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    50,     0,    59,    55,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,    47,     0,     0,     0,    35,
       0,    60,    57,    58,    56,    51,    52,    53,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,    34,     0,     0,     0,    27,     0,     0,     0,    45,
      37,     0,    48,    29,     0,     0,    22,    31,    12,     0,
       0,    43,     0,     0,     0,    36,     0,    38,     0,     0,
      23,     0,    46,     0,     0,    32,    24,     0,    44,     0,
       0,    25,    30,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,   211,   203,  -101,   207,  -101,  -101,   192,
    -101,  -100,  -101,   119,  -101,   -57,   -35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    15,    16,    17,    26,    27,    28,
     125,    85,   108,   109,   126,    69,    70
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    82,     6,   115,    13,   119,   122,    59,     7,    62,
      63,   117,    65,    13,    35,   107,   138,    67,    68,     1,
      71,     2,    60,     8,    20,    10,    21,    14,    36,   118,
     140,    89,   142,     2,   139,   103,    14,    92,    93,    94,
      95,    96,    97,    98,    -8,    61,   100,   151,   102,    84,
      18,    41,   106,    -9,    84,   111,    42,    11,   104,    43,
      12,    77,    78,    44,    45,    79,   111,   134,    46,    47,
      48,    49,    50,    22,    51,   120,    52,   127,    33,   129,
      34,    19,   131,   132,    25,    29,    53,    30,    31,    32,
      54,    72,    55,   -21,    73,    74,    75,    76,    77,    78,
      37,   145,    79,   146,   147,    38,   148,    39,   149,   111,
      57,    58,    64,   110,    81,   153,   -39,   -39,    42,   -39,
      66,    43,   -39,   -39,   -39,    44,    45,    86,   -39,    84,
      46,    47,    48,    49,    50,    79,    51,    90,    52,   -39,
      99,   101,   -39,   -39,   -39,   -39,   -39,   -39,    53,   105,
     -39,   -39,    54,   -39,    55,   -39,    41,   -39,   107,   -42,
     -42,    42,   -42,   112,    43,   -42,   -42,   -42,    44,    45,
     124,   -42,   116,    46,    47,    48,    49,    50,   128,    51,
     121,    52,   -42,   130,   133,   -42,   -42,   -42,   -42,   -42,
     -42,    53,   135,   -42,   -42,    54,   -42,    55,   -42,    41,
     -42,   136,   -40,   -40,    42,   -40,   143,    43,   -40,   -40,
     -40,    44,    45,   144,   -40,     9,    46,    47,    48,    49,
      50,    24,    51,    23,    52,   -40,    40,   123,   -40,   -40,
     -40,   -40,   -40,   -40,    53,     0,   -40,   -40,    54,   -40,
      55,   -40,    41,   -40,     0,   -41,   -41,    42,   -41,     0,
      43,   -41,   -41,   -41,    44,    45,     0,   -41,     0,    46,
      47,    48,    49,    50,     0,    51,     0,    52,   -41,     0,
       0,   -41,   -41,   -41,   -41,   -41,   -41,    53,     0,   -41,
     -41,    54,   -41,    55,   -41,    41,   -41,     0,     0,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,     0,
       0,     0,    46,    47,    48,    49,    50,   141,    51,     0,
      52,     0,     0,     0,     0,     0,   150,     0,     0,     0,
      53,     0,     0,     0,    54,     0,    55,    72,     0,   114,
      73,    74,    75,    76,    77,    78,    72,     0,    79,    73,
      74,    75,    76,    77,    78,    84,   137,    79,     0,     0,
       0,     0,    72,     0,    84,    73,    74,    75,    76,    77,
      78,    87,     0,    79,     0,     0,     0,     0,    72,     0,
       0,    73,    74,    75,    76,    77,    78,    83,    72,    79,
       0,    73,    74,    75,    76,    77,    78,     0,     0,    79,
      88,     0,    72,     0,     0,    73,    74,    75,    76,    77,
      78,    72,     0,    79,    73,    74,    75,    76,    77,    78,
      72,     0,    79,    73,    74,    75,    76,    77,    78,     0,
       0,    79,     0,     0,    72,     0,    91,    73,    74,    75,
      76,    77,    78,     0,     0,    79,    72,     0,   113,    73,
      74,    75,    76,    77,    78,     0,    72,    79,    80,    73,
      74,    75,    76,    77,    78,     0,    72,    79,   152,    73,
      74,    75,    76,    77,    78,   -43,     0,    79,   -43,   -43,
      75,    76,    77,    78,     0,     0,    79
};

static const yytype_int16 yycheck[] =
{
      35,    58,    39,   103,     1,   105,    15,    42,    23,    44,
      45,     7,    47,     1,    25,    24,     7,    52,    53,     1,
      55,     3,     1,     0,    42,     8,    44,    24,    39,    25,
     130,    66,   132,     3,    25,     1,    24,    72,    73,    74,
      75,    76,    77,    78,    41,    24,    81,   147,    83,    45,
      40,     1,    87,    41,    45,    90,     6,    40,    24,     9,
      23,    34,    35,    13,    14,    38,   101,   124,    18,    19,
      20,    21,    22,    41,    24,    11,    26,   112,    43,   114,
      45,    39,   117,   118,    24,    23,    36,    39,    41,    44,
      40,    27,    42,    43,    30,    31,    32,    33,    34,    35,
      39,   136,    38,   138,   139,    23,   141,    44,   143,   144,
      23,    39,    23,     1,    40,   150,     4,     5,     6,     7,
      25,     9,    10,    11,    12,    13,    14,    44,    16,    45,
      18,    19,    20,    21,    22,    38,    24,    39,    26,    27,
      24,    39,    30,    31,    32,    33,    34,    35,    36,    23,
      38,    39,    40,    41,    42,    43,     1,    45,    24,     4,
       5,     6,     7,    42,     9,    10,    11,    12,    13,    14,
      39,    16,    44,    18,    19,    20,    21,    22,    39,    24,
      44,    26,    27,    23,    23,    30,    31,    32,    33,    34,
      35,    36,    43,    38,    39,    40,    41,    42,    43,     1,
      45,    45,     4,     5,     6,     7,    17,     9,    10,    11,
      12,    13,    14,    39,    16,     4,    18,    19,    20,    21,
      22,    18,    24,    16,    26,    27,    34,   108,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,     1,    45,    -1,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,     1,    45,    -1,    -1,    -1,
       6,    -1,    -1,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,     7,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    40,    -1,    42,    27,    -1,     4,
      30,    31,    32,    33,    34,    35,    27,    -1,    38,    30,
      31,    32,    33,    34,    35,    45,     5,    38,    -1,    -1,
      -1,    -1,    27,    -1,    45,    30,    31,    32,    33,    34,
      35,    10,    -1,    38,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    12,    27,    38,
      -1,    30,    31,    32,    33,    34,    35,    -1,    -1,    38,
      16,    -1,    27,    -1,    -1,    30,    31,    32,    33,    34,
      35,    27,    -1,    38,    30,    31,    32,    33,    34,    35,
      27,    -1,    38,    30,    31,    32,    33,    34,    35,    -1,
      -1,    38,    -1,    -1,    27,    -1,    43,    30,    31,    32,
      33,    34,    35,    -1,    -1,    38,    27,    -1,    41,    30,
      31,    32,    33,    34,    35,    -1,    27,    38,    39,    30,
      31,    32,    33,    34,    35,    -1,    27,    38,    39,    30,
      31,    32,    33,    34,    35,    27,    -1,    38,    30,    31,
      32,    33,    34,    35,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    47,    48,    49,    39,    23,     0,    49,
       8,    40,    23,     1,    24,    50,    51,    52,    40,    39,
      42,    44,    41,    52,    50,    24,    53,    54,    55,    23,
      39,    41,    44,    43,    45,    25,    39,    39,    23,    44,
      55,     1,     6,     9,    13,    14,    18,    19,    20,    21,
      22,    24,    26,    36,    40,    42,    62,    23,    39,    62,
       1,    24,    62,    62,    23,    62,    25,    62,    62,    61,
      62,    62,    27,    30,    31,    32,    33,    34,    35,    38,
      39,    40,    61,    12,    45,    57,    44,    10,    16,    62,
      39,    43,    62,    62,    62,    62,    62,    62,    62,    24,
      62,    39,    62,     1,    24,    23,    62,    24,    58,    59,
       1,    62,    42,    41,     4,    57,    44,     7,    25,    57,
      11,    44,    15,    59,    39,    56,    60,    62,    39,    62,
      23,    62,    62,    23,    61,    43,    45,     5,     7,    25,
      57,     7,    57,    17,    39,    62,    62,    62,    62,    62,
       7,    57,    39,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    53,    53,    54,    54,
      55,    56,    56,    57,    57,    57,    57,    57,    58,    58,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     6,     8,     0,     1,
       1,     2,    10,     4,     6,     2,     0,     1,     1,     3,
       3,     0,     1,     5,     6,     7,     8,     3,     1,     2,
       6,     1,     3,     1,     3,     3,     6,     5,     7,     3,
       5,     7,     4,     6,     8,     5,     7,     3,     5,     2,
       2,     3,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     1,     1,     1,     1
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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: class_list  */
#line 123 "cool.y"
                        { (yyloc) = (yylsp[0]); ast_root = program((yyvsp[0].classes)); }
#line 1436 "cool.tab.c"
    break;

  case 3: /* class_list: class  */
#line 128 "cool.y"
                { (yyval.classes) = single_Classes((yyvsp[0].class_));
                  parse_results = (yyval.classes); }
#line 1443 "cool.tab.c"
    break;

  case 4: /* class_list: class_list class  */
#line 131 "cool.y"
                { (yyval.classes) = append_Classes((yyvsp[-1].classes),single_Classes((yyvsp[0].class_))); 
                  parse_results = (yyval.classes); }
#line 1450 "cool.tab.c"
    break;

  case 5: /* class_list: error ';'  */
#line 134 "cool.y"
      { (yyval.classes) = (yyval.classes);}
#line 1456 "cool.tab.c"
    break;

  case 6: /* class: CLASS TYPEID '{' feature_list '}' ';'  */
#line 139 "cool.y"
                { (yyval.class_) = class_((yyvsp[-4].symbol), idtable.add_string("Object"),(yyvsp[-2].features),
			      stringtable.add_string(curr_filename)); }
#line 1463 "cool.tab.c"
    break;

  case 7: /* class: CLASS TYPEID INHERITS TYPEID '{' feature_list '}' ';'  */
#line 142 "cool.y"
                { (yyval.class_) = class_((yyvsp[-6].symbol),(yyvsp[-4].symbol),(yyvsp[-2].features),stringtable.add_string(curr_filename)); }
#line 1469 "cool.tab.c"
    break;

  case 8: /* feature_list: %empty  */
#line 148 "cool.y"
    {  (yyval.features) = nil_Features(); }
#line 1475 "cool.tab.c"
    break;

  case 9: /* feature_list: nonempty_feature_list  */
#line 149 "cool.y"
                        {}
#line 1481 "cool.tab.c"
    break;

  case 10: /* nonempty_feature_list: feature  */
#line 153 "cool.y"
            {(yyval.features) = nil_Features();}
#line 1487 "cool.tab.c"
    break;

  case 11: /* nonempty_feature_list: nonempty_feature_list feature  */
#line 155 "cool.y"
                                {(yyval.features) = append_Features((yyvsp[-1].features), single_Features((yyvsp[0].feature)));}
#line 1493 "cool.tab.c"
    break;

  case 12: /* feature: OBJECTID '(' formal_list ')' ':' TYPEID '{' expression '}' ';'  */
#line 159 "cool.y"
  {(yyval.feature) = method((yyvsp[-9].symbol), (yyvsp[-7].formals), (yyvsp[-4].symbol), (yyvsp[-2].expression));}
#line 1499 "cool.tab.c"
    break;

  case 13: /* feature: OBJECTID ':' TYPEID ';'  */
#line 162 "cool.y"
  {(yyval.feature) = attr((yyvsp[-3].symbol),(yyvsp[-1].symbol), no_expr());}
#line 1505 "cool.tab.c"
    break;

  case 14: /* feature: OBJECTID ':' TYPEID ASSIGN expression ';'  */
#line 165 "cool.y"
  {(yyval.feature) = attr((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression));}
#line 1511 "cool.tab.c"
    break;

  case 15: /* feature: error ';'  */
#line 168 "cool.y"
  {(yyval.feature) = (yyval.feature);}
#line 1517 "cool.tab.c"
    break;

  case 16: /* formal_list: %empty  */
#line 173 "cool.y"
  {(yyval.formals) = nil_Formals();}
#line 1523 "cool.tab.c"
    break;

  case 17: /* formal_list: nonempty_formal_list  */
#line 175 "cool.y"
  {}
#line 1529 "cool.tab.c"
    break;

  case 18: /* nonempty_formal_list: declaration  */
#line 180 "cool.y"
    {(yyval.formals) = single_Formals((yyvsp[0].formal));}
#line 1535 "cool.tab.c"
    break;

  case 19: /* nonempty_formal_list: formal_list ',' declaration  */
#line 182 "cool.y"
    {(yyval.formals) = append_Formals((yyvsp[-2].formals), single_Formals((yyvsp[0].formal)));}
#line 1541 "cool.tab.c"
    break;

  case 20: /* declaration: OBJECTID ':' TYPEID  */
#line 187 "cool.y"
    {(yyval.formal) = formal((yyvsp[-2].symbol), (yyvsp[0].symbol));}
#line 1547 "cool.tab.c"
    break;

  case 21: /* expression_list: %empty  */
#line 191 "cool.y"
  {(yyval.expressions) = nil_Expressions();}
#line 1553 "cool.tab.c"
    break;

  case 22: /* expression_list: nonempty_expression_list  */
#line 193 "cool.y"
  {}
#line 1559 "cool.tab.c"
    break;

  case 23: /* let_list: ',' OBJECTID ':' TYPEID let_list  */
#line 197 "cool.y"
      { (yyval.expression) = let((yyvsp[-3].symbol), (yyvsp[-1].symbol), no_expr(), (yyvsp[0].expression)); }
#line 1565 "cool.tab.c"
    break;

  case 24: /* let_list: ',' OBJECTID ':' TYPEID IN expression  */
#line 199 "cool.y"
      { (yyval.expression) = let((yyvsp[-4].symbol), (yyvsp[-2].symbol), no_expr(), (yyvsp[0].expression)); }
#line 1571 "cool.tab.c"
    break;

  case 25: /* let_list: ',' OBJECTID ':' TYPEID ASSIGN expression let_list  */
#line 201 "cool.y"
      { (yyval.expression) = let((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression), (yyvsp[0].expression)); }
#line 1577 "cool.tab.c"
    break;

  case 26: /* let_list: ',' OBJECTID ':' TYPEID ASSIGN expression IN expression  */
#line 203 "cool.y"
      { (yyval.expression) = let((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1583 "cool.tab.c"
    break;

  case 27: /* let_list: ',' error let_list  */
#line 205 "cool.y"
      { (yyval.expression) = (yyval.expression); }
#line 1589 "cool.tab.c"
    break;

  case 28: /* case_list: case_  */
#line 209 "cool.y"
      { (yyval.cases) = single_Cases((yyvsp[0].case_)); /*printf("Single Case\n");*/ }
#line 1595 "cool.tab.c"
    break;

  case 29: /* case_list: case_list case_  */
#line 211 "cool.y"
      { (yyval.cases) = append_Cases((yyvsp[-1].cases), single_Cases((yyvsp[0].case_))); /*printf("Multiple Cases\n");*/ }
#line 1601 "cool.tab.c"
    break;

  case 30: /* case_: OBJECTID ':' TYPEID DARROW expression ';'  */
#line 214 "cool.y"
      { (yyval.case_) = branch((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression)); /*printf("case: ID:Type => expr\n");*/ }
#line 1607 "cool.tab.c"
    break;

  case 31: /* nonempty_expression_list: expression  */
#line 218 "cool.y"
  {(yyval.expressions) = single_Expressions((yyvsp[0].expression));}
#line 1613 "cool.tab.c"
    break;

  case 32: /* nonempty_expression_list: nonempty_expression_list ',' expression  */
#line 220 "cool.y"
  {(yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression)));}
#line 1619 "cool.tab.c"
    break;

  case 33: /* expression_semicolon_list: expression  */
#line 224 "cool.y"
 {(yyval.expressions) = single_Expressions((yyvsp[0].expression));}
#line 1625 "cool.tab.c"
    break;

  case 34: /* expression_semicolon_list: expression_semicolon_list ';' expression  */
#line 227 "cool.y"
{(yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression)));}
#line 1631 "cool.tab.c"
    break;

  case 35: /* expression: OBJECTID ASSIGN expression  */
#line 231 "cool.y"
  {(yyval.expression) = assign((yyvsp[-2].symbol),(yyvsp[0].expression));}
#line 1637 "cool.tab.c"
    break;

  case 36: /* expression: expression '.' OBJECTID '(' expression_list ')'  */
#line 233 "cool.y"
  {(yyval.expression) = dispatch((yyvsp[-5].expression), (yyvsp[-3].symbol), (yyvsp[-1].expressions));}
#line 1643 "cool.tab.c"
    break;

  case 37: /* expression: WHILE expression LOOP expression POOL  */
#line 236 "cool.y"
  {(yyval.expression) = loop((yyvsp[-3].expression), (yyvsp[-1].expression));}
#line 1649 "cool.tab.c"
    break;

  case 38: /* expression: IF expression THEN expression ELSE expression FI  */
#line 239 "cool.y"
  {(yyval.expression) = cond((yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression));}
#line 1655 "cool.tab.c"
    break;

  case 39: /* expression: '{' expression_semicolon_list ';'  */
#line 242 "cool.y"
  {(yyval.expression) = block((yyvsp[-1].expressions));}
#line 1661 "cool.tab.c"
    break;

  case 40: /* expression: '{' expression_semicolon_list ';' error ';'  */
#line 245 "cool.y"
  {(yyval.expression) = (yyval.expression);}
#line 1667 "cool.tab.c"
    break;

  case 41: /* expression: '{' expression_semicolon_list ';' error ';' expression_semicolon_list ';'  */
#line 248 "cool.y"
  {(yyval.expression) = (yyval.expression);}
#line 1673 "cool.tab.c"
    break;

  case 42: /* expression: error ';' expression_semicolon_list ';'  */
#line 251 "cool.y"
  {(yyval.expression) = (yyval.expression);}
#line 1679 "cool.tab.c"
    break;

  case 43: /* expression: LET OBJECTID ':' TYPEID IN expression  */
#line 254 "cool.y"
  {(yyval.expression) = let((yyvsp[-4].symbol), (yyvsp[-2].symbol), no_expr(), (yyvsp[0].expression));}
#line 1685 "cool.tab.c"
    break;

  case 44: /* expression: LET OBJECTID ':' TYPEID ASSIGN expression IN expression  */
#line 257 "cool.y"
  {(yyval.expression) = let((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1691 "cool.tab.c"
    break;

  case 45: /* expression: LET OBJECTID ':' TYPEID let_list  */
#line 260 "cool.y"
  {(yyval.expression) = let((yyvsp[-3].symbol), (yyvsp[-1].symbol), no_expr(), (yyvsp[0].expression));}
#line 1697 "cool.tab.c"
    break;

  case 46: /* expression: LET OBJECTID ':' TYPEID ASSIGN expression let_list  */
#line 263 "cool.y"
  {(yyval.expression) = let((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression), (yyvsp[0].expression));}
#line 1703 "cool.tab.c"
    break;

  case 47: /* expression: LET error let_list  */
#line 266 "cool.y"
  {(yyval.expression) = (yyval.expression);}
#line 1709 "cool.tab.c"
    break;

  case 48: /* expression: CASE expression OF case_list ESAC  */
#line 269 "cool.y"
  {(yyval.expression) = typcase((yyvsp[-3].expression), (yyvsp[-1].cases));}
#line 1715 "cool.tab.c"
    break;

  case 49: /* expression: NEW TYPEID  */
#line 271 "cool.y"
  {(yyval.expression) = new_((yyvsp[0].symbol));}
#line 1721 "cool.tab.c"
    break;

  case 50: /* expression: ISVOID expression  */
#line 273 "cool.y"
  {(yyval.expression) = isvoid((yyvsp[0].expression));}
#line 1727 "cool.tab.c"
    break;

  case 51: /* expression: expression '+' expression  */
#line 275 "cool.y"
  {(yyval.expression) = plus((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1733 "cool.tab.c"
    break;

  case 52: /* expression: expression '-' expression  */
#line 277 "cool.y"
  {(yyval.expression) = sub((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1739 "cool.tab.c"
    break;

  case 53: /* expression: expression '*' expression  */
#line 279 "cool.y"
  {(yyval.expression) = mul((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1745 "cool.tab.c"
    break;

  case 54: /* expression: expression '/' expression  */
#line 281 "cool.y"
  {(yyval.expression) = divide((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1751 "cool.tab.c"
    break;

  case 55: /* expression: '~' expression  */
#line 283 "cool.y"
  {(yyval.expression) = neg((yyvsp[0].expression));}
#line 1757 "cool.tab.c"
    break;

  case 56: /* expression: expression '<' expression  */
#line 285 "cool.y"
  {(yyval.expression) = lt((yyvsp[-2].expression),(yyvsp[0].expression));}
#line 1763 "cool.tab.c"
    break;

  case 57: /* expression: expression LE expression  */
#line 287 "cool.y"
  {(yyval.expression) = leq((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1769 "cool.tab.c"
    break;

  case 58: /* expression: expression '=' expression  */
#line 289 "cool.y"
  {(yyval.expression) = eq((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1775 "cool.tab.c"
    break;

  case 59: /* expression: NOT expression  */
#line 291 "cool.y"
  {(yyval.expression) = comp((yyvsp[0].expression));}
#line 1781 "cool.tab.c"
    break;

  case 60: /* expression: '(' expression ')'  */
#line 293 "cool.y"
  {(yyval.expression) = (yyvsp[-1].expression);}
#line 1787 "cool.tab.c"
    break;

  case 61: /* expression: OBJECTID  */
#line 295 "cool.y"
  {(yyval.expression) = object((yyvsp[0].symbol));}
#line 1793 "cool.tab.c"
    break;

  case 62: /* expression: INT_CONST  */
#line 297 "cool.y"
  {(yyval.expression) = int_const((yyvsp[0].symbol));}
#line 1799 "cool.tab.c"
    break;

  case 63: /* expression: STR_CONST  */
#line 299 "cool.y"
  {(yyval.expression) = string_const((yyvsp[0].symbol));}
#line 1805 "cool.tab.c"
    break;

  case 64: /* expression: BOOL_CONST  */
#line 301 "cool.y"
  {(yyval.expression) = bool_const((yyvsp[0].boolean));}
#line 1811 "cool.tab.c"
    break;


#line 1815 "cool.tab.c"

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
  *++yylsp = yyloc;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 303 "cool.y"


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

