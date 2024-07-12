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
#line 1 "lispToForth/tradForth.y"
                      // SECCION 1 
#include "lispToForth/tradForth.h"


int yylex () ;
int yyerror (char* mensaje) ; 
char *gen_code (char *) ;
char *my_malloc (int nbytes) ;



char temp [2048] ;
char *concat_ptr;

char *act_function = "";


typedef struct s_attr {
     int value ;       //  - valor numerico entero 
     int type ;        //  - tipo de dato
     char* trad;       //  - traduccion a Forth
     char* code ;    
     struct nodoAST* nodo;     //  - nodo del arbol sintactico abstracto
} t_attr ;

#define YYSTYPE t_attr





#line 102 "y.tab.c"

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
    DEFVAR = 262,
    SETQ = 263,
    SETF = 264,
    AREF = 265,
    MAKE = 266,
    ARRAY = 267,
    LET = 268,
    WHILE = 269,
    LOOP = 270,
    IF = 271,
    PROGN = 272,
    DO = 273,
    PRINT = 274,
    DEFUN = 275,
    RETURN = 276,
    FROM = 277,
    AND = 278,
    OR = 279,
    LEQ = 280,
    GEQ = 281,
    NEQ = 282,
    DOTIMES = 283,
    LENGTH = 284,
    INCF = 285,
    REDUCE = 286
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define IDENTIF 259
#define INTEGER 260
#define STRING 261
#define DEFVAR 262
#define SETQ 263
#define SETF 264
#define AREF 265
#define MAKE 266
#define ARRAY 267
#define LET 268
#define WHILE 269
#define LOOP 270
#define IF 271
#define PROGN 272
#define DO 273
#define PRINT 274
#define DEFUN 275
#define RETURN 276
#define FROM 277
#define AND 278
#define OR 279
#define LEQ 280
#define GEQ 281
#define NEQ 282
#define DOTIMES 283
#define LENGTH 284
#define INCF 285
#define REDUCE 286

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


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
      39,    40,    34,    32,     2,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    36,    38,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    81,    82,    88,    89,    90,    91,    92,
      93,    94,    95,    99,    99,   109,   110,   117,   125,   136,
     151,   154,   160,   164,   171,   178,   179,   186,   194,   201,
     202,   214,   217,   221,   236,   237,   252,   266,   280,   294,
     308,   323,   337,   352,   366,   380,   394,   410,   415,   423,
     424
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENTIF", "INTEGER", "STRING",
  "DEFVAR", "SETQ", "SETF", "AREF", "MAKE", "ARRAY", "LET", "WHILE",
  "LOOP", "IF", "PROGN", "DO", "PRINT", "DEFUN", "RETURN", "FROM", "AND",
  "OR", "LEQ", "GEQ", "NEQ", "DOTIMES", "LENGTH", "INCF", "REDUCE", "'+'",
  "'-'", "'*'", "'/'", "'='", "'<'", "'>'", "'('", "')'", "$accept",
  "axioma", "instrucciones", "sentencia", "deffuncion", "$@1",
  "argumentosfun", "returnfrom", "definicion", "restodef", "asignacion",
  "condicion", "restoif", "bucle", "llamada", "argumentos", "print",
  "restoprint", "expresion", "operando", "variable", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    43,    45,    42,    47,    61,    60,    62,    40,
      41
};
# endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -30,   125,    10,   -51,   -30,    22,     1,     1,   -28,   -27,
      -1,    22,     0,    11,   -19,   -51,   -24,   -23,   -20,   -51,
     -18,    -9,    -8,   -51,   -51,   -51,   -51,    17,   124,   -51,
      22,   -51,   -51,    25,    22,    20,    -6,    22,    -3,   -51,
     -51,   -51,   -51,    15,   -51,   -51,   -51,   -51,   -51,   -51,
       4,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,   -51,    73,   -51,   -51,   -51,     1,     1,
      35,    23,    16,    50,   -51,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    24,    22,    25,
     -30,   -30,     1,    22,    18,    37,    42,    45,    48,    49,
      51,    52,    53,    54,    55,    61,    78,    62,    63,   -51,
      72,    74,     1,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,    22,    22,    75,   -32,
     -30,   -51,    79,   -51,   -30,    43,   -51,   -51,    80,   -51,
     -51,   -30,   -51,    81,    82,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     2,     3,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     7,
       0,     0,     0,     1,     4,    47,    49,     0,     0,    28,
      29,    34,    48,     0,     0,     0,     0,     0,     0,    32,
      31,    33,    13,     0,    12,     5,     6,     8,     9,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    18,    20,    22,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     3,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    15,    17,    39,    40,    44,    45,    46,    35,
      36,    37,    38,    41,    42,    43,     0,     0,     0,     0,
       3,    16,     0,    23,     3,     0,    25,    24,     0,    21,
      19,     3,    14,     0,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,    -4,   -51,   -51,   -51,   -50,   -51,   -51,   -26,
     -51,   -51,   -51,   -51,   -51,    83,   -51,   -51,   -10,   -51,
      12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    15,    72,   111,    16,    17,    65,
      18,    19,   137,    20,    21,    29,    22,    40,    30,    31,
      32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    38,    41,    25,    26,    26,    39,   135,   136,     1,
      23,    35,    36,    37,    43,    42,    44,    45,    33,    34,
      46,    50,    47,    66,    67,    25,    26,    70,    25,    26,
      68,    48,    49,    69,    27,    27,    71,    73,    74,    28,
      91,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    90,    93,    92,    27,   106,   114,    27,
     141,    28,   131,   108,    64,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   115,   107,    66,
      88,    89,   116,   113,    87,   117,   109,   110,   118,   119,
     126,   120,   121,   122,   123,   124,    51,    52,    53,    54,
      55,   125,   127,   128,   112,    56,    57,    58,    59,    60,
      61,    62,   129,    63,   130,   134,   132,   133,     0,   139,
     142,   144,   145,     0,   112,     0,   138,     0,     0,     5,
     140,     0,     6,     7,     8,     0,     0,   143,     9,     0,
      10,    11,     0,     0,    12,    13,    14,    51,    52,    53,
      54,    55,     0,     0,     0,     0,    56,    57,    58,    59,
      60,    61,    62
};

static const yytype_int16 yycheck[] =
{
       4,    11,    12,     3,     4,     4,     6,    39,    40,    39,
       0,    39,    39,    14,    33,     4,    40,    40,     6,     7,
      40,     4,    40,    33,    34,     3,     4,    37,     3,     4,
      10,    40,    40,    39,    34,    34,    39,    22,    34,    39,
      17,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    18,     4,    39,    34,    33,    40,    34,
      17,    39,   112,    89,    39,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    40,    88,    89,
      68,    69,    40,    93,    11,    40,    90,    91,    40,    40,
      12,    40,    40,    40,    40,    40,    23,    24,    25,    26,
      27,    40,    40,    40,    92,    32,    33,    34,    35,    36,
      37,    38,    40,    30,    40,    40,   126,   127,    -1,    40,
      40,    40,    40,    -1,   112,    -1,   130,    -1,    -1,     4,
     134,    -1,     7,     8,     9,    -1,    -1,   141,    13,    -1,
      15,    16,    -1,    -1,    19,    20,    21,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    42,    43,    44,     4,     7,     8,     9,    13,
      15,    16,    19,    20,    21,    45,    48,    49,    51,    52,
      54,    55,    57,     0,    43,     3,     4,    34,    39,    56,
      59,    60,    61,    61,    61,    39,    39,    14,    59,     6,
      58,    59,     4,    33,    40,    40,    40,    40,    40,    40,
       4,    23,    24,    25,    26,    27,    32,    33,    34,    35,
      36,    37,    38,    56,    39,    50,    59,    59,    10,    39,
      59,    39,    46,    22,    34,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    11,    61,    61,
      18,    17,    39,     4,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    33,    59,    50,    43,
      43,    47,    61,    59,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    12,    40,    40,    40,
      40,    47,    59,    59,    40,    39,    40,    53,    43,    40,
      43,    17,    40,    43,    40,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    46,    45,    47,    47,    48,    49,    49,
      50,    50,    51,    51,    52,    53,    53,    54,    55,    56,
      56,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     3,     2,     3,     3,
       2,     3,     3,     0,     8,     0,     2,     5,     3,     8,
       1,     6,     3,     7,     7,     1,     5,     5,     2,     0,
       2,     2,     1,     1,     1,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     1,     1,     1,
       3
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
#line 78 "lispToForth/tradForth.y"
                                                  { writeFile(yyvsp[0].trad); }
#line 1480 "y.tab.c"
    break;

  case 3:
#line 81 "lispToForth/tradForth.y"
                                                  { yyval.trad = ""; }
#line 1486 "y.tab.c"
    break;

  case 4:
#line 82 "lispToForth/tradForth.y"
                                                  { sprintf(temp, "%s%s", yyvsp[-1].trad, yyvsp[0].trad); 
                                                    yyval.trad = gen_code(temp);                 
                                                    }
#line 1494 "y.tab.c"
    break;

  case 5:
#line 88 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1500 "y.tab.c"
    break;

  case 6:
#line 89 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1506 "y.tab.c"
    break;

  case 7:
#line 90 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[0]; }
#line 1512 "y.tab.c"
    break;

  case 8:
#line 91 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1518 "y.tab.c"
    break;

  case 9:
#line 92 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1524 "y.tab.c"
    break;

  case 10:
#line 93 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[0]; }
#line 1530 "y.tab.c"
    break;

  case 11:
#line 94 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1536 "y.tab.c"
    break;

  case 12:
#line 95 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1542 "y.tab.c"
    break;

  case 13:
#line 99 "lispToForth/tradForth.y"
                                                { act_function = yyvsp[0].code; }
#line 1548 "y.tab.c"
    break;

  case 14:
#line 101 "lispToForth/tradForth.y"
                                                {                              
                                                sprintf(temp, ": %s ( %s-- n )\n%s;\n", yyvsp[-6].code, yyvsp[-3].trad, yyvsp[-1].trad);
                                                yyval.trad = gen_code(temp);
                                                act_function = ""; //TODO: REMOVE IF NOT USED
                                                }
#line 1558 "y.tab.c"
    break;

  case 15:
#line 109 "lispToForth/tradForth.y"
                                                { yyval.trad =" "; }
#line 1564 "y.tab.c"
    break;

  case 16:
#line 110 "lispToForth/tradForth.y"
                                                { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].trad); 
                                                yyval.trad = gen_code(temp); 
                                                }
#line 1572 "y.tab.c"
    break;

  case 17:
#line 117 "lispToForth/tradForth.y"
                                               { 
                                                sprintf(temp, "%s\nEXIT\n", yyvsp[0].trad);
                                                yyval.trad = gen_code(temp);
                                                }
#line 1581 "y.tab.c"
    break;

  case 18:
#line 125 "lispToForth/tradForth.y"
                                                     { if (yyvsp[0].type == 0) { // INT CASE
                                                        sprintf(temp, "VARIABLE %s\n%d %s !\n", yyvsp[-1].code, yyvsp[0].value, yyvsp[-1].code);
                                                        yyval.trad = gen_code(temp);

                                                        }
                                                        else { // VECTOR CASE
                                                        sprintf(temp, "CREATE %s %d ALLOT\n: inicializar-%s ( -- )\n\t%s %d CELLS 0 DO\n i %s +!\nLOOP ;\ninicializar-%s\n", 
                                                        yyvsp[-1].code, yyvsp[0].value, yyvsp[-1].code, yyvsp[-1].code, yyvsp[0].value, yyvsp[-1].code,yyvsp[-1].code);
                                                        yyval.trad = gen_code(temp);
                                                        }
                                                    }
#line 1597 "y.tab.c"
    break;

  case 19:
#line 137 "lispToForth/tradForth.y"
                                                    {   // For simlicity, we ignore the use of local variables
                                                        if (yyvsp[-3].type == 0) { // INT CASE
                                                        sprintf(temp, "VARIABLE %s\n%d %s !\n%s", yyvsp[-4].code, yyvsp[-3].value, yyvsp[-4].code, yyvsp[0].trad);
                                                        yyval.trad = gen_code(temp);
                                                        }
                                                        else { // VECTOR CASE
                                                        sprintf(temp, "CREATE %s %d ALLOT\n: inicializar-%s ( -- )\n\t%s %d CELLS 0 DO\n i %s +!\nLOOP ;\ninicializar-%s\n%s", 
                                                        yyvsp[-4].code, yyvsp[-3].value, yyvsp[-4].code, yyvsp[-4].code, yyvsp[-3].value, yyvsp[-4].code, yyvsp[-4].code, yyvsp[0].trad);
                                                        yyval.trad = gen_code(temp);
                                                        }

                                                    }
#line 1614 "y.tab.c"
    break;

  case 20:
#line 151 "lispToForth/tradForth.y"
                                                     { yyval.type = 0; 
                                                       yyval.value = yyvsp[0].value; 
                                                     }
#line 1622 "y.tab.c"
    break;

  case 21:
#line 154 "lispToForth/tradForth.y"
                                                     { yyval.type = 1; 
                                                      yyval.value = yyvsp[-1].value; 
                                                     }
#line 1630 "y.tab.c"
    break;

  case 22:
#line 160 "lispToForth/tradForth.y"
                                                                { 
                                                                sprintf(temp, "%s %s !\n", yyvsp[0].trad, yyvsp[-1].code); 
                                                                yyval.trad = gen_code(temp);
                                                                }
#line 1639 "y.tab.c"
    break;

  case 23:
#line 164 "lispToForth/tradForth.y"
                                                                { 
                                                                sprintf(temp, "%s %s CELLS %s + !\n", yyvsp[0].trad, yyvsp[-2].trad, yyvsp[-3].code);
                                                                yyval.trad = gen_code(temp);
                                                                }
#line 1648 "y.tab.c"
    break;

  case 24:
#line 172 "lispToForth/tradForth.y"
                                                      { 
                                                        sprintf(temp, "%s IF\n%s%sTHEN\n", yyvsp[-5].trad, yyvsp[-2].trad, yyvsp[0].trad);
                                                        yyval.trad = gen_code(temp);
                                                    }
#line 1657 "y.tab.c"
    break;

  case 25:
#line 178 "lispToForth/tradForth.y"
                                                    { yyval.trad=""; }
#line 1663 "y.tab.c"
    break;

  case 26:
#line 179 "lispToForth/tradForth.y"
                                                    {  
                                                    sprintf(temp, "ELSE\n%s", yyvsp[-2].trad);
                                                    yyval.trad = gen_code(temp);
                                                    }
#line 1672 "y.tab.c"
    break;

  case 27:
#line 186 "lispToForth/tradForth.y"
                                                  { 
                                                        sprintf(temp, "BEGIN\n%s WHILE\n%sREPEAT\n", yyvsp[-2].trad, yyvsp[0].trad);   
                                                        yyval.trad = gen_code(temp); 
                                                        }
#line 1681 "y.tab.c"
    break;

  case 28:
#line 194 "lispToForth/tradForth.y"
                                             { 
                                                 sprintf(temp, "%s%s\n", yyvsp[0].trad, yyvsp[-1].code);
                                                 yyval.trad = gen_code(temp);
                                                 }
#line 1690 "y.tab.c"
    break;

  case 29:
#line 201 "lispToForth/tradForth.y"
                                                 { yyval.trad = ""; }
#line 1696 "y.tab.c"
    break;

  case 30:
#line 202 "lispToForth/tradForth.y"
                                                 { 
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        sprintf(temp, "%s @\n%s", yyvsp[-1].trad, yyvsp[0].trad); 
                                                    }
                                                    else{
                                                        sprintf(temp, "%s\n%s", yyvsp[-1].trad, yyvsp[0].trad); 
                                                    }
                                                    yyval.trad = gen_code(temp); 
                                                }
#line 1710 "y.tab.c"
    break;

  case 31:
#line 214 "lispToForth/tradForth.y"
                                               { yyval = yyvsp[0]; }
#line 1716 "y.tab.c"
    break;

  case 32:
#line 217 "lispToForth/tradForth.y"
                                               {
                                                sprintf(temp, "S\" %s\" TYPE\n", yyvsp[0].code);
                                                yyval.trad = gen_code(temp);
                                                }
#line 1725 "y.tab.c"
    break;

  case 33:
#line 221 "lispToForth/tradForth.y"
                                                { 
                                                if (strcmp(yyvsp[0].code, "variable") == 0){
                                                    sprintf(temp, "%s @ .\n", yyvsp[0].trad);
                                                }
                                                else{
                                                    sprintf(temp, "%s .\n", yyvsp[0].trad);
                                                }
                                                yyval.trad = gen_code(temp);
                                                }
#line 1739 "y.tab.c"
    break;

  case 34:
#line 236 "lispToForth/tradForth.y"
                                                 { yyval=yyvsp[0]; }
#line 1745 "y.tab.c"
    break;

  case 35:
#line 237 "lispToForth/tradForth.y"
                                                    { 
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "+");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";

                                                 }
#line 1765 "y.tab.c"
    break;

  case 36:
#line 252 "lispToForth/tradForth.y"
                                                    { 
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "-");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                 }
#line 1784 "y.tab.c"
    break;

  case 37:
#line 266 "lispToForth/tradForth.y"
                                                     {  
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "*");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                 }
#line 1803 "y.tab.c"
    break;

  case 38:
#line 280 "lispToForth/tradForth.y"
                                                   {  
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "/");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                 }
#line 1822 "y.tab.c"
    break;

  case 39:
#line 294 "lispToForth/tradForth.y"
                                                   {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "AND");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                }
#line 1841 "y.tab.c"
    break;

  case 40:
#line 308 "lispToForth/tradForth.y"
                                                  {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "OR");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                               
                                                }
#line 1861 "y.tab.c"
    break;

  case 41:
#line 323 "lispToForth/tradForth.y"
                                                  {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "=");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                }
#line 1880 "y.tab.c"
    break;

  case 42:
#line 337 "lispToForth/tradForth.y"
                                                  {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "<");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";

                                                }
#line 1900 "y.tab.c"
    break;

  case 43:
#line 352 "lispToForth/tradForth.y"
                                                  {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, ">");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                }
#line 1919 "y.tab.c"
    break;

  case 44:
#line 366 "lispToForth/tradForth.y"
                                                  {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "<=");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                }
#line 1938 "y.tab.c"
    break;

  case 45:
#line 380 "lispToForth/tradForth.y"
                                                  { 
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, ">=");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                }
#line 1957 "y.tab.c"
    break;

  case 46:
#line 394 "lispToForth/tradForth.y"
                                                  {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-2].trad);
                                                    if (strcmp(yyvsp[-2].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", yyvsp[-1].trad);
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "/=");
                                                    yyval.trad = gen_code(temp);
                                                    yyval.code = "oper";
                                                }
#line 1976 "y.tab.c"
    break;

  case 47:
#line 410 "lispToForth/tradForth.y"
                                                { sprintf(temp, "%d", yyvsp[0].value);
                                                yyval.trad = gen_code(temp);
                                                yyval.value = yyvsp[0].value; 
                                                yyval.code = "number";
                                                }
#line 1986 "y.tab.c"
    break;

  case 48:
#line 415 "lispToForth/tradForth.y"
                                                { 

                                                sprintf(temp, "%s", yyvsp[0].code);
                                                yyval.trad = gen_code(temp);
                                                yyval.code = "variable";
                                                }
#line 1997 "y.tab.c"
    break;

  case 49:
#line 423 "lispToForth/tradForth.y"
                                                { yyval.code = yyvsp[0].code; }
#line 2003 "y.tab.c"
    break;

  case 50:
#line 424 "lispToForth/tradForth.y"
                                                { yyval.code = yyvsp[-1].code; }
#line 2009 "y.tab.c"
    break;


#line 2013 "y.tab.c"

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
#line 427 "lispToForth/tradForth.y"


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
    {"setq", SETQ}, {"setf", SETF}, {"aref", AREF}, {"return", RETURN}, {"from", FROM},
    {"while", WHILE}, {"loop", LOOP}, {"if", IF}, {"do", DO}, {"defvar", DEFVAR}, 
    {"make", MAKE}, {"array", ARRAY}, {"progn", PROGN}, {"defun", DEFUN},
    {"and", AND}, {"or", OR}, {"<=", LEQ}, {">=", GEQ}, 
    {"/=", NEQ}, {"let", LET}, {"print", PRINT}, {"dotimes", DOTIMES},
    {"length", LENGTH}, {"incf", INCF}, {"reduce",REDUCE}, //TODO:COMPLETAR CON FUNCIONALIDADES ADICIONALES
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
    cleanFile(); // limpia el archivo de salida
    yyparse () ;
}   
