X0	:	X0-Lex.l X0-Bison.y
		bison -d X0-Bison.y
		flex X0-Lex.l
		cc -o $@ X0-Bison.tab.c lex.yy.c -lfl
		
