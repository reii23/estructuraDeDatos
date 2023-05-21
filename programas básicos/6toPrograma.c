// uso de scanf //
/*
#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a);

  printf("Ingresaste: %d", a);

  return 0;
}
*/

/* El signo & antes del nombre de la variable es el operador de dirección.
Da la dirección, o ubicación en la memoria, de una variable.
Esto es necesario porque scanf coloca un valor de entrada en una dirección variable */


// programa que entrega la suma de dos numeros entregados por el usuario //
#include <stdio.h>

int main() {
  int a, b;
  printf("Ingresa dos numeros:");
  scanf("%d %d", &a, &b); // las entradas se almacenan en %d %d en &a y &b

  printf("\nLa suma de ambos numeros es: %d", a+b);

  return 0;
}