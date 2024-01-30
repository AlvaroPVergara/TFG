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
Symbol* createSymbol(const char *name, const char *type, void *memory_address, int size, int size_array, int offset) {
    Symbol *newSymbol = (Symbol*)malloc(sizeof(Symbol));
    newSymbol->name = strdup(name);
    newSymbol->type = strdup(type);
    newSymbol->memory_address = memory_address;
    newSymbol->size = size;
    newSymbol->size_array = size_array;
    newSymbol->offset = offset;
    return newSymbol;
}

// Inserta un símbolo en la tabla
void insertSymbol(Symbol **symTable, const char *name, const char *type, void *memory_address, int size, int size_array, int offset) {
    unsigned int index = hash(name);
    
    // Verifica si el índice está ocupado
    if (symTable[index] == NULL) {
        // Espacio libre, crea un nuevo símbolo
        symTable[index] = createSymbol(name, type, memory_address, size, size_array, offset);
    } else {
        // Maneja colisiones (puedes usar estrategias más avanzadas)
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

int inizializeTS() {
    Symbol **symTable = (Symbol**)calloc(TABLE_SIZE * sizeof(Symbol*));

    /*
    // Direcciones de memoria de las variables
    void *var1_address = malloc(sizeof(int));
    void *var2_address = malloc(sizeof(double));

    // Inser    ta algunos símbolos de ejemplo con direcciones de memoria
    insertSymbol(symTable, "variable1", "int", var1_address, sizeof(int), 0, 0);
    insertSymbol(symTable, "variable2", "double", var2_address, sizeof(double), 0, 0);
    insertSymbol(symTable, "array1", "int", NULL, sizeof(int), 5, 0);  // Ejemplo de un array

    // Busca un símbolo
    const char *searchName = "variable1";
    Symbol *foundSymbol = searchSymbol(symTable, searchName);

    if (foundSymbol != NULL) {
        printf("Símbolo '%s' encontrado en la tabla. Tipo: %s, Tamaño: %d, Offset: %d\n", searchName, foundSymbol->type, foundSymbol->size, foundSymbol->offset);
    } else {
        printf("Símbolo '%s' no encontrado en la tabla.\n", searchName);
    }

    // Libera la memoria de las variables
    free(var1_address);
    free(var2_address);

    // Libera la memoria de la tabla de símbolos
    destroySymbolTable(symTable);
    */
    return 0;
}