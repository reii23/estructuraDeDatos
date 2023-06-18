#include <stdlib.h>
#include <stdio.h>
#include "TDAListaEnlazada.h" //TDA creado por mi 

int main(int argc,  char *argv[]) {
    TDALista *L;
    Nodo *N;
    L = crearLista();
	
	insertarNodoIni(L,2);
	insertarNodoFin(L,4);
	recorrerLista(L);
	int vacia = isListaVacia(L);
	printf("La lista esta vacia? 1=Si 0=No: %d",vacia);
	return 0;
}