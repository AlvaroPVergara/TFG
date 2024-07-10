#include "tradC.h"


char* FILENAME = "cLisp/trad.lisp";
char temp [2048];
int local_var_counter = 0;


void cleanFile() {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fclose(file);
}

void writeFile(const char* text) {
    FILE* file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%s", text);
    fclose(file);
}

void recursiveAstToLisp(struct nodoAST* node){
    if (node == NULL) {
        return;
    }
    switch (node->tipo)
    {
    case NODO_INTERMEDIO:
        if (strcmp(node->nombre, "axioma") == 0){
            node = node->primer_nodo;
            recursiveAstToLisp(node);
            while (node->siguiente_hermano != NULL)
            {
                recursiveAstToLisp(node->siguiente_hermano);
                node = node->siguiente_hermano;
            }
            
        } else if (strcmp(node->nombre, "asignacion") == 0){
            writeFile("(setq ");
            writeFile(node->primer_nodo->nombre);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")\n");

        } else if (strcmp(node->nombre, "asignacion-vect") == 0){
            writeFile("(setf (aref ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(") ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano->siguiente_hermano);
            writeFile(")\n");

        } else if (strcmp(node->nombre, "index") == 0){
            recursiveAstToLisp(node->primer_nodo);

        } else if (strcmp(node->nombre, "return") == 0){
            writeFile("(return-from ");
            writeFile(node->primer_nodo->nombre);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")\n");
        
        } else if (strcmp(node->nombre, "last-return") == 0){
            writeFile(node->primer_nodo->nombre);
            writeFile("\n");
            
        } else if (strcmp(node->nombre, "llamada-funcion") == 0){
            writeFile("(");
            writeFile(node->primer_nodo->nombre);
            if (node->primer_nodo->siguiente_hermano->primer_nodo){
                node = node->primer_nodo->siguiente_hermano->primer_nodo;
                writeFile(" ");
                recursiveAstToLisp(node);
            }
            while (node->siguiente_hermano != NULL)
            {   
                writeFile(" ");
                recursiveAstToLisp(node->siguiente_hermano);
                node = node->siguiente_hermano;
            }
            writeFile(")\n");
            
        } else if (strcmp(node->nombre, "argumentos") == 0){
            node = node-> primer_nodo;
            if (node == NULL) return;
            while (node != NULL)
            {   
                writeFile(node->nombre);
                if (node->siguiente_hermano != NULL) {
                    writeFile(" ");
                }
                node = node->siguiente_hermano;
            }

            
        }else if (strcmp(node->nombre, "if") == 0){
            writeFile("(if ");

            recursiveAstToLisp(node->primer_nodo); //nodo condicion

            writeFile(" (progn\n");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano); //nodo statements

            writeFile(")\n");

        } else if (strcmp(node->nombre, "condicion") == 0){
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");

        } else if (strcmp(node->nombre, "statements") == 0){
            node = node->primer_nodo;
            if (node == NULL) return;
            recursiveAstToLisp(node);
            while (node->siguiente_hermano != NULL)
            {
                recursiveAstToLisp(node->siguiente_hermano);
                node = node->siguiente_hermano;
            }

        } else if (strcmp(node->nombre, "else") == 0){ //TODO: FIX ELSE
            writeFile("(progn\n");
            node = node->primer_nodo;
            recursiveAstToLisp(node);
            while (node->siguiente_hermano != NULL)
            {
                recursiveAstToLisp(node->siguiente_hermano);
                node = node->siguiente_hermano;
            }
            writeFile("))\n");

        }  else if (strcmp(node->nombre, "aric-if") == 0){
            writeFile("(if ");

            recursiveAstToLisp(node->primer_nodo); //nodo condicion
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano); //nodo 1
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano->siguiente_hermano); //nodo 0

            writeFile(")");

        }else if (strcmp(node->nombre, "while") == 0){
            writeFile("(loop while ");
            recursiveAstToLisp(node->primer_nodo); //nodo condicion
            writeFile(" do \n");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano); //nodo statements
            writeFile(")\n");

        } else if (strcmp(node->nombre, "for") == 0){
            writeFile("(let ");
            recursiveAstToLisp(node->primer_nodo); //nodo declaracion (for-init)
            node = node->primer_nodo->siguiente_hermano;
            writeFile(")\n");
            writeFile("(loop while ");
            recursiveAstToLisp(node); //nodo condicion
            node = node->siguiente_hermano;
            writeFile(" do \n");
            recursiveAstToLisp(node); //nodo statements
            node = node->siguiente_hermano;
            recursiveAstToLisp(node); //nodo incremento
            writeFile(")\n");

        } else if (strcmp(node->nombre, "for-init") == 0){
            recursiveAstToLisp(node->primer_nodo); 

        } else if (strcmp(node->nombre, "incremento") == 0){
            recursiveAstToLisp(node->primer_nodo); 

        } else if (strcmp(node->nombre, "and") == 0){
            writeFile("(and ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "or") == 0){
            writeFile("(or ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "neq") == 0){
            writeFile("(/= ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "eq") == 0){
            writeFile("(= ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "lt") == 0){
            writeFile("(< ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "leq") == 0){
            writeFile("(<= ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "gt") == 0){
            writeFile("(> ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "geq") == 0){
            writeFile("(>= ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "suma") == 0){
            writeFile("(+ ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "resta") == 0){
            writeFile("(- ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "multiplicacion") == 0){
            writeFile("(* ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "division") == 0){
            writeFile("(/ ");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(" ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano);
            writeFile(")");
            
        } else if (strcmp(node->nombre, "puts") == 0) {
            writeFile("(print \"");
            writeFile(node->primer_nodo->nombre);
            writeFile("\")\n");

        } else if (strcmp(node->nombre, "suma-elementos") == 0) {
            // We traduce our created function to understandable lisp

            // We set the value of variable to 0 in case it has a previous value
            writeFile("(setq ");
            writeFile(node->primer_nodo->nombre); // result variable name
            writeFile(" 0)\n");

            // Loop for each element in the vector
            writeFile("(dotimes (i (length ");
            recursiveAstToLisp(node-> primer_nodo->siguiente_hermano); // vector 
            writeFile(") ");
            writeFile(node->primer_nodo->nombre); // result variable name
            writeFile(")\n");

            // Add each element to the result variable
            writeFile("(incf ");
            writeFile(node->primer_nodo->nombre); // result variable name
            writeFile(" (aref ");
            recursiveAstToLisp(node-> primer_nodo->siguiente_hermano); // vector name
            writeFile(" i)))\n");

        } else if (strcmp(node->nombre, "producto-escalar") == 0) {
            // We traduce our created function to understandable lisp
            // Firstly, we don´t need to check the length of the vectors, because we have already done it in the semantic analysis

            writeFile("(setq ");
            writeFile(node->primer_nodo->nombre); // result variable name
            writeFile(" (reduce #'+ (map 'list #'* ");
            recursiveAstToLisp(node-> primer_nodo->siguiente_hermano); // vector 1
            writeFile(" ");
            recursiveAstToLisp(node-> primer_nodo->siguiente_hermano->siguiente_hermano); // vector 2
            writeFile(")))\n");

        } else if (strcmp(node->nombre, "invertir-vector") == 0) {
            // We traduce our created function to understandable lisp

            writeFile("(coerce (reverse (coerce ");
            recursiveAstToLisp(node->primer_nodo); // vector name
            writeFile(" 'list)) 'vector)\n");

        } else if (strcmp(node->nombre, "suma-vector") == 0) {
            // We traduce our created function to understandable lisp
            writeFile("(dotimes (i (length ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano); // vector name
            writeFile("))\n");
            writeFile("(setf (aref ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano); // vector name
            writeFile(" i) (+ (aref ");
            recursiveAstToLisp(node->primer_nodo->siguiente_hermano); // vector name
            writeFile(" i) ");
            recursiveAstToLisp(node->primer_nodo); // value to add
            writeFile(")))\n");
                

        } else { 
            printf("Error: unknown node type %s\n", node->nombre);
        }
        break;

    case NODO_FUNCION:
        {
            int isMain;
            isMain = strcmp(node->nombre, "main") == 0;
            writeFile("(defun ");
            writeFile(node->nombre);
            writeFile(" (");
            node = node -> primer_nodo;
            recursiveAstToLisp(node);
            writeFile(") \n");
            node = node -> siguiente_hermano;
            recursiveAstToLisp(node);
            while (node->siguiente_hermano != NULL)
            {
                recursiveAstToLisp(node->siguiente_hermano);
                node = node->siguiente_hermano;
            }
            for (int i = 0; i < local_var_counter; i++)
            {
                writeFile(")");
            }
            local_var_counter = 0;
            writeFile(")\n");
            if (isMain) {
                writeFile("(main)\n");
            }
        }
        break;

    case NODO_HOJA_FUNCION:
        writeFile(node -> nombre);
        break;

    case NODO_HOJA_VARIABLE_INIT:
        if (strcmp(node -> tipo_variable, "global-vector") == 0 || strcmp(node -> tipo_variable, "global-int") == 0){
            writeFile("(defvar ");
        } else {
            writeFile("(let ((");
            local_var_counter++;
        }
        if (strcmp(node -> tipo_variable, "global-vector") == 0){
            writeFile("*");
        }

        writeFile(node->nombre);

        if (strcmp(node -> tipo_variable, "global-vector") == 0){
            writeFile("*");
        }

        writeFile(" ");
        if (strcmp(node -> tipo_variable, "vector") == 0 || strcmp(node -> tipo_variable, "global-vector") == 0){
            writeFile("(make-array ");
        }
        sprintf(temp, "%d", node->valor);
        writeFile(temp);

        if ((strcmp(node -> tipo_variable, "vector") == 0) || strcmp(node -> tipo_variable, "global-vector") == 0){
            writeFile(")");
        }
        if (strcmp(node -> tipo_variable, "global-vector") != 0 && strcmp(node -> tipo_variable, "global-int") != 0){
            writeFile(")");
        }

        writeFile(")\n");
        break;

    case NODO_HOJA_VARIABLE:

        if (strcmp(node -> tipo_variable, "global-vector") == 0){
            writeFile("*");
        }
        writeFile(node->nombre);
        
        if (strcmp(node -> tipo_variable, "global-vector") == 0){
            writeFile("*");
        }
        break;

    case NODO_HOJA_NUMERO:
        sprintf(temp, "%d", node->valor);
        writeFile(temp);
        break;

    case NODO_HOJA_SIGNO:
        writeFile(node->nombre);
        break;
    
    case NODO_STRING:
        writeFile(node -> nombre);
        break;

    default:
        break;
    }


}


void astToLisp(struct nodoAST* node) {
    cleanFile();
    if (node == NULL) {
        return;
    }
    recursiveAstToLisp(node);
}


