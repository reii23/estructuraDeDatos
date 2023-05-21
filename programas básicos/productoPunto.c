// programa que recibe dos arreglos A y B y realiza el producto punto entre ellos //
// producto punto: sumar los terminos de la multiplicación de las respectivas posiciones de cada arreglo //

#include <stdio.h>

// Función para calcular el producto punto entre dos arreglos
int productoPunto(int arregloA[], int arregloB[], int n) {
    int resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado += arregloA[i] * arregloB[i];
    }
    return resultado;
}

// Función principal
int main() {
    int arregloA[] = {0, 1, 2}; // primer arreglo //
    int arregloB[] = {3, 4, 5}; // segundo arreglo //
    int n = 3;

    // Calculamos el producto punto
    int resultado = productoPunto(arregloA, arregloB, n);

    // Imprimimos el resultado
    printf("El producto punto entre los arreglos es: %d\n", resultado);

    return 0;
}
