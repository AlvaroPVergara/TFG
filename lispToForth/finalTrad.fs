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
2 3 + 1 CELLS vector + !
5 4 CELLS vector + !
29 7 CELLS vector + !
1 0 CELLS vector + !
;
: main (   -- n )
fun1
0 LOCALS| c |
0 to c
10 0 DO
i CELLS vector + @
c + to c
LOOP
S" (" TYPE
 10 0 DO
I CELLS vector + @ .
LOOP
S" )" TYPE CR
10 2 / 0 DO
I CELLS vector + @
 10 1 - I - CELLS vector + @
I CELLS vector + !
10 1 - I - CELLS vector + !
LOOP
S" (" TYPE
 10 0 DO
I CELLS vector + @ .
LOOP
S" )" TYPE CR
10 0 DO
i CELLS vector + @ 5 + i CELLS vector + !
LOOP
10 0 DO
I CELLS vector + @
I CELLS vector + @
*
 b @ + b !
LOOP
S" (" TYPE
 10 0 DO
I CELLS vector + @ .
LOOP
S" )" TYPE CR
S" Hola mundo" TYPE CR
c
;
main
