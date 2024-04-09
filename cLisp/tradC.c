#include "tradC.h"


char* FILENAME = "cLisp/trad.txt";
char temp [2048];


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
            
        } else if (strcmp(node->nombre, "if") == 0){
            writeFile("(if ");

            recursiveAstToLisp(node->primer_nodo); //nodo condicion

            writeFile(" (\n");
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

        } else if (strcmp(node->nombre, "else") == 0){
            writeFile("(\n");
            node = node->primer_nodo;
            recursiveAstToLisp(node);
            while (node->siguiente_hermano != NULL)
            {
                recursiveAstToLisp(node->siguiente_hermano);
                node = node->siguiente_hermano;
            }
            writeFile(")\n");

        } else if (strcmp(node->nombre, "while") == 0){
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

        } else { 
            printf("Error: unknown node type %s\n", node->nombre);
        }
        break;

    case NODO_FUNCION:
        writeFile("(defun ");
        writeFile(node->nombre);
        writeFile(" (");
        //TODO: PRINT ARGS
        writeFile(") (\n");
        node = node -> primer_nodo;
        recursiveAstToLisp(node);
        while (node->siguiente_hermano != NULL)
            {
                recursiveAstToLisp(node->siguiente_hermano);
                node = node->siguiente_hermano;
            }

        writeFile(")\n");
        break;

    case NODO_HOJA_FUNCION:
        writeFile(node -> nombre);
        break;

    case NODO_HOJA_VARIABLE_INIT:
        writeFile("(setq ");
        writeFile(node->nombre);
        writeFile(" ");
        //TODO: check type and print arrays
        sprintf(temp, "%d", node->valor);
        writeFile(temp);
        writeFile(")\n");
        break;

    case NODO_HOJA_VARIABLE:
        writeFile(node->nombre);
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


