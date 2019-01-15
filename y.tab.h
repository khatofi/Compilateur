/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    Pragma = 258,
    MPC = 259,
    Pourcent = 260,
    Precision = 261,
    Esp_Tab = 262,
    entier = 263,
    flottant = 264,
    Rounding = 265,
    Arg_Rounding = 266,
    variable = 267,
    type = 268,
    if_token = 269,
    elseif_token = 270,
    else_token = 271,
    while_token = 272,
    for_token = 273,
    comparateur = 274,
    all = 275
  };
#endif
/* Tokens.  */
#define Pragma 258
#define MPC 259
#define Pourcent 260
#define Precision 261
#define Esp_Tab 262
#define entier 263
#define flottant 264
#define Rounding 265
#define Arg_Rounding 266
#define variable 267
#define type 268
#define if_token 269
#define elseif_token 270
#define else_token 271
#define while_token 272
#define for_token 273
#define comparateur 274
#define all 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 94 "compilateur.y" /* yacc.c:1909  */

	struct {
		int num;
		float flt;
		char * yylstr;
		char* yylstr2;
	} type_y;

#line 103 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
