//Directivas del pre-procesador y Variables globales
//libreria
#include <stdio.h>

//macro define una constante
#define PI 3.1416

int y = 5; //variable global, porque se encuentra fuera de cualquier funcion

int main() {
    int x = 10; //variable local, porque se encuentra dentro de una funcion
    
    float suma = 0;
    suma = PI + x;

    printf("La suma de PI y x es: %.2f\n", suma);
    


    return 0;
}
