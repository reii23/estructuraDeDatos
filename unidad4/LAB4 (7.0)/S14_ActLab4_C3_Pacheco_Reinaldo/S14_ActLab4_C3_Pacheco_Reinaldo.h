#ifndef ABO_H
#define ABO_H

// struct del nodo con puntero al nodo izq y puntero al nodo derecho
typedef struct Nodo {
    int dato;
    struct Nodo* izquierda;
    struct Nodo* derecha;
} Nodo;

Nodo* crearNodo(int dato);
void insertar(Nodo** arbol, int dato); // inserta los elementos del archivo al arbol
void recorridoInorden(Nodo* arbol); // realiza el recorrido in-orden
int sumaDatos(Nodo* arbol); // realiza la suma de todos los elementos del archivo
int restaPesos(Nodo* arbol); // calcula el peso del subarbol mayor y lo resta con la del subarbol menor
int sumaHojas(Nodo* arbol); // obtiene los nodos hoja, con el puntero izq y derecha a nulo y va sumando si cumple la condición

#endif
