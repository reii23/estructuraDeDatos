//Estructura de datos para grafo con MATRIZ DE ADYACENCIA
// Grafo PONDERADO.
#include <stdbool.h>
struct c3grafo{
	float **Mad;
	int n;
	int m;
};
typedef struct c3grafo Grafoc3;
struct c3arista{
	int v,w;
	float peso;
};
typedef struct c3arista Aristac3;

//Encabezado Operaciones
Grafoc3 *crear_grafoc3(int n);
bool agregar_aristac3(Grafoc3 *g, Aristac3 a);
void mostrar_grafoc3(Grafoc3 *g);
bool eliminar_aristac3(Grafoc3 *g, Aristac3 a);
bool existe_aristac3(Grafoc3 *g, Aristac3 a);
bool existe_verticec3(Grafoc3 *g, int v);
int grado_verticec3(Grafoc3 *g, int v);
int *adyacentes_verticec3(Grafoc3 *g, int v);
void mostrar_adyacentesc3(Grafoc3 *g, int v);


// Programaci�n Operaciones

int grado_verticec3(Grafoc3 *g, int v){
	int cuenta=0;
	if (existe_verticec3(g,v)){ // existe v�rtice v?
		for (int j=0; j<g->n; j++) {
			if (g->Mad[v][j] != 0.0)
				cuenta = cuenta + 1;
		}
	}
	return cuenta;
}

int *adyacentes_verticec3(Grafoc3 *g, int v){
	int *adyacentes = NULL, k=0;
	if (grado_verticec3(g,v)){ // existe v�rtice v?
		adyacentes = (int*)malloc(sizeof(int) * grado_verticec3(g,v));
		for (int j=0; j<g->n; j++) {
			if (g->Mad[v][j] != 0.0){
					adyacentes[k] = j;
					k = k + 1;
			}
		}
	} //else printf("\n  adyacentes es NULL");
	return adyacentes;
}

Grafoc3 *crear_grafoc3(int n){
	Grafoc3 *g;
	g = malloc(sizeof(Grafoc3));
  g->Mad = malloc(sizeof(float*)*n);
	for (int i=0; i<n; i++){
      g->Mad[i] = malloc(sizeof(float)*n);
	}
	//Todas las aristas M[i][j] de la matriz quedan inactivas (sin conexi�n)
	for (int i=0; i<n;i++) {
		for (int j=0; j<n;j++) 
				g->Mad[i][j] = 0.0;
	}
  g->n = n;
  g->m = 0;
	return  g;	
}

void mostrar_grafoc3(Grafoc3 *g){ 
	printf("\n Numero de vertices:%d",g->n);
	printf("\n Numero de aristas:%d",g->m);
	printf("\n");
	for (int i=0; i < g->n; i++){ 
		for (int j=0; j < g->n; j++){
			printf("%.2f ", g->Mad[i][j]);
		}
		printf("\n");
	}
}

bool agregar_aristac3(Grafoc3 *g, Aristac3 a){
	if (existe_verticec3(g,a.v)){ // existe v�rtice v?
		if (existe_verticec3(g,a.w)){ // existe v�rtice w?
				g->Mad[a.v][a.w] = a.peso;
				g->m = g->m + 1;
				return true;
		}
	}
	return false;
}

bool eliminar_aristac3(Grafoc3 *g, Aristac3 a){
	if (existe_verticec3(g,a.v)){ // existe v�rtice v?
		if (existe_verticec3(g,a.w)){ // existe v�rtice w?
				g->Mad[a.v][a.w] = 0.0;
				g->m = g->m - 1;
				return true;
		}
	}
	return false;
}

bool existe_verticec3(Grafoc3 *g, int v){
	if (v < g->n)
		return true;
	else
		return false;
}

bool existe_aristac3(Grafoc3 *g, Aristac3 a){
	if (existe_verticec3(g,a.v)){ // existe v�rtice v?
		if (existe_verticec3(g,a.w)){ // existe v�rtice w?
			if (g->Mad[a.v][a.w] != 0.0)
				return true;
		}
	}
	return false;
}

void mostrar_adyacentesc3(Grafoc3 *g, int v){
			//Se asume que antes de llamar a esta operaci�n ha validado que adyacentes existe
			for (int j=0; j<g->n; j++) {
				if (g->Mad[v][j] != 0.0){
						printf("\n  %d", j);
			  }
		  }
}









