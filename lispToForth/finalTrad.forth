VARIABLE a
0 a !
CREATE vec1 10 ALLOT
: inicializar-vec1 ( -- )
	vec1 10 CELLS 0 DO
 i vec1 +!
LOOP;
inicializar-vec1
: main ( -- )
CREATE vector 3 ALLOT
: inicializar-vector ( -- )
	vector 3 CELLS 0 DO
 i vector +!
LOOP;
inicializar-vector
VARIABLE b
0 b !
1 b !
b 3 CELLS vec1 + !
a;
main