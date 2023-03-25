// Programa que recibe dos numeros enteros por consola y entrega por pantalla el menor de ellos //

#include <stdio.h>

int main() {
    int a, b, menor;
    
    printf("Ingrese el primer entero: ");
    scanf("%d", &a);
    
    printf("Ingrese el segundo entero: ");
    scanf("%d", &b);
    
    if (a < b) {
        menor = a;
    } else {
        menor = b;
    }
    
    printf("El menor entero es: %d\n", menor);
    
    return 0;
}
