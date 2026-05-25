// comprobar si un alumno ha aprobado un examen, nota minima para aprobar 5.

//librerias
#include<stdio.h>

//funcion principal
int main(void) {

    //variables
    float nota;

    //entrada de datos
    printf(" introducir nota del alumno: ");
    scanf ("%f" , & nota);

    //proceso

    if (nota >= 5) {
        printf (" El alumno esta aprobado \n");
    }

    if (nota < 5) {
        printf (" El alumno esta suspenso \n");
    }



    return 0;
}