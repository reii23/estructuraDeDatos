/*Estructura de datos para grafo usando LISTA DE ADYACENCIA
 GRAFO NO PONDERADO y DIRIGIDO -- > esto se explica en cátedra
 */ 
#include <stdbool.h>
#include <stdlib.h>
#include "TDALista.h"
struct grafo{
	Lista **lisv; 				//Arreglo donde cada celda representa un vertice y de tipo Lista
	int n; 						//número de nodos del grafo
	int m; 						//numero de vértices del grafo
};
typedef struct grafo Grafo;

/* Tarea 1: Dibuje una representación en memoria considerando 4 vértices 
            Identificar y comprender la operación del TDA lista que debe utilizar*/
Grafo *crear_grafo(int n); //Necesito saber el número de vértices a insertar inicialmente

/* Tarea 2: Modifique su dibujo anterior para que considere un nuevo vértice */
void agregar_vertice(Grafo *G); // agrega una celda (memoria) al arreglo dinámico del grafo creado

/*Tarea 3: Identificar y comprender la operación del TDA lista que debe utilizar */
void mostrar_grafo(Grafo *G); 

/* Tarea 4: Implemente esta operación */
void agregar_arista(Grafo *G, int v, int w); //agrega una arista (v,w) al grafo
										  // Es decir, agrega un nodo a la lista G-lisv[v]. ¿Qué más debe considerar?



/* PROGRAMACIÓN OPERACIONES */

Grafo *crear_grafo(int n){
	Grafo *G;
	G = malloc(sizeof(Grafo));
	G->lisv = malloc(sizeof(Lista)*n);
	for (int i=0; i<n; i++){
      G->lisv[i] = crear_lista(); 			//recuerde: ¿qué hace esta función?
	}
	G->n = n;
	G->m = 0;
	return  G;	
}

void agregar_vertice (Grafo *G){
	G->lisv = realloc(G->lisv, sizeof(Lista)*(G->n + 1)); 	//realloc reasigna tamaño memoria conservando lo anterior
	G->n = G->n + 1; 
	G->lisv[G->n-1] = crear_lista(); 						//G->n-1 es el último índice del arreglo G->lisv	

}

void mostrar_grafo(Grafo *G){ 
	printf("\n Numero de vertices:%d",G->n);
	printf("\n Numero de aristas:%d",G->m);
	for (int i=0; i<G->n; i++){
		printf("\n %d  ",i );
		mostrar_lista(G->lisv[i]);
	}

}

/* Después de programar esta función usela 
   para agregar vértices al grafo. 
   Siga las indicaciones de su docente
   Pruebe sus resultados */
void agregar_arista(Grafo *G, int v, int w){
	/*Ejemplo de Solución S8: */
	insertar_nodo_fin(G->lisv[v],w);
	G->m = G->m + 1; 	
}










