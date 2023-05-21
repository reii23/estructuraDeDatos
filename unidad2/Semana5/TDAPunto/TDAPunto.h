#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*estructura de datos del TDA punto */
struct punto{
	float x;
	float y;
};
typedef struct punto Punto;

//Encabezados de las funciones (operaciones del TDA Punto)*/

// Punto *crearPunto(float n1, float n2);
// int obtenerCuadrante(Punto *P);
// void mostrarPunto(Punto *A);
// void deplazarPunto(float dx, float dy, Punto *A);
// float obtenerDistanciaDesdeOrigen(Punto *A);
// float obtenerDistancia(Punto *A, Punto *B);
// float obtenerDistancia2(Punto *A, Punto *B);
// float obtenerPuntoMedio(Punto *A, Punto *B);

//Programar primera función del TDA
Punto *crearPunto(float n1, float n2){
	Punto *p;
	p = (Punto*)malloc(sizeof(Punto)) ;
	p->x = n1;
	p->y = n2;
	return p;
}

int obtenerCuadrante(Punto *P){
	if (P->x >= 0 && P->y>=0) return 1;
	if (P->x <  0 && P->y>=0) return 2;
	if (P->x <  0 && P->y<0) return 3;
	if (P->x >= 0 && P->y<0) return 4;
}

void mostrarPunto(Punto *A){
	printf("\n (%f,%f)", A->x, A->y);
}

void deplazarPunto(float dx, float dy, Punto *A){
	A->x = A->x + dx; // o no?
	A->y = A->y + dy; 
}

float obtenerDistanciaDesdeOrigen(Punto *A){
	  float d;
	  d = pow((A->y*A->y + A->x * A->x ) , 0.5 );
	  return d;  
}

float obtenerDistancia(Punto *A, Punto *B){
	float d=0;
	d = sqrt( pow((B->y - A->y),2) + pow((B->x - A->x),2) );
	return d;
}

float obtenerDistancia2(Punto *A, Punto *B){
	  //d = ( (yb-ya)^2 + (xb – xa)^2 )^(1/2)
	  float d;
	  d = pow( (pow(A->x - B->x, 2) + pow(A->y - B->y, 2)), 1/2 );
	  return d;
}


//pow(a,b)  = a elevado a b
