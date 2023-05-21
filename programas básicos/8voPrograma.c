// programa que utiliza el bucle "for" para imprimir los numeros del 0 al 9, para ello se utiliza //
// un valor inicial 0, y la condición de que mientras el numero sea menor al maximo se imprima, //
// incrementando el numero en cada una de las iteraciones //

#include <stdio.h>
int main() {
    int i;
    int max = 30;
    for (i = 0; i < max; i++) {
        printf("%d\n", i);
    }
}