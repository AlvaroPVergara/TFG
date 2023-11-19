#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "AST.h"




struct nodoAST* crearNodoNumero(int valor) {
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_HOJA;
    nuevoNodo->valor = valor;
    nuevoNodo->nombre = strdup("NUMERO"); // Copiar la cadena usando strdup
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
}


struct nodoAST* crearNodoVariable(char* nombre, int valor) {
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_HOJA;
    nuevoNodo->valor = valor;
    nuevoNodo->nombre = strdup(nombre); // Copiar la cadena usando strdup
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
}

struct nodoAST* crearNodoIntermedio(char* nombre) {
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_INTERMEDIO;
    nuevoNodo->valor = 0;
    nuevoNodo->nombre = strdup(nombre); // Copiar la cadena usando strdup
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
}

void agregarHijo(struct nodoAST* padre, struct nodoAST* hijo) {
    if (padre->primer_nodo == NULL) {
        padre->primer_nodo = hijo;
    } else {
        struct nodoAST* temp = padre->primer_nodo;
        while (temp->siguiente_hermano != NULL) {
            temp = temp->siguiente_hermano;
        }
        temp->siguiente_hermano = hijo;
    }

    //printf("Agregando hijo %d a %s\n", hijo->valor, padre->nombre);
}

void liberarAST(struct nodoAST* raiz) {
    if (raiz == NULL) {
        return;
    }

    free(raiz->nombre); // Liberar la memoria de la cadena de caracteres

    struct nodoAST* temp = raiz->primer_nodo;
    while (temp != NULL) {
        struct nodoAST* siguiente = temp->siguiente_hermano;
        liberarAST(temp);
        temp = siguiente;
    }

    free(raiz);
}

/*
void imprimirAST(struct nodoAST* raiz) {
    if (raiz == NULL) {
        return;
    }

    if (raiz->tipo == NODO_HOJA) {
        printf("%d           ", raiz->valor);
    } else {
        printf("%s\n", raiz->nombre);
        imprimirAST(raiz->primer_nodo);

        struct nodoAST* temp = raiz->primer_nodo->siguiente_hermano;
        while (temp != NULL) {
            imprimirAST(temp);
            temp = temp->siguiente_hermano;
        }
    }
}*/


void imprimirASTRecursivo(struct nodoAST* nodo, int nivel) {
    if (nodo == NULL) {
        return;
    }

    // Imprime el nodo actual con un número de espacios/tabulaciones según el nivel
    for (int i = 0; i < nivel; ++i) {
        printf("    ");
    }
    printf("%s", nodo->nombre);

    // Imprime el valor si es un nodo hoja
    if (nodo->tipo == NODO_HOJA) {
        printf(" %d", nodo->valor);
    }

    printf("\n");

    // Llama recursivamente para imprimir los hijos
    imprimirASTRecursivo(nodo->primer_nodo, nivel + 1);
    imprimirASTRecursivo(nodo->siguiente_hermano, nivel);
}

void imprimirAST(struct nodoAST* raiz) {
    imprimirASTRecursivo(raiz, 0);
}
