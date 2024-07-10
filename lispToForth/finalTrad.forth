VARIABLE a
0 a !
CREATE vec1 10 ALLOT
: inicializar-vec1 ( --)
vec1 10 CELLS 0 DO
	 i vec1 + !
LOOP;
inicializar-vec1
