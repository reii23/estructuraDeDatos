#include <stdio.h>
#include <stdlib.h>
#include "S14_ActLab4_C3_Pacheco_Reinaldo.h"
/* gcc S14_ActLab4_C3_Pacheco_Reinaldo.c S14_ActLab4_C3_Pacheco_Reinaldo.h -o lab4
./lab4  */ 

// creacion de nodo //
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); // reserva de memoria
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// insertar nodos en el árbol //
void insertar(Nodo** arbol, int dato) {
    if (*arbol == NULL) {       
        *arbol = crearNodo(dato);       // si apunta a nulo, creo un nodo //
    } else {
        if (dato < (*arbol)->dato) {    
            insertar(&(*arbol)->izquierda, dato);// como es ABO, si el dato es menor se inserta a la izquierda, en caso contrario se inserta a la derecha
        } else {
            insertar(&(*arbol)->derecha, dato);
        }
    }
}

// realiza el recorrido in-orden en un arbol en ambos lados
void recorridoInorden(Nodo* arbol) {
    if (arbol != NULL) { // mientras sea distinto de nulo
        recorridoInorden(arbol->izquierda);
        printf("%d ", arbol->dato); // muestro el dato
        recorridoInorden(arbol->derecha);
    }
}

int sumaDatos(Nodo* arbol) {
    if (arbol == NULL) { // si el árbol es nulo, el contenido de los nodos será 0.
        return 0;
    } else {
        return arbol->dato + sumaDatos(arbol->izquierda) + sumaDatos(arbol->derecha); // caso contrario, sumo el contenido de los datos del arbol de izq y derecha
    }
}

// obtener el peso, problema 3
int obtenerPeso(Nodo* arbol) {
    if (arbol == NULL) {
        return 0;
    } else {
        return 1 + obtenerPeso(arbol->izquierda) + obtenerPeso(arbol->derecha); // obtener el peso de los arboles
    }
}

int restaPesos(Nodo* arbol) {
    if (arbol == NULL) {
        return 0;
    } else {
        int pesoIzquierdo = obtenerPeso(arbol->izquierda); // obtener el peso del arbol apuntando a la izq
        int pesoDerecho = obtenerPeso(arbol->derecha); // obtener el peso del arbol apuntando a la der
        return abs(pesoIzquierdo - pesoDerecho); // se retorna la diferencia de los pesos,el peso del izquierdo menos el derecho
    } 
}

// primero identificar nodos hoja, luego sumar todos los nodos que sean hoja
int sumaHojas(Nodo* arbol) {
    if (arbol == NULL) {
        return 0; // si el arbol es nulo no hay nodo hoja, entonces la suma es 0
    } else if (arbol->izquierda == NULL && arbol->derecha == NULL) { // identifica si el nodo es una hoja, para ello, su puntero a izq y a derecha apunta a nulo //
        return arbol->dato;                 
    } else {
        return sumaHojas(arbol->izquierda) + sumaHojas(arbol->derecha); // suma
    }
}

int main() {
    Nodo* arbol = NULL;
    FILE* archivo;
    int dato;

    archivo = fopen("datos40_1-1000.txt", "r"); // se lee el archivo datos40_1-100.txt 
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    while (fscanf(archivo, "%d", &dato) != EOF) {
        insertar(&arbol, dato); // se insertan hasta que se hayan leido todos los datos
        recorridoInorden(arbol);
        printf("\n");
    }
    fclose(archivo);
    printf("-----------PROBLEMA 2-----------\n");
    printf("Suma del contenido de los nodos: %d\n", sumaDatos(arbol));
    printf("-----------PROBLEMA 3-----------\n");
    printf("Diferencia de pesos entre el subarbol mayor y menor: %d\n", restaPesos(arbol));
    printf("-----------PROBLEMA 4-----------\n");
    printf("Suma de los nodos hoja del arbol: %d\n", sumaHojas(arbol));

    return 0;
}
