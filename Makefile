all:
	yacc -d vectorialC.y
	gcc -Wall y.tab.c AST.c TS.c -o vectorialC
	./vectorialC < test.txt