#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "TDAGrafo_LA_labS8.h"


int main(int argc,  char *argv[]) {

	Grafo *g;
    g = crear_grafo(4); //crea el grafo con 4 v�rtices
    printf("\nGrafo creado en @ = %p  con  %d vertices\n", g, g->n);
	mostrar_grafo(g);
	agregar_vertice(g); 	
	printf("\nGrafo creado en @ = %p  con  %d vertices\n", g, g->n);
	mostrar_grafo(g);
	printf("\n------------\n");
	agregar_arista(g,0,1); // primero muestra que nodos queremos conectar
	agregar_arista(g,0,2);
	agregar_arista(g,0,3);
	agregar_arista(g,1,1);
	agregar_arista(g,1,2);
	agregar_arista(g,1,3);
	agregar_arista(g,4,1);
	mostrar_grafo(g);

	int i, num_vertices, v, w;
	Grafo *grafo;
	FILE *fp;
	fp = fopen("grafo.txt","r");
	fscanf(fp, "%d", &num_vertices); // lee el primer elemento del archivo
	grafo = crear_grafo(num_vertices);
	while(fscanf(fp,"%i %i", &v, &w) == 2); // leer cada linea del archivo y lee los dos enteros
		agregar_arista(grafo,v,w);
	printf("\n\n");
  return 0;
}