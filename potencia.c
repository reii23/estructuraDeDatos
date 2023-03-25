#include <stdio.h>

int main() {
    int a, b, resultado = 1;

    printf("Ingrese el valor de a: ");
    scanf("%d", &a);

    printf("Ingrese el valor de b: ");
    scanf("%d", &b);

    for(int i = 1; i <= b; i++) {
        resultado *= a;
    }

    printf("%d elevado a %d es igual a %d\n", a, b, resultado);

    return 0;
}
