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
    RR = 275,
    RL = 276,
    STRINGSYM = 277,
    SWITCHSYM = 278,
    UNTILSYM = 279,
    WHILESYM = 280,
    WRITESYM = 281,
    LBRACE = 282,
    RBRACE = 283,
    LBRACKET = 284,
    RBRACKET = 285,
    BECOMES = 286,
    COMMA = 287,
    LSS = 288,
    LEQ = 289,
    GTR = 290,
    GEQ = 291,
    EQL = 292,
    NEQ = 293,
    PLUS = 294,
    INCPLUS = 295,
    MINUS = 296,
    INCMINUS = 297,
    TIMES = 298,
    DEVIDE = 299,
    LPAREN = 300,
    RPAREN = 301,
    MOD = 302,
    SEMICOLON = 303,
    XOR = 304,
    AND = 305,
    OR = 306,
    NOT = 307,
    YAJU = 308,
    YARIMASUNESYM = 309,
    KIBONOHANASYM = 310,
    IDENT = 311,
    INTEGER = 312,
    STRING = 313,
    CHAR = 314,
    BOOL = 315,
    REAL = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 160 "X0-Bison.y" /* yacc.c:1909  */

	char 	*ident;
	int 	number;
	char 	*text;
	char 	single_char;
	int 	flag;
	double 	realnumber;

#line 125 "X0-Bison.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_X0_BISON_TAB_H_INCLUDED  */
