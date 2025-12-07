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




/* First part of user prologue.  */
#line 7 "src/cminus.y"

#define _POSIX_C_SOURCE 200809L
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "symtab.h" 

static char savedName[120]; 
static char savedID[120]; /* Buffer para salvar IDs de arrays/params */
static int savedNum;
static TreeNode *savedTree; 

int yylex(void);
void yyerror(char *message);

#line 87 "src/parse.c"

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

#include "parse.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_INPUT = 9,                      /* INPUT  */
  YYSYMBOL_OUTPUT = 10,                    /* OUTPUT  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_NUM = 12,                       /* NUM  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NE = 15,                        /* NE  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_TIMES = 22,                     /* TIMES  */
  YYSYMBOL_OVER = 23,                      /* OVER  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 26,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 27,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 28,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 29,                    /* RBRACE  */
  YYSYMBOL_SEMI = 30,                      /* SEMI  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_ERROR = 32,                     /* ERROR  */
  YYSYMBOL_LOWER_THAN_ELSE = 33,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_programa = 35,                  /* programa  */
  YYSYMBOL_declaration_list = 36,          /* declaration_list  */
  YYSYMBOL_declaration = 37,               /* declaration  */
  YYSYMBOL_var_declaration = 38,           /* var_declaration  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_type_specifier = 41,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 42,           /* fun_declaration  */
  YYSYMBOL_43_3 = 43,                      /* $@3  */
  YYSYMBOL_params = 44,                    /* params  */
  YYSYMBOL_param_list = 45,                /* param_list  */
  YYSYMBOL_param = 46,                     /* param  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_compound_stmt = 48,             /* compound_stmt  */
  YYSYMBOL_49_5 = 49,                      /* $@5  */
  YYSYMBOL_local_declarations = 50,        /* local_declarations  */
  YYSYMBOL_statement_list = 51,            /* statement_list  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_expression_stmt = 53,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 54,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 55,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 56,               /* return_stmt  */
  YYSYMBOL_input_stmt = 57,                /* input_stmt  */
  YYSYMBOL_output_stmt = 58,               /* output_stmt  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_var = 60,                       /* var  */
  YYSYMBOL_61_6 = 61,                      /* $@6  */
  YYSYMBOL_simple_expression = 62,         /* simple_expression  */
  YYSYMBOL_relop = 63,                     /* relop  */
  YYSYMBOL_additive_expression = 64,       /* additive_expression  */
  YYSYMBOL_addop = 65,                     /* addop  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_mulop = 67,                     /* mulop  */
  YYSYMBOL_factor = 68,                    /* factor  */
  YYSYMBOL_call = 69,                      /* call  */
  YYSYMBOL_70_7 = 70,                      /* $@7  */
  YYSYMBOL_args = 71,                      /* args  */
  YYSYMBOL_arg_list = 72                   /* arg_list  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    39,    48,    52,    53,    58,    65,    67,
      64,    80,    81,    86,    86,   100,   101,   105,   111,   116,
     123,   122,   131,   138,   150,   150,   159,   167,   171,   179,
     183,   184,   185,   186,   187,   188,   189,   193,   194,   198,
     200,   205,   210,   211,   215,   225,   234,   235,   240,   242,
     241,   252,   254,   258,   259,   260,   261,   262,   263,   267,
     268,   272,   273,   277,   278,   282,   283,   287,   288,   289,
     290,   291,   299,   298,   309,   310,   314,   320
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "INT",
  "RETURN", "VOID", "WHILE", "INPUT", "OUTPUT", "ID", "NUM", "ASSIGN",
  "EQ", "NE", "LT", "LE", "GT", "GE", "PLUS", "MINUS", "TIMES", "OVER",
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMI",
  "COMMA", "ERROR", "LOWER_THAN_ELSE", "$accept", "programa",
  "declaration_list", "declaration", "var_declaration", "$@1", "$@2",
  "type_specifier", "fun_declaration", "$@3", "params", "param_list",
  "param", "$@4", "compound_stmt", "$@5", "local_declarations",
  "statement_list", "statement", "expression_stmt", "selection_stmt",
  "iteration_stmt", "return_stmt", "input_stmt", "output_stmt",
  "expression", "var", "$@6", "simple_expression", "relop",
  "additive_expression", "addop", "term", "mulop", "factor", "call", "$@7",
  "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,  -104,  -104,     5,    -3,  -104,  -104,    15,  -104,  -104,
    -104,   -21,  -104,    14,    25,    39,    16,  -104,    48,    50,
      51,    44,  -104,    52,    54,    55,    49,    22,    56,    57,
      58,  -104,  -104,    50,  -104,  -104,    60,  -104,  -104,  -104,
      -3,  -104,    71,     8,    59,    64,     1,    66,    67,    68,
      17,  -104,    41,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,    63,    81,  -104,    53,    11,  -104,  -104,
      41,    72,  -104,    65,    41,   -10,    41,    73,    74,    75,
    -104,    41,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
      41,    41,  -104,  -104,    41,    76,    77,  -104,    78,    79,
    -104,    80,    41,    41,  -104,  -104,  -104,    42,    11,  -104,
      36,    36,    82,    83,    70,  -104,    84,    85,   102,  -104,
    -104,  -104,  -104,  -104,    41,    36,  -104,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,     0,     2,     4,     5,     0,     6,     1,
       3,     8,     7,     0,     0,     0,     0,     9,     0,    16,
       0,    15,    18,     0,    19,    22,     0,     0,     0,     0,
       0,    24,    14,     0,    17,    10,     0,    23,    27,    21,
      29,    26,     0,     0,     8,     0,     0,     0,     0,     0,
      48,    70,     0,    25,    38,    31,    28,    30,    32,    33,
      34,    35,    36,     0,    68,    47,    52,    60,    64,    69,
       0,     0,    42,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    57,    58,    54,    53,    55,    56,    61,    62,
       0,     0,    65,    66,     0,     0,     0,    43,     0,     0,
      71,     0,     0,    75,    67,    46,    68,    51,    59,    63,
       0,     0,     0,     0,     0,    77,     0,    74,    39,    41,
      44,    45,    50,    73,     0,     0,    76,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,  -104,   103,    86,  -104,  -104,    87,  -104,  -104,
    -104,  -104,    88,  -104,    91,  -104,  -104,  -104,  -103,  -104,
    -104,  -104,  -104,  -104,  -104,   -46,   -36,  -104,  -104,  -104,
      -6,  -104,    19,  -104,    20,  -104,  -104,  -104,  -104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    13,    23,     7,     8,    14,
      20,    21,    22,    29,    55,    38,    40,    43,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    77,    65,    90,
      66,    91,    67,    94,    68,    69,    78,   116,   117
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      73,    99,     1,   -13,     2,     9,    79,   118,   119,    12,
      71,    45,    50,    51,    46,   100,    47,    48,    49,    50,
      51,    18,   127,    19,    95,    52,    11,    18,    98,    33,
     101,    72,    52,    92,    93,   105,    31,    53,    54,    45,
      15,   -72,    46,   -49,    47,    48,    49,    50,    51,    16,
      71,    17,    50,    51,   106,   106,   114,   115,   106,    24,
      52,    25,    88,    89,    31,    52,    54,    82,    83,    84,
      85,    86,    87,    88,    89,    27,    26,    31,   126,    28,
     -20,    30,    44,    36,   107,    37,    35,    39,    70,    12,
      74,    75,    76,    80,    81,    97,    96,   122,   103,   102,
     104,   110,   100,   111,   112,   113,   125,    10,     0,   123,
     108,     0,   120,   121,   109,    34,   124,    32,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42
};

static const yytype_int8 yycheck[] =
{
      46,    11,     5,    24,     7,     0,    52,   110,   111,    30,
       9,     3,    11,    12,     6,    25,     8,     9,    10,    11,
      12,     5,   125,     7,    70,    24,    11,     5,    74,     7,
      76,    30,    24,    22,    23,    81,    28,    29,    30,     3,
      26,    24,     6,    26,     8,     9,    10,    11,    12,    24,
       9,    12,    11,    12,    90,    91,   102,   103,    94,    11,
      24,    11,    20,    21,    28,    24,    30,    14,    15,    16,
      17,    18,    19,    20,    21,    31,    25,    28,   124,    27,
      26,    26,    11,    26,    90,    27,    30,    27,    24,    30,
      24,    24,    24,    30,    13,    30,    24,    27,    24,    26,
      25,    25,    25,    25,    25,    25,     4,     4,    -1,    25,
      91,    -1,    30,    30,    94,    27,    31,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    35,    36,    37,    38,    41,    42,     0,
      37,    11,    30,    39,    43,    26,    24,    12,     5,     7,
      44,    45,    46,    40,    11,    11,    25,    31,    27,    47,
      26,    28,    48,     7,    46,    30,    26,    27,    49,    27,
      50,    38,    41,    51,    11,     3,     6,     8,     9,    10,
      11,    12,    24,    29,    30,    48,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    62,    64,    66,    68,    69,
      24,     9,    30,    59,    24,    24,    24,    61,    70,    59,
      30,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      63,    65,    22,    23,    67,    59,    24,    30,    59,    11,
      25,    59,    26,    24,    25,    59,    60,    64,    66,    68,
      25,    25,    25,    25,    59,    59,    71,    72,    52,    52,
      30,    30,    27,    25,    31,     4,    59,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    39,    40,
      38,    41,    41,    43,    42,    44,    44,    45,    45,    46,
      47,    46,    46,    46,    49,    48,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    56,    56,    57,    58,    59,    59,    60,    61,
      60,    62,    62,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    70,    69,    71,    71,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     0,     0,
       8,     1,     1,     0,     7,     1,     1,     3,     1,     2,
       0,     5,     2,     4,     0,     5,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     5,
       7,     5,     2,     3,     5,     5,     3,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     0,     5,     1,     0,     3,     1
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
  case 2: /* programa: declaration_list  */
#line 35 "src/cminus.y"
                                        { savedTree = yyvsp[0]; }
#line 1233 "src/parse.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 39 "src/cminus.y"
                                        {
                                          YYSTYPE t = yyvsp[-1];
                                          if (t != NULL) {
                                              while (t->sibling != NULL)
                                                  t = t->sibling;
                                              t->sibling = yyvsp[0];
                                              yyval = yyvsp[-1];
                                          } else yyval = yyvsp[0];
                                        }
#line 1247 "src/parse.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 48 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1253 "src/parse.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 52 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1259 "src/parse.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 53 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1265 "src/parse.c"
    break;

  case 7: /* var_declaration: type_specifier ID SEMI  */
#line 58 "src/cminus.y"
                                         {
                                          yyval = newStmtNode(VarDeclK);
                                          yyval->attr.name = strdup(tokenString); 
                                          yyval->type = (yyvsp[-2]->attr.name[0]=='i') ? Integer : Void;
                                          yyval->child[0] = yyvsp[-2];
                                        }
#line 1276 "src/parse.c"
    break;

  case 8: /* $@1: %empty  */
#line 65 "src/cminus.y"
      { strcpy(savedID, tokenString); }
#line 1282 "src/parse.c"
    break;

  case 9: /* $@2: %empty  */
#line 67 "src/cminus.y"
      { savedNum = atoi(tokenString); }
#line 1288 "src/parse.c"
    break;

  case 10: /* var_declaration: type_specifier ID $@1 LBRACK NUM $@2 RBRACK SEMI  */
#line 69 "src/cminus.y"
                                        {
                                          yyval = newStmtNode(VarDeclK);
                                          yyval->attr.name = strdup(savedID); /* Usa o nome salvo */
                                          yyval->type = Integer;
                                          yyval->child[0] = yyvsp[-7];
                                          yyval->child[1] = newExpNode(ConstK);
                                          yyval->child[1]->attr.val = savedNum;
                                        }
#line 1301 "src/parse.c"
    break;

  case 11: /* type_specifier: INT  */
#line 80 "src/cminus.y"
                                        { yyval = newExpNode(TypeK); yyval->attr.name = "int"; }
#line 1307 "src/parse.c"
    break;

  case 12: /* type_specifier: VOID  */
#line 81 "src/cminus.y"
                                        { yyval = newExpNode(TypeK); yyval->attr.name = "void"; }
#line 1313 "src/parse.c"
    break;

  case 13: /* $@3: %empty  */
#line 86 "src/cminus.y"
                                        {
                                          strcpy(savedName, tokenString);
                                        }
#line 1321 "src/parse.c"
    break;

  case 14: /* fun_declaration: type_specifier ID $@3 LPAREN params RPAREN compound_stmt  */
#line 89 "src/cminus.y"
                                         {
                                          yyval = newStmtNode(FunDeclK);
                                          yyval->attr.name = strdup(savedName);
                                          yyval->type = (yyvsp[-6]->attr.name[0]=='i') ? Integer : Void;
                                          yyval->child[0] = yyvsp[-6];
                                          yyval->child[1] = yyvsp[-2];
                                          yyval->child[2] = yyvsp[0];
                                        }
#line 1334 "src/parse.c"
    break;

  case 15: /* params: param_list  */
#line 100 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1340 "src/parse.c"
    break;

  case 16: /* params: VOID  */
#line 101 "src/cminus.y"
                                        { yyval = NULL; }
#line 1346 "src/parse.c"
    break;

  case 17: /* param_list: param_list COMMA param  */
#line 105 "src/cminus.y"
                                        {
                                          YYSTYPE t = yyvsp[-2];
                                          while (t->sibling) t = t->sibling;
                                          t->sibling = yyvsp[0];
                                          yyval = yyvsp[-2];
                                        }
#line 1357 "src/parse.c"
    break;

  case 18: /* param_list: param  */
#line 111 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1363 "src/parse.c"
    break;

  case 19: /* param: INT ID  */
#line 116 "src/cminus.y"
                                        {
                                          yyval = newStmtNode(ParamK);
                                          yyval->attr.name = strdup(tokenString);
                                          yyval->type = Integer;
                                          yyval->child[0] = newExpNode(TypeK); yyval->child[0]->attr.name = "int";
                                        }
#line 1374 "src/parse.c"
    break;

  case 20: /* $@4: %empty  */
#line 123 "src/cminus.y"
      { strcpy(savedID, tokenString); }
#line 1380 "src/parse.c"
    break;

  case 21: /* param: INT ID $@4 LBRACK RBRACK  */
#line 125 "src/cminus.y"
      {
          yyval = newStmtNode(ParamK);
          yyval->attr.name = strdup(savedID); /* Usa o nome correto */
          yyval->type = Integer;
          yyval->child[0] = newExpNode(TypeK); yyval->child[0]->attr.name = "int";
      }
#line 1391 "src/parse.c"
    break;

  case 22: /* param: VOID ID  */
#line 131 "src/cminus.y"
                                        {
                                          yyval = newStmtNode(ParamK);
                                          yyval->attr.name = strdup(tokenString);
                                          yyval->type = Void;
                                          yyval->child[0] = newExpNode(TypeK); yyval->child[0]->attr.name = "void";
                                        }
#line 1402 "src/parse.c"
    break;

  case 23: /* param: VOID ID LBRACK RBRACK  */
#line 138 "src/cminus.y"
                                        {
                                          yyval = newStmtNode(ParamK);
                                          /* Neste caso tokenString é RBRACK e perdemos o ID.
                                             Mas void array é inválido de qualquer forma. 
                                             Deixamos genérico. */
                                          yyval->attr.name = "void_arr";
                                          yyval->type = Void;
                                          yyval->child[0] = newExpNode(TypeK); yyval->child[0]->attr.name = "void";
                                        }
#line 1416 "src/parse.c"
    break;

  case 24: /* $@5: %empty  */
#line 150 "src/cminus.y"
             { scope_push("local"); }
#line 1422 "src/parse.c"
    break;

  case 25: /* compound_stmt: LBRACE $@5 local_declarations statement_list RBRACE  */
#line 150 "src/cminus.y"
                                                                               {
                                          scope_pop();
                                          yyval = newStmtNode(CompoundK);
                                          yyval->child[0] = yyvsp[-2];
                                          yyval->child[1] = yyvsp[-1];
                                        }
#line 1433 "src/parse.c"
    break;

  case 26: /* local_declarations: local_declarations var_declaration  */
#line 159 "src/cminus.y"
                                         {
                                          YYSTYPE t = yyvsp[-1];
                                          if (t != NULL) {
                                              while (t->sibling) t = t->sibling;
                                              t->sibling = yyvsp[0];
                                              yyval = yyvsp[-1];
                                          } else yyval = yyvsp[0];
                                        }
#line 1446 "src/parse.c"
    break;

  case 27: /* local_declarations: %empty  */
#line 167 "src/cminus.y"
                                         { yyval = NULL; }
#line 1452 "src/parse.c"
    break;

  case 28: /* statement_list: statement_list statement  */
#line 171 "src/cminus.y"
                                        {
                                          YYSTYPE t = yyvsp[-1];
                                          if (t != NULL) {
                                              while (t->sibling) t = t->sibling;
                                              t->sibling = yyvsp[0];
                                              yyval = yyvsp[-1];
                                          } else yyval = yyvsp[0];
                                        }
#line 1465 "src/parse.c"
    break;

  case 29: /* statement_list: %empty  */
#line 179 "src/cminus.y"
                                         { yyval = NULL; }
#line 1471 "src/parse.c"
    break;

  case 30: /* statement: expression_stmt  */
#line 183 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1477 "src/parse.c"
    break;

  case 31: /* statement: compound_stmt  */
#line 184 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1483 "src/parse.c"
    break;

  case 32: /* statement: selection_stmt  */
#line 185 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1489 "src/parse.c"
    break;

  case 33: /* statement: iteration_stmt  */
#line 186 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1495 "src/parse.c"
    break;

  case 34: /* statement: return_stmt  */
#line 187 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1501 "src/parse.c"
    break;

  case 35: /* statement: input_stmt  */
#line 188 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1507 "src/parse.c"
    break;

  case 36: /* statement: output_stmt  */
#line 189 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1513 "src/parse.c"
    break;

  case 37: /* expression_stmt: expression SEMI  */
#line 193 "src/cminus.y"
                                        { yyval = yyvsp[-1]; }
#line 1519 "src/parse.c"
    break;

  case 38: /* expression_stmt: SEMI  */
#line 194 "src/cminus.y"
                                        { yyval = NULL; }
#line 1525 "src/parse.c"
    break;

  case 39: /* selection_stmt: IF LPAREN expression RPAREN statement  */
#line 199 "src/cminus.y"
                                        { yyval = newStmtNode(IfK); yyval->child[0] = yyvsp[-2]; yyval->child[1] = yyvsp[0]; }
#line 1531 "src/parse.c"
    break;

  case 40: /* selection_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 201 "src/cminus.y"
                                        { yyval = newStmtNode(IfK); yyval->child[0] = yyvsp[-4]; yyval->child[1] = yyvsp[-2]; yyval->child[2] = yyvsp[0]; }
#line 1537 "src/parse.c"
    break;

  case 41: /* iteration_stmt: WHILE LPAREN expression RPAREN statement  */
#line 206 "src/cminus.y"
                                        { yyval = newStmtNode(WhileK); yyval->child[0] = yyvsp[-2]; yyval->child[1] = yyvsp[0]; }
#line 1543 "src/parse.c"
    break;

  case 42: /* return_stmt: RETURN SEMI  */
#line 210 "src/cminus.y"
                                        { yyval = newStmtNode(ReturnK); }
#line 1549 "src/parse.c"
    break;

  case 43: /* return_stmt: RETURN expression SEMI  */
#line 211 "src/cminus.y"
                                        { yyval = newStmtNode(ReturnK); yyval->child[0] = yyvsp[-1]; }
#line 1555 "src/parse.c"
    break;

  case 44: /* input_stmt: INPUT LPAREN ID RPAREN SEMI  */
#line 215 "src/cminus.y"
                                        {
                                          yyval = newStmtNode(CallK);
                                          yyval->attr.name = "input";
                                          TreeNode *arg = newExpNode(IdK);
                                          arg->attr.name = strdup(tokenString);
                                          yyval->child[0] = arg;
                                        }
#line 1567 "src/parse.c"
    break;

  case 45: /* output_stmt: OUTPUT LPAREN expression RPAREN SEMI  */
#line 226 "src/cminus.y"
                                        {
                                          yyval = newStmtNode(CallK);
                                          yyval->attr.name = "output";
                                          yyval->child[0] = yyvsp[-2];
                                        }
#line 1577 "src/parse.c"
    break;

  case 46: /* expression: var ASSIGN expression  */
#line 234 "src/cminus.y"
                                        { yyval = newStmtNode(AssignK); yyval->child[0] = yyvsp[-2]; yyval->child[1] = yyvsp[0]; }
#line 1583 "src/parse.c"
    break;

  case 47: /* expression: simple_expression  */
#line 235 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1589 "src/parse.c"
    break;

  case 48: /* var: ID  */
#line 240 "src/cminus.y"
                                        { yyval = newExpNode(IdK); yyval->attr.name = strdup(tokenString); }
#line 1595 "src/parse.c"
    break;

  case 49: /* $@6: %empty  */
#line 242 "src/cminus.y"
      { strcpy(savedID, tokenString); }
#line 1601 "src/parse.c"
    break;

  case 50: /* var: ID $@6 LBRACK expression RBRACK  */
#line 244 "src/cminus.y"
      {
          yyval = newExpNode(IdK);
          yyval->attr.name = strdup(savedID); /* Usa nome salvo */
          yyval->child[0] = yyvsp[-2]; /* child[0] é o índice */
      }
#line 1611 "src/parse.c"
    break;

  case 51: /* simple_expression: additive_expression relop additive_expression  */
#line 253 "src/cminus.y"
                                        { yyval = yyvsp[-1]; yyval->child[0] = yyvsp[-2]; yyval->child[1] = yyvsp[0]; }
#line 1617 "src/parse.c"
    break;

  case 52: /* simple_expression: additive_expression  */
#line 254 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1623 "src/parse.c"
    break;

  case 53: /* relop: LE  */
#line 258 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = LE; }
#line 1629 "src/parse.c"
    break;

  case 54: /* relop: LT  */
#line 259 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = LT; }
#line 1635 "src/parse.c"
    break;

  case 55: /* relop: GT  */
#line 260 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = GT; }
#line 1641 "src/parse.c"
    break;

  case 56: /* relop: GE  */
#line 261 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = GE; }
#line 1647 "src/parse.c"
    break;

  case 57: /* relop: EQ  */
#line 262 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = EQ; }
#line 1653 "src/parse.c"
    break;

  case 58: /* relop: NE  */
#line 263 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = NE; }
#line 1659 "src/parse.c"
    break;

  case 59: /* additive_expression: additive_expression addop term  */
#line 267 "src/cminus.y"
                                        { yyval = yyvsp[-1]; yyval->child[0] = yyvsp[-2]; yyval->child[1] = yyvsp[0]; }
#line 1665 "src/parse.c"
    break;

  case 60: /* additive_expression: term  */
#line 268 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1671 "src/parse.c"
    break;

  case 61: /* addop: PLUS  */
#line 272 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = PLUS; }
#line 1677 "src/parse.c"
    break;

  case 62: /* addop: MINUS  */
#line 273 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = MINUS; }
#line 1683 "src/parse.c"
    break;

  case 63: /* term: term mulop factor  */
#line 277 "src/cminus.y"
                                        { yyval = yyvsp[-1]; yyval->child[0] = yyvsp[-2]; yyval->child[1] = yyvsp[0]; }
#line 1689 "src/parse.c"
    break;

  case 64: /* term: factor  */
#line 278 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1695 "src/parse.c"
    break;

  case 65: /* mulop: TIMES  */
#line 282 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = TIMES; }
#line 1701 "src/parse.c"
    break;

  case 66: /* mulop: OVER  */
#line 283 "src/cminus.y"
                                        { yyval = newExpNode(OpK); yyval->attr.op = OVER; }
#line 1707 "src/parse.c"
    break;

  case 67: /* factor: LPAREN expression RPAREN  */
#line 287 "src/cminus.y"
                                        { yyval = yyvsp[-1]; }
#line 1713 "src/parse.c"
    break;

  case 68: /* factor: var  */
#line 288 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1719 "src/parse.c"
    break;

  case 69: /* factor: call  */
#line 289 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1725 "src/parse.c"
    break;

  case 70: /* factor: NUM  */
#line 290 "src/cminus.y"
                                        { yyval = newExpNode(ConstK); yyval->attr.val = atoi(tokenString); }
#line 1731 "src/parse.c"
    break;

  case 71: /* factor: INPUT LPAREN RPAREN  */
#line 291 "src/cminus.y"
                                        {
                                          yyval = newStmtNode(CallK);
                                          yyval->attr.name = "input";
                                        }
#line 1740 "src/parse.c"
    break;

  case 72: /* $@7: %empty  */
#line 299 "src/cminus.y"
      { strcpy(savedID, tokenString); }
#line 1746 "src/parse.c"
    break;

  case 73: /* call: ID $@7 LPAREN args RPAREN  */
#line 301 "src/cminus.y"
      {
          yyval = newStmtNode(CallK);
          yyval->attr.name = strdup(savedID);
          yyval->child[0] = yyvsp[-1];
      }
#line 1756 "src/parse.c"
    break;

  case 74: /* args: arg_list  */
#line 309 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1762 "src/parse.c"
    break;

  case 75: /* args: %empty  */
#line 310 "src/cminus.y"
                                         { yyval = NULL; }
#line 1768 "src/parse.c"
    break;

  case 76: /* arg_list: arg_list COMMA expression  */
#line 314 "src/cminus.y"
                                        {
                                          YYSTYPE t = yyvsp[-2];
                                          while (t->sibling) t = t->sibling;
                                          t->sibling = yyvsp[0];
                                          yyval = yyvsp[-2];
                                        }
#line 1779 "src/parse.c"
    break;

  case 77: /* arg_list: expression  */
#line 320 "src/cminus.y"
                                        { yyval = yyvsp[0]; }
#line 1785 "src/parse.c"
    break;


#line 1789 "src/parse.c"

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

#line 323 "src/cminus.y"


void yyerror(char *message) {
    fprintf(listing, "ERRO SINTATICO: %s na linha %d\n", message, lineno);
    Error = TRUE;
}

TreeNode *parse(void) {
    yyparse();
    return savedTree;
}
