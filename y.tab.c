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
Symbol **tabla = NULL;
Symbol* sym = NULL;
int long_variable = 0;


typedef struct s_attr {
     int value ;       //  - valor numerico entero 
     int type ;        //  - tipo de dato
     char* trad;       //  - traduccion a Forth
     char* code ;    
     struct nodoAST* nodo;     //  - nodo del arbol sintactico abstracto
} t_attr ;

#define YYSTYPE t_attr





#line 106 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    IDENTIF = 259,                 /* IDENTIF  */
    INTEGER = 260,                 /* INTEGER  */
    STRING = 261,                  /* STRING  */
    DEFVAR = 262,                  /* DEFVAR  */
    SETQ = 263,                    /* SETQ  */
    SETF = 264,                    /* SETF  */
    AREF = 265,                    /* AREF  */
    MAKE = 266,                    /* MAKE  */
    ARRAY = 267,                   /* ARRAY  */
    LET = 268,                     /* LET  */
    WHILE = 269,                   /* WHILE  */
    LOOP = 270,                    /* LOOP  */
    IF = 271,                      /* IF  */
    PROGN = 272,                   /* PROGN  */
    DO = 273,                      /* DO  */
    PRINT = 274,                   /* PRINT  */
    DEFUN = 275,                   /* DEFUN  */
    RETURN = 276,                  /* RETURN  */
    FROM = 277,                    /* FROM  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    LEQ = 280,                     /* LEQ  */
    GEQ = 281,                     /* GEQ  */
    NEQ = 282,                     /* NEQ  */
    DOTIMES = 283,                 /* DOTIMES  */
    LENGTH = 284,                  /* LENGTH  */
    INCF = 285,                    /* INCF  */
    REDUCE = 286,                  /* REDUCE  */
    MAP = 287,                     /* MAP  */
    LIST = 288,                    /* LIST  */
    COERCE = 289,                  /* COERCE  */
    REVERSE = 290                  /* REVERSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define MAP 287
#define LIST 288
#define COERCE 289
#define REVERSE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_DEFVAR = 7,                     /* DEFVAR  */
  YYSYMBOL_SETQ = 8,                       /* SETQ  */
  YYSYMBOL_SETF = 9,                       /* SETF  */
  YYSYMBOL_AREF = 10,                      /* AREF  */
  YYSYMBOL_MAKE = 11,                      /* MAKE  */
  YYSYMBOL_ARRAY = 12,                     /* ARRAY  */
  YYSYMBOL_LET = 13,                       /* LET  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_LOOP = 15,                      /* LOOP  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_PROGN = 17,                     /* PROGN  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_PRINT = 19,                     /* PRINT  */
  YYSYMBOL_DEFUN = 20,                     /* DEFUN  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_FROM = 22,                      /* FROM  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_LEQ = 25,                       /* LEQ  */
  YYSYMBOL_GEQ = 26,                       /* GEQ  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_DOTIMES = 28,                   /* DOTIMES  */
  YYSYMBOL_LENGTH = 29,                    /* LENGTH  */
  YYSYMBOL_INCF = 30,                      /* INCF  */
  YYSYMBOL_REDUCE = 31,                    /* REDUCE  */
  YYSYMBOL_MAP = 32,                       /* MAP  */
  YYSYMBOL_LIST = 33,                      /* LIST  */
  YYSYMBOL_COERCE = 34,                    /* COERCE  */
  YYSYMBOL_REVERSE = 35,                   /* REVERSE  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '='  */
  YYSYMBOL_41_ = 41,                       /* '<'  */
  YYSYMBOL_42_ = 42,                       /* '>'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '#'  */
  YYSYMBOL_46_ = 46,                       /* '\''  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_axioma = 48,                    /* axioma  */
  YYSYMBOL_instrucciones = 49,             /* instrucciones  */
  YYSYMBOL_sentencia = 50,                 /* sentencia  */
  YYSYMBOL_deffuncion = 51,                /* deffuncion  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_argumentosfun = 53,             /* argumentosfun  */
  YYSYMBOL_returnfrom = 54,                /* returnfrom  */
  YYSYMBOL_definicion = 55,                /* definicion  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_restodef = 57,                  /* restodef  */
  YYSYMBOL_asignacion = 58,                /* asignacion  */
  YYSYMBOL_condicion = 59,                 /* condicion  */
  YYSYMBOL_restoif = 60,                   /* restoif  */
  YYSYMBOL_bucle = 61,                     /* bucle  */
  YYSYMBOL_llamada = 62,                   /* llamada  */
  YYSYMBOL_argumentos = 63,                /* argumentos  */
  YYSYMBOL_print = 64,                     /* print  */
  YYSYMBOL_restoprint = 65,                /* restoprint  */
  YYSYMBOL_incf = 66,                      /* incf  */
  YYSYMBOL_invertir = 67,                  /* invertir  */
  YYSYMBOL_expresion = 68,                 /* expresion  */
  YYSYMBOL_operando = 69,                  /* operando  */
  YYSYMBOL_variable = 70                   /* variable  */
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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
       2,     2,     2,     2,     2,    45,     2,     2,     2,    46,
      43,    44,    38,    36,     2,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    40,    42,     2,     2,     2,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    91,    92,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   114,   114,   124,   125,
     132,   140,   158,   157,   180,   183,   189,   203,   207,   212,
     240,   247,   248,   255,   259,   267,   279,   286,   287,   299,
     302,   306,   327,   342,   358,   359,   374,   388,   402,   416,
     430,   445,   459,   474,   488,   502,   516,   532,   537,   543,
     550,   551
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "DEFVAR", "SETQ", "SETF", "AREF", "MAKE", "ARRAY",
  "LET", "WHILE", "LOOP", "IF", "PROGN", "DO", "PRINT", "DEFUN", "RETURN",
  "FROM", "AND", "OR", "LEQ", "GEQ", "NEQ", "DOTIMES", "LENGTH", "INCF",
  "REDUCE", "MAP", "LIST", "COERCE", "REVERSE", "'+'", "'-'", "'*'", "'/'",
  "'='", "'<'", "'>'", "'('", "')'", "'#'", "'\\''", "$accept", "axioma",
  "instrucciones", "sentencia", "deffuncion", "$@1", "argumentosfun",
  "returnfrom", "definicion", "$@2", "restodef", "asignacion", "condicion",
  "restoif", "bucle", "llamada", "argumentos", "print", "restoprint",
  "incf", "invertir", "expresion", "operando", "variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -26,     8,   137,    21,   -26,    -1,   -26,   -16,     5,
      -3,    -3,   -20,   -19,    12,     5,     1,    23,   -12,   -15,
      -3,   -14,   -26,   -13,   -11,   -10,   -26,    -8,    -6,     6,
      20,    24,   -26,   -26,   -26,   -26,   198,   -26,     5,   -26,
     -26,    11,    13,    22,    14,     5,    26,   -26,   -26,   -26,
     -26,    33,    -3,    36,    -5,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,    -3,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,   -26,    35,   -26,   -26,
     178,   -26,    -3,    -3,    47,    61,    37,    77,    41,    75,
      43,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,    50,    56,   -26,     5,    11,    -1,
      -1,    -3,     5,    59,    -3,    68,    60,    63,    64,    69,
      71,    85,    86,    87,    90,    91,    95,    98,    99,   100,
      57,   103,   104,   -26,   105,   107,    -3,   -26,    -3,     5,
      -3,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,     5,   118,     5,   116,   -25,    -1,
     -26,   117,   119,   120,   124,   126,   -26,   -26,   145,   -26,
     -26,   131,     9,   -26,   149,   -26,   138,    -1,    -1,   -26,
      -1,   140,   141,   143,   -26,   142,   -26,    -1,   146,   158,
     148,   -26,   147,   151,   -26,    -3,   152,   -26,   159,    -3,
      -3,   162,   163,   -26
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    60,     0,     0,     0,     2,     3,    15,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     1,     4,    61,    57,     0,    36,    37,    44,
      58,     0,     0,     0,     0,     0,     0,    40,    39,    41,
      16,     0,     0,     0,     0,    12,     5,     6,     8,     9,
      11,    13,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    21,    24,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     3,
       3,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,    18,    20,     0,     0,
       0,    59,    49,    50,    54,    55,    56,    45,    46,    47,
      48,    51,    52,    53,     0,     0,     0,     0,     0,     3,
      19,     0,     0,     0,     0,     0,    28,    22,     0,    31,
      30,     0,     0,    42,     0,    25,     0,     3,     3,    17,
       3,     0,     0,     0,    23,     0,    35,     3,     0,     0,
       0,    34,     0,     0,    32,     0,     0,    43,     0,     0,
       0,     0,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -26,   -26,    -4,   -26,   -26,   -26,    74,   -26,   -26,   -26,
     121,   -26,   132,   -26,   -26,   -26,   173,   -26,   -26,   -26,
     -26,    25,   -26,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,    22,    86,   135,    23,    24,   177,
      78,    25,    26,   170,    27,    28,    37,    29,    48,    30,
      31,    38,    39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,     1,    33,     1,    35,     1,     7,    47,    35,     1,
      41,    42,     8,     1,    35,     1,    35,     1,   168,   169,
      53,    32,    34,    43,    44,    51,    45,    50,    52,    54,
      90,    55,    82,    56,    57,     2,    58,     2,    59,     2,
      46,    49,     3,     2,    36,    63,   104,     2,    36,     2,
      60,     2,    88,   180,    77,    87,    80,    83,    64,    65,
      66,    67,    68,    91,    61,   109,    79,    81,    62,    85,
      84,    69,    70,    71,    72,    73,    74,    75,   110,    89,
     111,   112,   107,   108,   113,   114,   115,   129,   138,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   130,   140,   155,   141,   133,   134,   142,   143,     7,
       7,   136,   154,   144,   139,   145,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   146,
     147,   148,   131,    79,   149,   150,   136,   137,   161,   151,
     163,     9,   152,   153,    10,    11,    12,   156,   157,   158,
      13,   159,    14,    15,   165,   171,    16,    17,    18,     7,
     167,   172,   178,   173,   162,    19,   174,    20,   175,   176,
     183,    21,   181,   184,   185,   179,   186,     7,     7,   164,
       7,   166,   182,   191,   187,   188,   190,     7,    63,   189,
     192,   193,   194,   195,    15,   197,   196,   199,   198,   200,
     201,    64,    65,    66,    67,    68,   202,   203,    63,   105,
     160,    76,   106,     0,    69,    70,    71,    72,    73,    74,
      75,    64,    65,    66,    67,    68,     0,     0,     0,   132,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75
};

static const yytype_int16 yycheck[] =
{
       0,     4,     6,     4,     3,     4,     6,     6,     3,     4,
      10,    11,     4,     4,     3,     4,     3,     4,    43,    44,
      20,     0,    38,    43,    43,    37,    14,     4,    43,    43,
      35,    44,    10,    44,    44,    38,    44,    38,    44,    38,
      15,    16,    43,    38,    43,    10,    11,    38,    43,    38,
      44,    38,    52,    44,    43,    22,    43,    43,    23,    24,
      25,    26,    27,    63,    44,    18,    41,    42,    44,    43,
      45,    36,    37,    38,    39,    40,    41,    42,    17,    43,
      43,     4,    82,    83,    43,    10,    43,    37,    29,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    45,    34,    46,    44,   109,   110,    44,    44,   109,
     110,   111,    12,    44,   114,    44,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    44,
      44,    44,   107,   108,    44,    44,   136,   112,   138,    44,
     140,     4,    44,    44,     7,     8,     9,    44,    44,    44,
      13,    44,    15,    16,    36,   159,    19,    20,    21,   159,
      44,    44,    17,    44,   139,    28,    46,    30,    44,    43,
      32,    34,   172,   177,   178,    44,   180,   177,   178,   154,
     180,   156,    33,   187,    44,    44,    44,   187,    10,    46,
      44,    33,    44,    46,    16,   195,    45,    38,    46,   199,
     200,    23,    24,    25,    26,    27,    44,    44,    10,    31,
     136,    38,    80,    -1,    36,    37,    38,    39,    40,    41,
      42,    23,    24,    25,    26,    27,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    38,    43,    48,    49,    50,    70,     4,     4,
       7,     8,     9,    13,    15,    16,    19,    20,    21,    28,
      30,    34,    51,    54,    55,    58,    59,    61,    62,    64,
      66,    67,     0,    49,    38,     3,    43,    63,    68,    69,
      70,    70,    70,    43,    43,    14,    68,     6,    65,    68,
       4,    37,    43,    70,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    10,    23,    24,    25,    26,    27,    36,
      37,    38,    39,    40,    41,    42,    63,    43,    57,    68,
      43,    68,    10,    43,    68,    43,    52,    22,    70,    43,
      35,    70,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    11,    31,    59,    70,    70,    18,
      17,    43,     4,    43,    10,    43,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    37,
      45,    68,    57,    49,    49,    53,    70,    68,    29,    70,
      34,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    12,    46,    44,    44,    44,    44,
      53,    70,    68,    70,    68,    36,    68,    44,    43,    44,
      60,    49,    44,    44,    46,    44,    43,    56,    17,    44,
      44,    70,    33,    32,    49,    49,    49,    44,    44,    46,
      44,    49,    44,    33,    44,    46,    45,    70,    46,    38,
      70,    70,    44,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    52,    51,    53,    53,
      54,    55,    56,    55,    57,    57,    58,    58,    58,    58,
      59,    60,    60,    61,    61,    61,    62,    63,    63,    64,
      65,    65,    66,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     3,     2,     3,     3,
       2,     3,     3,     3,     3,     1,     0,     8,     0,     2,
       5,     3,     0,     9,     1,     6,     3,     4,     7,    18,
       7,     1,     5,     5,    10,     9,     2,     0,     2,     2,
       1,     1,     7,    12,     1,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     1,     1,     5,
       1,     3
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
  case 2: /* axioma: instrucciones  */
#line 85 "lispToForth/tradForth.y"
                                                  {
                                                    writeFile(yyvsp[0].trad); 
                                                    destroySymbolTable(tabla);
                                                  }
#line 1404 "y.tab.c"
    break;

  case 3: /* instrucciones: %empty  */
#line 91 "lispToForth/tradForth.y"
                                                  { yyval.trad = ""; }
#line 1410 "y.tab.c"
    break;

  case 4: /* instrucciones: sentencia instrucciones  */
#line 92 "lispToForth/tradForth.y"
                                                  { sprintf(temp, "%s%s", yyvsp[-1].trad, yyvsp[0].trad); 
                                                    yyval.trad = gen_code(temp);                 
                                                    }
#line 1418 "y.tab.c"
    break;

  case 5: /* sentencia: '(' definicion ')'  */
#line 98 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1424 "y.tab.c"
    break;

  case 6: /* sentencia: '(' asignacion ')'  */
#line 99 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1430 "y.tab.c"
    break;

  case 7: /* sentencia: '(' condicion  */
#line 100 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[0]; }
#line 1436 "y.tab.c"
    break;

  case 8: /* sentencia: '(' bucle ')'  */
#line 101 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1442 "y.tab.c"
    break;

  case 9: /* sentencia: '(' llamada ')'  */
#line 102 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1448 "y.tab.c"
    break;

  case 10: /* sentencia: '(' deffuncion  */
#line 103 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[0]; }
#line 1454 "y.tab.c"
    break;

  case 11: /* sentencia: '(' print ')'  */
#line 104 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1460 "y.tab.c"
    break;

  case 12: /* sentencia: '(' returnfrom ')'  */
#line 105 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1466 "y.tab.c"
    break;

  case 13: /* sentencia: '(' incf ')'  */
#line 106 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1472 "y.tab.c"
    break;

  case 14: /* sentencia: '(' invertir ')'  */
#line 107 "lispToForth/tradForth.y"
                                                { yyval=yyvsp[-1]; }
#line 1478 "y.tab.c"
    break;

  case 15: /* sentencia: variable  */
#line 108 "lispToForth/tradForth.y"
                                                { sprintf(temp, "%s\n", yyvsp[0].code); 
                                                    yyval.trad = gen_code(temp); 
                                                }
#line 1486 "y.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 114 "lispToForth/tradForth.y"
                                                { act_function = yyvsp[0].code; }
#line 1492 "y.tab.c"
    break;

  case 17: /* deffuncion: DEFUN IDENTIF $@1 '(' argumentosfun ')' instrucciones ')'  */
#line 116 "lispToForth/tradForth.y"
                                                {                              
                                                sprintf(temp, ": %s ( %s -- n )\n%s;\n", yyvsp[-6].code, yyvsp[-3].trad ,yyvsp[-1].trad);
                                                yyval.trad = gen_code(temp);
                                                act_function = "";
                                                }
#line 1502 "y.tab.c"
    break;

  case 18: /* argumentosfun: %empty  */
#line 124 "lispToForth/tradForth.y"
                                                { yyval.trad =" "; }
#line 1508 "y.tab.c"
    break;

  case 19: /* argumentosfun: variable argumentosfun  */
#line 125 "lispToForth/tradForth.y"
                                                { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].trad); 
                                                yyval.trad = gen_code(temp); 
                                                }
#line 1516 "y.tab.c"
    break;

  case 20: /* returnfrom: RETURN '-' FROM IDENTIF expresion  */
#line 132 "lispToForth/tradForth.y"
                                               { 
                                                sprintf(temp, "%s\nEXIT\n", yyvsp[0].trad);
                                                yyval.trad = gen_code(temp);
                                                }
#line 1525 "y.tab.c"
    break;

  case 21: /* definicion: DEFVAR variable restodef  */
#line 140 "lispToForth/tradForth.y"
                                                        { 
                                                        if (tabla == NULL){
                                                            tabla = initSymbolTable();
                                                        }
                                                        if (yyvsp[0].type == 0) { // INT CASE
                                                        insertSymbol(tabla, yyvsp[-1].code, "global", 0, 0);
                                                        sprintf(temp, "VARIABLE %s\n%d %s !\n", yyvsp[-1].code, yyvsp[0].value, yyvsp[-1].code);
                                                        yyval.trad = gen_code(temp);      

                                                        }
                                                        else { // VECTOR CASE
                                                        insertSymbol(tabla, yyvsp[-1].code, "global", yyvsp[0].value, 0);
                                                        sprintf(temp, "CREATE %s %d CELLS ALLOT\n: init-vector ( -- )\n%s %d 0 DO\n0 over I CELLS + !\nLOOP\n DROP ;\ninit-vector\n", yyvsp[-1].code, yyvsp[0].value, yyvsp[-1].code, yyvsp[0].value);
                                                        yyval.trad = gen_code(temp);
                                                        }
                                                        
                                                    }
#line 1547 "y.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 158 "lispToForth/tradForth.y"
                                                    { if (yyvsp[-2].type == 0) { // INT CASE
                                                            insertSymbol(tabla, yyvsp[-3].code, "local", 0, 0);
                                                        }
                                                        else { // VECTOR CASE
                                                            insertSymbol(tabla, yyvsp[-3].code, "local", yyvsp[-2].value, 0);
                                                        }
                                                    }
#line 1559 "y.tab.c"
    break;

  case 23: /* definicion: LET '(' '(' variable restodef ')' ')' $@2 instrucciones  */
#line 165 "lispToForth/tradForth.y"
                                                    {   
                                                        if (yyvsp[-4].type == 0) { // INT CASE
                                                        sprintf(temp, "%d LOCALS| %s |\n%s", yyvsp[-4].value, yyvsp[-5].code,  yyvsp[0].trad);
                                                        yyval.trad = gen_code(temp);
                                                        
                                                        }
                                                        else { // VECTOR CASE
                                                        sprintf(temp, "CREATE %s %d ALLOT\n: inicializar-%s ( -- )\n\t%s %d CELLS 0 DO\n i %s +!\nLOOP ;\ninicializar-%s\n%s", 
                                                        yyvsp[-5].code, yyvsp[-4].value, yyvsp[-5].code, yyvsp[-5].code, yyvsp[-4].value, yyvsp[-5].code, yyvsp[-5].code, yyvsp[0].trad);
                                                        yyval.trad = gen_code(temp);
                                                        }

                                                    }
#line 1577 "y.tab.c"
    break;

  case 24: /* restodef: expresion  */
#line 180 "lispToForth/tradForth.y"
                                                     { yyval.type = 0; 
                                                       yyval.value = yyvsp[0].value; 
                                                     }
#line 1585 "y.tab.c"
    break;

  case 25: /* restodef: '(' MAKE '-' ARRAY expresion ')'  */
#line 183 "lispToForth/tradForth.y"
                                                     { yyval.type = 1; 
                                                      yyval.value = yyvsp[-1].value; 
                                                     }
#line 1593 "y.tab.c"
    break;

  case 26: /* asignacion: SETQ variable expresion  */
#line 189 "lispToForth/tradForth.y"
                                                                { 
                                                                sym = searchSymbol(tabla, yyvsp[-1].code);
                                                                if (sym == NULL) {
                                                                    yyerror("Variable no declarada");
                                                                } else if (strcmp(sym->type, "global")== 0){
                                                                    sprintf(temp, "%s %s !\n", yyvsp[0].trad, yyvsp[-1].code); 

                                                                } else if (strcmp(sym->type, "local")== 0){
                                                                    sprintf(temp, "%s to %s\n", yyvsp[0].trad, yyvsp[-1].code);

                                                                }

                                                                yyval.trad = gen_code(temp);
                                                                }
#line 1612 "y.tab.c"
    break;

  case 27: /* asignacion: SETQ variable '(' condicion  */
#line 203 "lispToForth/tradForth.y"
                                                                { 
                                                                sprintf(temp, "%s %s !\n", yyvsp[0].trad, yyvsp[-2].code); 
                                                                yyval.trad = gen_code(temp);
                                                                }
#line 1621 "y.tab.c"
    break;

  case 28: /* asignacion: SETF '(' AREF variable expresion ')' expresion  */
#line 207 "lispToForth/tradForth.y"
                                                                { 
                                                                sprintf(temp, "%s %s CELLS %s + !\n", yyvsp[0].trad, yyvsp[-2].trad, yyvsp[-3].code);
                                                                yyval.trad = gen_code(temp);
                                                                }
#line 1630 "y.tab.c"
    break;

  case 29: /* asignacion: SETQ variable '(' REDUCE '#' '\'' '+' '(' MAP '\'' LIST '#' '\'' '*' variable variable ')' ')'  */
#line 213 "lispToForth/tradForth.y"
                                                                 { 
                                                                sym = searchSymbol(tabla, yyvsp[-16].code);
                                                                if (sym == NULL) {
                                                                    yyerror("Variable no declarada");
                                                                } else if (strcmp(sym->type, "global")== 0){
                                                                    sym = searchSymbol(tabla, yyvsp[-3].code);
                                                                    if (sym == NULL) {
                                                                        yyerror("Variable no declarada");
                                                                    } else{
                                                                        sprintf(temp,"%d 0 DO\nI CELLS %s + @\nI CELLS %s + @\n*\n %s @ + %s !\nLOOP\n", 
                                                                        sym -> size_array, yyvsp[-3].code, yyvsp[-2].code, yyvsp[-16].code, yyvsp[-16].code);
                                                                    }
                                                    
                                                                } else if (strcmp(sym->type, "local")== 0){
                                                                    sym = searchSymbol(tabla, yyvsp[-3].code);
                                                                    if (sym == NULL) {
                                                                        yyerror("Variable no declarada");
                                                                    } else{
                                                                        sprintf(temp,"%d 0 DO\nI CELLS %s + @\nI CELLS %s + @\n*\n %s + to %s\nLOOP\n", 
                                                                        sym -> size_array, yyvsp[-3].code, yyvsp[-2].code, yyvsp[-16].code, yyvsp[-16].code);
                                                                    }
                                                                }
                                                                yyval.trad = gen_code(temp);
                                                                }
#line 1659 "y.tab.c"
    break;

  case 30: /* condicion: IF expresion '(' PROGN instrucciones ')' restoif  */
#line 241 "lispToForth/tradForth.y"
                                                      { 
                                                        sprintf(temp, "%s IF\n%s%sTHEN\n", yyvsp[-5].trad, yyvsp[-2].trad, yyvsp[0].trad);
                                                        yyval.trad = gen_code(temp);
                                                    }
#line 1668 "y.tab.c"
    break;

  case 31: /* restoif: ')'  */
#line 247 "lispToForth/tradForth.y"
                                                    { yyval.trad=""; }
#line 1674 "y.tab.c"
    break;

  case 32: /* restoif: '(' PROGN instrucciones ')' ')'  */
#line 248 "lispToForth/tradForth.y"
                                                    {  
                                                    sprintf(temp, "ELSE\n%s", yyvsp[-2].trad);
                                                    yyval.trad = gen_code(temp);
                                                    }
#line 1683 "y.tab.c"
    break;

  case 33: /* bucle: LOOP WHILE expresion DO instrucciones  */
#line 255 "lispToForth/tradForth.y"
                                                  { 
                                                        sprintf(temp, "BEGIN\n%s WHILE\n%sREPEAT\n", yyvsp[-2].trad, yyvsp[0].trad);   
                                                        yyval.trad = gen_code(temp); 
                                                        }
#line 1692 "y.tab.c"
    break;

  case 34: /* bucle: DOTIMES '(' variable '(' LENGTH variable ')' variable ')' instrucciones  */
#line 260 "lispToForth/tradForth.y"
                                                  { 
                                                    sym = searchSymbol(tabla, yyvsp[-4].code);
                                                    long_variable = sym -> size_array;
                                                    sprintf(temp, "%d 0 DO\n%sLOOP\n", long_variable, yyvsp[0].trad);
                                                    yyval.trad = gen_code(temp); 

                                                  }
#line 1704 "y.tab.c"
    break;

  case 35: /* bucle: DOTIMES '(' variable '(' LENGTH variable ')' ')' instrucciones  */
#line 268 "lispToForth/tradForth.y"
                                                  { 
                                                    sym = searchSymbol(tabla, yyvsp[-3].code);
                                                    long_variable = sym -> size_array;
                                                    sprintf(temp, "%d 0 DO\n%sLOOP\n", long_variable, yyvsp[0].trad);
                                                    yyval.trad = gen_code(temp); 

                                                  }
#line 1716 "y.tab.c"
    break;

  case 36: /* llamada: IDENTIF argumentos  */
#line 279 "lispToForth/tradForth.y"
                                             { 
                                                 sprintf(temp, "%s%s\n", yyvsp[0].trad, yyvsp[-1].code);
                                                 yyval.trad = gen_code(temp);
                                                 }
#line 1725 "y.tab.c"
    break;

  case 37: /* argumentos: %empty  */
#line 286 "lispToForth/tradForth.y"
                                                 { yyval.trad = ""; }
#line 1731 "y.tab.c"
    break;

  case 38: /* argumentos: expresion argumentos  */
#line 287 "lispToForth/tradForth.y"
                                                 { 
                                                    if (strcmp(yyvsp[-1].code, "variable") == 0){
                                                        sprintf(temp, "%s @\n%s", yyvsp[-1].trad, yyvsp[0].trad); 
                                                    }
                                                    else{
                                                        sprintf(temp, "%s\n%s", yyvsp[-1].trad, yyvsp[0].trad); 
                                                    }
                                                    yyval.trad = gen_code(temp); 
                                                }
#line 1745 "y.tab.c"
    break;

  case 39: /* print: PRINT restoprint  */
#line 299 "lispToForth/tradForth.y"
                                               { yyval = yyvsp[0]; }
#line 1751 "y.tab.c"
    break;

  case 40: /* restoprint: STRING  */
#line 302 "lispToForth/tradForth.y"
                                               {
                                                sprintf(temp, "S\" %s\" TYPE\n", yyvsp[0].code);
                                                yyval.trad = gen_code(temp);
                                                }
#line 1760 "y.tab.c"
    break;

  case 41: /* restoprint: expresion  */
#line 306 "lispToForth/tradForth.y"
                                                { 
                                                if (strcmp(yyvsp[0].code, "variable") == 0){
                                                    sym = searchSymbol(tabla, yyvsp[0].trad);
                                                    if (sym == NULL) {
                                                        yyerror("Variable no declarada");
                                                        sprintf(temp, "%s @ .\n", yyvsp[0].trad);
                                                    } else if (strcmp(sym->type, "global")== 0){
                                                        sprintf(temp, "%s @ .\n", yyvsp[0].trad);
                                                    } else if (strcmp(sym->type, "local")== 0){
                                                        sprintf(temp, "%s .\n", yyvsp[0].trad);
                                                    }

                                                }
                                                else{
                                                    sprintf(temp, "%s .\n", yyvsp[0].trad);
                                                }
                                                yyval.trad = gen_code(temp);
                                                }
#line 1783 "y.tab.c"
    break;

  case 42: /* incf: INCF variable '(' AREF variable expresion ')'  */
#line 327 "lispToForth/tradForth.y"
                                                     { 
                                                    sym = searchSymbol(tabla, yyvsp[-5].code);
                                                    if (sym == NULL) {
                                                        yyerror("Variable no declarada");
                                                    } else if (strcmp(sym->type, "global")== 0){
                                                        sprintf(temp, "i CELLS %s + @\n%s + %s !\n", yyvsp[-2].code, yyvsp[-5].code, yyvsp[-5].code );
                                                    } else if (strcmp(sym->type, "local")== 0){
                                                        sprintf(temp, "i CELLS %s + @\n%s + to %s\n", yyvsp[-2].code, yyvsp[-5].code, yyvsp[-5].code );
                                                    }
                                                    yyval.trad = gen_code(temp); // TODO: REVISAR
                                                    }
#line 1799 "y.tab.c"
    break;

  case 43: /* invertir: COERCE '(' REVERSE '(' COERCE variable '\'' LIST ')' ')' '\'' variable  */
#line 342 "lispToForth/tradForth.y"
                                                                                 { 
                                                    sym = searchSymbol(tabla, yyvsp[-6].code);
                                                    if (sym == NULL) {
                                                        yyerror("Variable no declarada");
                                                        sprintf(temp, "\n");
                                                    } else {
                                                        sprintf(temp,"%d 2 / 0 DO\nI CELLS %s + @\n %d 1 - I - CELLS %s + @\nI CELLS %s + !\n%d 1 - I - CELLS %s + !\nLOOP\n",
                                                        sym -> size_array, yyvsp[-6].code, sym -> size_array, yyvsp[-6].code, yyvsp[-6].code, sym -> size_array, yyvsp[-6].code);
                                                    }
                                                    yyval.trad = gen_code(temp);
                                                    }
#line 1815 "y.tab.c"
    break;

  case 44: /* expresion: operando  */
#line 358 "lispToForth/tradForth.y"
                                                 { yyval=yyvsp[0]; }
#line 1821 "y.tab.c"
    break;

  case 45: /* expresion: '(' '+' expresion expresion ')'  */
#line 359 "lispToForth/tradForth.y"
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
#line 1841 "y.tab.c"
    break;

  case 46: /* expresion: '(' '-' expresion expresion ')'  */
#line 374 "lispToForth/tradForth.y"
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
#line 1860 "y.tab.c"
    break;

  case 47: /* expresion: '(' '*' expresion expresion ')'  */
#line 388 "lispToForth/tradForth.y"
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
#line 1879 "y.tab.c"
    break;

  case 48: /* expresion: '(' '/' expresion expresion ')'  */
#line 402 "lispToForth/tradForth.y"
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
#line 1898 "y.tab.c"
    break;

  case 49: /* expresion: '(' AND expresion expresion ')'  */
#line 416 "lispToForth/tradForth.y"
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
#line 1917 "y.tab.c"
    break;

  case 50: /* expresion: '(' OR expresion expresion ')'  */
#line 430 "lispToForth/tradForth.y"
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
#line 1937 "y.tab.c"
    break;

  case 51: /* expresion: '(' '=' expresion expresion ')'  */
#line 445 "lispToForth/tradForth.y"
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
#line 1956 "y.tab.c"
    break;

  case 52: /* expresion: '(' '<' expresion expresion ')'  */
#line 459 "lispToForth/tradForth.y"
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
#line 1976 "y.tab.c"
    break;

  case 53: /* expresion: '(' '>' expresion expresion ')'  */
#line 474 "lispToForth/tradForth.y"
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
#line 1995 "y.tab.c"
    break;

  case 54: /* expresion: '(' LEQ expresion expresion ')'  */
#line 488 "lispToForth/tradForth.y"
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
#line 2014 "y.tab.c"
    break;

  case 55: /* expresion: '(' GEQ expresion expresion ')'  */
#line 502 "lispToForth/tradForth.y"
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
#line 2033 "y.tab.c"
    break;

  case 56: /* expresion: '(' NEQ expresion expresion ')'  */
#line 516 "lispToForth/tradForth.y"
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
#line 2052 "y.tab.c"
    break;

  case 57: /* operando: NUMBER  */
#line 532 "lispToForth/tradForth.y"
                                                { sprintf(temp, "%d", yyvsp[0].value);
                                                yyval.trad = gen_code(temp);
                                                yyval.value = yyvsp[0].value; 
                                                yyval.code = "number";
                                                }
#line 2062 "y.tab.c"
    break;

  case 58: /* operando: variable  */
#line 537 "lispToForth/tradForth.y"
                                                { 

                                                sprintf(temp, "%s", yyvsp[0].code);
                                                yyval.trad = gen_code(temp);
                                                yyval.code = "variable";
                                                }
#line 2073 "y.tab.c"
    break;

  case 59: /* operando: '(' AREF variable expresion ')'  */
#line 543 "lispToForth/tradForth.y"
                                                  { 
                                                sprintf(temp, "%s CELLS %s +", yyvsp[-1].trad, yyvsp[-2].code);
                                                yyval.trad = gen_code(temp);
                                                yyval.code = "variable";
                                                }
#line 2083 "y.tab.c"
    break;

  case 60: /* variable: IDENTIF  */
#line 550 "lispToForth/tradForth.y"
                                                { yyval.code = yyvsp[0].code; }
#line 2089 "y.tab.c"
    break;

  case 61: /* variable: '*' IDENTIF '*'  */
#line 551 "lispToForth/tradForth.y"
                                                { yyval.code = yyvsp[-1].code; }
#line 2095 "y.tab.c"
    break;


#line 2099 "y.tab.c"

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

#line 554 "lispToForth/tradForth.y"


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
    {"and", AND}, {"or", OR}, {"<=", LEQ}, {">=", GEQ}, {"/=", NEQ}, {"let", LET}, {"print", PRINT}, 
    {"dotimes", DOTIMES}, {"coerce", COERCE}, {"reverse", REVERSE},
    {"length", LENGTH}, {"incf", INCF}, {"reduce",REDUCE}, {"map", MAP}, {"list", LIST},
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
    char expandable_ops [] = "!<=>|%/&+-*#\'" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;


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
