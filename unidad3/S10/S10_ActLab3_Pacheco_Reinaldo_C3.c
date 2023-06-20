#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "S10_TDAGrafoMa_C3.h"

void recorrerGrafo(Grafoc3 *grafo, int v, int w, bool *visitados);

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

// PROBLEMA 2: Encontrar los vértices sumidero de un grafo dirigido, "vertice sumidero: no tiene antecesores"
int *verticesSumidero(Grafoc3 *grafo, int *numVerticesSumidero) {
    int *vertices = NULL;
    *numVerticesSumidero = 0; // iniciio el num de vertices sumidero
    for (int v = 0; v < grafo->n; v++) {
        bool tieneAntecesores = false; // vertice sumidero se centra en la cantidad de antecesores que tiene el grafo
        for (int u = 0; u < grafo->n; u++) {
            if (grafo->Mad[u][v] != 0.0) {
                tieneAntecesores = true;
                break;} }
        if (!tieneAntecesores) {
            (*numVerticesSumidero)++;
            vertices = realloc(vertices, sizeof(int) * (*numVerticesSumidero));
            vertices[(*numVerticesSumidero) - 1] = v;}}
    return vertices;}

// PROBLEMA 3: Encontrar el camino mas largo
void encontrarCamino(Grafoc3 *grafo, int v, int w) { // encontraar camino para el grafo //
    bool *visitados = calloc(grafo->n, sizeof(bool));
    visitados[v] = true; // si fue visitado//
    recorrerGrafo(grafo, v, w, visitados);
    free(visitados);}

void recorrerGrafo(Grafoc3 *grafo, int v, int w, bool *visitados) {
    printf("%d ", v);
    if (v == w)
        return;
    for (int u = 0; u < grafo->n; u++) {
        if (grafo->Mad[v][u] != 0.0 && !visitados[u]) { // si está conectado y aún no ha sido visitado
            visitados[u] = true;
            recorrerGrafo(grafo, u, w, visitados); }}} // retorno la cant de nodos visitados (camino mas largo)

// MAIN //
int main(int argc, char *argv[]) {
    // PROBLEMA 1: Crear un grafo desde el archivo S10_datos_grafo_C3.txt
    Grafoc3 *grafo = crearGrafo("S10_datos_grafo_C3.txt");
    if (grafo == NULL) {
        return 1; }
    mostrar_grafoc3(grafo);
    printf("\n");

    // PROBLEMA 2: Encontrar los vértices Sumidero
    int numVerticesSumidero; // defino la var que cuenta el numero de vertices sumidero //
    int *verticesSumideroArr = verticesSumidero(grafo, &numVerticesSumidero); // defino el arreglo //

    printf("Resultados del problema 2 (vertices Sumidero):\n");
    for (int i = 0; i < numVerticesSumidero; i++) {
        printf("%d ", verticesSumideroArr[i]);} // entrego el arreglo de verticesSumidero
    printf("\n");

    printf("\n");

    // PROBLEMA 3: Encontrar el camino más largo
    int v = 0;
    int w = 7; 
    int visitados = 0;
    printf("Resultados del problema 3 (camino mas largo):\n", v, w,visitados); // retorno el camino mas largo //
    encontrarCamino(grafo, v, w);
    printf("\n\n");
    return 0;
}