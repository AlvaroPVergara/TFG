all:
	yacc -d baseLanguage/vectorialC.y
	gcc -Wall y.tab.c dataStructures/AST.c dataStructures/TS.c cLisp/tradC.c -o baseLanguage/vectorialC
	baseLanguage/vectorialC < test.txt
	sbcl --script cLisp/trad.lisp
	yacc -d -v lispToForth/tradForth.y
	gcc -Wall y.tab.c lispToForth/fileForth.c -o lispToForth/tradForth
	lispToForth/tradForth < cLisp/trad.lisp