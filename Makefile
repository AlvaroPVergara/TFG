all:
	yacc -d basicCalc.y
	gcc -Wall y.tab.c AST.c -o basicCalc -ll
	./basicCalc < test.txt