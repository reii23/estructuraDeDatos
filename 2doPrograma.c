// Programa que entrega un nombre y edad actual //
#include <stdio.h>
int main ()
{
    int fechaActual;
    int fechaNacimiento;
    int edad;

    fechaActual = 2022;
    fechaNacimiento = 2002;
    edad = fechaActual - fechaNacimiento;
    
    printf("Hola Reinaldo, tu naciste el año %d, y tu edad es de %d años", fechaNacimiento, edad);
    printf("\n");
    return 0;
}