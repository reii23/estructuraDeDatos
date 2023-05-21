#include <stdio.h>
#include <stdlib.h>

// ESTRUCTURA DE DATOS TDA lista
typedef struct nodoGenerico {
  int dato;
  struct nodoGenerico *sig;
} Nodo;

typedef struct listaGenerica {
  Nodo *head;
  int n;
} TDALista;

TDALista *crearLista() {
  TDALista *L = (TDALista *)malloc(sizeof(TDALista));
  L->head = NULL;
  L->n = 0;
  return L;
}

Nodo *crearNodo(int val) {
  Nodo *N;
  N = (Nodo *)malloc(sizeof(Nodo));
  N->dato = val;
  N->sig = NULL;
  return N;
}

int isListaVacia(TDALista *L) {
  if (L->head == NULL) {
    return 1;  // SI ES VACIA DEBE SER 1
  } else {
    return 0;
  }
}

void insertarNodoIni(TDALista *L, int val) {
  Nodo *N;
  N = crearNodo(val);
  if (!(isListaVacia(L))) {
    N->sig = L->head;
  }
  L->head = N;
  L->n = L->n + 1;
}

void recorrerLista(TDALista *L) {  // muestra a medida que recorre
  printf("\n");
  Nodo *aux;
  if (!(isListaVacia(L))) {
    aux = L->head;
    while (aux != NULL) {
      printf("Nodo=%d -> ", aux->dato);
      aux = aux->sig;
    }
  }
}

void insertarNodoFin(TDALista *L, int val) {
  Nodo *Nvo;
  Nvo = crearNodo(val);
  Nodo *aux;
  aux = L->head;
  if (!(isListaVacia(L))) {
    if (aux->sig != NULL) {
      aux = aux->sig;
    }
    aux->sig = Nvo;
    L->n = L->n + 1;
  }
}

// llamar void insertarEnPos(TDALista *L, int pos, int val);

void insertarEnPos(TDALista *L, int pos, int val) {
  if (pos < 1 || pos > L->n + 1) {
    printf("Error: La posición está fuera de rango\n");
    return;
  }

  if (pos == 1) {
    insertarNodoIni(L, val);
  } else {
    Nodo *Nvo = crearNodo(val);
    Nodo *aux = L->head;
    int i;

    for (i = 1; i < pos - 1; i++) {
      aux = aux->sig;
    }

    Nvo->sig = aux->sig;
    aux->sig = Nvo;
    L->n = L->n + 1;
  }
}

// llamar void eliminarInicio(TDALista *L);

void eliminarInicio(TDALista *L) {
  if (isListaVacia(L)) {
    printf("Error: La lista está vacía, no se puede eliminar el inicio\n");
    return;
  }

  Nodo *aux = L->head;
  L->head = aux->sig;
  free(aux);
  L->n = L->n - 1;
}

// llamar void eliminarFin(TDALista *L);

void eliminarFin(TDALista *L) {
  if (isListaVacia(L)) {
    printf("Error: La lista está vacía, no se puede eliminar el final\n");
    return;
  }

  Nodo *aux = L->head;
  Nodo *prev = NULL;

  while (aux->sig != NULL) {
    prev = aux;
    aux = aux->sig;
  }

  if (prev != NULL) {
    prev->sig = NULL;
  } else {
    L->head = NULL;
  }

  free(aux);
  L->n = L->n - 1;
}

// llamar void eliminarElem(TDALista *L, int val);

void eliminarElem(TDALista *L, int val) {
  if (isListaVacia(L)) {
    printf("Error: La lista está vacía, no se puede eliminar elementos\n");
    return;
  }

  Nodo *aux = L->head;
  Nodo *prev = NULL;

  while (aux != NULL && aux->dato != val) {
    prev = aux;
    aux = aux->sig;
  }

  if (aux == NULL) {
    printf("Error: El elemento %d no se encontró en la lista\n", val);
    return;
  }

  if (prev != NULL) {
    prev->sig = aux->sig;
  } else {
    L->head = aux->sig;
  }

  free(aux);
  L->n = L->n - 1;
}
