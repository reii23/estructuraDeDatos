
// LAB 1 //
/* Nombre: Reinaldo Pacheco Parra
Asignatura: Estructura de Datos
Sección : C-3 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("datosC3.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
    }
    int n;
    fscanf(fp,"%d",&n); // lectura cant de datos del archivo//

    int *datos = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {   // almaceno los datos en un arreglo//
        fscanf(fp,"%d",&datos[i]);
    }
    fclose(fp);

    printf("elementos leidos:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    FILE *salida = fopen("salida.txt", "w");
    if (salida == NULL) {
        printf("Error al crear el archivo de salida\n");
    }
    int cantTotal = n;
    int cantDivisibiles = 0; // muestro la cant de elementos //
    fprintf(salida, "La cantidad total de elementos: %d\n", cantTotal);
    fprintf(salida, "Los elementos divisibles por 3 son: "); // elementos divisibles por 3 //
    for (int i = 0; i < n; i++) {
        if (datos[i]%3==0) {
            cantDivisibiles++;
            fprintf(salida, "%d ", datos[i]);
        }
    }
    fprintf(salida,"\n");   // elementeos que no se dividen por 3 //
    fprintf(salida,"Los elementos no divisibles por 3 son: ");
    for (int i = 0; i < n; i++) {
        if (datos[i] % 3 != 0) {
            fprintf(salida, "%d ", datos[i]);
        }
    }
    fprintf(salida, "\n");
    printf("se ha creado un archivo llamado salida.txt que contiene la informacion requerida:\n");

    // Cerrar el archivo de salida
    fclose(salida);
}
