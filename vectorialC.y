%{                      // SECCION 1 
#include "basicCalc.h"
//int memoria [26] ;   	// Se define una zona de memoria para las variables 

int yylex () ;
int yyerror (char* mensaje) ; 
char *gen_code (char *) ;
char *my_malloc (int nbytes) ;
char *act_function;
struct nodoAST* lastNode = NULL;
struct nodoAST* functionNode = NULL;
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

                        
axioma:     INTEGER declaracionesGlob funcionesDef  mainDef 	{   printf ("Arbol sintactico abstracto:\n");
                                                                struct nodoAST* nodoAxioma = crearNodoIntermedioGenerico("axioma", 3, $2.nodo, $3.nodo, $4.nodo);
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
            

/*------------ GLOBAL DECLARATION VARIABLE MANAGEMENT ------------*/

declaracionesGlob:                                                              { ; }
                        | declaracionesGlobRec ';' INTEGER declaracionesGlob            { 
                                                                                if ($3.nodo){
                                                                                    agregarHermano($1.nodo, $3.nodo);
                                                                                }
                                                                                $$.nodo = $1.nodo;
                                                                                }
                                                                             
                        ;

declaracionesGlobRec:   IDENTIF restGlobVar restDeclaracionesGlob   {   struct nodoAST *nodoVar = NULL;
                                                                                if ($2.code==NULL){
                                                                                    printf("(setq %s %d)%s\n", $1.code, $2.value, $3.code);
                                                                                    nodoVar = crearNodoVariableInit($2.code, $3.value, "int");
                                                                                    
                                                                                } else{
                                                                                    printf("(setq %s %s)%s\n", $1.code, $2.code, $3.code); 
                                                                                    nodoVar = crearNodoVariableInit($1.code, 0, "vector");
                                                                                }
                                                                                if ($3.nodo){
                                                                                    // A la hora de generar el AST, es indiferente si las variables se declaran juntas o separadas
                                                                                    // Tomo la decisión de que se genere el AST como si se declararan separadas
                                                                                    agregarHermano(nodoVar, $3.nodo);
                                                                                }
                                                                                $$.nodo = nodoVar;
                                                                            }
                        ;

restDeclaracionesGlob:                                                      { $$.code = ""; 
                                                                                $$.nodo = NULL;
                                                                            }
                        | ',' IDENTIF restGlobVar restDeclaracionesGlob     {   struct nodoAST *nodoVar = NULL;
                                                                                if ($3.code==NULL){
                                                                                    sprintf(temp, " (setq %s %d)%s", $2.code, $3.value, $4.code);
                                                                                    $$.code = gen_code(temp);
                                                                                    nodoVar = crearNodoVariableInit($2.code, $3.value, "int");
                                                                                } else {
                                                                                    sprintf(temp, " (setq %s %s)%s", $2.code, $3.code, $4.code);
                                                                                    $$.code = gen_code(temp);
                                                                                    nodoVar = crearNodoVariableInit($2.code, 0, "vector");
                                                                                }
                                                                                if ($4.nodo){
                                                                                    agregarHermano(nodoVar, $4.nodo);
                                                                                }
                                                                                $$.nodo = nodoVar;
                                                                            }
                        ;

restGlobVar:                    { $$.value = 0; 
                                    $$.code = NULL;}
            | '=' NUMBER        { $$.value = $2.value; 
                                    $$.code = NULL;}
            | '[' NUMBER ']'    { 
                                    sprintf(temp, "(make-array %d)", $2.value);
								    $$.code = gen_code(temp); }
            ;


/*------------ FUNCTIONS DECLARATION MANAGEMENT ------------*/

funcionesDef:                                       { $$.nodo = functionNode;}
            |    IDENTIF '(' funcionArgs ')'  '{'    { printf("(defun %s (%s)\n", $1.code, $3.prefija); 
                                                            act_function = $1.code;
                                                            if (functionNode == NULL) { 
                                                                functionNode = crearNodoIntermedioGenerico("Funciones", 0);
                                                            }
                                                          
                                                    }
                recSentenciaFin                     {   
                                                        struct nodoAST* nodoFunc = crearNodoIntermedioGenerico($1.code, 0);
                                                        if ( $7.nodo){
                                                            agregarHijo(nodoFunc, $7.nodo);
                                                        }
                                                        agregarHijo(functionNode, nodoFunc);
                                                        act_function = NULL;
                                                        lastNode = NULL;
                                                    }
                INTEGER funcionesDef                        { 
                                                        $$.nodo = functionNode;
                                                    }
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
                                                    
mainDef:  MAIN '(' ')' '{'   { printf("(defun main ()\n");
                                        act_function = "main"; 
                                        lastNode = NULL;
                                    }
                    recSentenciaFin { 
                                        struct nodoAST* nodoMain = crearNodoIntermedioGenerico("main", 1, lastNode);
                                        $$.nodo = nodoMain;
                                    }
                    ;


/*------------ STATEMENT LEVEL ------------*/
recSentenciaFin:      '}'                              { printf(")\n"); 
                                                        $$.nodo = lastNode;
                                                        }
                    |   RETURN /*expresionAric*/ expresion ';' '}'       { printf("%s\n)\n", $2.prefija); } 
                    |   RETURN /*expresionAric*/ expresion ';'           { printf("(return-from %s %s)\n", act_function, $2.prefija); }
                        recSentenciaNoFin              { ; }
                    |   sentencia                      { if ($1.prefija) { printf("%s\n", $1.prefija); }}
                        recSentenciaFin                { 
                                                        if ($1.nodo && lastNode) {                                                            
                                                                agregarHermano($1.nodo, lastNode);
                                                        } 
                                                        $$.nodo = $1.nodo;
                                                        lastNode = $1.nodo;
                                                        }
//                    |   /*declaraciones*/ declaracion                  { ; }
                    ;

recSentenciaNoFin:      RETURN /*expresionAric*/ expresion ';' '}'   { printf("%s\n)\n", $2.prefija); }
                    |   RETURN /*expresionAric*/ expresion ';'       { printf("(return-from %s %s)", act_function, $2.prefija); }
                        recSentenciaNoFin          { ; }
                    |   sentencia                  { if ($1.prefija) { printf("%s\n", $1.prefija); }}
                        recSentenciaFin            { if ($1.nodo && lastNode) {                                                            
                                                                agregarHermano($1.nodo, lastNode);
                                                        } 
                                                        $$.nodo = $1.nodo;
                                                        lastNode = $1.nodo;
                        }
//                    |   /*declaraciones*/ declaracion              { ; }
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