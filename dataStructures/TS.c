#include "TS.h"

// Función hash simple para generar el índice
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

// Inicializa la tabla de símbolos
Symbol* createSymbol(const char *name, const char *type, int size_array, int array_pos) {
    Symbol *newSymbol = (Symbol*)malloc(sizeof(Symbol));
    newSymbol->name = strdup(name);
    newSymbol->type = strdup(type);
    newSymbol->size_array = size_array;
    newSymbol->array_pos = array_pos;
    return newSymbol;
}

// Inserta un símbolo en la tabla
void insertSymbol(Symbol **symTable, const char *name, const char *type, int size_array, int array_pos) {
    unsigned int index = hash(name);
    
    // Verifica si el índice está ocupado
    if (symTable[index] == NULL) {
        // Espacio libre, crea un nuevo símbolo
        symTable[index] = createSymbol(name, type, size_array, array_pos);
    } else {
        // TODO: Manejar colisiones
        printf("Colisión al insertar el símbolo '%s'.\n", name);
    }
}

// Busca un símbolo en la tabla
Symbol* searchSymbol(Symbol **symTable, const char *name) {
    unsigned int index = hash(name);
    Symbol *symbol = symTable[index];

    // Verifica si el símbolo está presente y tiene el mismo nombre
    if (symbol != NULL && strcmp(symbol->name, name) == 0) {
        return symbol;
    } else {
        // Puedes manejar colisiones o simplemente devolver NULL
        return NULL;
    }
}

// Libera la memoria de la tabla de símbolos
void destroySymbol(Symbol *symbol) {
    free(symbol->name);
    free(symbol->type);
    free(symbol);
}

// Libera la memoria de la tabla de símbolos
void destroySymbolTable(Symbol **symTable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (symTable[i] != NULL) {
            destroySymbol(symTable[i]);
        }
    }
    free(symTable);
}

Symbol** initSymbolTable() {
    Symbol **symTable = (Symbol**)calloc(TABLE_SIZE, sizeof(Symbol*));
    return symTable;
}



// Función para realizar el análisis semántico
void semanticAnalysis(struct nodoAST* raiz, Symbol **symTable) {

    // Recorre el árbol AST para realizar el análisis semántico
    if (raiz != NULL) {
        // Verifica si el nodo actual es una hoja
        if (raiz->tipo == NODO_HOJA_VARIABLE_INIT) {
            // Inserta el símbolo en la tabla de símbolos
            Symbol *foundSymbol = searchSymbol(symTable, raiz->nombre);
            if (foundSymbol != NULL) {
                printf("Símbolo '%s' ya existe en la tabla.\n", raiz->nombre);
                //TODO: RAISE ERROR
            } else {
                if (strcmp(raiz->tipo_variable, "int") == 0 || strcmp(raiz->tipo_variable, "global-int") == 0){
                    insertSymbol(symTable, raiz->nombre, raiz->tipo_variable, 0, 0);
                } else if (strcmp(raiz->tipo_variable, "vector") == 0 || strcmp(raiz->tipo_variable, "global-vector") == 0){
                    insertSymbol(symTable, raiz->nombre, raiz->tipo_variable, raiz->valor, 0);
                } else {
                    printf("Tipo de variable '%s' no válido.\n", raiz->nombre);
                }
                printf("Símbolo '%s' insertado en la tabla.\n", raiz->nombre);
            }
        } 

        else if (raiz->tipo == NODO_HOJA_VARIABLE) {
            // Busca el símbolo en la tabla de símbolos
            Symbol *foundSymbol = searchSymbol(symTable, raiz->nombre);
            if (foundSymbol != NULL) {
                printf("Símbolo '%s' encontrado en la tabla. Tipo: %s, Tamaño del vector: %d, Offset: %d\n", raiz->nombre, foundSymbol->type, foundSymbol->size_array, foundSymbol->array_pos);
                // Actualiza el tipo de variable en el árbol AST
                if (strcmp(foundSymbol->type, "global-int") == 0 && strcmp(raiz->tipo_variable, "int") == 0){
                    raiz->tipo_variable = "global-int";
                    printf("Tipo de variable '%s' actualizado a '%s'.\n", raiz->nombre, raiz->tipo_variable);
                } else if (strcmp(foundSymbol->type, "global-vector") == 0 && strcmp(raiz->tipo_variable, "global-int") != 0){
                    raiz->tipo_variable = "global-vector";
                    printf("Tipo de variable '%s' actualizado a '%s'.\n", raiz->nombre, raiz->tipo_variable);
                }
            } else {
                printf("Símbolo '%s' no encontrado en la tabla.\n", raiz->nombre);
                // TODO: RAISE ERROR
            }
        }

        // Recorre los nodos hijos
        struct nodoAST* temp = raiz->primer_nodo;
        while (temp != NULL) {
            semanticAnalysis(temp, symTable);
            temp = temp->siguiente_hermano;
        }
    }    
    return;
}