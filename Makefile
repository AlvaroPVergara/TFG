all:
	yacc -d basicCalc.y
	gcc -Wall y.tab.c AST.c -o basicCalc
	./basicCalc < test.txt