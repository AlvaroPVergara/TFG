#ifndef AST_H
#define AST_H

typedef enum{
    NODO_HOJA,
    NODO_INTERMEDIO
} tipoNodo;


struct nodoAST{
    tipoNodo tipo;
    int valor;
    char* nombre; 
    struct nodoAST* primer_nodo;
    struct nodoAST* siguiente_hermano;
};


struct nodoAST crearNodoNumero(int valor);
struct nodoAST crearNodoVariable(char* nombre, int valor);
struct nodoAST crearNodoIntermedio(char* nombre);
void agregarHijo(struct nodoAST* padre, struct nodoAST* hijo);
void imprimirAST(struct nodoAST* raiz);

#endif // AST_H