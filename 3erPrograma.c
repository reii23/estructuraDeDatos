// Programa que recibe una cantidad de días y los transforma a segundos //
#include <stdio.h>
int main() {
    int cantidadDias, cantidadSegundos;

    printf("Ingresa la cantidad de dias a transformar: ");
    scanf("%d", &cantidadDias);

    cantidadSegundos = cantidadDias * 24 * 60 * 60;
    printf("La cantidad de segundos es: %d\n", cantidadSegundos);

    return 0;
}
