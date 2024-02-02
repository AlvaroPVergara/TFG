all:
	yacc -d basicCalc.y
	gcc -Wall y.tab.c AST.c TS.c -o basicCalc
	./basicCalc < test.txt