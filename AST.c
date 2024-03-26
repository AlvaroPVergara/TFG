#include <stdarg.h> // Para usar va_list, va_start, va_arg, va_end
#include "AST.h"



// Crea un nodo hoja con el nombre "NUMERO" y el valor especificado
struct nodoAST* crearNodoNumero(int valor) {
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_HOJA_NUMERO;
    nuevoNodo->valor = valor;
    nuevoNodo->nombre = strdup("NUMERO"); 
    nuevoNodo->tipo_variable = NULL;
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
}


// Crea un nodo hoja con el nombre y el valor especificado
struct nodoAST* crearNodoVariable(char* nombre, int valor, char* tipo) {
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_HOJA_VARIABLE;
    nuevoNodo->valor = valor;
    nuevoNodo->nombre = strdup(nombre);
    nuevoNodo->tipo_variable = tipo;
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
}

// Crea un nodo hoja con el nombre y el valor especificado
struct nodoAST* crearNodoVariableInit(char* nombre, int valor, char* tipo) {
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_HOJA_VARIABLE_INIT;
    nuevoNodo->valor = valor;
    nuevoNodo->nombre = strdup(nombre); 
    nuevoNodo->tipo_variable = tipo;
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
}

// Crea un nodo hoja con el nombre y el valor especificado
struct nodoAST* crearNodoSigno(char* nombre, int valor)
{
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));;
    nuevoNodo->tipo = NODO_HOJA_SIGNO;
    nuevoNodo->valor = valor;
    nuevoNodo->nombre = strdup(nombre);
    nuevoNodo->tipo_variable = NULL; 
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
};

struct nodoAST* crearNodoFuncion(char* nombre){
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));;
    nuevoNodo->tipo = NODO_FUNCION;
    nuevoNodo->valor = 0;
    nuevoNodo->nombre = strdup(nombre);
    nuevoNodo->tipo_variable = NULL;
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
};

struct nodoAST* crearNodoString(char* nombre){
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));;
    nuevoNodo->tipo = NODO_STRING;
    nuevoNodo->valor = 0;
    nuevoNodo->nombre = strdup(nombre);
    nuevoNodo->tipo_variable = NULL;
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
};



// Crea un nodo intermedio con el nombre especificado
struct nodoAST* crearNodoIntermedio(char* nombre) {
    struct nodoAST* nuevoNodo = (struct nodoAST*)malloc(sizeof(struct nodoAST));
    nuevoNodo->tipo = NODO_INTERMEDIO;
    nuevoNodo->valor = 0;
    nuevoNodo->nombre = strdup(nombre); 
    nuevoNodo->tipo_variable = NULL;
    nuevoNodo->primer_nodo = NULL;
    nuevoNodo->siguiente_hermano = NULL;
    return nuevoNodo;
}

// Añade un nodo hijo al nodo padre
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
}

void agregarHermano(struct nodoAST* hermano, struct nodoAST* nuevo) {
    if (hermano->siguiente_hermano == NULL) {
        hermano->siguiente_hermano = nuevo;
    } else {
        struct nodoAST* temp = hermano->siguiente_hermano;
        while (temp->siguiente_hermano != NULL) {
            temp = temp->siguiente_hermano;
        }
        temp->siguiente_hermano = nuevo;
    }
}


/* Crea un nodo intermedio con el nombre especificado
* y le agrega los nodos hijos pasados por parámetro
*/

struct nodoAST* crearNodoIntermedioGenerico(char* nombre, int numHijos, ...) {
    struct nodoAST* nuevoNodo = crearNodoIntermedio(nombre);

    va_list args;
    va_start(args, numHijos);

    for (int i = 0; i < numHijos; ++i) {
        struct nodoAST* hijo = va_arg(args, struct nodoAST*);
        agregarHijo(nuevoNodo, hijo);
    }

    va_end(args);

    return nuevoNodo;
}

void changeName(struct nodoAST* nodo, char* nombre) {
    nodo->nombre = strdup(nombre);
}

// Libera la memoria del árbol AST
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

// Imprime el árbol AST de forma recursiva mediante tabulaciones
void imprimirASTRecursivo(struct nodoAST* nodo, int nivel) {
    if (nodo == NULL) {
        return;
    }

    // Imprime el nodo actual con un número de espacios/tabulaciones según el nivel
    for (int i = 0; i < nivel; ++i) {
        printf("    ");
    }

    // Imprime el nombre del nodo, solo en caso de que este sea intermedio.
    if (nodo->tipo == NODO_INTERMEDIO){
        printf("%s", nodo->nombre);
    }

    // Imprime el valor si es un nodo hoja numérico
    if (nodo->tipo == NODO_HOJA_NUMERO) {
        printf("%s", nodo->nombre);
        printf(" %d", nodo->valor);
    }

    // Imprime el valor si es un nodo hoja variable
    if (nodo->tipo == NODO_HOJA_VARIABLE || nodo->tipo == NODO_HOJA_VARIABLE_INIT) {
        printf("VAR");
        printf(" %s", nodo->nombre);
    }

    // Imprime el valor si es un nodo hoja signo
    if (nodo->tipo == NODO_HOJA_SIGNO) {
        printf("SIGNO");
        printf(" %s", nodo->nombre);
    }

    if (nodo->tipo == NODO_FUNCION) {
        printf("FUNCION");
        printf(" %s", nodo->nombre);
    }

    if(nodo->tipo == NODO_STRING){
        printf(" %s", nodo->nombre);
    }


    printf("\n");

    // Llama recursivamente para imprimir los hijos
    imprimirASTRecursivo(nodo->primer_nodo, nivel + 1);
    imprimirASTRecursivo(nodo->siguiente_hermano, nivel);
}

// Imprime el árbol AST dada su raíz
void imprimirAST(struct nodoAST* raiz) {
    imprimirASTRecursivo(raiz, 0);
}
