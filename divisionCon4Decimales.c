// Programa que recibe un valor a y un valor b y entrega la división de a respecto a b con un truncamiento de 4 decimales //
// nota: para obtener el resultado con 4 decimales se utiliza el método %4lf\n el cual se puede modificar con la cantidad de
// decimales deseada //
w
#include <stdio.h>

int main() {
    double a, b, resultado;

    printf("Introduce el valor de a: ");
    scanf("%lf", &a);

    printf("Introduce el valor de b: ");
    scanf("%lf", &b);

    resultado = a / b;

    printf("Resultado: %.4lf\n", resultado);

    return 0;
}
