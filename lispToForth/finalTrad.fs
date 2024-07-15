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
: fun2 (   -- n )
3 1 > b !
;
: main (   -- n )
fun1
0 LOCALS| c |
0 LOCALS| d |
5 to c
10 to d
0 to c
10 0 DO
i CELLS vector + @
c + to c
LOOP
c .
S" Hola mundo" TYPE
c
;
main
