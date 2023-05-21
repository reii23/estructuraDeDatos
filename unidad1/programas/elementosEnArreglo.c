// programa que dados dos arreglos "A" y "B" entregados por consola cuenta la cantidad de veces que cada elemento de A
// se encuentra dentro del arreglo B //

#include <stdio.h>

// Definición de la estructura Arreglo
struct Arreglo {
    int n;           // Largo del arreglo
    int A[100];      // Arreglo de enteros de longitud máxima 100
};

int main() {
    int i, j;         // Declaración de variables de tipo entero
    struct Arreglo arrA, arrB;   // Declaración de dos variables de tipo Arreglo

    printf("Ingrese el largo de los arreglos: ");
    scanf("%d", &arrA.n);    // Solicita al usuario el largo de los arreglos y lo almacena en arrA.n y arrB.n
    arrB.n = arrA.n;

    printf("Ingrese los valores del arreglo A:\n");
    for(i=0; i<arrA.n; i++) {
        scanf("%d", &arrA.A[i]);   // Ingresa los valores del arreglo A y los almacena en arrA.A[i]
    }
    
    printf("Ingrese los valores del arreglo B:\n");
    for(i=0; i<arrB.n; i++) {
        scanf("%d", &arrB.A[i]);   // Ingresa los valores del arreglo B y los almacena en arrB.A[i]
    }
    
    printf("\nCantidad de veces que cada elemento de A se encuentra en B:\n");
    for(i=0; i<arrA.n; i++) {
        int count = 0;   // Inicializa la variable count en 0
        for(j=0; j<arrB.n; j++) {
            if(arrA.A[i] == arrB.A[j]) {   // Si el elemento actual de A se encuentra en B
                count++;   // Incrementa el contador
            }
        }
        printf("%d: %d\n", arrA.A[i], count);   // Muestra la cantidad de veces que el elemento actual de A se encuentra en B
}
    }