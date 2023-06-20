#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "TDAGrafo_MA_labS9.h"


int main(int argc,  char *argv[]) {

/*	Ejemplo de Soluci�n : Crear grafo desde archivo */
		
	FILE*pf;		   //para abrir archivo
	pf = fopen(argv[1],"r");
	int n_vertices, m_aristas;
	int i,j,k;
	TDAgrafo *G;
	if (pf ==NULL){
		printf("Error de archivo\n");
	}else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d", &n_vertices); 		
		G=crearGrafoVacio(n_vertices);	
		//dependiendo de las lineas de archivo, 
		// 1 para grafo no dirigido no ponderado
		while (fscanf(pf, "%d %d", &i, &j ) == 2){
			G->adyacencias[i][j] = 1;
		}
		fclose(pf);
	}
	
	// Paso d)
	printf("\n\nDATOS DEL GRAFO @%p:\n",G);
	mostrar_grafo(G);
				
		
	printf("\n\n");
  return 0;
}