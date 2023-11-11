#include <stdio.h>
#include <stdlib.h>
#include "AST.h"




struct nodoAST crearNodoNumero(int valor){
    struct nodoAST* nuevoNodo = (struct nodoAST*) malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_HOJA;
    nuevoNodo->valor = valor;
    nuevoNodo->nombre = "NUMERO"; 
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return *nuevoNodo;
}

struct nodoAST crearNodoVariable(char* nombre, int valor){
    struct nodoAST* nuevoNodo = (struct nodoAST*) malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_HOJA;
    nuevoNodo->valor = valor;
    nuevoNodo->nombre = nombre; 
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return *nuevoNodo;
}

struct nodoAST crearNodoIntermedio(char* nombre){
    struct nodoAST* nuevoNodo = (struct nodoAST*) malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_INTERMEDIO;
    nuevoNodo->valor = 0;
    nuevoNodo->nombre = nombre; 
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return *nuevoNodo;
}

void agregarHijo(struct nodoAST* padre, struct nodoAST* hijo){
    if(padre->primer_nodo == NULL){
        padre->primer_nodo = hijo;
    }else{
        struct nodoAST* temp = padre->primer_nodo;
        while(temp->siguiente_hermano != NULL){
            temp = temp->siguiente_hermano;
        }
        temp->siguiente_hermano = hijo;
    }

    printf("Agregando hijo %d a %s\n", hijo->valor, padre->nombre);
}

void imprimirAST(struct nodoAST* raiz){
    if(raiz == NULL){
        return;
    }
    if(raiz->tipo == NODO_HOJA){
        printf("%d", raiz->valor);

    }else{
        /*
        printf("%s", raiz->nombre);
        printf("(");
        struct nodoAST* temp = raiz->primer_nodo;
        if (temp != NULL){
                printf("temp: %s\n", temp->nombre);
            } else{
                printf("temp: NULL\n");
            }
        while(temp != NULL){
            temp = temp->siguiente_hermano;
            
            imprimirAST(temp);
            
            if(temp != NULL){
                printf(",");
            }
        }
        printf(")");*/

        printf("%s\n", raiz->nombre);
        printf("%s\n", raiz->primer_nodo->nombre);
        if (raiz->primer_nodo->siguiente_hermano != NULL){printf("%s\n", raiz->primer_nodo->siguiente_hermano->nombre);}
        
    }
}





