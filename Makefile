all:
	@echo "\n\n\n Ejecución del Programa\n"
	yacc -d baseLanguage/vectorialC.y
	gcc -Wall y.tab.c dataStructures/AST.c dataStructures/TS.c cLisp/tradC.c -o baseLanguage/vectorialC
	baseLanguage/vectorialC < test.txt
	@echo "\n Ejecución de Lisp\n"
	sbcl --script cLisp/trad.lisp
	@echo "\n\n\n Traducción a Forth\n"
	yacc -d -v lispToForth/tradForth.y
	gcc -Wall y.tab.c dataStructures/TS.c lispToForth/fileForth.c -o lispToForth/tradForth
	lispToForth/tradForth < cLisp/trad.lisp
	@echo "\n Ejecución de Forth\n"
	echo bye | gforth lispToForth/finalTrad.fs
	@echo "\n Fin del Programa\n"
