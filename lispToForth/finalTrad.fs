VARIABLE a
0 a !
VARIABLE b
0 b !
CREATE vector 10 ALLOT
: inicializar-vector ( -- )
	vector 10 CELLS 0 DO
 i vector +!
LOOP ;
inicializar-vector
: fun1 (  -- n )
1 a !
LOCALS| x |
0 x !
10 x !
;
: fun2 ( numero  -- n )
3 1 > b !
;
: main (  -- n )
LOCALS| c |
0 c !
S" Hola mundo" TYPE
c
;
main
