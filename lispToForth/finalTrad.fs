VARIABLE a
0 a !
VARIABLE b
0 b !
CREATE vector 10 CELLS ALLOT
: init-vector ( -- )
vector 10 0 DO
0 over I CELLS + !
LOOP
 DROP ;
init-vector
: fun1 (   -- n )
5 4 CELLS vector + !
29 7 CELLS vector + !
1 0 CELLS vector + !
;
: main (   -- n )
fun1
10 0 DO
I CELLS vector + @
I CELLS vector + @
*
 a @ + a !
LOOP
a @ .
S" Hola mundo" TYPE
a
;
main
