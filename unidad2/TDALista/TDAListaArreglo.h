#include <stdio.h>
#include <stdlib.h>

/*estructura de datos del TDA Lista */
struct lista{
	int arrLista[MAX_LISTA];//=(int*)malloc(sizeof(int)*MAX);  //Arreglo de tipo de dato lista, en este caso entero
	int n;
};
typedef struct lista LISTA;

//Encabezados de las funciones (operaciones del TDA Lista)*/
// Lista *crearLista(int MAX);
// mostrarLista(Lista L);
// insertarInicio(Lista L, int x);
// insertarFin(Lista L, int x);
// insertarEnPos(Lista L, int p, int x);
// eliminarInicio(Lista L);
// eliminarFin(Lista L);
// eliminarElem(Lista L, int x);
// int BuscarElem(Lista L, int x)
// ActualizarLista(Lista L, int p, int x)
// int RecuperaElem(Lista L, int p)
// int PrimeroLista(Lista L) 	 
// int UltimoLista(Lista L) 
// bool IsVacía(Lista L) 	
// bool IsFull(Lista L)	
// int LargoLista(Lista L) 


LISTA *crearLista(){
	LISTA *lista;
	lista= (LISTA*) malloc (sizeof(LISTA));
	lista->n=0;
	return lista;	
}

void mostrarLista(LISTA *L){
	int i;
	for(i=0;i<L->n;i++){
		printf("[%d]%d ", i, L->arrLista[i]);	
	}	
}

void insertarInicio(LISTA *L, int x){
	int largoLista=L->n;
	int i;
	if (largoLista<MAX_LISTA) {
		if (largoLista!=0) {
			for(i=(largoLista-1);i>=0;i--){
				L->arrLista[i+1]=L->arrLista[i];	
			}
		}
		L->arrLista[0]=x;
		L->n = largoLista+1;
	}else{
		printf("Lista llena, valor %d NO insertado \n", x);
	}