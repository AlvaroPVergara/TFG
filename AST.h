#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef enum{
    NODO_HOJA_NUMERO,
    NODO_HOJA_VARIABLE,
    NODO_HOJA_VARIABLE_INIT,
    NODO_HOJA_SIGNO,
    NODO_INTERMEDIO,
    NODO_FUNCION,
    NODO_STRING
} tipoNodo;


struct nodoAST{
    tipoNodo tipo;
    int valor;
    char* nombre; 
    char* tipo_variable;
    struct nodoAST* primer_nodo;
    struct nodoAST* siguiente_hermano;
};


struct nodoAST* crearNodoNumero(int valor);
struct nodoAST* crearNodoVariable(char* nombre, int valor,  char* tipo);
struct nodoAST* crearNodoVariableInit(char* nombre, int valor, char* tipo);
struct nodoAST* crearNodoSigno(char* nombre, int valor);
struct nodoAST* crearNodoFuncion(char* nombre);
struct nodoAST* crearNodoString(char* nombre);
struct nodoAST* crearNodoIntermedio(char* nombre);
void agregarHijo(struct nodoAST* padre, struct nodoAST* hijo);
void agregarHermano(struct nodoAST* hermano, struct nodoAST* nuevo);
struct nodoAST* crearNodoIntermedioGenerico(char* nombre, int numHijos, ...);
void changeName(struct nodoAST* nodo, char* nombre);
void liberarAST(struct nodoAST* raiz);
void imprimirAST(struct nodoAST* raiz);

#endif // AST_H