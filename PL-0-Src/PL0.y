%{
#include "code.h"
#include "malloc.h"

%}

%union{
char *ident;
int number;
}


%token SYM_begin,SYM_call,SYM_const
%token SYM_do,SYM_end,SYM_if
%token SYM_odd,SYM_procedure,SYM_read
%token SYM_then,SYM_var,SYM_while
%token SYM_write,SYM_ident,SYM_number
%token SYM_lss,SYM_leq,SYM_gtr
%token SYM_geq,SYM_plus,SYM_minus
%token SYM_times,SYM_slash,SYM_lparen
%token SYM_rparen,SYM_eql,SYM_comma,SYM_becomes
%token SYM_period,SYM_neq,SYM_semicolon

%token <ident> SYM_ident
%token <number> SYM_number

%%


// rules section

program:
	{lev--;}
	block SYM_period
	;

block:
	{
	lev++;
	dx=3;
	levelReg[lev].tx0=tx;
	table[tx].adr=cx;
	gen(jmp,0,1);
	if(lev>LEVMAX)
		error(32);
	}
	declareList
	{
	code[table[levelReg[lev].tx0].adr].a=cx;
	table[levelReg[lev].tx0].adr=cx;
	table[levelReg[lev].tx0].size=dx;
	levelReg[lev].cx0=cx;
	gen(ini,0,dx);
	}
	statement
	{
	gen(opr,0,0);
	printf("\n");
	
	}
	;

declareList:
	|declareList declare
	;

declare:constDeclareList
	|varDeclareList
	|SYM_procedure SYM_ident
	{
	strcpy(id,$2);
	enter(procedur);
	}
	SYM_semicolon
	{levelReg[lev].dx0=dx;}
	block
	{
	lev--;
	dx=levelReg[lev].dx0;
	}
	SYM_semicolon
	;
	
constDeclareList:SYM_const constDeclare SYM_semicolon
	;

constDeclare:SYM_ident
	{strcpy(id,$1);}
	SYM_eql SYM_number
	{
	num=$4;
	enter(constant);
	}
	|constDeclare SYM_comma SYM_ident
	{strcpy(id,$3);}
	SYM_eql SYM_number
	{
	num=$6;
	enter(constant);
	}
	;

varDeclareList:SYM_var varDeclare SYM_semicolon
	;

varDeclare:SYM_ident
	{
	strcpy(id,$1);
	enter(variable);
	}
	|varDeclare SYM_comma SYM_ident
	{
	strcpy(id,$3);
	enter(variable);
	}
	;

statement:SYM_ident
	{
	int i;
	strcpy(id,$1);
	i=position(id);
	if(i==0){
		error(0);
	}else{
		if(table[i].kind!=variable){
			error(12);
			i=0;
			}
		}
		$<number>$=i;
	}
	SYM_becomes expression
	{
	int i;
	if($<number>2!=0){
		i=$<number>2;
		gen(sto,lev-table[i].level,table[i].adr);
		}
	}
	|SYM_if condition
	{
	$<number>$=cx;
	gen(jpc,0,0);
	}
	SYM_then statement
	{code[$<number>3].a=cx;}
	|SYM_while
	{cx1=cx;}
	condition
	{
	cx2=cx;
	gen(jpc,0,0);
	}
	SYM_do statement
	{
	gen(jmp,0,cx1);
	code[cx2].a=cx;
	}
	|SYM_call SYM_ident
	{
	int i;
	strcpy(id,$2);
	i=position(id);
	if(i==0)
		error(11);
	else{
		if(table[i].kind==procedur)
			gen(cal,lev-table[i].level,table[i].adr);
		else
			error(15);
		}
	}
	|SYM_read SYM_lparen readIdentList SYM_rparen
	|SYM_write SYM_lparen writeExprList SYM_rparen
		{gen(opr,0,15);}
	|SYM_begin statementList SYM_end
	;

readIdentList:SYM_ident
	{
	int i;
	strcpy(id,$1);
	i=position(id);
	if(i==0)
		error(35);
	else{
		gen(opr,0,16);
		gen(sto,lev-table[i].level,table[i].adr);
	}
	}
	|readIdentList SYM_comma SYM_ident
	{
	int i;
	strcpy(id,$3);
	i=position(id);
	if(i==0)
		error(35);
	else{
		gen(opr,0,16);
		gen(sto,lev-table[i].level,table[i].adr);
	}
	}
	;

writeExprList:expression
	{gen(opr,0,14);}
	|writeExprList SYM_comma expression
	{gen(opr,0,14);}
	;

statementList:statement
	|statementList SYM_semicolon statement
	;

expression:term
	|SYM_plus term
	|SYM_minus term
		{gen(opr,0,1);}
	|expression SYM_plus term
		{gen(opr,0,2);}
	|expression SYM_minus term
		{gen(opr,0,3);}
	;

condition:SYM_odd expression
	{gen(opr,0,6);}
	|expression SYM_eql expression
	{gen(opr,0,8);}
	|expression SYM_neq expression
	{gen(opr,0,9);}
	|expression SYM_lss expression
	{gen(opr,0,10);}
	|expression SYM_geq expression
	{gen(opr,0,11);}
	|expression SYM_gtr expression
	{gen(opr,0,12);}
	|expression SYM_leq expression
	{gen(opr,0,13);}
	;

term:factor
	|term SYM_times factor
		{gen(opr,0,4);}
	|term SYM_slash factor
		{gen(opr,0,5);}
	;

factor:SYM_ident
	{
	int i;
	strcpy(id,$1);
	i=position(id);
	if(i==0)
		error(11);
	else
		switch(table[i].kind){
			case constant:
				gen(lit,0,table[i].val);
				break;
			case variable:
				gen(lod,lev-table[i].level,table[i].adr);
				break;
			case procedur:
				error(21);
				break;
			}
	}
	|SYM_number
	{
	int num;
	num=$1;
	if(num>AMAX){
		error(31);
		num=0;
		}
	gen(lit,0,num);
	}
	|SYM_lparen expression SYM_rparen
	;


%%

/////////////////////////////////////////////////////////////////////////////
// programs section
yyerror(char *s){
	err++;
	printf("%s in line %d\n",s,line);
	fprintf(fa1,"%s in line %d\n",s,line);
}
void main(void)
{
	if((fa1=fopen("c:\\fa1.txt","w"))==NULL){
		printf("Cann't open file!\n");
		exit(0);
		}
	
	printf("Input file?\n");
	fprintf(fa1,"Input file?\n");
	scanf("%s",fname);
	fprintf(fa1,"%s",fname);
	if((fin=fopen(fname,"r"))==NULL){
		printf("Cann't open file according to given filename\n");
		exit(0);
	}
	redirectInput(fin);
	printf("List object code?[y/n]");
	scanf("%s",fname);
	fprintf(fa1,"\nList object code?\n");
	if(fname[0]=='y')
		listswitch=true;
	else
		listswitch=false;
	err=0;
	cx=0;
	if((fa=fopen("c:\\fa.txt","w"))==NULL){
		printf("Cann't open fa.txt file!\n");
		exit(0);
	}
	if((fa2=fopen("c:\\fa2.txt","w"))==NULL){
		printf("Cann't open fa2.txt file!\n");
		exit(0);
	}
	yyparse();
	fclose(fa);
	fclose(fa1);
	if(err==0)
		{
		listcode();
		interpret();
		}
	else
		printf("%d errors in PL/0 program\n",err);
	fclose(fin);
	getchar();
	return;
}




