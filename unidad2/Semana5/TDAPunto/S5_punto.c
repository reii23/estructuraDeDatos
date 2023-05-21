#include <stdio.h>
#include "TDAPunto.h"
#include <stdlib.h>

/* PASOS PARA PROGRAMAR UN TDA PREVIAMENTE ESPECIFICADO */
//CONSIDERAR:
//PASO 1: CREAR EL .h  (Punto.h)
//PASO 2: CREAR FUENTE DONDE ESTÉ EL main() PARA PROBAR EL TDA (en este caso S5_punto.c)
//PASO 3: COMPILAR Y EJECUTAR

/* 
 COMPILAR CON:
 > gcc S5_punto.c -o S5
 > ./S5
 o 
 > S5
 
*/

int main(){
	float distancia;
	Punto *pto1, *pto2;
	int cuadrante;

	pto1 = crearPunto(2,1);
	mostrarPunto(pto1);

	pto2 = crearPunto(-5,8);
	mostrarPunto(pto2);
	distancia = obtenerDistancia(pto1, pto2);
	printf("\n La distancia entre los dos puntos: %f",distancia);
	cuadrante = obtenerCuadrante(pto1); 
	printf("\n cuadrante punto 1 : %d", cuadrante ) ;

	printf("\n Punto 1 antes de desplazar:");
	mostrarPunto(pto1);
	printf("\n Punto 1 despues de desplazar:");
	deplazarPunto(4.206, 5.603, pto1);
	mostrarPunto(pto1);
  
	printf("\n");
  
 
}