%{
#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "pl0Yacc.tab.h"
int line=0;
void yyerror(char *);
int yywrap(void);
%}

%%
[ \t]	{;}
[\n]	{line++;}
"begin"	{return SYM_begin;}
"call"	{return SYM_call;}
"const"	{return SYM_const;}
"do"	{return SYM_do;}
"end"	{return SYM_end;}
"if"	{return SYM_if;}
"odd"	{return SYM_odd;}
"procedure"	{return SYM_procedure;}
"read"	{return SYM_read;}
"then"	{return SYM_then;}
"var"	{return SYM_var;}
"while"	{return SYM_while;}
"write"	{return SYM_write;}
[A-Za-z]([A-Za-z]|[0-9])*	{
	yylval.ident=(char *)malloc(strlen(yytext)+1);
	strcpy(yylval.ident,yytext);
	return SYM_ident;
}
[0-9]+	{
	yylval.number=atoi(yytext);
	return SYM_number;}
":="	{return SYM_becomes;}
"<"		{return SYM_lss;}
"<="	{return SYM_leq;}
">"		{return SYM_gtr;}
">="	{return SYM_geq;}
"+"		{return SYM_plus;}
"-"		{return SYM_minus;}
"*"		{return SYM_times;}
"/"		{return	SYM_slash;}
"("		{return	SYM_lparen;}
")"		{return	SYM_rparen;}
"="		{return	SYM_eql;}
","		{return SYM_comma;}
"."		{return SYM_period;}
"#"		{return SYM_neq;}
";"		{return	SYM_semicolon;}
.		{yyerror("unknown character");}

%%

void redirectInput(FILE *input){
	yyin=input;
}

int yygetchar(void){
	int ret;
	ret=getc(yyin);
	printf("%c",ret);
	return ret;
}

int yywrap(void)
{
return 1;
}
