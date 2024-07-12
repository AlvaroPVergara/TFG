VARIABLE a
0 a !
CREATE vec1 10 ALLOT
: inicializar-vec1 ( -- )
	vec1 10 CELLS 0 DO
 i vec1 +!
LOOP;
inicializar-vec1
: fun1 (b vec  -- n )
b @ 3 + b !
;
: main ( -- n )
a @
vec1 @
fun1
3
EXIT
BEGIN
a @ 5 < WHILE
a @ 1 + a !
REPEAT
;
main
