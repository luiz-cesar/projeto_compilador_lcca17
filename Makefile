$DEPURA=1

compilador: lex.yy.c y.tab.c compilador.o stack.o compilador.h stack.h
	gcc lex.yy.c compilador.tab.c compilador.o stack.o -o compilador -ll -ly -lc

lex.yy.c: compilador.l compilador.h
	flex compilador.l

y.tab.c: compilador.y compilador.h
	bison compilador.y -d -v

compilador.o : compilador.h compiladorF.c
	gcc -c compiladorF.c -o compilador.o

stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o

clean :
	rm -f compilador.o stack.o compilador compilador.tab.* lex.yy.c
