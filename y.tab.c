/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "vectorialC.y"
                      // SECCION 1 
#include "basicCalc.h"
//int memoria [26] ;   	// Se define una zona de memoria para las variables 

int yylex () ;
int yyerror (char* mensaje) ; 
char *gen_code (char *) ;
char *my_malloc (int nbytes) ;
char *act_function;
struct nodoAST* lastNode = NULL;
struct nodoAST* nodoAxioma = NULL;
char temp [2048] ;

typedef struct s_attr {
     int value ;       //  - valor numerico entero 
     char* code ;    
     char* prefija;   //  - expresion prefija
     struct nodoAST* nodo;     //  - nodo del arbol sintactico abstracto
} t_attr ;

#define YYSTYPE t_attr


#line 94 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    IDENTIF = 259,
    INTEGER = 260,
    STRING = 261,
    MAIN = 262,
    WHILE = 263,
    FOR = 264,
    IF = 265,
    ELSE = 266,
    PUTS = 267,
    PRINTF = 268,
    AND = 269,
    OR = 270,
    LEQ = 271,
    GEQ = 272,
    EQ = 273,
    NEQ = 274,
    RETURN = 275,
    UNARY_SIGN = 276
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define IDENTIF 259
#define INTEGER 260
#define STRING 261
#define MAIN 262
#define WHILE 263
#define FOR 264
#define IF 265
#define ELSE 266
#define PUTS 267
#define PRINTF 268
#define AND 269
#define OR 270
#define LEQ 271
#define GEQ 272
#define EQ 273
#define NEQ 274
#define RETURN 275
#define UNARY_SIGN 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

#define YYUNDEFTOK  2
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    32,    24,    22,    29,    23,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    21,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    67,    68,    91,    96,   111,   123,   126,
     142,   146,   149,   158,   172,   173,   176,   177,   186,   187,
     194,   194,   211,   215,   220,   225,   238,   242,   246,   277,
     295,   299,   310,   325,   326,   338,   350,   362,   375,   376,
     386,   398,   406,   415
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENTIF", "INTEGER", "STRING",
  "MAIN", "WHILE", "FOR", "IF", "ELSE", "PUTS", "PRINTF", "AND", "OR",
  "LEQ", "GEQ", "EQ", "NEQ", "RETURN", "'='", "'+'", "'-'", "'*'", "'/'",
  "UNARY_SIGN", "'('", "';'", "','", "'['", "']'", "')'", "'{'", "'}'",
  "$accept", "axioma", "declaraciones", "nuevaDeclaracion", "varGlob",
  "varRecGlob", "restoVar", "funcionesDef", "funcionesDefRec",
  "funcionArgs", "recArgFunct", "mainDef", "$@1", "recSentenciaFin",
  "recSentenciaNoFin", "sentencia", "declaracion", "asignacion",
  "expresion", "termino", "operando", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    61,    43,    45,    42,    47,   276,    40,    59,    44,
      91,    93,    41,   123,   125
};
# endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,    21,    36,    26,     3,   -68,    43,    49,    52,   -68,
     -68,    32,    41,   -68,   -68,    58,   -68,    37,    40,    68,
      45,    44,    46,    47,   -68,    -4,    69,    48,    49,   -68,
      -1,    32,    21,   -68,   -68,    56,    74,    12,   -68,    77,
      -1,    51,    55,   -68,   -68,    -1,    12,   -68,   -68,   -68,
      10,    10,    12,    35,   -68,   -68,    80,   -68,   -68,   -68,
     -68,     6,   -68,   -68,    20,    12,    12,    12,    12,     4,
      59,   -68,   -68,    24,    24,   -68,   -68,    12,   -68,   -68,
      -1,    49,    42,   -68,   -68,     7,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,    10,     0,     1,     0,    16,     0,     4,
       6,     8,     0,     2,    11,     0,     5,     0,     0,     0,
       0,     0,    18,     0,    12,    10,     0,     0,    16,    17,
       0,     8,     3,    20,    19,     0,     0,     0,    22,     0,
       0,     0,     0,     9,     7,     0,     0,    31,    42,    41,
       0,     0,     0,     0,    33,    38,    14,    25,    30,    29,
      21,    32,    39,    40,     0,     0,     0,     0,     0,     0,
       0,    13,    43,    34,    35,    36,    37,     0,    23,    24,
       0,    16,     0,    28,    15,     0,    26,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,    53,   -68,   -68,    57,    62,     8,   -68,    63,
     -68,   -68,   -68,   -40,     5,   -67,   -68,   -68,   -45,   -68,
       0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     4,     9,    10,    20,    11,    16,    71,    17,
      29,    13,    45,    39,    79,    40,    41,    42,    53,    54,
      55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      57,    61,    80,    35,    36,    60,     1,    64,    35,    36,
      12,    35,    36,    48,    49,    48,    49,     6,    80,    37,
      73,    74,    75,    76,    77,     3,     8,    77,    65,    66,
      67,    68,    82,    38,    50,    51,     5,    52,    78,    52,
      83,    86,    65,    66,    67,    68,    14,     6,    67,    68,
      62,    63,    72,     7,    15,    18,     8,    65,    66,    67,
      68,    19,    22,    69,    65,    66,    67,    68,    21,    23,
      85,    24,    25,    26,    32,    28,    27,    46,    47,    58,
      30,    33,    56,    59,    70,    44,    81,    31,    43,    84,
      87,    34
};

static const yytype_int8 yycheck[] =
{
      40,    46,    69,     4,     5,    45,     5,    52,     4,     5,
       7,     4,     5,     3,     4,     3,     4,    21,    85,    20,
      65,    66,    67,    68,    20,     4,    30,    20,    22,    23,
      24,    25,    77,    34,    22,    23,     0,    27,    34,    27,
      80,    34,    22,    23,    24,    25,     3,    21,    24,    25,
      50,    51,    32,    27,     5,     3,    30,    22,    23,    24,
      25,    29,     4,    28,    22,    23,    24,    25,    27,    32,
      28,    31,     4,    28,     5,    29,    32,    21,     4,    28,
      33,    33,     5,    28,     4,    32,    27,    25,    31,    81,
      85,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    36,     4,    37,     0,    21,    27,    30,    38,
      39,    41,     7,    46,     3,     5,    42,    44,     3,    29,
      40,    27,     4,    32,    31,     4,    28,    32,    29,    45,
      33,    41,     5,    33,    44,     4,     5,    20,    34,    48,
      50,    51,    52,    40,    37,    47,    21,     4,     3,     4,
      22,    23,    27,    53,    54,    55,     5,    48,    28,    28,
      48,    53,    55,    55,    53,    22,    23,    24,    25,    28,
       4,    43,    32,    53,    53,    53,    53,    20,    34,    49,
      50,    27,    53,    48,    42,    28,    34,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    40,    40,
      41,    41,    41,    42,    43,    43,    44,    44,    45,    45,
      47,    46,    48,    48,    48,    48,    49,    49,    49,    50,
      50,    51,    52,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     2,     1,     5,     0,     4,
       0,     2,     3,     6,     0,     3,     0,     3,     0,     2,
       0,     6,     1,     4,     4,     2,     4,     4,     2,     2,
       2,     2,     3,     1,     3,     3,     3,     3,     1,     2,
       2,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 54 "vectorialC.y"
                                                {   printf ("Arbol sintactico abstracto:\n");
                                                imprimirAST(nodoAxioma); 
                                                printf("\n\n");
                                                printf ("Tabla de símbolos:\n");
                                                Symbol **tabla = initSymbolTable();
                                                semanticAnalysis(nodoAxioma, tabla);
                                                destroySymbolTable(tabla);
                                                liberarAST(nodoAxioma);
                                                printf ("\n\n");
                                            }
#line 1424 "y.tab.c"
    break;

  case 4:
#line 68 "vectorialC.y"
                                           { act_function = yyvsp[-1].code; 
                                            if (! nodoAxioma){
                                                nodoAxioma = crearNodoIntermedioGenerico("axioma", 0);
                                            }
                                            if (yyvsp[0].code){ // Variables
                                                // Gestion de nodo AST
                                                struct nodoAST* nodoVar;                                        
                                                nodoVar = crearNodoVariableInit(yyvsp[-1].code, yyvsp[0].value, yyvsp[0].code);                                               
                                                if (yyvsp[0].nodo){
                                                    agregarHermano(nodoVar, yyvsp[0].nodo);
                                                }
                                                agregarHijo(nodoAxioma, nodoVar);
                                                // Impresión de la notación prefija
                                                printf("(setq %s %s\n",yyvsp[-1].code ,yyvsp[0].prefija); 
                                            } else{ // Functions
                                                //TODO: CAMBIAR EL NOMBRE DE EL NODO $2.nodo->nombre = $1.code;
                                                agregarHijo(nodoAxioma, yyvsp[0].nodo);
                                                //impresión de la notación prefija
                                                printf("(defun %s %s", yyvsp[-1].code, yyvsp[0].prefija);
                                            } 
                                            }
#line 1450 "y.tab.c"
    break;

  case 5:
#line 91 "vectorialC.y"
                                            { 
                                            yyval.nodo = yyvsp[0].nodo;
                                            yyval.prefija = yyvsp[0].prefija;
                                            yyval.code = NULL; // NULL for functions
                                            }
#line 1460 "y.tab.c"
    break;

  case 6:
#line 96 "vectorialC.y"
                                            { yyval.value = yyvsp[0].value;
                                            yyval.nodo = yyvsp[0].nodo;
                                            yyval.prefija = yyvsp[0].prefija;
                                            if (yyvsp[0].code){
                                                yyval.code = "int"; //NOT NULL FOR VARIABLES
                                            }
                                            else {
                                                yyval.code = "vector"; //NOT NULL FOR VARIABLES
                                            }
                                            }
#line 1475 "y.tab.c"
    break;

  case 7:
#line 111 "vectorialC.y"
                                                                                { 
                                                                                 yyval.value = yyvsp[-4].value;
                                                                                 yyval.nodo = yyvsp[-3].nodo;
                                                                                 sprintf(temp, "%s)%s", yyvsp[-4].code, yyvsp[-3].code);
                                                                                 yyval.prefija = gen_code(temp);
                                                                                 yyval.code = yyvsp[-4].code;
                                                                                 act_function = NULL;
                                                                                }
#line 1488 "y.tab.c"
    break;

  case 8:
#line 123 "vectorialC.y"
                                                                { yyval.code = ""; 
                                                                  yyval.nodo = NULL;
                                                                }
#line 1496 "y.tab.c"
    break;

  case 9:
#line 126 "vectorialC.y"
                                                              {   struct nodoAST *nodoVar = NULL;
                                                                  sprintf(temp, " (setq %s %s)%s", yyvsp[-2].code, yyvsp[-1].prefija, yyvsp[0].prefija);
                                                                  yyval.prefija = gen_code(temp); 
                                                                  yyval.code = yyvsp[-1].code;             
                                                                if (yyvsp[-1].value){      
                                                                    nodoVar = crearNodoVariableInit(yyvsp[-2].code, 0, "vector");
                                                                } else {
                                                                    nodoVar = crearNodoVariableInit(yyvsp[-2].code, yyvsp[-1].value, "int");
                                                                }
                                                                if (yyvsp[0].nodo){
                                                                    agregarHermano(nodoVar, yyvsp[0].nodo);
                                                                }
                                                                yyval.nodo = nodoVar;
                                                                }
#line 1515 "y.tab.c"
    break;

  case 10:
#line 142 "vectorialC.y"
                                { yyval.value = 0; 
                                    sprintf(temp, "0");
                                    yyval.prefija = yyval.code = gen_code(temp);
                                    }
#line 1524 "y.tab.c"
    break;

  case 11:
#line 146 "vectorialC.y"
                                { yyval.value = yyvsp[0].value; 
                                    sprintf(temp, "%d", yyvsp[0].value);
                                    yyval.prefija = yyval.code = gen_code(temp);}
#line 1532 "y.tab.c"
    break;

  case 12:
#line 149 "vectorialC.y"
                                { yyval.value = 0;
                                    sprintf(temp, "(make-array %d)", yyvsp[-1].value);
								    yyval.prefija = gen_code(temp); 
                                    yyval.code = NULL;}
#line 1541 "y.tab.c"
    break;

  case 13:
#line 159 "vectorialC.y"
                                                    { //Nodo de la funcion
                                                        struct nodoAST* nodoFunc = crearNodoIntermedioGenerico("NombreFuncTemp", 0);
                                                        if ( yyvsp[-2].nodo){
                                                            agregarHijo(nodoFunc, yyvsp[-2].nodo);
                                                        }
                                                        yyval.nodo = nodoFunc;
                                                        //Notacion prefija
                                                        sprintf(temp," (%s)\n%s", yyvsp[-5].prefija, yyvsp[-2].prefija);
                                                        yyval.prefija = gen_code(temp); 
                                                        act_function = NULL;
                                                    }
#line 1557 "y.tab.c"
    break;

  case 15:
#line 173 "vectorialC.y"
                                                    { act_function = yyvsp[-2].code; }
#line 1563 "y.tab.c"
    break;

  case 16:
#line 176 "vectorialC.y"
                                            { yyval.prefija = ""; }
#line 1569 "y.tab.c"
    break;

  case 17:
#line 177 "vectorialC.y"
                                                         {    if( yyvsp[0].prefija == NULL)    {
                                                    sprintf(temp, "%s",  yyvsp[-1].code);
                                                } else{
                                                    sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].prefija);
                                                }
                                                yyval.prefija = gen_code(temp);
                                            }
#line 1581 "y.tab.c"
    break;

  case 18:
#line 186 "vectorialC.y"
                                    { yyval.prefija = NULL; }
#line 1587 "y.tab.c"
    break;

  case 19:
#line 187 "vectorialC.y"
                                                        { yyval.prefija = yyvsp[0].prefija; }
#line 1593 "y.tab.c"
    break;

  case 20:
#line 194 "vectorialC.y"
                                    { 
                                        act_function = "main"; 
                                        lastNode = NULL;
                                    }
#line 1602 "y.tab.c"
    break;

  case 21:
#line 198 "vectorialC.y"
                                    {   //Nodo AST
                                        if (! nodoAxioma){
                                            nodoAxioma = crearNodoIntermedioGenerico("axioma", 0);
                                        }
                                        struct nodoAST* nodoMain = crearNodoIntermedioGenerico("main", 1, lastNode);
                                        agregarHijo(nodoAxioma, nodoMain);
                                        //Notacion prefija
                                        printf("(defun main ()\n%s", yyvsp[0].prefija);
                                    }
#line 1616 "y.tab.c"
    break;

  case 22:
#line 211 "vectorialC.y"
                                                       { sprintf(temp,")\n"); 
                                                        yyval.prefija = gen_code(temp);
                                                        yyval.nodo = lastNode;
                                                        }
#line 1625 "y.tab.c"
    break;

  case 23:
#line 215 "vectorialC.y"
                                                                                { 
                                                                                sprintf(temp,"%s\n)\n", yyvsp[-2].prefija);
                                                                                yyval.prefija = gen_code(temp);
                                                                                }
#line 1634 "y.tab.c"
    break;

  case 24:
#line 220 "vectorialC.y"
                                                                                 { 
                                                                                sprintf(temp,"(return-from %s %s)\n%s", act_function, yyvsp[-2].prefija, yyvsp[-1].prefija); 
                                                                                yyval.prefija = gen_code(temp); 
                                                                                }
#line 1643 "y.tab.c"
    break;

  case 25:
#line 225 "vectorialC.y"
                                                                                { 
                                                                                // Nodos AST
                                                                                if (yyvsp[-1].nodo && lastNode) {                                                            
                                                                                        agregarHermano(yyvsp[-1].nodo, lastNode);
                                                                                } 
                                                                                yyval.nodo = yyvsp[-1].nodo;
                                                                                lastNode = yyvsp[-1].nodo;
                                                                                // Notacion prefija
                                                                                sprintf(temp,"%s\n%s", yyvsp[-1].prefija, yyvsp[0].prefija);
                                                                                yyval.prefija = gen_code(temp); 
                                                                                }
#line 1659 "y.tab.c"
    break;

  case 26:
#line 238 "vectorialC.y"
                                                                                { 
                                                                                sprintf(temp,"%s\n)\n", yyvsp[-2].prefija);
                                                                                yyval.prefija = gen_code(temp);
                                                                                }
#line 1668 "y.tab.c"
    break;

  case 27:
#line 242 "vectorialC.y"
                                                                                 { 
                                                                                sprintf(temp,"(return-from %s %s)\n%s", act_function, yyvsp[-2].prefija, yyvsp[-1].prefija); 
                                                                                yyval.prefija = gen_code(temp); 
                                                                                }
#line 1677 "y.tab.c"
    break;

  case 28:
#line 246 "vectorialC.y"
                                                                                { 
                                                                                // Nodos AST
                                                                                if (yyvsp[-1].nodo && lastNode) {                                                            
                                                                                        agregarHermano(yyvsp[-1].nodo, lastNode);
                                                                                } 
                                                                                yyval.nodo = yyvsp[-1].nodo;
                                                                                lastNode = yyvsp[-1].nodo;
                                                                                // Notacion prefija
                                                                                sprintf(temp,"%s\n%s", yyvsp[-1].prefija, yyvsp[0].prefija);
                                                                                yyval.prefija = gen_code(temp); 
                                                                                }
#line 1693 "y.tab.c"
    break;

  case 29:
#line 277 "vectorialC.y"
                                                              { yyval = yyvsp[-1]; }
#line 1699 "y.tab.c"
    break;

  case 30:
#line 295 "vectorialC.y"
                                                                    { yyval = yyvsp[-1]; }
#line 1705 "y.tab.c"
    break;

  case 31:
#line 299 "vectorialC.y"
                                           { // Para calculadora
                                             yyval.value = 0 ; 
                                             // Para AST
                                             yyval.nodo = crearNodoVariableInit(yyvsp[0].code, 0, "int");
                                             // Para notacion prefija
                                             sprintf (temp, "(setq %s 0)", yyvsp[0].code);
                                             yyval.prefija = gen_code(temp);
                                        }
#line 1718 "y.tab.c"
    break;

  case 32:
#line 310 "vectorialC.y"
                                     {    // Para calculadora
                                             yyval.value = yyvsp[0].value ;

                                             // Para AST
                                             struct nodoAST* nodoVar = crearNodoVariable(yyvsp[-2].code, yyvsp[0].value, "int");
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("asignacion", 2, nodoVar, yyvsp[0].nodo);
                                             yyval.nodo = nuevoNodo;

                                             // Para notacion prefija
                                             sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].prefija);
                                             yyval.prefija = gen_code(temp);
                                        }
#line 1735 "y.tab.c"
    break;

  case 33:
#line 325 "vectorialC.y"
                                         { yyval = yyvsp[0] ; }
#line 1741 "y.tab.c"
    break;

  case 34:
#line 326 "vectorialC.y"
                                         {   // Para calculadora
                                             yyval.value = yyvsp[-2].value + yyvsp[0].value ;  

                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("suma", 2, yyvsp[-2].nodo, yyvsp[0].nodo);
                                             yyval.nodo = nuevoNodo;

                                             // Notacion prefija
                                             sprintf(temp, "(+ %s %s)", yyvsp[-2].prefija, yyvsp[0].prefija); 
                                             yyval.prefija =  gen_code(temp);
                                        }
#line 1757 "y.tab.c"
    break;

  case 35:
#line 338 "vectorialC.y"
                                         {   // Para calculadora
                                             yyval.value = yyvsp[-2].value - yyvsp[0].value ;  

                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("resta", 2, yyvsp[-2].nodo, yyvsp[0].nodo);
                                             yyval.nodo = nuevoNodo;

                                             // Notacion prefija
                                             sprintf(temp, "(- %s %s)", yyvsp[-2].prefija, yyvsp[0].prefija);
                                             yyval.prefija =  gen_code(temp);
                                        }
#line 1773 "y.tab.c"
    break;

  case 36:
#line 350 "vectorialC.y"
                                         {   // Para calculadora
                                             yyval.value = yyvsp[-2].value * yyvsp[0].value ;  

                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("multiplicacion", 2, yyvsp[-2].nodo, yyvsp[0].nodo);
                                             yyval.nodo = nuevoNodo;

                                             // Notacion prefija
                                             sprintf(temp, "(* %s %s)", yyvsp[-2].prefija, yyvsp[0].prefija);
                                             yyval.prefija =  gen_code(temp);
                                        }
#line 1789 "y.tab.c"
    break;

  case 37:
#line 362 "vectorialC.y"
                                         {   // Para calculadora
                                             yyval.value = yyvsp[-2].value / yyvsp[0].value ;  

                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("división", 2, yyvsp[-2].nodo, yyvsp[0].nodo);
                                             yyval.nodo = nuevoNodo;

                                             // Notacion prefija
                                             sprintf(temp, "(/ %s %s)", yyvsp[-2].prefija, yyvsp[0].prefija);
                                             yyval.prefija =  gen_code(temp);
                                        }
#line 1805 "y.tab.c"
    break;

  case 38:
#line 375 "vectorialC.y"
                                                 { yyval = yyvsp[0] ; }
#line 1811 "y.tab.c"
    break;

  case 39:
#line 376 "vectorialC.y"
                                               {  // Para calculadora
                                                    yyval.value = yyvsp[0].value ; 
                                                    // Para AST
                                                    struct nodoAST* nodoSigno = crearNodoSigno("+", yyvsp[0].value);
                                                    struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("signo-unario", 2, nodoSigno, yyvsp[0].nodo);
                                                    yyval.nodo = nuevoNodo;
                                                    // Para notacion prefija
                                                    sprintf (temp, "(+ %s)", yyvsp[0].prefija);
                                                    yyval.prefija = gen_code(temp);
                                                }
#line 1826 "y.tab.c"
    break;

  case 40:
#line 386 "vectorialC.y"
                                               { // Para calculadora
                                                    yyval.value = -yyvsp[0].value ; 
                                                    // Para AST
                                                    struct nodoAST* nodoSigno = crearNodoSigno("-", - yyvsp[0].value);
                                                    struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("signo unario", 2, nodoSigno, yyvsp[0].nodo);
                                                    yyval.nodo = nuevoNodo;
                                                    // Para notacion prefija
                                                    sprintf (temp, "(- %s)", yyvsp[0].prefija);
                                                    yyval.prefija = gen_code(temp);
                                                }
#line 1841 "y.tab.c"
    break;

  case 41:
#line 398 "vectorialC.y"
                                        { // Para calculadora
                                             yyval.value = yyvsp[0].value ;
                                             // Para AST
                                             yyval.nodo = crearNodoVariable(yyvsp[0].code, yyvsp[0].value, "int");
                                             // Para notacion prefija
                                             sprintf (temp, "%s", yyvsp[0].code);
                                             yyval.prefija = gen_code(temp);
                                        }
#line 1854 "y.tab.c"
    break;

  case 42:
#line 406 "vectorialC.y"
                                         { // Para calculadora
                                             yyval.value = yyvsp[0].value ;
                                             // Para AST
                                             yyval.nodo = crearNodoNumero(yyvsp[0].value);
                                             // Para notacion prefija
                                             sprintf (temp, "%d", yyvsp[0].value);
                                             yyval.prefija = gen_code(temp);

                                         }
#line 1868 "y.tab.c"
    break;

  case 43:
#line 415 "vectorialC.y"
                                         { yyval = yyvsp[-1] ; }
#line 1874 "y.tab.c"
    break;


#line 1878 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 418 "vectorialC.y"


                        /* SECCION 4  Codigo en C */
int n_line = 1 ;

int yyerror(char *mensaje) {
    fprintf(stderr, "%s en la linea %d\n", mensaje, n_line);
    return 0; 
}


char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No memoria left for additional %d bytes\n", nbytes) ;
        fprintf (stderr, "%ld bytes reserved in %d calls\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}

/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords[] = {
    {"main", MAIN}, {"int", INTEGER}, {"puts", PUTS}, {"printf", PRINTF},
    {"while", WHILE}, {"for", FOR}, {"if", IF}, {"else", ELSE},
    {"&&", AND}, {"||", OR}, {"<=", LEQ}, {">=", GEQ}, {"==", EQ},
    {"!=", NEQ}, {"return", RETURN},
    {NULL, 0} // Marca el fin de la tabla
};


t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/


char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}

int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char expandable_ops [] = "!<=>|%/&+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == '\r' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            //printf ("WARNING: string with more than 255 characters in line %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
         //printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
               //printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
               //printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (expandable_ops, c) != NULL) { // busca c en operadores expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

    //printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
        //printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}

int main ()
{
    yyparse () ;
}   
