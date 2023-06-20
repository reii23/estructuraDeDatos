#include <stdio.h>
#include <stdlib.h>

/* ESTRUCTURA DE DATOS  del TDA lista  */
struct nodo{
  int info;
  struct nodo *sig;
};
typedef struct nodo Nodo;

struct lista{
  Nodo *head;
  int n; //Número de nodos agregados a la lista
};
typedef struct lista Lista;


/* Encabezados de las operaciones programadas*/

Lista *crear_lista();
int is_lista_vacia(Lista *L);
Nodo *crear_nodo(int val);
void insertar_nodo_ini(Lista *L, int val); 
void insertar_nodo_fin(Lista *L, int val);
void mostrar_lista(Lista *L);
int  eliminar_nodo_ini(Lista *L);
int  eliminar_nodo_fin(Lista *L);
void eliminar_nodo(Lista *L, int valE); /* eliminar dado un valor */
Nodo *buscar_Nodo(Lista *L, int val); /* retorna la dirección del nodo encontrado */


/* Programación de las Operaciones */

Lista *crear_lista(){
	Lista *L = (Lista*)malloc(sizeof(Lista));
  L->head = NULL;
  L->n = 0;
	return L;
}

int is_lista_vacia(Lista *L){
	if(L->head == NULL)
		return 1; /*es 1 cuando la lista es vacía*/
	else
		return 0;
}

Nodo *crear_nodo(int val){
	Nodo *new_nodo;
	new_nodo = (Nodo*)malloc(sizeof(Nodo));
	new_nodo->info = val;
  new_nodo->sig = NULL;	
  return new_nodo;
}

void insertar_nodo_ini(Lista *L, int val){
	Nodo *new_nodo;
	new_nodo = crear_nodo(val);
	if (!(is_lista_vacia(L))){ 
			new_nodo->sig = L->head;
	}
	L->head = new_nodo;
	L->n = L->n + 1;  /* aumenta el número de nodos de la lista L */
}

void insertar_nodo_fin(Lista *L, int val){
	Nodo *new_nodo,*aux;
	new_nodo = crear_nodo(val);
	if (!(is_lista_vacia(L))){ 
		aux = L->head;
		while(aux->sig !=NULL){
			aux = aux->sig;
		}
		aux->sig = new_nodo;
	}else{
		L->head = new_nodo;
	}
	L->n = L->n + 1;  /* aumenta el número de nodos de la lista L */
}


void mostrar_lista(Lista *L){
	Nodo *aux;
	if (!(is_lista_vacia(L))){ 
	    aux = L->head;
			printf("->");
	    while(aux != NULL){
		    printf(" %d", aux->info);
		    aux = aux->sig;
	    }
    }
}

int eliminar_nodo_ini(Lista *L){
	Nodo *aux;
	int e=0;
	if (!is_lista_vacia(L)) {
		aux =  L->head; 
		L->head = L->head->sig; 
		e = aux->info;
		L->n = L->n  - 1; /* descuenta el número de nodos de la lista */
		aux->sig = NULL;
		free (aux) ; 
	}
	return e;
}

int  eliminar_nodo_fin(Lista *L){
	Nodo *aux, *auxE;
	int e=0;
	if (!is_lista_vacia(L)){
		/* mover el aux al penúltimo nodo */
		aux = L->head;
		while(aux->sig->sig !=NULL){
				aux = aux->sig;
		}		
		e = aux->sig->info;
		L->n = L->n - 1;
		auxE = aux->sig;
		aux->sig = NULL;
		free (auxE) ; 
	}
	return e;	
}

Nodo *buscar_nodo(Lista *L, int val){
	Nodo *aux=NULL;
	if  (!is_lista_vacia(L)) {
		aux = L->head;
		while(aux != NULL){
			if(aux->info != val)
				aux = aux->sig;
			else
				return aux;
		}
		aux=NULL; /* no lo encontró */
  }
	return aux;
}

void eliminar_nodo(Lista *L, int val){
	Nodo *auxE, *aux; 
	int e;
	if  (!is_lista_vacia(L)) {
		auxE = buscar_nodo(L,val);
		if (auxE != NULL){
			if (auxE == L->head){  
			   e = eliminar_nodo_ini(L);
			}else {
			   if (auxE->sig == NULL){ 
						e = eliminar_nodo_fin(L);
			   }else {
						/* Si el nodo a eliminar no está en el inicio ni en el fin 
						   mueve el aux al nodo anterior al que se elimina */
						aux = L->head;
						while(aux->sig != auxE){
								aux = aux -> sig;
						}
						auxE = aux->sig ;
						aux->sig = auxE->sig;
						L->n = L->n - 1;
						auxE->sig = NULL;
						free (auxE) ; 
				} 
			}
		}
	}	
} 

/* Otras operaciones útiles */

Nodo *primer_nodo(Lista *L){
	return L->head; /* si es vacía debiera retornal NULL */
}

Nodo *ultimo_nodo(Lista *L){
	Nodo *aux=NULL;
	if  (!is_lista_vacia(L)) {	
		 aux = L->head;
		 while(aux->sig !=NULL){
			 aux = aux->sig;
		 }
  }
	return aux;
}

Nodo *penultimo_nodo(Lista *L){
	Nodo *aux=NULL;
	if  (!is_lista_vacia(L)) {	/* ¿qué pasa cuando L tiene un solo nodo */
		 aux = L->head;
		 while(aux->sig->sig !=NULL){
			 aux = aux->sig;
		 }
	}
	return aux;

}


Nodo *nodo_anterior(Lista *L, int val){ 
	Nodo *aux=NULL;
	if  (!is_lista_vacia(L)) {	/* ¿qué pasa cuando L tiene un solo nodo */
		aux = L->head;
		while(aux -> sig !=NULL){
			if(aux->sig->info == val)
      		return aux;
			else
					aux = aux -> sig;
			}
  }
	return aux; /* ¿qué pasa si no encuentra el valor */
}