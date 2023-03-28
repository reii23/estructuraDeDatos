// crea un programa en c que Dado un arreglo A de enteros de largo n,
// y un valor x, retornar verdadero si el valor x existe en el arreglo, o falso en caso contrario. utilizando funciones //

#include <stdio.h>

// Función que busca un número en un arreglo //
int buscarNumero(int arreglo[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arreglo[i] == x) {
            return 1;
        }
    }
    return 0;
}

// Función principal //
int main() {
    int arreglo[] = {1, 2, 3, 4, 5}; // arreglo //
    int n = 5; // largo del arreglo //
    int x = 3; // numero que se quiere buscar en el arreglo //

    // Llamamos a la función para buscar el número
    if (buscarNumero(arreglo, n, x)) {
        printf("El numero %d se encuentra en el arreglo.\n", x);
    } else {
        printf("El numero %d no se encuentra en el arreglo.\n", x);
    }
}