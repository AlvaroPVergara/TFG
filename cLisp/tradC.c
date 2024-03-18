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
            
            break;
        } else if (strcmp(node->nombre, "asignacion") == 0){
            break;
        } else if (strcmp(node->nombre, "axioma") == 0){
            
        } else if (strcmp(node->nombre, "axioma") == 0){
            
        } else if (strcmp(node->nombre, "axioma") == 0){
            
        } else if (strcmp(node->nombre, "axioma") == 0){
            
        } else if (strcmp(node->nombre, "axioma") == 0){
            
        } else { //Funciones
            writeFile("(defun ");
            writeFile(node->nombre);
            writeFile(" (");
            //TODO: PRINT ARGS
            writeFile(") (\n");
            recursiveAstToLisp(node->primer_nodo);
            writeFile(")\n");
        }
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


