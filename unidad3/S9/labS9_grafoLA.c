#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "TDAGrafo_LA_labS9.h"


int main(int argc,  char *argv[]) {

/*	Ejemplo de Soluci�n de S8: Crear grafo desde archivo */
		
	// Paso a)
	int i, num_vertices, v, w;
	FILE *fp;
	Grafo *g;
	
	// Paso b)
	//fp = fopen("datos_grafo.txt", "r");
	fp = fopen(argv[1], "r");
	fscanf(fp, "%d", &num_vertices); //lee el dato de la primera fila del archivo
	
	g =  crear_grafo(num_vertices);
	printf("\nGrafo creado en @ = %p  con  %d vertices\n", g, g->n);
	
	// Paso c)
	while (fscanf(fp, "%i %i", &v, &w ) == 2){
	  agregar_arista(g,v, w);
	  agregar_arista(g,w,v);
	}
	
	// Paso d)
	printf("\n\nDATOS DEL GRAFO @%p:",g);
	mostrar_grafo(g);
				
		
	printf("\n\n");
  return 0;
}