  %{                      // SECCION 1 
#include "lispToForth/tradForth.h"


int yylex () ;
int yyerror (char* mensaje) ; 
char *gen_code (char *) ;
char *my_malloc (int nbytes) ;



char temp [2048] ;
char *concat_ptr;

typedef struct s_attr {
     int value ;       //  - valor numerico entero 
     char* code ;    
     char* prefija;   //  - expresion prefija
     struct nodoAST* nodo;     //  - nodo del arbol sintactico abstracto
} t_attr ;

#define YYSTYPE t_attr

%}
                     // SECCION 2 

%token NUMBER   
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token DEFVAR
%token SETQ  
%token SETF       
%token AREF 
%token MAKE
%token ARRAY
%token LET
%token WHILE
%token LOOP     
%token IF
%token PROGN
%token DO
%token PRINT
%token DEFUN
%token RETURN
%token FROM

%token AND          // tokens logical
%token OR  
%token LEQ          // lesser or equal
%token GEQ          // greater or equal
%token NEQ          // NEQ

%token DOTIMES
%token LENGTH
%token INCF
%token REDUCE



%left '+' '-'
%left '*' '/'
%left AND OR
%left '=' '<' '>' LEQ GEQ NEQ

%%

                        // SECCION 3: Gramatica - Semantico 


axioma: instrucciones                             { cleanFile() ; } 
        ;

instrucciones:                                    { ; } // lambda
                | sentencia instrucciones         { ; } 
            ;


sentencia:   '(' definicion ')'                 { ; } 
            | '(' asignacion ')'                { ; }
            | expresion                         { ; }
            | '(' condicion                     { ; }
            | '(' bucle ')'                     { ; }
            | '(' llamada ')'                   { ; }
            | '(' deffuncion                    { ; }
            | PRINT STRING                  { ; }
            | RETURN sentencia              { ; }
            ;

// FUNCIONES
deffuncion: DEFUN IDENTIF '(' argumentosfun ')' instrucciones ')' { ; }
            ;

argumentosfun:   |                             { ; } // lambda
                variable argumentosfun         { ; }
                ;


// DEFINICIONES
definicion: DEFVAR variable restodef       { ; }
            ;
        
restodef:   expresion                           { ; }
            | '(' MAKE '-' ARRAY expresion ')'       { ; }
            ;

// ASIGNACIONES
asignacion:   SETQ variable sentencia                    { ; }
            | SETF variable sentencia                    { ; }
            |  LET '(' '(' variable expresion ')' ')' 
            instrucciones                               { ; }
            ;

// CONDICIONALES
condicion: IF '(' expresion ')' '(' PROGN   
            instrucciones ')' restoif                 { ; }
            ;

restoif:    ')'                                       { ; }
            | '(' PROGN  instrucciones ')' ')'               { ; }
            ;

// BUCLES
bucle:   LOOP WHILE '(' expresion ')' DO instrucciones  { ; }



// LLAMADAS
llamada: IDENTIF '(' instrucciones ')'          { ; }


// OPERACIONES



expresion:          operando                    { ; }
                |    '+' expresion expresion     { ; }
                |    '-' expresion expresion     { ; }
                |    '*' expresion expresion     { ; }
                |    '/' expresion expresion     { ; }
                |    AND expresion expresion     { ; }
                |    OR expresion expresion      { ; }
                |    '=' expresion expresion     { ; }
                |    '<' expresion expresion     { ; }
                |    '>' expresion expresion     { ; }
                |    LEQ expresion expresion     { ; }
                |    GEQ expresion expresion     { ; }
                |    NEQ expresion expresion     { ; }
                ;

operando:       NUMBER                          { ; }
                | variable                       { ; }
                | '(' expresion ')'             { ; }
                ;

variable:        IDENTIF                         { ; }
                | '*' IDENTIF '*'               { ; }
                ;

%%

                        /* SECCION 4  Codigo en C */
int n_line = 1 ;

int yyerror(char *mensaje) {
    fprintf(stderr, "%s en la linea %d\n", mensaje, n_line);
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


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords[] = {
    {"setq", SETQ}, {"setf", SETF}, {"aref", AREF}, {"return-", RETURN}, {"from", FROM},
    {"while", WHILE}, {"loop", LOOP}, {"if", IF}, {"do", DO}, {"defvar", DEFVAR}, 
    {"make", MAKE}, {"array", ARRAY}, {"progn", PROGN}, {"defun", DEFUN},
    {"and", AND}, {"or", OR}, {"<=", LEQ}, {">=", GEQ}, 
    {"/=", NEQ}, {"let", LET}, {"print", PRINT}, {"dotimes", DOTIMES},
    {"length", LENGTH}, {"incf", INCF}, {"reduce",REDUCE}, //TODO:COMPLETAR CON FUNCIONALIDADES ADICIONALES
    {NULL, 0} // Marca el fin de la tabla
};


t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}




/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/


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
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char expandable_ops [] = "!<=>|%/&+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == '\r' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            //printf ("WARNING: string with more than 255 characters in line %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
         //printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
               //printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
               //printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (expandable_ops, c) != NULL) { // busca c en operadores expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

    //printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
        //printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}

int main ()
{
    yyparse () ;
}   