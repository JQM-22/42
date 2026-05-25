// determinar si un numero es par o impar

//librerias
#include<stdio.h>

//funcion principal
int main (void) {

    //variables
    int numero;

    //entrada de datos
    printf ("introducir numero: ");
    scanf ("%d" , & numero);

    //proceso

    if (numero % 2 == 0) {
        printf ("el numero es par \n");
    }

    if (numero % 2 != 0) {
        printf ("el numero es impar \n");
    }

    return 0;
}