%{                      // SECCION 1 
#include <stdio.h>
#include "./AST.h"
//int memoria [26] ;   	// Se define una zona de memoria para las variables 

int yylex () ;
int yyerror (char* mensaje) ; 



typedef struct s_attr {
     int valor ;       //  - valor numerico entero 
     int indice ;      //  - indice para identificar una variable 
     struct nodoAST* nodo;     //  - nodo del arbol sintactico abstracto
} t_attr ;

#define YYSTYPE t_attr

%}
                     // SECCION 2 

%token  NUMERO    // Todos los token tienen un tipo para la pila
%token  VARIABLE  



%right  '='             //  es la ultima operacion que se debe realizar
%left   '+' '-'         //  menor orden de precedencia 
%left   '*' '/'         //  orden de precedencia intermedio 
// %left   SIGNO_UNARIO    //  mayor orden de precedencia 
%%
                        // SECCION 3: Gramatica - Semantico 
axioma:       expresion '\n'              { printf ("Expresion=%d\n", $1.valor) ;
                                             /*printf("Nombre del nodo raiz: %s\n", $1.nodo->nombre);
                                             printf("Valor del primer hijo: %d\n", $1.nodo->primer_nodo->valor);
                                             printf("Valor del segundo hijo: %d\n", $1.nodo->primer_nodo->siguiente_hermano->valor);*/
                                             imprimirAST($1.nodo);
                                             liberarAST($1.nodo);
                                              } 
                      r_expr/* 
            | VARIABLE '=' expresion '\n' { memoria [$1] = $3;
                                            printf ("%c=%d\n", $1+'A', $3);
                                          }
                       r_expr */
            ; 

  r_expr:                      /* lambda */
            | axioma
            ; 

expresion:    termino                    { $$ = $1 ; }
            | expresion '+' expresion    { $$.valor = $1.valor + $3.valor ;  
                                             struct nodoAST* nuevoNodo = crearNodoIntermedio("suma");
                                             /*printf("Agregando a nuevo nodo: %s\n", nuevoNodo->nombre);
                                             printf("Agregando nodo1: %d\n", $1.nodo->valor);
                                             printf("Agregando nodo2: %d\n", $3.nodo->valor);*/
                                             if ($1.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $1.nodo);
                                             }
                                             //printf("Primer hijo de suma: %d\n", nuevoNodo->primer_nodo->valor);
                                             if ($3.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $3.nodo);
                                             }
                                             //printf("Segundo hijo de suma: %d\n", nuevoNodo->primer_nodo->siguiente_hermano->valor);
                                             $$.nodo = nuevoNodo;
                                         }    
            | expresion '-' expresion    { $$.valor = $1.valor - $3.valor ;  
                                             struct nodoAST* nuevoNodo = crearNodoIntermedio("resta");
                                             if ($1.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $1.nodo);
                                             }
                                             if ($3.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $3.nodo);
                                             }
                                             $$.nodo = nuevoNodo;
                                             }
            | expresion '*' expresion    {   $$.valor = $1.valor * $3.valor ;  
                                             struct nodoAST* nuevoNodo = crearNodoIntermedio("multiplicacion");
                                             if ($1.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $1.nodo);
                                             }
                                             if ($3.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $3.nodo);
                                             }
                                             $$.nodo = nuevoNodo;
                                        }
            | expresion '/' expresion    { $$.valor = $1.valor / $3.valor ;  
                                             struct nodoAST* nuevoNodo = crearNodoIntermedio("división");
                                             if ($1.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $1.nodo);
                                             }
                                             if ($3.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $3.nodo);
                                             }
                                             $$.nodo = nuevoNodo;
                                        }
            ;

termino:      operando                           { $$ = $1 ; }
/*            | '+' operando %prec SIGNO_UNARIO    { $$ = $2 ; }
            | '-' operando %prec SIGNO_UNARIO    { $$ = -$2 ; } */
            ; 

operando:     /*VARIABLE                   { $$ = memoria [$1] ; }
            | */NUMERO                     {   $$.valor = $1.valor ;
                                             $$.nodo = crearNodoNumero($1.valor);
                                         }
            | '(' expresion ')'          { $$ = $2 ; }
            ;

%%

                        /* SECCION 4  Codigo en C */
int n_linea = 1 ;

int yyerror(char *mensaje) {
    fprintf(stderr, "%s en la linea %d\n", mensaje, n_linea);
    return 0; // Asegúrate de que yyerror devuelva un valor, en este caso, 0.
}

int yylex ()
{
    unsigned char c ;

    do {
         c = getchar () ;
    } while (c == ' ') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
         return NUMERO ;
    }

    if (c >= 'A' && c <= 'Z') {
         yylval.indice = c - 'A' ;  // resta a c el valor ascii de A
         return VARIABLE ;
    }

    if (c >= 'a' && c <= 'z') {
         yylval.indice = c - 'a' ;  // resta a c el valor ascii de a 
         return VARIABLE ;
    }

    if (c == '\n')
          n_linea++ ;
    return c ;
}

int main ()
{
    yyparse () ;
}