// condicionales
// sentencia if: 
// if: (condicion)
// {accion a ejecutar si la condicion es verdadera}


// prueba de divisibilidad

//Librerias
#include<stdio.h>

//funcion principal
int main (void) {

    int n1, n2;

    //entrada de datos
    printf ("introducir numero 1: ");
    scanf ("%d", &n1);  
    printf ("introducir numero 2: ");
    scanf ("%d", &n2);

    //proceso positivo
    if ( n1 % n2 == 0) {
        printf ("%d es divisible entre %d \n" , n1 , n2);   
    }

    //proceso negativo
    if ( n1 % n2 == 1) {
        printf ("%d no es divisible entre %d \n" , n1 , n2);   
    }


    return 0;
}