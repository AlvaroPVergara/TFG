    %{                      // SECCION 1 
#include "baseLanguage/vectorialC.h"
//int memoria [26] ;   	// Se define una zona de memoria para las variables 

int yylex () ;
int yyerror (char* mensaje) ; 
char *gen_code (char *) ;
char *my_malloc (int nbytes) ;
struct nodoAST* node_to_bool(struct nodoAST* nodo);
struct nodoAST* node_to_aric(struct nodoAST* nodo);

char *act_function;
struct nodoAST* lastNode = NULL;
struct nodoAST* lastNodeGlobal = NULL;
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


%right '='                    // es la ultima operacion que se debe realizar
%left OR
%left AND
%left EQ NEQ
%left '<' LEQ '>' GEQ
%left '+' '-'                 // menor orden de precedencia
%left '*' '/'                 // orden de precedencia intermedio
%left UNARY_SIGN              // mayor orden de precedencia
%%
                        // SECCION 3: Gramatica - Semantico 

                        
axioma:     INTEGER declaraciones mainDef 	{   printf("%s%s", $2.prefija, $3.prefija);
                                                printf ("Arbol sintactico abstracto:\n");
                                                struct nodoAST* nodoAxioma;
                                                if (lastNodeGlobal){
                                                    nodoAxioma = crearNodoIntermedioGenerico("axioma", 2, lastNodeGlobal, $3.nodo);
                                                } else {
                                                    nodoAxioma = crearNodoIntermedioGenerico("axioma", 1, $3.nodo);
                                                }
                                                
                                                imprimirAST(nodoAxioma); 

                                                astToLisp(nodoAxioma);

                                                printf("\n\n");
                                                printf ("Tabla de símbolos:\n");
                                                Symbol **tabla = initSymbolTable();
                                                semanticAnalysis(nodoAxioma, tabla);
                                                destroySymbolTable(tabla);
                                                liberarAST(nodoAxioma);
                                                printf ("\n\n");
                                            }
            ;
        


declaraciones:                              { $$.prefija = ""; } //Lambda 
                | IDENTIF nuevaDeclaracion { act_function = $1.code; 
                                            if ($2.code){ // Variables
                                                // Gestion de nodo AST
                                                struct nodoAST* nodoVar;                                        
                                                nodoVar = crearNodoVariableInit($1.code, $2.value, $2.code);                                               
                                                if (! lastNodeGlobal){
                                                    lastNodeGlobal = nodoVar;
                                                } else{
                                                    agregarHermano(nodoVar, lastNodeGlobal);
                                                    lastNodeGlobal = nodoVar;
                                                }
                                                // notación prefija
                                                sprintf(temp,"(setq %s %s",$1.code ,$2.prefija); 
                                                $$.prefija = gen_code(temp);
                                            } else{ // Functions
                                                changeName($2.nodo, $1.code);
                                                if (! lastNodeGlobal){
                                                    lastNodeGlobal = $2.nodo;
                                                } else{
                                                    agregarHermano($2.nodo, lastNodeGlobal);
                                                    lastNodeGlobal = $2.nodo;
                                                }
                                                // notación prefija
                                                sprintf(temp,"(defun %s %s", $1.code, $2.prefija);
                                                $$.prefija = gen_code(temp);
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
                                            if (strcmp($1.code, "int") == 0){
                                                $$.code = "int"; //NOT NULL FOR VARIABLES
                                            }
                                            else if (strcmp($1.code, "vector") == 0){
                                                $$.code = "vector"; //NOT NULL FOR VARIABLES
                                            }
                                            else{
                                                $$.code = "vector"; //NOT NULL FOR VARIABLES
                                                printf("ERROR: NO SE PUDO CREAR LA VARIABLE\n");
                                            }
                                            }
                ;


/*------------ GLOBAL DECLARATION VARIABLE MANAGEMENT ------------*/

varGlob:    restoVar varRecGlob ';' INTEGER declaraciones                       { 
                                                                                if ($1.code){
                                                                                    $$.code = "vector";
                                                                                    $$.value = $1.value;
                                                                                    sprintf(temp, "%s)%s\n%s",$1.prefija ,$2.prefija, $5.prefija);
                                                                                } else {
                                                                                    $$.code = "int";
                                                                                    $$.value = 0; 
                                                                                    sprintf(temp, "0)%s\n%s", $2.prefija, $5.prefija);
                                                                                }
                                                                                 $$.nodo = $2.nodo;        
                                                                                 $$.prefija = gen_code(temp);
                                                                                 act_function = NULL;
                                                                                }
                                                                             
                        ;


varRecGlob:                                                     { $$.code = ""; 
                                                                  $$.nodo = NULL;
                                                                  $$.prefija = "";
                                                                }
                        | ',' IDENTIF restoVar varRecGlob     {   struct nodoAST *nodoVar = NULL;
                                                                  sprintf(temp, " (setq %s %s)%s", $2.code, $3.prefija, $4.prefija);
                                                                  $$.prefija = gen_code(temp); 
                                                                  $$.code = $3.code;             
                                                                if ($3.code){      
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

restoVar:                       {  ; }
            | '=' NUMBER        {   
                                    $$.value = $2.value; 
                                    sprintf(temp, "%d", $2.value);
                                    $$.prefija = $$.code = gen_code(temp);}
            | '[' NUMBER ']'    {   $$.value = $2.value;
                                    sprintf(temp, "(make-array %d)", $2.value);
								    $$.prefija = gen_code(temp); 
                                    $$.code = "vector";}
            ;


/*------------ FUNCTIONS DECLARATION MANAGEMENT ------------*/

funcionesDef:   funcionArgs ')' '{'                 { lastNode = NULL; }
                recSentenciaFin    
                INTEGER funcionesDefRec             { //Nodo de la funcion
                                                        // TODO: MANAGE ARGS
                                                        struct nodoAST* nodoFunc = crearNodoFuncion("NombreFuncTemp");
                                                        if ( $5.nodo){
                                                            agregarHijo(nodoFunc, $5.nodo);
                                                        }
                                                        $$.nodo = nodoFunc;
                                                        
                                                        //Notacion prefija
                                                        sprintf(temp," (%s)\n%s%s", $1.prefija, $5.prefija, $7.prefija);
                                                        $$.prefija = gen_code(temp); 
                                                        act_function = NULL;
                                                    }
            ;

funcionesDefRec:                                    { $$.prefija = ""; //Lambda  
                                                    }    
                | IDENTIF '(' funcionesDef          { act_function = $1.code;
                                                    //Nodo AST
                                                    changeName($3.nodo, $1.code);
                                                    if (! lastNodeGlobal){
                                                        lastNodeGlobal = $3.nodo;
                                                    } else{
                                                        agregarHermano($3.nodo, lastNodeGlobal);
                                                        lastNodeGlobal = $3.nodo;
                                                    }
                                                    //Notacion prefija
                                                     sprintf(temp, "(defun %s %s", $1.code, $3.prefija);
                                                     $$.prefija = gen_code(temp);
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
                                                    
mainDef:  MAIN '(' ')' '{'          { 
                                        act_function = "main"; 
                                        lastNode = NULL;
                                    }
                    recSentenciaFin {   //Nodo AST
                                        struct nodoAST* nodoMain = crearNodoFuncion("main");
                                        agregarHijo(nodoMain, lastNode);
                                        $$.nodo = nodoMain;
                                        //Notacion prefija
                                        sprintf(temp,"(defun main ()\n%s", $6.prefija);
                                        $$.prefija = gen_code(temp);
                                    }
                    ;


/*------------ STATEMENT LEVEL ------------*/
recSentenciaFin:      '}'                              { sprintf(temp,")\n"); 
                                                        $$.prefija = gen_code(temp);
                                                        $$.nodo = lastNode;
                                                        }
                    |   RETURN expresionAric ';' '}'                { 
                                                                    struct nodoAST* nodoReturn = crearNodoIntermedioGenerico("last-return", 1, $2.nodo);
                                                                    $$.nodo = nodoReturn;
                                                                    if (lastNode){
                                                                        agregarHermano(nodoReturn, lastNode);
                                                                    }
                                                                    lastNode = nodoReturn;
                                                                    sprintf(temp,"%s\n)\n", $2.prefija);
                                                                    $$.prefija = gen_code(temp);
                                                                    } 

                    |   RETURN expresionAric ';' recSentenciaNoFin  { 
                                                                    struct nodoAST* nodoHojaFun = crearNodoHojaFuncion(act_function);
                                                                    struct nodoAST* nodoReturn = crearNodoIntermedioGenerico("return", 2, nodoHojaFun, $2.nodo);
                                                                    $$.nodo = nodoReturn;
                                                                    if (lastNode){
                                                                        agregarHermano(nodoReturn, lastNode);
                                                                    }
                                                                    lastNode = nodoReturn;
                                                                    sprintf(temp,"(return-from %s %s)\n%s", act_function, $2.prefija, $4.prefija); 
                                                                    $$.prefija = gen_code(temp); 
                                                                    }

                    |   sentencia recSentenciaFin                   { 
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
recSentenciaNoFin is used for the statement level, but only after a return statement that is not the last statement of the function.
This is made to ensure that the regular return statement is not the last return statement of the function.
*/
recSentenciaNoFin:      RETURN expresionAric ';' '}'                { 
                                                                    struct nodoAST* nodoReturn = crearNodoIntermedioGenerico("last-return", 1, $2.nodo);
                                                                    $$.nodo = nodoReturn;
                                                                    if (lastNode){
                                                                        agregarHermano(nodoReturn, lastNode);
                                                                    }
                                                                    lastNode = nodoReturn;
                                                                    sprintf(temp,"%s\n)\n", $2.prefija);
                                                                    $$.prefija = gen_code(temp);
                                                                    } 
                    |   RETURN expresionAric  ';' recSentenciaNoFin { 
                                                                    struct nodoAST* nodoHojaFun = crearNodoHojaFuncion(act_function);
                                                                    struct nodoAST* nodoReturn = crearNodoIntermedioGenerico("return", 2, nodoHojaFun, $2.nodo);
                                                                    $$.nodo = nodoReturn;
                                                                    if (lastNode){
                                                                        agregarHermano(nodoReturn, lastNode);
                                                                    }
                                                                    lastNode = nodoReturn;
                                                                    sprintf(temp,"(return-from %s %s)\n%s", act_function, $2.prefija, $4.prefija); 
                                                                    $$.prefija = gen_code(temp); 
                                                                    }
                    |   sentencia recSentenciaFin                   { 
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
recSentenciaCond is the recursive function for the statement level, but is used only for the while, for and if statements.
Is used this way because it does not leave room for a regular return statement. 
(which is only posible if is the last statement of the function)*/

recSentenciaCond:   '}'                                             {printf(")\n"); }
                    |   sentencia recSentenciaCond                  { if ($2.nodo){
                                                                        agregarHermano($1.nodo, $2.nodo);
                                                                    }
                                                                    $$.nodo = $1.nodo; 
                                                                    sprintf(temp,"%s\n%s", $1.prefija, $2.prefija);
                                                                    $$.prefija = gen_code(temp); 
                                                                    }
                    |   RETURN expresionAric ';' recSentenciaCond   { 
                                                                    struct nodoAST* nodoHojaFun = crearNodoHojaFuncion(act_function);
                                                                    struct nodoAST* nodoReturn = crearNodoIntermedioGenerico("return", 2, nodoHojaFun, $2.nodo);
                                                                    if ($4.nodo){
                                                                        agregarHermano(nodoReturn, $4.nodo);
                                                                    }
                                                                    $$.nodo = nodoReturn;
                                                                    sprintf(temp,"(return-from %s %s)\n%s", act_function, $2.prefija, $4.prefija); 
                                                                    $$.prefija = gen_code(temp); 
                                                                    }
                    ;    


sentencia:   asignacion  ';'                                  { $$ = $1; }
/*
            | PRINTF '(' STRING ',' expresion printRec ')' ';'  { if ($6.code) {
                                                                    sprintf (temp, "(print %s) %s", $5.code, $6.code);
                                                                 } else {
                                                                    sprintf (temp, "(print %s)", $5.code);
                                                                 }
                                                                $$.code = gen_code (temp) ; 
                                                                }
                                                       
*/
            | PUTS '('  STRING  ')' ';'                         { sprintf(temp, "(print \"%s\")",$3.code);
                                                                $$.prefija = gen_code (temp) ; 
                                                                struct nodoAST* nodoString = crearNodoString($3.code);
                                                                struct nodoAST* nodoPuts = crearNodoIntermedioGenerico("puts", 1, nodoString);
                                                                $$.nodo = nodoPuts;
                                                                }
            | sentenciaWhile                                    { $$.code = NULL; 
                                                                  $$.nodo = $1.nodo;}  
            | sentenciaIF                                       { $$.code = NULL; 
                                                                  $$.nodo = $1.nodo;}       
            | sentenciaFor                                      { $$.code = NULL; 
                                                                  $$.nodo = $1.nodo;}
            | funcionLlamada   ';'                              { $$ = $1; 
                                                                
                                                                }
          
            | declaracion      ';'                                  { $$ = $1; }
            ;
                                                        

declaracion: INTEGER IDENTIF restoVar   { 
                                             // Para AST
                                            struct nodoAST *nodoVar = NULL;
                                            if ($3.code){      
                                                nodoVar = crearNodoVariableInit($2.code, $3.value, "vector");
                                            } else {
                                                nodoVar = crearNodoVariableInit($2.code, $3.value, "int");
                                            }
                                            $$.nodo = nodoVar;

                                             // Para notacion prefija
                                             sprintf(temp, " (setq %s %s)", $2.code, $3.prefija);
                                             $$.prefija = gen_code(temp);
                                        }
           ;


asignacion: IDENTIF '=' expresionAric    { 
                                             // Para AST
                                             struct nodoAST* nodoVar = crearNodoVariable($1.code, $3.value, "int");
                                             struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("asignacion", 2, nodoVar, $3.nodo);
                                             $$.nodo = nuevoNodo;

                                             // Para notacion prefija
                                             sprintf (temp, "(setq %s %s)", $1.code, $3.prefija);
                                             $$.prefija = gen_code(temp);
                                        }
            ;

sentenciaIF:  IF '(' expresionBool  ')' '{' 
              recSentenciaCond  restoIF         { 
                                                struct nodoAST* nodoCond = crearNodoIntermedioGenerico("condicion", 1, $3.nodo);
                                                struct nodoAST* nodoStatements = crearNodoIntermedioGenerico("statements", 1, $6.nodo);
                                                struct nodoAST* nodoIf = crearNodoIntermedioGenerico("if", 2, nodoCond, nodoStatements);
                                                if ($7.nodo){
                                                    agregarHermano(nodoIf, $7.nodo);
                                                }
                                                $$.nodo = nodoIf;

                                                }
            ;


restoIF:                                        { $$.nodo = NULL; }
        | ELSE '{' recSentenciaCond             { struct nodoAST* nodoElse = crearNodoIntermedioGenerico("else", 1, $3.nodo);
                                                  $$.nodo = nodoElse;
                                                }
        ;


sentenciaWhile: WHILE '(' expresionBool  ')' '{' 
                recSentenciaCond                {
                                                struct nodoAST* nodoCond = crearNodoIntermedioGenerico("condicion", 1, $3.nodo);
                                                struct nodoAST* nodoStatements = crearNodoIntermedioGenerico("statements", 1, $6.nodo);
                                                struct nodoAST* nodoWhile = crearNodoIntermedioGenerico("while", 2, nodoCond, nodoStatements);
                                                $$.nodo = nodoWhile;
                                                }


sentenciaFor: FOR '(' declaracionFor ';' expresionBool 
                ';' asignacion ')' '{' recSentenciaCond {
                                                        struct nodoAST* nodoInit = crearNodoIntermedioGenerico("for-init", 1, $3.nodo);
                                                        struct nodoAST* nodoCond = crearNodoIntermedioGenerico("condicion", 1, $5.nodo);
                                                        struct nodoAST* nodoInc = crearNodoIntermedioGenerico("incremento", 1, $7.nodo);
                                                        struct nodoAST* nodoStatements = crearNodoIntermedioGenerico("statements", 1, $10.nodo);
                                                        struct nodoAST* nodoFor = crearNodoIntermedioGenerico("for", 4,nodoInit, nodoCond, nodoStatements, nodoInc);
                                                        $$.nodo = nodoFor;
                                                        }

declaracionFor: INTEGER IDENTIF /*restVar */            {
                                                        struct nodoAST* nodoVar = crearNodoVariableInit($2.code, 0, "int");
                                                        $$.nodo = nodoVar;
                                                        }



funcionLlamada: IDENTIF '(' funcionArgsLlamada ')'      { 
                                                            struct nodoAST* nodoHojaFun = crearNodoHojaFuncion($1.code);
                                                            struct nodoAST* nodoArgumentos = crearNodoIntermedioGenerico("argumentos", 1, $3.nodo);
                                                            
                                                            struct nodoAST* nodoLlamada = crearNodoIntermedioGenerico("llamada-funcion", 2, nodoHojaFun, nodoArgumentos);
                                                            $$.nodo = nodoLlamada;

                                                            sprintf(temp,"(%s %s)", $1.code, $3.prefija);
                                                            $$.prefija = gen_code(temp);
                                                        }
            ;

funcionArgsLlamada:                                        { $$.code = ""; }
                    |  expresionAric recArgFunctLlamada    {   if( $2.code == NULL)    {
                                                                sprintf(temp, "%s",  $1.code);
                                                                $$.nodo = $1.nodo;
                                                            } else{
                                                                sprintf(temp, "%s %s", $1.code, $2.code);
                                                                agregarHermano($1.nodo, $2.nodo);
                                                                $$.nodo = $1.nodo;
                                                            }
                                                            $$.prefija = gen_code(temp);
                                                        }
                    ;

recArgFunctLlamada:                         { $$.code = NULL; }
			 | ',' funcionArgsLlamada		{ $$.code = $2.code; 
                                              $$.nodo = $2.nodo;
                                            
                                            }
             ;


/* ------------------------------------- EXPRESSION LEVEL --------------------------------------- */


expresionBool: expresion        { if ( $1.value == 0){
                                    sprintf(temp, "(/= 0 %s)", $1.prefija);
                                    $$.prefija = gen_code(temp);
                                    $$.nodo = node_to_bool($1.nodo);
                                  } else{
                                    $$.prefija = $1.prefija;
                                    $$.nodo = $1.nodo;
                                  }
                                }
            ;

expresionAric: expresion        { if ( $1.value == 1){
                                    sprintf(temp, "(if %s 1 0)", $1.prefija);
                                    $$.prefija = gen_code(temp); 
                                    struct nodoAST* nodo_aric = node_to_aric($1.nodo);
                                    $$.nodo = nodo_aric;
                                  } else{
                                    $$.prefija = $1.prefija;
                                    $$.nodo = $1.nodo;
                                  }
                                }
            ;


expresion: termino                     { $$.prefija = $1.prefija;
                                         if ($1.value != 0 && $1.value != 1){
                                            $$.value = 0;
                                         } else {
                                            $$.value = 2;
                                         }                                       
                                         
                                         $$.nodo = $1.nodo;
                                         }

           | expresion AND expresion  { concat_ptr = temp; 
                                        concat_ptr += sprintf(concat_ptr, "(and ");
                                        struct nodoAST* nodoexp1 = $1.nodo;
                                        struct nodoAST* nodoexp2 = $3.nodo;
                                        if ($1.value == 0){
                                            // Concat $1 transformed
                                            concat_ptr += sprintf(concat_ptr, "(/= 0 %s) ", $1.prefija);
                                            struct nodoAST* nodo_bool = node_to_bool(nodoexp1);
                                            nodoexp1 = nodo_bool;
                                        } else {
                                            // Concat $1 as is
                                            concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        }
                                        if ($3.value == 0){
                                            // Concat $3 transformed
                                            concat_ptr += sprintf(concat_ptr, "(/= 0 %s))", $3.prefija);
                                            struct nodoAST* nodo_bool = node_to_bool(nodoexp2);
                                            nodoexp2 = nodo_bool;
                                        } else {
                                            concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        }
                                        $$.value = 1;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoAnd = crearNodoIntermedioGenerico("and", 2, nodoexp1, nodoexp2);
                                        $$.nodo = nodoAnd;
                                        }
 
            | expresion OR expresion  { concat_ptr = temp; 
                                        concat_ptr += sprintf(concat_ptr, "(or ");
                                        struct nodoAST* nodoexp1 = $1.nodo;
                                        struct nodoAST* nodoexp2 = $3.nodo;
                                        if ($1.value == 0){
                                            // Concat $1 transformed
                                            concat_ptr += sprintf(concat_ptr, "(/= 0 %s) ", $1.prefija);
                                            struct nodoAST* nodo_bool = node_to_bool(nodoexp1);
                                            nodoexp1 = nodo_bool;
                                        } else {
                                            // Concat $1 as is
                                            concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        }
                                        if ($3.value == 0){
                                            // Concat $3 transformed
                                            concat_ptr += sprintf(concat_ptr, "(/= 0 %s))", $3.prefija);
                                            struct nodoAST* nodo_bool = node_to_bool(nodoexp2);
                                            nodoexp2 = nodo_bool;
                                        } else {
                                            concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        }
                                        $$.value = 1;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoOr = crearNodoIntermedioGenerico("or", 2, nodoexp1, nodoexp2);
                                        $$.nodo = nodoOr;
                                        }

            | expresion NEQ expresion  {concat_ptr = temp;  
                                        concat_ptr += sprintf(concat_ptr, "(/= ");
                                        
                                        concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        
                                        $$.value = 1;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoNeq = crearNodoIntermedioGenerico("neq", 2, $1.nodo, $3.nodo);
                                        $$.nodo = nodoNeq;
                                        }

            | expresion EQ expresion   { concat_ptr = temp;  
                                         concat_ptr += sprintf(concat_ptr, "(== ");
                                        
                                         concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                         concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        
                                        $$.value = 1;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoEq = crearNodoIntermedioGenerico("eq", 2, $1.nodo, $3.nodo);
                                        $$.nodo = nodoEq;
                                        }

            | expresion '<' expresion  {concat_ptr = temp;   
                                        concat_ptr += sprintf(concat_ptr, "(< ");
                                        
                                        concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        
                                        $$.value = 1;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoLt = crearNodoIntermedioGenerico("lt", 2, $1.nodo, $3.nodo);
                                        $$.nodo = nodoLt;
                                        }

            | expresion LEQ expresion  { concat_ptr = temp;  
                                        concat_ptr += sprintf(concat_ptr, "(<= ");    

                                        concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        
                                        $$.value = 1;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoLeq = crearNodoIntermedioGenerico("leq", 2, $1.nodo, $3.nodo);
                                        $$.nodo = nodoLeq;
                                        }

            | expresion '>' expresion  {concat_ptr = temp;   
                                        concat_ptr += sprintf(concat_ptr, "(> ");
                                        
                                        concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        
                                        $$.value = 1;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoGt = crearNodoIntermedioGenerico("gt", 2, $1.nodo, $3.nodo);
                                        $$.nodo = nodoGt;
                                        }

            | expresion GEQ expresion  {concat_ptr = temp;    
                                        concat_ptr += sprintf(concat_ptr, "(>= ");
                                        
                                        concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        
                                        $$.value = 1;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoGeq = crearNodoIntermedioGenerico("geq", 2, $1.nodo, $3.nodo    );
                                        $$.nodo = nodoGeq;
                                        }

                       
            // Arithmetic expressions tranlsated to boolean expressions
            |   expresion '+' expresion  { concat_ptr = temp;
                                        concat_ptr += sprintf(concat_ptr, "(+ ");
                                        struct nodoAST* nodoexp1 = $1.nodo;
                                        struct nodoAST* nodoexp2 = $3.nodo;
                                        if ($1.value == 1){
                                            // Concat $1 transformed
                                            concat_ptr += sprintf(concat_ptr, "(if %s 1 0) ", $1.prefija);
                                            struct nodoAST* nodo_aric = node_to_aric(nodoexp1);
                                            nodoexp1 = nodo_aric;
                                        } else {
                                            // Concat $1 as is
                                            concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        }
                                        if ($3.value == 1){
                                            // Concat $3 transformed
                                            concat_ptr += sprintf(concat_ptr, "(if %s 1 0))", $3.prefija);
                                            struct nodoAST* nodo_aric = node_to_aric(nodoexp2);
                                            nodoexp2 = nodo_aric;
                                        } else {
                                            concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        }
                                        $$.value = 0;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoSuma = crearNodoIntermedioGenerico("suma", 2, nodoexp1, nodoexp2);
                                        $$.nodo = nodoSuma;
                                        }

            |   expresion '-' expresion  { concat_ptr = temp;
                                        concat_ptr += sprintf(concat_ptr, "(- ");
                                        struct nodoAST* nodoexp1 = $1.nodo;
                                        struct nodoAST* nodoexp2 = $3.nodo;
                                        if ($1.value == 1){
                                            // Concat $1 transformed
                                            concat_ptr += sprintf(concat_ptr, "(if %s 1 0) ", $1.prefija);
                                            struct nodoAST* nodo_aric = node_to_aric(nodoexp1);
                                            nodoexp1 = nodo_aric;
                                        } else {
                                            // Concat $1 as is
                                            concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        }
                                        if ($3.value == 1){
                                            // Concat $3 transformed
                                            concat_ptr += sprintf(concat_ptr, "(if %s 1 0))", $3.prefija);
                                            struct nodoAST* nodo_aric = node_to_aric(nodoexp2);
                                            nodoexp2 = nodo_aric;
                                        } else {
                                            concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        }
                                        $$.value = 0;
                                        $$.prefija = gen_code (temp) ; 
                                        // Nodo AST
                                        struct nodoAST* nodoResta = crearNodoIntermedioGenerico("resta", 2, nodoexp1, nodoexp2);
                                        $$.nodo = nodoResta;
                                        }

            |   expresion '*' expresion  { concat_ptr = temp;
                                        concat_ptr += sprintf(concat_ptr, "(* ");
                                        struct nodoAST* nodoexp1 = $1.nodo;
                                        struct nodoAST* nodoexp2 = $3.nodo;
                                        if ($1.value == 1){
                                            // Concat $1 transformed
                                            concat_ptr += sprintf(concat_ptr, "(if %s 1 0) ", $1.prefija);
                                            struct nodoAST* nodo_aric = node_to_aric(nodoexp1);
                                            nodoexp1 = nodo_aric;
                                        } else {
                                            // Concat $1 as is
                                            concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        }
                                        if ($3.value == 1){
                                            // Concat $3 transformed
                                            concat_ptr += sprintf(concat_ptr, "(if %s 1 0))", $3.prefija);
                                            struct nodoAST* nodo_aric = node_to_aric(nodoexp2);
                                            nodoexp2 = nodo_aric;
                                        } else {
                                            concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        }
                                        $$.value = 0;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoMult = crearNodoIntermedioGenerico("multiplicacion", 2, nodoexp1, nodoexp2);
                                        $$.nodo = nodoMult;
                                        }

            |   expresion '/' expresion  {concat_ptr = temp; 
                                        concat_ptr += sprintf(concat_ptr, "(/ ");
                                        struct nodoAST* nodoexp1 = $1.nodo;
                                        struct nodoAST* nodoexp2 = $3.nodo;
                                        if ($1.value == 1){
                                            // Concat $1 transformed
                                            concat_ptr += sprintf(concat_ptr, "(if %s 1 0) ", $1.prefija);
                                            struct nodoAST* nodo_aric = node_to_aric(nodoexp1);
                                            nodoexp1 = nodo_aric;
                                        } else {
                                            // Concat $1 as is
                                            concat_ptr += sprintf(concat_ptr, "%s ", $1.prefija);
                                        }
                                        if ($3.value == 1){
                                            // Concat $3 transformed
                                            concat_ptr += sprintf(concat_ptr, "(if %s 1 0))", $3.prefija);
                                            struct nodoAST* nodo_aric = node_to_aric(nodoexp2);
                                            nodoexp2 = nodo_aric;
                                        } else {
                                            concat_ptr += sprintf(concat_ptr, "%s )", $3.prefija);
                                        }
                                        $$.value = 0;
                                        $$.prefija = gen_code (temp) ; 

                                        // Nodo AST
                                        struct nodoAST* nodoDiv = crearNodoIntermedioGenerico("division", 2, nodoexp1, nodoexp2);
                                        $$.nodo = nodoDiv;
                                        }
            ;

termino:      operando                           { $$ = $1 ; }
            | '+' operando %prec UNARY_SIGN    { 
                                                    $$.value = $2.value ; 
                                                    // Para AST
                                                    struct nodoAST* nodoSigno = crearNodoSigno("+", $2.value);
                                                    struct nodoAST* nuevoNodo = crearNodoIntermedioGenerico("signo-unario", 2, nodoSigno, $2.nodo);
                                                    $$.nodo = nuevoNodo;
                                                    // Para notacion prefija
                                                    sprintf (temp, "(+ %s)", $2.prefija);
                                                    $$.prefija = gen_code(temp);
                                                }
            | '-' operando %prec UNARY_SIGN    { 
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

operando:    IDENTIF                    {    
                                             $$.value = $1.value ;
                                             // Para AST
                                             $$.nodo = crearNodoVariable($1.code, $1.value, "int");
                                             // Para notacion prefija
                                             sprintf (temp, "%s", $1.code);
                                             $$.prefija = gen_code(temp);
                                        }
            | NUMBER                     { 
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

struct nodoAST* node_to_bool(struct nodoAST* nodo){
    struct nodoAST* nodo_bool = crearNodoIntermedioGenerico("neq", 2, nodo, crearNodoNumero(0));
    return nodo_bool;
}

struct nodoAST* node_to_aric(struct nodoAST* nodo){   
    struct nodoAST* nodo_aric = crearNodoIntermedioGenerico("aric-if", 3, nodo, crearNodoNumero(1), crearNodoNumero(0));
    return nodo_aric;
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