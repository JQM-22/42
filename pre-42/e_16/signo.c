// introducir nombre y signo zodiaco, e imprimir nombre, solo si el signo es Aries

//librerias
#include<stdio.h>
#include<string.h>

//funcion principal
int main (void){

//variabels
char nombre[20] , signo[20];

//entrada de datos
printf ("introducir nombre: ");
scanf ("%19s" , nombre);
printf ("Introducir signo del zodiaco: ");
scanf ("%19s" , signo);

//proceso
if (strcmp (signo , "aries") == 0 ) {
    printf ("El signo de %s es Aries \n" , nombre);
}
else {
    printf ("El signo de %s NO es Aries \n" , nombre);
}


    return 0;
}