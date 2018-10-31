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

#ifndef YY_YY_X0_BISON_TAB_H_INCLUDED
# define YY_YY_X0_BISON_TAB_H_INCLUDED
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
    BOOLSYM = 258,
    BREAKSYM = 259,
    CALLSYM = 260,
    CASESYM = 261,
    CHARSYM = 262,
    CONSTSYM = 263,
    CONTINUESYM = 264,
    DOSYM = 265,
    ELSESYM = 266,
    EXITSYM = 267,
    FORSYM = 268,
    INTSYM = 269,
    IFSYM = 270,
    MAINSYM = 271,
    READSYM = 272,
    REALSYM = 273,
    REPEATSYM = 274,
    STRINGSYM = 275,
    SWITCHSYM = 276,
    UNTILSYM = 277,
    WHILESYM = 278,
    WRITESYM = 279,
    LBRACE = 280,
    RBRACE = 281,
    LBRACKET = 282,
    RBRACKET = 283,
    BECOMES = 284,
    LSS = 285,
    LEQ = 286,
    GTR = 287,
    GEQ = 288,
    EQL = 289,
    NEQ = 290,
    PLUS = 291,
    INCPLUS = 292,
    MINUS = 293,
    INCMINUS = 294,
    TIMES = 295,
    DEVIDE = 296,
    LPAREN = 297,
    RPAREN = 298,
    MOD = 299,
    SEMICOLON = 300,
    XOR = 301,
    AND = 302,
    OR = 303,
    NOT = 304,
    YAJU = 305,
    IDENT = 306,
    INTEGER = 307,
    STRING = 308,
    BOOL = 309,
    REAL = 310,
    CHAR = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 76 "X0-Bison.y" /* yacc.c:1909  */

	char 	*ident;
	int 	number;
	char 	*text;
	char 	single_char;
	int 	flag;
	double 	realnumber;

#line 120 "X0-Bison.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_X0_BISON_TAB_H_INCLUDED  */
