#include <stdlib.h>
#include <stdio.h>

/* Agregue el TDA que va a utilizar en esta actividad*/
#include "S6_TDALista_C3.h"

/* FUNCIONES */

/* obtenerMenor: Función que retorna el numero menor de una lista*/
int obtenerMenor(Listac3 *l3){
    if (c3is_lista_vacia(l3)){
        printf("Lista vacía");}/*si la lista es vacía, retorno, lista vacía*/
    Nodoc3 *aux = l3->headc3;
    int menor = aux->infoc3;
    while (aux != NULL){
        if (aux->infoc3 < menor) {	/*comparo el numero, me quedo con el menor y lo guardo en la variable "menor"*/
            menor = aux->infoc3;}
        aux = aux->sigc3;}
    return menor;
}

/* obtenerMayor: Función que retorna el numero mayor de una lista*/
int obtenerMayor(Listac3 *l3){
    if (c3is_lista_vacia(l3)){
        printf("La lista está vacía.\n"); /* si la lista es vacía, retorno lista vacia*/
        return -1;}
    Nodoc3 *aux = l3->headc3;
    int mayor = aux->infoc3;
    while (aux != NULL){
        if (aux->infoc3 > mayor){ /*realizo lo mismo que con el obtener menor solo que ahora me quedo con el numero mayor*/
            mayor = aux->infoc3;}
        aux = aux->sigc3;}
    return mayor;}

void mostrarPromedio(Listac3 *l3){
    if (c3is_lista_vacia(l3)){
        printf("Lista vacía");
        return;}
    Nodoc3 *aux = l3->headc3;
    int suma = 0; /* guarda la suma de todos los elementos */
    int cont = 0; /* cont de lista */
    while (aux != NULL){
        suma += aux->infoc3;
        cont++;
        aux = aux->sigc3;}
    float promedio = (float) suma/cont; /*se divide la suma de todos lols elementos en la cantidad de elementos*/
    printf("A: El promedio de la lista es: %.2f\n", promedio);} /*promedio es flotante*/

int main(int argc,  char *argv[]){

	/* PROBLEMA 1. 
	/* crea una lista enlazada, inserta el número 33, luego el número 26, luego el 27,
    luego el 32, mostrar la lista, luego inserta al inicio el 24, al final el 40 y al final el 28.
    luego muestra la lista */
		
    printf("Resultados del problema 1:");		
		Listac3 *l3;
		/* creo lista e ingreso los numeros iniciales*/
		l3 = c3crear_lista();
		c3insertar_nodo_ini(l3,33);
		c3insertar_nodo_fin(l3,26);
		c3insertar_nodo_fin(l3,27);
		c3insertar_nodo_fin(l3,32);

		/* muestro la lista con los primeros ingresados */
		c3mostrar_lista(l3);
		
		c3insertar_nodo_ini(l3,24);
		c3insertar_nodo_fin(l3,40);
		c3insertar_nodo_fin(l3,28);

		/* muestro la lista con los nuevos ingresados */
		c3mostrar_lista(l3);

	/* PROBLEMA 2.  /*
	/* Dada la lista creada en el problema 1, se entrega el menor elemento */
	printf("\n");
    printf("Resultados del problema 2:\n");
	int menor = obtenerMenor(l3); /*llamo al menor creado en la función y lo muestro*/
    printf("El menor elemento de la lista es: %d\n", menor);
    printf("\n");

		/* PROBLEMA 3. 
		/*  a) Promedio de la lista
        	b) Eliminar numero mayor y menor y mostrar lista
        	c) Repetir al inicio el numero mayor de la nueva lista modificada (en este caso seria 33 porque se eliminó el 40 y 22) */
    printf("Resultados del problema 3:\n");		

	/* a: mostrar promedio de la lista */
	mostrarPromedio(l3);

	/* b: eliminacion de mayor y menor y mostrar lista */
	int mayor = obtenerMayor(l3);
	c3eliminar_nodo(l3, mayor);
   	c3eliminar_nodo(l3, menor);
	printf("B: La lista sin el mayor y el menor es:");
	c3mostrar_lista(l3);
    printf("\n");

	/*c: repetir la lista b con el nuevoMayor al inicio nuevoMayor = 33 al inicio*/
	/* obtengo el nuevo mayor de la nueva lista*/
	int nuevoMayor=obtenerMayor(l3);
	c3insertar_nodo_ini(l3,nuevoMayor); /*se inserta al comienzo*/
	printf("C: La nueva lista con el nuevo mayor al comienzo es:");
	c3mostrar_lista(l3); /*muestro*/
		return 0;
}