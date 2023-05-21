#include <stdio.h>
#include <stdlib.h>
#define MAX_LISTA 10
#include "TDAListaArreglo.h"


/* PASOS PARA PROGRAMAR UN TDA PREVIAMENTE ESPECIFICADO */
//CONSIDERAR:
//PASO 1: CREAR EL .h  (TDAListaArreglo.h)
//PASO 2: CREAR FUENTE DONDE ESTÉ EL main() PARA PROBAR EL TDA (en este caso S5_listaArreglo.c)
//PASO 3: COMPILAR Y EJECUTAR

/* 
 COMPILAR CON:
 > gcc S5_listaArreglo.c -o S5
 > ./S5
 o 
 > S5
 
*/


int main(){
	
	LISTA *Lista;
	
	Lista=crearLista();
	
	insertarInicio(Lista,5);
	insertarInicio(Lista,8);
	insertarInicio(Lista,2);
	insertarInicio(Lista,9);
	printf("\n Lista completa: ");
	mostrarLista(Lista);
	
	printf("\n");
  
 
}