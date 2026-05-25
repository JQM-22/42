// comprobar si un numero es positivo o negativo

//librerias
#include<stdio.h>

//funcion principal
int main (void) {

        //variables
        float numero;

        //entrada de datos
        printf ("introducir numero: ");
        scanf ("%f" , &numero);
    
        //proceso
        if (numero < 0) {
            printf (" el numero es negativo \n");
        } 
        
        else {
            printf (" el numero es positivo \n");
        }


    return 0;
}