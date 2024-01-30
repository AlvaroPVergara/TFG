#ifndef TS_H
#define TS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 255

// Estructura para representar un símbolo
typedef struct Symbol {
    char *name;
    char *type;
    void *memory_address;
    int size;
    int size_array; // 0 if not array
    int offset;

    
} Symbol;

// Estructura para la tabla de símbolos
typedef struct SymbolTable {
    Symbol *table[TABLE_SIZE];
} SymbolTable;

#endif // TS_H