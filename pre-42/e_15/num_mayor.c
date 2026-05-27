// comprobar el mayor de dos numeros

//librerias
#include<stdio.h>

//funcion principal
int main (void) {

    float num1, num2;

    //entrada de datos
    printf ("introducir numero 1: ");
    scanf ("%f" , &num1);
    printf ("introducir numero 2: ");
    scanf ("%f" , &num2);

    //proceso
    if (num1 < num2) {
        printf ("El mayor nuumero es : %.2f \n" , num2);
    }
    else 
        if (num1 > num2) {
        printf ("El mayor numero es: %.2f \n" , num1);
        }
        else {
        printf ("Ambos numeros son iguales \n"); 
        }           

 
    return 0;
}