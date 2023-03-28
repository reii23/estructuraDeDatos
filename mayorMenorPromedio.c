// prograsma que recibe un largo n y valores en base al largo del arreglo para crear un arreglo, por pantalla se entrega el //
// elemento mayor, el elemento menor y el promedio entre todos los elementos del arreglo //

#include <stdio.h>

struct Arreglo {   // definición de la estructura Arreglo
    int n;         
    int A[100];
};

int main() {
    int i, cantElementos=0;   // declaración de variables
    struct Arreglo Arreglo;   // declaración de la variable de tipo array
    
    printf("Ingrese el largo del arreglo: ");
    scanf("%d", &Arreglo.n);   // solicita al usuario el largo del arreglo y lo almacena en Arreglo.n
    
    printf("Ingrese los valores del arreglo:\n");
    
    for(i=0; i<Arreglo.n; i++) {
        scanf("%d", &Arreglo.A[i]);   // ingresa los valores del arreglo y los almacena en Arreglo.A[i]
        cantElementos++;   // cuenta la cantidad de elementos ingresados
    }
    
    int max = Arreglo.A[0];   // se inicializan las variables " maximo, minimo, suma en 0"
    int min = Arreglo.A[0];   
    int suma = 0;   
    float promedio;   
    
    for(i=0; i<Arreglo.n; i++) {   // se recorre el arreglo
        if(Arreglo.A[i] > max) {   // si el elemento actual es mayor que el valor máximo
            max = Arreglo.A[i];   // actualiza el valor máximo
        }
        
        if(Arreglo.A[i] < min) {   // si el elemento actual es menor que el valor mínimo
            min = Arreglo.A[i];   // actualiza el valor mínimo
        }
        
        suma += Arreglo.A[i];   // suma el elemento actual a la variable suma
    }
    
    promedio = (float) suma / Arreglo.n;   // calcula el promedio del arreglo (suma de todos los elementos dividido en el largo del arreglo)
    
    printf("\nEl mayor elemento del arreglo es: %d", max);   // muestra el valor máximo
    printf("\nEl menor elemento del arreglo es: %d", min);   // muestra el valor mínimo
    printf("\nEl promedio de los valores del arreglo es: %.2f", promedio);   // muestra el promedio

}