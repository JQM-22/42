// sentencia if de dos alternativas: if - else
/* if (condicion)
    accion1
else
    accion2*/

//nota del estudiante

//librerias
#include<stdio.h>

//funcion principal
int main (void) {

    //variables 
    float nota;

    //entrada de datos
    printf ("introducir nota del alumno: ");
    scanf ("%f" , & nota);

    //proceso
    if (nota >= 5.0) {
        printf ("aprobado \n");
    }
    else {
        printf ("suspendido \n");
    }

    return 0;
}