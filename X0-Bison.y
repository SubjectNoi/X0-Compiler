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
	constant_char,
	variable_int,
	variable_real,
	variable_bool,
	variable_string,
	variable_char,
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
char		id_name[ID_NAME_LEN];
int			outter_int;
float		outter_real;
bool		outter_bool;
char		outter_char;
char		outter_string[STRING_LEN];
int			err_num;

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
%token LPAREN, RPAREN, MOD, SEMICOLON, XOR, AND, OR, NOT, YAJU, YARIMASUNESYM

%token <ident> 		IDENT
%token <integer> 	INTEGER
%token <string>		STRING
%token <bool>		BOOL
%token <real>		REAL
%token <char>		CHAR

%%

program: 				MAINSYM 
						{	gen(jmp, 0, 0);
						}
						LBRACE 
						statement_list 
						{
						
						}
						RBRACE 
						;
		
declaration_list:		declaration_list declaration_stat 
					  | declaration_stat 
					  | 
						;

declaration_stat:		type IDENT SEMICOLON 
					  | type IDENT LBRACKET INTEGER RBRACKET SEMICOLON
					  | CONSTSYM type IDENT BECOMES expression SEMICOLON {
						  	/*
						  	switch ($2) {
								case INTSYM:
									enter(constant_int);
									break;
								case STRINGSYM:
									enter(constant_string);
									break;
								case REALSYM:
									enter(constant_real);
									break;
								case CHARSYM:
									enter(constant_char);
									break;
								case BOOLSYM:
									enter(constant_bool);
									break;
							}
							*/
							return 0;
					  	}
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
						{	gen(lod, 0, 0);
							gen(sto, 0, 0);
						}
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

void init() {
	sym_tab_tail 		= 0;
	vm_code_pointer 	= 0 ;
	outter_int 			= 0;
	outter_real 		= 0.0;
	outter_char 		= 0;
	outter_bool 		= false;
	err_num				= 0;
	strcpy(outter_string, "\0");
}

int yyerror(char *s) {
	err_num++;
	printf("%s in line %d.\n", s, line);
	fprintf(foutput, "%s in line %d.\n", s, line);
	return 0;
}

void gen(enum fct x, int y, int z) {
	if (vm_code_pointer > CODE_MAX) {
		printf("Program is too long!\n");
		exit(1);
	}
	if (z > ADDRESS_MAX) {
		printf("Acquiring address out of boundn");
		exit(1);
	}
	code[vm_code_pointer].f 	= x;
	code[vm_code_pointer].lev 	= y;
	code[vm_code_pointer].opr 	= z;
	vm_code_pointer++;
}

void enter(enum object k) {
	sym_tab_tail++;
	strcpy(table[sym_tab_tail].name, id_name);
	table[sym_tab_tail].kind = k;
	switch (k) {
		case constant_int:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_int, STRING_LEN);
			break;
		case constant_real:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_real, STRING_LEN);
			break;
		case constant_string:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_int, STRING_LEN);
			break;
		case constant_char:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_char, STRING_LEN);
			break;
		case constant_bool:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_bool, STRING_LEN);
			break;
		case variable_int:
		
			break;
		case variable_real:
		
			break;
		case variable_string:
		
			break;
		case variable_char:
		
			break;
		case variable_bool:
		
			break;
	}
}

void display_sym_tab() {

}

void listall() {
	int i;
	char name[][5] = {
		{"lit"}, {"opr"}, {"lod"}, {"sto"},
		{"cal"}, {"ini"}, {"jmp"}, {"jpc"},
	};
	for (i = 0; i < vm_code_pointer; i++) {
		printf("%4d %s %4d %4d\n", i, name[code[i].f], code[i].lev, code[i].opr);
		fprintf(fcode, "%4d %s %4d %4d\n", i, name[code[i].f], code[i].lev, code[i].opr);
	}
}

int main(int argc, int **argv) {
	fcode = fopen("fcode", "w+");
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
	init();
	yyparse();
	listall();
}
