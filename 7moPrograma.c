// programa que entrega la potencia entre dos numeros //
#include <stdio.h>

int main() {
    int base, exponente;
    int i, resultado = 1;

    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);

    for (i = 0; i < exponente; i++) {
        resultado *= base;
    }
    printf("El resultado de %d elevado a %d es: %d\n", base, exponente, resultado);

    return 0;
}
