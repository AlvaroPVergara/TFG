#ifndef TS_H
#define TS_H
#define TABLE_SIZE 255

#include "AST.h"



// Estructura para representar un símbolo
typedef struct Symbol {
    char *name;
    char *type;
    int size_array; // 0 if not array
    int array_pos; // 0 if not array
    
} Symbol;

// Estructura para la tabla de símbolos
typedef struct SymbolTable {
    Symbol *table[TABLE_SIZE];
} SymbolTable;

void semanticAnalysis(struct nodoAST* raiz, Symbol **symTable);
Symbol** initSymbolTable();
void insertSymbol(Symbol **symTable, const char *name, const char *type, int size_array, int array_pos);
Symbol* searchSymbol(Symbol **symTable, const char *name);
char * getSymbolsByType(Symbol **symTable, const char *type);
void destroySymbolTable(Symbol **symTable);
#endif // TS_H