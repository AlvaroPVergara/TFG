%{                      // SECCION 1 
#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para code
#include <stdlib.h>           // declaraciones para exit ()
#include "./AST.h"
//int memoria [26] ;   	// Se define una zona de memoria para las variables 

int yylex () ;
int yyerror (char* mensaje) ; 
char *gen_code (char *) ;
char *my_malloc (int nbytes) ;

char temp [2048] ;

typedef struct s_attr {
     int valor ;       //  - valor numerico entero 
     int indice ;      //  - indice para identificar una variable 
     char* postfija;   //  - expresion postfija
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
axioma:       expresion '\n'              { printf ("Resultado=%d\n\n", $1.valor) ;
                                             printf ("Expresion postfija:\n %s\n\n", $1.postfija) ;
                                             printf ("Arbol sintactico abstracto:\n");
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
            | expresion '+' expresion    {   // Para calculadora
                                             $$.valor = $1.valor + $3.valor ;  
                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedio("suma");
                                             if ($1.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $1.nodo);
                                             }
                                             if ($3.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $3.nodo);
                                             }
                                             $$.nodo = nuevoNodo;
                                             // Notacion postfija
                                             sprintf(temp, "(+ %s %s)", $1.postfija, $3.postfija); 
                                             $$.postfija =  gen_code(temp);
                                        }    

            | expresion '-' expresion    {   // Para calculadora
                                             $$.valor = $1.valor - $3.valor ;  
                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedio("resta");
                                             if ($1.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $1.nodo);
                                             }
                                             if ($3.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $3.nodo);
                                             }
                                             $$.nodo = nuevoNodo;
                                             // Notacion postfija
                                             sprintf(temp, "(- %s %s)", $1.postfija, $3.postfija);
                                             $$.postfija =  gen_code(temp);
                                        }
                                             
            | expresion '*' expresion    {   // Para calculadora
                                             $$.valor = $1.valor * $3.valor ;  
                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedio("multiplicacion");
                                             if ($1.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $1.nodo);
                                             }
                                             if ($3.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $3.nodo);
                                             }
                                             $$.nodo = nuevoNodo;
                                             // Notacion postfija
                                             sprintf(temp, "(* %s %s)", $1.postfija, $3.postfija);
                                             $$.postfija =  gen_code(temp);
                                        }

            | expresion '/' expresion    {   // Para calculadora
                                             $$.valor = $1.valor / $3.valor ;  
                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedio("división");
                                             if ($1.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $1.nodo);
                                             }
                                             if ($3.nodo != NULL) {
                                                 agregarHijo(nuevoNodo, $3.nodo);
                                             }
                                             $$.nodo = nuevoNodo;
                                             // Notacion postfija
                                             sprintf(temp, "(/ %s %s)", $1.postfija, $3.postfija);
                                             $$.postfija =  gen_code(temp);
                                        }
            ;

termino:      operando                           { $$ = $1 ; }
/*            | '+' operando %prec SIGNO_UNARIO    { $$ = $2 ; }
            | '-' operando %prec SIGNO_UNARIO    { $$ = -$2 ; } */
            ; 

operando:     /*VARIABLE                   { $$ = memoria [$1] ; }
            | */NUMERO                     { // Para calculadora
                                             $$.valor = $1.valor ;
                                             // Para AST
                                             $$.nodo = crearNodoNumero($1.valor);
                                             // Para notacion postfija
                                             sprintf (temp, "%d", $1.valor);
                                             $$.postfija = gen_code(temp);

                                         }
            | '(' expresion ')'          { $$ = $2 ; }
            ;

%%

                        /* SECCION 4  Codigo en C */
int n_linea = 1 ;

int yyerror(char *mensaje) {
    fprintf(stderr, "%s en la linea %d\n", mensaje, n_linea);
    return 0; 
}


char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No memoria left for additional %d bytes\n", nbytes) ;
        fprintf (stderr, "%ld bytes reserved in %d calls\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
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