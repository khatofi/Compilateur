compilateur: y.tab.c lex.yy.c
	gcc -Wall -Wextra -o compilateur lex.yy.c y.tab.c -lfl

lex.yy.c: compilateur.l
	lex compilateur.l
	
y.tab.c: compilateur.y
	yacc -d compilateur.y
	

	

