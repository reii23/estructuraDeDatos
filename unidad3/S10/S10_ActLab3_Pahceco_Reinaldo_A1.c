#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "S10_TDAGrafoMa_C3.h"

void caminoRecursivo(Grafoc3 *grafo, int v, int w, bool *visitados);

// PROBLEMA 1: Crear un grafo a partir del archivo S10_datos_grafo_C3.txt
Grafoc3 *crearGrafo(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return NULL;}
    int numVertices;
    fscanf(archivo, "%d", &numVertices);
    Grafoc3 *grafo = crear_grafoc3(numVertices);

    int v, w;
    float peso;
    while (fscanf(archivo, "%d %d %f", &v, &w, &peso) == 3) {
        Aristac3 arista = {v, w, peso};
        agregar_aristac3(grafo, arista);}
    fclose(archivo); // cerrar archivo //
    return grafo; // retornar grafo //
}

// PROBLEMA 2: Encontrar los vértices fuente de un grafo dirigido, "vertice fuente: no tiene antecesores"
int *verticesFuente(Grafoc3 *grafo, int *numVerticesFuente) {
    int *vertices = NULL;
    *numVerticesFuente = 0;

    for (int v = 0; v < grafo->n; v++) {
        bool tieneAntecesores = false;
        for (int u = 0; u < grafo->n; u++) {
            if (grafo->Mad[u][v] != 0.0) {
                tieneAntecesores = true;
                break;
            }
        }
        if (!tieneAntecesores) {
            (*numVerticesFuente)++;
            vertices = realloc(vertices, sizeof(int) * (*numVerticesFuente));
            vertices[(*numVerticesFuente) - 1] = v;
        }
    }
    return vertices;
}

// PROBLEMA 3: Encontrar todos los nodos en un camino de v a w
void encontrarCamino(Grafoc3 *grafo, int v, int w) {
    bool *visitados = calloc(grafo->n, sizeof(bool));
    visitados[v] = true;

    printf("Camino de %d a %d: ", v, w);
    caminoRecursivo(grafo, v, w, visitados);

    free(visitados);
}

void caminoRecursivo(Grafoc3 *grafo, int v, int w, bool *visitados) {
    printf("%d ", v);

    if (v == w)
        return;

    for (int u = 0; u < grafo->n; u++) {
        if (grafo->Mad[v][u] != 0.0 && !visitados[u]) {
            visitados[u] = true;
            caminoRecursivo(grafo, u, w, visitados);
        }
    }
}

int main(int argc, char *argv[]) {
    // PROBLEMA 1: Crear un grafo desde el archivo S10_datos_grafo_C3.txt
    Grafoc3 *grafo = crearGrafo("S10_datos_grafo_C3.txt");
    if (grafo == NULL) {
        return 1;
    }

    printf("Grafo creado:\n");
    mostrar_grafoc3(grafo);
    printf("\n");

    // PROBLEMA 2: Encontrar los vértices fuente
    int numVerticesFuente;
    int *verticesFuenteArr = verticesFuente(grafo, &numVerticesFuente);

    printf("Resultados del problema 2 (vértices fuente):\n");
    for (int i = 0; i < numVerticesFuente; i++) {
        printf("%d ", verticesFuenteArr[i]);
    }
    printf("\n");

    free(verticesFuenteArr);

    printf("\n");

    // PROBLEMA 3: Encontrar todos los nodos en un camino de v a w
    int v = 0; // Vértice inicial
    int w = 5; // Vértice final

    printf("Resultados del problema 3 (camino de %d a %d):\n", v, w);
    encontrarCamino(grafo, v, w);

    printf("\n\n");

    // Liberar la memoria utilizada por el grafo
    for (int i = 0; i < grafo->n; i++) {
        free(grafo->Mad[i]);
    }
    free(grafo->Mad);
    free(grafo);

    return 0;
}

