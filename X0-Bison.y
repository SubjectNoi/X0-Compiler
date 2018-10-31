%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

#define bool 			int
#define true 			1
#define false 			0

#define SYM_TABLE 		200				// Max Capicity of symbol table
#define ID_NAME_LEN		20				// Max length of ident
#define ADDRESS_MAX		8192			// Upper bound of the address
#define DEPTH_MAX		10				// Max depth of declaration
#define CODE_MAX		1000			// Max Virtual Machine code amount
#define STACK_SIZE		2000			// Max Run-Time stack element amount
#define STRING_LEN		201				// Max length of const string
#define ERROR_MAG_NUM	1145141919810	// For error processing

typedef unsigned char byte;

enum object {
	constant_int,
	constant_real,
	constant_bool,
	constant_string,
	variable_int,
	variable_real,
	variable_bool,
	variable_string,
};

struct symbol_table {
	char 	name[ID_NAME_LEN];
	enum 	object kind;
	int 	addr;
	byte 	val[STRING_LEN];			// Use byte to store all kind of data, use pointer to specify them
//	void*	val;						// Using pointer to specify unlimitted length constant string @todo: in the future.
};

struct symbol_table table[SYM_TABLE];	// Store all symbol

enum fct {
	lit,	opr,	lod,
	sto,	cal,	ini,
	jmp,	jpc,
};

struct instruction {
	enum 	fct f;
	int 	lev;						// Un-used in X0
	int		opr;
};

struct instruction code[CODE_MAX];		// Store V-Machine code

int			sym_tab_tail;
int			vm_code_pointer;

FILE*		fin;
FILE*		ftable;
FILE*		fcode;
FILE*		foutput;
FILE*		fresult;
char		fname;
int 		err;
extern int	line;

void 		init();
void		enter(enum object k);
void 		gen(enum fct x, int y, int z);

%}

%union {
	char 	*ident;
	int 	number;
	char 	*text;
	char 	single_char;
	int 	flag;
	double 	realnumber;
}

%token BOOLSYM, BREAKSYM, CALLSYM, CASESYM, CHARSYM, CONSTSYM, CONTINUESYM, DOSYM, ELSESYM
%token ELSESYM, EXITSYM, FORSYM, INTSYM, IFSYM, MAINSYM, READSYM, REALSYM, REPEATSYM
%token STRINGSYM, SWITCHSYM, UNTILSYM, WHILESYM, WRITESYM, LBRACE, RBRACE, LBRACKET, RBRACKET
%token BECOMES, LSS, LEQ, GTR, GEQ, EQL, NEQ, PLUS, INCPLUS, MINUS, INCMINUS,TIMES, DEVIDE
%token LPAREN, RPAREN, MOD, SEMICOLON, XOR, AND, OR, NOT, YAJU

%token <ident> 		IDENT
%token <integer> 	INTEGER
%token <string>		STRING
%token <bool>		BOOL
%token <real>		REAL
%token <char>		CHAR

%%

program: 				MAINSYM LBRACE statement_list RBRACE 
						;
		
declaration_list:		declaration_list declaration_stat 
					  | declaration_stat 
					  | 
						;

declaration_stat:		type IDENT SEMICOLON 
					  | type IDENT LBRACKET INTEGER RBRACKET SEMICOLON
					  | CONSTSYM type IDENT BECOMES expression SEMICOLON
						;
					
type:					INTSYM 
					  | STRINGSYM 
					  | BOOLSYM 
					  | REALSYM 
					  | CHARSYM
						;
	
statement_list:			statement_list statement 
					  | statement 
					  | 
						;
						
statement:				expression_statement 
					  | if_statement 
					  | while_statement 
					  | read_statement 
					  | write_statement 
					  | compound_statement 
					  | for_statement 
					  | do_statement 
					  | declaration_stat 
					  | continue_stat 
					  | break_stat 
					  |
						;
						
continue_stat:			CONTINUESYM SEMICOLON
						;
						
break_stat:				BREAKSYM SEMICOLON
						;
						
if_statement:			IFSYM LPAREN expression RPAREN compound_statement 
					  | IFSYM LPAREN expression RPAREN compound_statement ELSESYM compound_statement 
						;
	
while_statement:		WHILESYM LPAREN expression RPAREN compound_statement
						;
	
write_statement:		WRITESYM LPAREN expression RPAREN SEMICOLON
						;
	
read_statement:			READSYM LPAREN var RPAREN SEMICOLON
						;
						
compound_statement:		LBRACE statement_list RBRACE
						;
						
for_statement:			FORSYM LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN compound_statement
						;
						
do_statement:			DOSYM compound_statement WHILESYM LPAREN expression RPAREN SEMICOLON
						;
	
var:					IDENT 
					  | IDENT LBRACKET expression RBRACKET
						;

expression_statement:	expression SEMICOLON 
					  | SEMICOLON
						;

expression:				var BECOMES expression 
					  | simple_expr
						;

simple_expr:			additive_expr 
					  | additive_expr OPR additive_expr 
					  | additive_expr SINGLEOPR 
					  | SINGLEOPR additive_expr
						;

SINGLEOPR:				INCPLUS 
					  | INCMINUS 
					  | NOT
						;

OPR:					EQL 
					  | NEQ 
					  | LSS 
					  | LEQ 
					  | GTR 
					  | GEQ 
					  | AND 
					  | OR 
					  | XOR
						;

additive_expr:			term 
					  | additive_expr PLUSMINUS term
						;

PLUSMINUS:				PLUS 
					  | MINUS
						;

term:					factor 
					  | term TIMESDEVIDE factor
						;

TIMESDEVIDE:			TIMES 
					  | DEVIDE
						;

factor:					LPAREN expression RPAREN 
					  | var 
					  | INTEGER 
					  | REAL 
					  | STRING 
					  | BOOL 
					  | CHAR
						;

%%

int main(int argc, int **argv) {
	if (argc != 2) {
		printf("Please specific ONE source code file!\n");
		return 0;
	}
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror(argv[1]);
		return 1;
	}
	redirectInput(f);
	yyparse();
}
