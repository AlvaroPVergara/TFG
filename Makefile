all:
	yacc -d baseLanguage/vectorialC.y
	gcc -Wall y.tab.c dataStructures/AST.c dataStructures/TS.c cLisp/tradC.c -o baseLanguage/vectorialC
	baseLanguage/vectorialC < test.txt