// programa que utiliza los tipos de datos entero, flotante y char //
#include <stdio.h>

int main() {
  int a, b;
  float salario = 56.23; // se asigna el numero 56.23 a la variable flotante //
  char letra = 'Z'; // se asigna la letra Z a la variable caracter //
  a = 8;
  b = 34;
  int c = a+b; // se asigna la suma de a y b a la variable entero //

  printf("%d \n", c); // se muestra el valor dentro de la variable entero "c"
  printf("%f \n", salario);
  printf("%c \n", letra); 

  return 0;
}