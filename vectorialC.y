%{                      // SECCION 1 
#include "basicCalc.h"
//int memoria [26] ;   	// Se define una zona de memoria para las variables 

int yylex () ;
int yyerror (char* mensaje) ; 
char *gen_code (char *) ;
char *my_malloc (int nbytes) ;
char *act_function;
struct nodoAST* lastNode = NULL;
struct nodoAST* nodoAxioma = NULL;
char temp [2048] ;

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
%token MAIN          // identifica el comienzo del proc. main
%token WHILE
%token FOR         
%token IF
%token ELSE
%token PUTS
%token PRINTF
%token AND          // tokens logical
%token OR  
%token LEQ          // lesser or equal
%token GEQ          // greater or equal
%token EQ           // EQ
%token NEQ          // NEQ
%token RETURN


%right  '='             //  es la ultima operacion que se debe realizar
%left   '+' '-'         //  menor orden de precedencia 
%left   '*' '/'         //  orden de precedencia intermedio 
%left   UNARY_SIGN      //  mayor orden de precedencia 
%%
                        // SECCION 3: Gramatica - Semantico 

                        
axioma:     INTEGER declaraciones mainDef 	{   printf ("Arbol sintactico abstracto:\n");
                                                imprimirAST(nodoAxioma); 
                                                printf("\n\n");
                                                printf ("Tabla de símbolos:\n");
                                                Symbol **tabla = initSymbolTable();
                                                semanticAnalysis(nodoAxioma, tabla);
                                                destroySymbolTable(tabla);
                                                liberarAST(nodoAxioma);
                                                printf ("\n\n");
                                            }
            ;
            

declaraciones:  //Lambda
                | IDENTIF nuevaDeclaracion { act_function = $1.code; 
                                            if (! nodoAxioma){
                                                nodoAxioma = crearNodoIntermedioGenerico("axioma", 0);
                                            }
                                            if ($2.code){ // Variables
                                                // Gestion de nodo AST
                                                struct nodoAST* nodoVar;                                        
                                                nodoVar = crearNodoVariableInit($1.code, $2.value, $2.code);                                               
                                                if ($2.nodo){
                                                    agregarHermano(nodoVar, $2.nodo);
                                                }
                                                agregarHijo(nodoAxioma, nodoVar);
                                                // Impresión de la notación prefija
                                                printf("(setq %s %s\n",$1.code ,$2.prefija); 
                                            } else{ // Functions
                                                changeName($2.nodo, $1.code);
                                                agregarHijo(nodoAxioma, $2.nodo);
                                                //impresión de la notación prefija
                                                printf("(defun %s %s", $1.code, $2.prefija);
                                            } 
                                            }
                ;

nuevaDeclaracion:  '(' funcionesDef         { 
                                            $$.nodo = $2.nodo;
                                            $$.prefija = $2.prefija;
                                            $$.code = NULL; // NULL for functions
                                            }
                    | varGlob               { $$.value = $1.value;
                                            $$.nodo = $1.nodo;
                                            $$.prefija = $1.prefija;
                                            if ($1.code){
                                                $$.code = "int"; //NOT NULL FOR VARIABLES
                                            }
                                            else {
                                                $$.code = "vector"; //NOT NULL FOR VARIABLES
                                            }
                                            }
                ;


/*------------ GLOBAL DECLARATION VARIABLE MANAGEMENT ------------*/

varGlob:    restoVar varRecGlob ';' INTEGER declaraciones                       { 
                                                                                 $$.value = $1.value;
                                                                                 $$.nodo = $2.nodo;
                                                                                 sprintf(temp, "%s)%s", $1.code, $2.code);
                                                                                 $$.prefija = gen_code(temp);
                                                                                 $$.code = $1.code;
                                                                                 act_function = NULL;
                                                                                }
                                                                             
                        ;


varRecGlob:                                                     { $$.code = ""; 
                                                                  $$.nodo = NULL;
                                                                }
                        | ',' IDENTIF restoVar varRecGlob     {   struct nodoAST *nodoVar = NULL;
                                                                  sprintf(temp, " (setq %s %s)%s", $2.code, $3.prefija, $4.prefija);
                                                                  $$.prefija = gen_code(temp); 
                                                                  $$.code = $3.code;             
                                                                if ($3.value){      
                                                                    nodoVar = crearNodoVariableInit($2.code, 0, "vector");
                                                                } else {
                                                                    nodoVar = crearNodoVariableInit($2.code, $3.value, "int");
                                                                }
                                                                if ($4.nodo){
                                                                    agregarHermano(nodoVar, $4.nodo);
                                                                }
                                                                $$.nodo = nodoVar;
                                                                }
                        ;

restoVar:                       { $$.value = 0; 
                                    sprintf(temp, "0");
                                    $$.prefija = $$.code = gen_code(temp);
                                    }
            | '=' NUMBER        { $$.value = $2.value; 
                                    sprintf(temp, "%d", $2.value);
                                    $$.prefija = $$.code = gen_code(temp);}
            | '[' NUMBER ']'    { $$.value = 0;
                                    sprintf(temp, "(make-array %d)", $2.value);
								    $$.prefija = gen_code(temp); 
                                    $$.code = NULL;}
            ;


/*------------ FUNCTIONS DECLARATION MANAGEMENT ------------*/

funcionesDef:   funcionArgs ')' '{' recSentenciaFin    
                INTEGER funcionesDefRec             { //Nodo de la funcion
                                                        struct nodoAST* nodoFunc = crearNodoIntermedioGenerico("NombreFuncTemp", 0);
                                                        if ( $4.nodo){
                                                            agregarHijo(nodoFunc, $4.nodo);
                                                        }
                                                        $$.nodo = nodoFunc;
                                                        //Notacion prefija
                                                        sprintf(temp," (%s)\n%s", $1.prefija, $4.prefija);
                                                        $$.prefija = gen_code(temp); 
                                                        act_function = NULL;
                                                    }
            ;

funcionesDefRec:  //Lambda
                | IDENTIF '(' funcionesDef          { act_function = $1.code; }
                ;

funcionArgs:                                { $$.prefija = ""; }
            |  INTEGER /*varIdentf*/ IDENTIF recArgFunct {    if( $3.prefija == NULL)    {
                                                    sprintf(temp, "%s",  $2.code);
                                                } else{
                                                    sprintf(temp, "%s %s", $2.code, $3.prefija);
                                                }
                                                $$.prefija = gen_code(temp);
                                            }
            ;

recArgFunct:                        { $$.prefija = NULL; }
			 | ',' funcionArgs		{ $$.prefija = $2.prefija; }
             ;



/*------------ MAIN FUNCTION DECLARATION MANAGEMENT ------------*/
                                                    
mainDef:  MAIN '(' ')' '{'          { 
                                        act_function = "main"; 
                                        lastNode = NULL;
                                    }
                    recSentenciaFin {   //Nodo AST
                                        if (! nodoAxioma){
                                            nodoAxioma = crearNodoIntermedioGenerico("axioma", 0);
                                        }
                                        struct nodoAST* nodoMain = crearNodoIntermedioGenerico("main", 1, lastNode);
                                        agregarHijo(nodoAxioma, nodoMain);
                                        //Notacion prefija
                                        printf("(defun main ()\n%s", $6.prefija);
                                    }
                    ;


/*------------ STATEMENT LEVEL ------------*/
recSentenciaFin:      '}'                              { sprintf(temp,")\n"); 
                                                        $$.prefija = gen_code(temp);
                                                        $$.nodo = lastNode;
                                                        }
                    |   RETURN /*expresionAric*/ expresion ';' '}'              { 
                                                                                sprintf(temp,"%s\n)\n", $2.prefija);
                                                                                $$.prefija = gen_code(temp);
                                                                                } 

                    |   RETURN /*expresionAric*/ expresion ';' recSentenciaNoFin { 
                                                                                sprintf(temp,"(return-from %s %s)\n%s", act_function, $2.prefija, $3.prefija); 
                                                                                $$.prefija = gen_code(temp); 
                                                                                }

                    |   sentencia recSentenciaFin                               { 
                                                                                // Nodos AST
                                                                                if ($1.nodo && lastNode) {                                                            
                                                                                        agregarHermano($1.nodo, lastNode);
                                                                                } 
                                                                                $$.nodo = $1.nodo;
                                                                                lastNode = $1.nodo;
                                                                                // Notacion prefija
                                                                                sprintf(temp,"%s\n%s", $1.prefija, $2.prefija);
                                                                                $$.prefija = gen_code(temp); 
                                                                                }
                    ;

recSentenciaNoFin:      RETURN /*expresionAric*/ expresion ';' '}'              { 
                                                                                sprintf(temp,"%s\n)\n", $2.prefija);
                                                                                $$.prefija = gen_code(temp);
                                                                                } 
                    |   RETURN /*expresionAric*/ expresion ';' recSentenciaNoFin { 
                                                                                sprintf(temp,"(return-from %s %s)\n%s", act_function, $2.prefija, $3.prefija); 
                                                                                $$.prefija = gen_code(temp); 
                                                                                }
                    |   sentencia recSentenciaFin                               { 
                                                                                // Nodos AST
                                                                                if ($1.nodo && lastNode) {                                                            
                                                                                        agregarHermano($1.nodo, lastNode);
                                                                                } 
                                                                                $$.nodo = $1.nodo;
                                                                                lastNode = $1.nodo;
                                                                                // Notacion prefija
                                                                                sprintf(temp,"%s\n%s", $1.prefija, $2.prefija);
                                                                                $$.prefija = gen_code(temp); 
                                                                                }
                    ;

/*
recSentenciaCond:   '}'                            {printf(")\n"); }
                    |   sentencia                  { if ($1.code) { printf("%s\n", $1.code); }}
                        recSentenciaCond           { ; }
                    |   RETURN expresionAric ';'   { printf("(return-from %s %s)", act_function, $2.code); }
                        recSentenciaCond           { ; }   
                    |   declaraciones              { ; }
                    ;    
    
recSentenciaFor:   '}'                             { ; }
                    |   sentencia                  { if ($1.code) { printf("%s\n", $1.code); }}
                        recSentenciaFor            { ; }
                    |   RETURN expresionAric ';'   { printf("(return-from %s %s)", act_function, $2.code); }
                        recSentenciaFor            { ; }   
                    |   declaraciones              { ; }
                    ;  
*/

sentencia:   asignacion  ';'                                  { $$ = $1; }
/*
            | PRINTF '(' STRING ',' expresion printRec ')' ';'  { if ($6.code) {
                                                                    sprintf (temp, "(print %s) %s", $5.code, $6.code);
                                                                 } else {
                                                                    sprintf (temp, "(print %s)", $5.code);
                                                                 }
                                                                $$.code = gen_code (temp) ; 
                                                                }
                                                       

            | PUTS '('  STRING  ')' ';'                         { sprintf(temp, "(print \"%s\")",$4.code);
                                                                    $$.code = gen_code (temp) ; }
            | sentenciaWhile                                    { $$.code = NULL; } 
            | sentenciaIF                                       { $$.code = NULL; }
            | sentenciaFOR                                      { $$.code = NULL; }
            | funcionLlamada   ';'                              { $$.code = $1.code; }
*/           
            | declaracion      ';'                                  { $$ = $1; }
            ;
                                                        

declaracion: INTEGER IDENTIF               { // Para calculadora
                                             $$.value = 0 ; 
                                             // Para AST
                                             $$.nodo = crearNodoVariableInit($2.code, 0, "int");
                                             // Para notacion prefija
                                             sprintf (temp, "(setq %s 0)", $2.code);
                                             $$.prefija = gen_code(temp);
                                        }
           ;


asignacion: IDENTIF '=' expresion    {    // Para calculadora
                                             $$.value = $3.value ;

                                             // Para AST
                                             struct nodoAST* nodoVar = crearNodoVariable($1.code, $3.value, "int");
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("asignacion", 2, nodoVar, $3.nodo);
                                             $$.nodo = nuevoNodo;

                                             // Para notacion prefija
                                             sprintf (temp, "(setq %s %s)", $1.code, $3.prefija);
                                             $$.prefija = gen_code(temp);
                                        }
            ;


expresion:    termino                    { $$ = $1 ; }
            | expresion '+' expresion    {   // Para calculadora
                                             $$.value = $1.value + $3.value ;  

                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("suma", 2, $1.nodo, $3.nodo);
                                             $$.nodo = nuevoNodo;

                                             // Notacion prefija
                                             sprintf(temp, "(+ %s %s)", $1.prefija, $3.prefija); 
                                             $$.prefija =  gen_code(temp);
                                        }    

            | expresion '-' expresion    {   // Para calculadora
                                             $$.value = $1.value - $3.value ;  

                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("resta", 2, $1.nodo, $3.nodo);
                                             $$.nodo = nuevoNodo;

                                             // Notacion prefija
                                             sprintf(temp, "(- %s %s)", $1.prefija, $3.prefija);
                                             $$.prefija =  gen_code(temp);
                                        }
                                             
            | expresion '*' expresion    {   // Para calculadora
                                             $$.value = $1.value * $3.value ;  

                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("multiplicacion", 2, $1.nodo, $3.nodo);
                                             $$.nodo = nuevoNodo;

                                             // Notacion prefija
                                             sprintf(temp, "(* %s %s)", $1.prefija, $3.prefija);
                                             $$.prefija =  gen_code(temp);
                                        }

            | expresion '/' expresion    {   // Para calculadora
                                             $$.value = $1.value / $3.value ;  

                                             // Para AST
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("división", 2, $1.nodo, $3.nodo);
                                             $$.nodo = nuevoNodo;

                                             // Notacion prefija
                                             sprintf(temp, "(/ %s %s)", $1.prefija, $3.prefija);
                                             $$.prefija =  gen_code(temp);
                                        }
            ;

termino:      operando                           { $$ = $1 ; }
            | '+' operando %prec UNARY_SIGN    {  // Para calculadora
                                                    $$.value = $2.value ; 
                                                    // Para AST
                                                    struct nodoAST* nodoSigno = crearNodoSigno("+", $2.value);
                                                    struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("signo-unario", 2, nodoSigno, $2.nodo);
                                                    $$.nodo = nuevoNodo;
                                                    // Para notacion prefija
                                                    sprintf (temp, "(+ %s)", $2.prefija);
                                                    $$.prefija = gen_code(temp);
                                                }
            | '-' operando %prec UNARY_SIGN    { // Para calculadora
                                                    $$.value = -$2.value ; 
                                                    // Para AST
                                                    struct nodoAST* nodoSigno = crearNodoSigno("-", - $2.value);
                                                    struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("signo unario", 2, nodoSigno, $2.nodo);
                                                    $$.nodo = nuevoNodo;
                                                    // Para notacion prefija
                                                    sprintf (temp, "(- %s)", $2.prefija);
                                                    $$.prefija = gen_code(temp);
                                                } 
            ; 

operando:    IDENTIF                    { // Para calculadora
                                             $$.value = $1.value ;
                                             // Para AST
                                             $$.nodo = crearNodoVariable($1.code, $1.value, "int");
                                             // Para notacion prefija
                                             sprintf (temp, "%s", $1.code);
                                             $$.prefija = gen_code(temp);
                                        }
            | NUMBER                     { // Para calculadora
                                             $$.value = $1.value ;
                                             // Para AST
                                             $$.nodo = crearNodoNumero($1.value);
                                             // Para notacion prefija
                                             sprintf (temp, "%d", $1.value);
                                             $$.prefija = gen_code(temp);

                                         }
            | '(' expresion ')'          { $$ = $2 ; }
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
    {"main", MAIN}, {"int", INTEGER}, {"puts", PUTS}, {"printf", PRINTF},
    {"while", WHILE}, {"for", FOR}, {"if", IF}, {"else", ELSE},
    {"&&", AND}, {"||", OR}, {"<=", LEQ}, {">=", GEQ}, {"==", EQ},
    {"!=", NEQ}, {"return", RETURN},
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