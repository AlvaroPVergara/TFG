/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    LIST = 288                     /* LIST  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
