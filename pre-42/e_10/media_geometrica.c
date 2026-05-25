// crear un programa que calcuele la media geometrica de 3 numeros

//librerias
#include<stdio.h>
#include<math.h>

//funcion principal
int main (void) {

    //variables
    float n1, n2, n3, MG;

    //entrada de datos
    printf ("introducir numero 1: ");
    scanf ("%f" , &n1);
    printf ("introducir numero 2: ");
    scanf ("%f" , &n2);
    printf ("introducir numero 3: ");
    scanf ("%f" , &n3);

    //calculo de la media geometrica

    MG = cbrt(n1 * n2 * n3);

    //salida de datos
    printf ("El resultado es : %.2f \n" , MG);


    return 0;
}