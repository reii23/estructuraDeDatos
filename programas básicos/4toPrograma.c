// programa que entrega el tamaño en bites de cada uno de los tipos de datos: entero, flotante, doble y caracter //

#include <stdio.h>

int main() {
  printf("int: %ld \n", sizeof(int));
  printf("float: %ld \n", sizeof(float));
  printf("double: %ld \n", sizeof(double));
  printf("char: %ld \n", sizeof(char));
  return 0;
}