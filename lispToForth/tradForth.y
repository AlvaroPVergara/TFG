  %{                      // SECCION 1 
#include "lispToForth/tradForth.h"


int yylex () ;
int yyerror (char* mensaje) ; 
char *gen_code (char *) ;
char *my_malloc (int nbytes) ;



char temp [2048] ;
char *concat_ptr;

char *act_function = "";
Symbol **tabla = NULL;
Symbol* sym = NULL;
int long_variable = 0;


typedef struct s_attr {
     int value ;       //  - valor numerico entero 
     int type ;        //  - tipo de dato
     char* trad;       //  - traduccion a Forth
     char* code ;    
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
%token MAP
%token LIST
%token COERCE
%token REVERSE



%left '+' '-'
%left '*' '/'
%left AND OR
%left '=' '<' '>' LEQ GEQ NEQ

%%

                        // SECCION 3: Gramatica - Semantico 


axioma: instrucciones                             {
                                                    writeFile($1.trad); 
                                                    destroySymbolTable(tabla);
                                                  } 
        ;

instrucciones:                                    { $$.trad = ""; } // lambda
                | sentencia instrucciones         { sprintf(temp, "%s%s", $1.trad, $2.trad); 
                                                    $$.trad = gen_code(temp);                 
                                                    } 
            ;


sentencia:   '(' definicion ')'                 { $$=$2; } 
            | '(' asignacion ')'                { $$=$2; }
            | '(' condicion                     { $$=$2; } 
            | '(' bucle ')'                     { $$=$2; }
            | '(' llamada ')'                   { $$=$2; }
            | '(' deffuncion                    { $$=$2; }
            | '(' print ')'                     { $$=$2; }
            | '(' returnfrom ')'                { $$=$2; }
            | '(' incf ')'                      { $$=$2; }
            | variable                          { sprintf(temp, "%s\n", $1.code); 
                                                    $$.trad = gen_code(temp); 
                                                }
            ;

// FUNCIONES
deffuncion: DEFUN IDENTIF                       { act_function = $2.code; }
            '(' argumentosfun ')' instrucciones ')' 
                                                {                
                                                if ($5.code){
                                                sprintf(temp, ": %s ( %s -- n )\nLOCALS| %s |\n%s;\n", $2.code, $5.trad, $5.code ,$7.trad);
                                                $$.trad = gen_code(temp);
                                                act_function = "";
                                                }
                                                else{
                                                sprintf(temp, ": %s ( -- n )\n%s;\n", $2.code ,$7.trad);
                                                $$.trad = gen_code(temp);
                                                act_function = "";
                                                }          
                                                
                                                }

            ;

argumentosfun:                                  { $$.trad =NULL; 
                                                $$.code =NULL;} // lambda
                | variable argumentosfun        { 
                                                if ($2.trad){
                                                    sprintf(temp, "%s_ %s_", $1.code, $2.trad); 
                                                }
                                                else{
                                                    sprintf(temp, "%s", $1.code); 
                                                }
                                                $$.trad = gen_code(temp); 
                                                if ($2.code){
                                                    sprintf(temp, "%s %s", $2.code, $1.code); 
                                                } else {
                                                    sprintf(temp, "%s", $1.code); 
                                                }
                                                
                                                $$.code = gen_code(temp); ;
                                                }
                ;


// RETURN
returnfrom: RETURN '-' FROM IDENTIF expresion  { 
                                                sprintf(temp, "%s\nEXIT\n", $5.trad);
                                                $$.trad = gen_code(temp);
                                                }
            ;


// DEFINICIONES
definicion: DEFVAR variable restodef                    { 
                                                        if (tabla == NULL){
                                                            tabla = initSymbolTable();
                                                        }
                                                        if ($3.type == 0) { // INT CASE
                                                        insertSymbol(tabla, $2.code, "global", 0, 0);
                                                        sprintf(temp, "VARIABLE %s\n%d %s !\n", $2.code, $3.value, $2.code);
                                                        $$.trad = gen_code(temp);      

                                                        }
                                                        else { // VECTOR CASE
                                                        insertSymbol(tabla, $2.code, "global", $3.value, 0);
                                                        sprintf(temp, "CREATE %s %d CELLS ALLOT\n: init-vector ( -- )\n%s %d 0 DO\n0 over I CELLS + !\nLOOP\n DROP ;\ninit-vector\n", $2.code, $3.value, $2.code, $3.value);
                                                        $$.trad = gen_code(temp);
                                                        }
                                                        
                                                    }
            |  LET '(' '(' variable restodef ')' ')'
                                                    { if ($5.type == 0) { // INT CASE
                                                            insertSymbol(tabla, $4.code, "local", 0, 0);
                                                        }
                                                        else { // VECTOR CASE
                                                            insertSymbol(tabla, $4.code, "local", $5.value, 0);
                                                        }
                                                    }
            instrucciones                           {   
                                                        if ($5.type == 0) { // INT CASE
                                                        sprintf(temp, "%d LOCALS| %s |\n%s", $5.value, $4.code,  $9.trad);
                                                        $$.trad = gen_code(temp);
                                                        
                                                        }
                                                        else { // VECTOR CASE
                                                        sprintf(temp, "CREATE %s %d ALLOT\n: inicializar-%s ( -- )\n\t%s %d CELLS 0 DO\n i %s +!\nLOOP ;\ninicializar-%s\n%s", 
                                                        $4.code, $5.value, $4.code, $4.code, $5.value, $4.code, $4.code, $9.trad);
                                                        $$.trad = gen_code(temp);
                                                        }

                                                    }
            ;
        
restodef:   expresion                                { $$.type = 0; 
                                                       $$.value = $1.value; 
                                                     }
            | '(' MAKE '-' ARRAY expresion ')'       { $$.type = 1; 
                                                      $$.value = $5.value; 
                                                     }   
            ;

// ASIGNACIONES
asignacion:   SETQ variable expresion                           { 
                                                                sym = searchSymbol(tabla, $2.code);
                                                                if (sym == NULL) {
                                                                    yyerror("Variable no declarada");
                                                                } else if (strcmp(sym->type, "global")== 0){
                                                                    sprintf(temp, "%s %s !\n", $3.trad, $2.code); 

                                                                } else if (strcmp(sym->type, "local")== 0){
                                                                    sprintf(temp, "%s to %s\n", $3.trad, $2.code);

                                                                }

                                                                $$.trad = gen_code(temp);
                                                                }
            | SETQ variable '(' invertir ')'                    { 
                                                                $$ = $4;                      
                                                                }
            | SETQ variable '(' condicion                       { 
                                                                sprintf(temp, "%s %s !\n", $4.trad, $2.code); 
                                                                $$.trad = gen_code(temp);
                                                                }         
            | SETF '(' AREF variable expresion ')' expresion    { 
                                                                if (strcmp($7.code, "variable") == 0){
                                                                    sym = searchSymbol(tabla, $7.trad);
                                                                    if (sym != NULL){
                                                                        if (strcmp(sym->type, "global")== 0){
                                                                           sprintf(temp, "%s @ %s CELLS %s + !\n", $7.trad, $5.trad, $4.code);
                                                                        } else{
                                                                            sprintf(temp, "%s %s CELLS %s + !\n", $7.trad, $5.trad, $4.code);
                                                                        }
                                                                    }
                                                                } else {
                                                                    sprintf(temp, "%s %s CELLS %s + !\n", $7.trad, $5.trad, $4.code);
                                                                }
                                                                $$.trad = gen_code(temp);
                                                                }   
            // PRODUCTO ESCALAR
            | SETQ variable '(' REDUCE '#' '\'' '+' '(' 
            MAP '\'' LIST '#' '\'' '*' variable variable ')' ')' { 
                                                                sym = searchSymbol(tabla, $2.code);
                                                                if (sym == NULL) {
                                                                    yyerror("Variable no declarada");
                                                                } else if (strcmp(sym->type, "global")== 0){
                                                                    sym = searchSymbol(tabla, $15.code);
                                                                    if (sym == NULL) {
                                                                        yyerror("Variable no declarada");
                                                                    } else{
                                                                        sprintf(temp,"%d 0 DO\nI CELLS %s + @\nI CELLS %s + @\n*\n %s @ + %s !\nLOOP\n", 
                                                                        sym -> size_array, $15.code, $16.code, $2.code, $2.code);
                                                                    }
                                                    
                                                                } else if (strcmp(sym->type, "local")== 0){
                                                                    sym = searchSymbol(tabla, $15.code);
                                                                    if (sym == NULL) {
                                                                        yyerror("Variable no declarada");
                                                                    } else{
                                                                        sprintf(temp,"%d 0 DO\nI CELLS %s + @\nI CELLS %s + @\n*\n %s + to %s\nLOOP\n", 
                                                                        sym -> size_array, $15.code, $16.code, $2.code, $2.code);
                                                                    }
                                                                }
                                                                $$.trad = gen_code(temp);
                                                                }
            ;

// CONDICIONALES
condicion: IF  expresion '(' PROGN   
            instrucciones ')' restoif                 { 
                                                        sprintf(temp, "%s IF\n%s%sTHEN\n", $2.trad, $5.trad, $7.trad);
                                                        $$.trad = gen_code(temp);
                                                    }
            ;

restoif:    ')'                                     { $$.trad=""; }
            | '(' PROGN  instrucciones ')' ')'      {  
                                                    sprintf(temp, "ELSE\n%s", $3.trad);
                                                    $$.trad = gen_code(temp);
                                                    }
            ;

// BUCLES
bucle:   LOOP WHILE  expresion  DO instrucciones  { 
                                                        sprintf(temp, "BEGIN\n%s WHILE\n%sREPEAT\n", $3.trad, $5.trad);   
                                                        $$.trad = gen_code(temp); 
                                                        }
        | DOTIMES '(' variable '(' LENGTH variable')' variable ')'
         instrucciones                            { 
                                                    sym = searchSymbol(tabla, $6.code);
                                                    long_variable = sym -> size_array;
                                                    sprintf(temp, "%d 0 DO\n%sLOOP\n", long_variable, $10.trad);
                                                    $$.trad = gen_code(temp); 

                                                  }
        | DOTIMES '(' variable '(' LENGTH variable')' ')'
         instrucciones                            { 
                                                    sym = searchSymbol(tabla, $6.code);
                                                    long_variable = sym -> size_array;
                                                    sprintf(temp, "%d 0 DO\n%sLOOP\n", long_variable, $9.trad);
                                                    $$.trad = gen_code(temp); 

                                                  }



// LLAMADAS FUNCIONES
llamada:    IDENTIF argumentos               { 
                                                 sprintf(temp, "%s%s\n", $2.trad, $1.code);
                                                 $$.trad = gen_code(temp);
                                                 }
            ;


argumentos:                                      { $$.trad = ""; } // lambda
            | expresion argumentos               { 
                                                    if (strcmp($1.code, "variable") == 0){
                                                        sprintf(temp, "%s @\n%s", $1.trad, $2.trad); 
                                                    }
                                                    else{
                                                        sprintf(temp, "%s\n%s", $1.trad, $2.trad); 
                                                    }
                                                    $$.trad = gen_code(temp); 
                                                }
            ;

// PRINT
print: PRINT restoprint                        { $$ = $2; }
        ;

restoprint: STRING                             {
                                                sprintf(temp, "S\" %s \" TYPE CR\n", $1.code);
                                                $$.trad = gen_code(temp);
                                                }
            | expresion                         { 
                                                if (strcmp($1.code, "variable") == 0){
                                                    sym = searchSymbol(tabla, $1.trad);
                                                    if (sym == NULL) {
                                                        yyerror("Variable no declarada");
                                                        sprintf(temp, "%s @ . CR\n", $1.trad);
                                                    } else if (strcmp(sym->type, "global")== 0){
                                                        if (sym -> size_array == 0){
                                                            sprintf(temp, "%s @ . CR\n", $1.trad);
                                                        } else {
                                                            sprintf(temp, "S\" (\" TYPE\n %d 0 DO\nI CELLS %s + @ .\nLOOP\nS\" )\" TYPE CR\n", sym -> size_array, $1.trad);
                                                        }
                                                    } else if (strcmp(sym->type, "local")== 0){
                                                        sprintf(temp, "%s . CR\n", $1.trad);
                                                    }

                                                }
                                                else{
                                                    sprintf(temp, "%s . CR\n", $1.trad);
                                                }
                                                $$.trad = gen_code(temp);
                                                }
            ;

// INCREMENTO
incf: INCF  variable '(' AREF variable expresion ')' { 
                                                    sym = searchSymbol(tabla, $2.code);
                                                    if (sym == NULL) {
                                                        yyerror("Variable no declarada");
                                                    } else if (strcmp(sym->type, "global")== 0){
                                                        sprintf(temp, "i CELLS %s + @\n%s + %s !\n", $5.code, $2.code, $2.code );
                                                    } else if (strcmp(sym->type, "local")== 0){
                                                        sprintf(temp, "i CELLS %s + @\n%s + to %s\n", $5.code, $2.code, $2.code );
                                                    }
                                                    $$.trad = gen_code(temp);
                                                    }
    ;


// INVERTIR VECTOR
invertir: COERCE '(' REVERSE '(' COERCE variable '\'' LIST ')' ')' '\'' variable { 
                                                    sym = searchSymbol(tabla, $6.code);
                                                    if (sym == NULL) {
                                                        yyerror("Variable no declarada");
                                                        sprintf(temp, "\n");
                                                    } else {
                                                        sprintf(temp,"%d 2 / 0 DO\nI CELLS %s + @\n %d 1 - I - CELLS %s + @\nI CELLS %s + !\n%d 1 - I - CELLS %s + !\nLOOP\n",
                                                        sym -> size_array, $6.code, sym -> size_array, $6.code, $6.code, sym -> size_array, $6.code);
                                                    }
                                                    $$.trad = gen_code(temp);
                                                    }
            ;


// OPERACIONES

expresion:          operando                     { $$=$1; }
                |   '(' '+' expresion expresion ')' { 
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $3.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $4.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "+");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";

                                                 }
                |   '(' '-' expresion expresion ')' { 
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $3.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $4.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "-");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                 }
                |   '(' '*' expresion expresion  ')' {  
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $3.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $4.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "*");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                 }
                |  '(' '/' expresion expresion ')' {  
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $3.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $4.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "/");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                 }
                | '(' AND expresion expresion  ')' {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "AND");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                }   
                | '(' OR expresion expresion ')'  {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "OR");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                               
                                                }
                | '(' '=' expresion expresion ')' {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "=");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                }
                | '(' '<' expresion expresion ')' {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "<");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";

                                                }
                | '(' '>' expresion expresion ')' {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $3.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        sym = searchSymbol(tabla, $4.trad);
                                                        if (sym != NULL){
                                                            if (strcmp(sym->type, "global")== 0){
                                                                concat_ptr += sprintf(concat_ptr, "@ ");
                                                            }
                                                        }
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, ">");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                }
                | '(' LEQ expresion expresion ')' {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "<=");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                }
                | '(' GEQ expresion expresion ')' { 
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, ">=");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                }
                | '(' NEQ expresion expresion ')' {
                                                    concat_ptr = temp;
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $3.trad);
                                                    if (strcmp($3.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "%s ", $4.trad);
                                                    if (strcmp($4.code, "variable") == 0){
                                                        concat_ptr += sprintf(concat_ptr, "@ ");
                                                    }
                                                    concat_ptr += sprintf(concat_ptr, "/=");
                                                    $$.trad = gen_code(temp);
                                                    $$.code = "oper";
                                                }
                ;

operando:       NUMBER                          { sprintf(temp, "%d", $1.value);
                                                $$.trad = gen_code(temp);
                                                $$.value = $1.value; 
                                                $$.code = "number";
                                                }
                | variable                      { 

                                                sprintf(temp, "%s", $1.code);
                                                $$.trad = gen_code(temp);
                                                $$.code = "variable";
                                                }
                | '(' AREF variable expresion ')' { 
                                                sprintf(temp, "%s CELLS %s + @", $4.trad, $3.code);
                                                $$.trad = gen_code(temp);
                                                $$.code = "variable";
                                                }
                ;

variable:        IDENTIF                        { $$.code = $1.code; }
                | '*' IDENTIF '*'               { $$.code = $2.code; }
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
    {"setq", SETQ}, {"setf", SETF}, {"aref", AREF}, {"return", RETURN}, {"from", FROM},
    {"while", WHILE}, {"loop", LOOP}, {"if", IF}, {"do", DO}, {"defvar", DEFVAR}, 
    {"make", MAKE}, {"array", ARRAY}, {"progn", PROGN}, {"defun", DEFUN},
    {"and", AND}, {"or", OR}, {"<=", LEQ}, {">=", GEQ}, {"/=", NEQ}, {"let", LET}, {"print", PRINT}, 
    {"dotimes", DOTIMES}, {"coerce", COERCE}, {"reverse", REVERSE},
    {"length", LENGTH}, {"incf", INCF}, {"reduce",REDUCE}, {"map", MAP}, {"list", LIST},
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
    char expandable_ops [] = "!<=>|%/&+-*#\'" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;


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
    cleanFile(); // limpia el archivo de salida
    yyparse () ;
}   