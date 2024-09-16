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
: fun1 ( -- n )
2 3 + 1 CELLS vector + !
5 4 CELLS vector + !
10 7 CELLS vector + !
1 0 CELLS vector + !
a @ 9 CELLS vector + !
;
: operacionesyestructuras ( val1_ val2_ -- n )
LOCALS| val2 val1 |
val1 val2 > IF
S" El primer valor es mayor " TYPE CR
ELSE
S" El segundo valor es mayor " TYPE CR
THEN
val1 val1 val2 * 4 2 - / - a !
a @ . CR
BEGIN
a @ 0 <= WHILE
a @ 3 + a !
a @ . CR
REPEAT
a
;
: main ( -- n )
2
4
operacionesyestructuras
10
5
operacionesyestructuras
fun1
S" VALORES DEL VECTOR " TYPE CR
S" (" TYPE
 10 0 DO
I CELLS vector + @ .
LOOP
S" )" TYPE CR
S" SUMAR ELEMENTOS " TYPE CR
0 LOCALS| c |
0 to c
10 0 DO
i CELLS vector + @
c + to c
LOOP
c . CR
S" PRODUCTO ESCALAR " TYPE CR
10 0 DO
I CELLS vector + @
I CELLS vector + @
*
 b @ + b !
LOOP
b @ . CR
S" INVERTIR VECTOR " TYPE CR
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
S" INCREMENTO " TYPE CR
10 0 DO
i CELLS vector + @ 5 + i CELLS vector + !
LOOP
S" (" TYPE
 10 0 DO
I CELLS vector + @ .
LOOP
S" )" TYPE CR
S" Hola mundo " TYPE CR
c
;
main
