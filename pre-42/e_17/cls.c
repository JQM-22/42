// hacer un programa que borre la pantalla al pulsar 1

//librerias
#include<stdio.h>
#include<stdlib.h>

//funcion principal
int main (void) {

    char tecla;

    //entrada de datos
    printf ("programa de borrado de pantalla \n");
    printf ("------------------------------- \n");
    printf ("------------------------------- \n");
    printf ("------------------------------- \n");
    printf (" introducir numero 1: ");
    scanf (" %c" , & tecla);

    //proceso
    if (tecla == '1') {
        system ("clear"); //En Linux no exixte "cls" usar "clear"
        printf ("ha funcionado el limpiado de pantalla");
    }
    else {
        //fflush (stdin);  //limpiar memoria del buffer
        /* NO ES NECESARIO fflush, al dejar el espacio en (" %c") ya se consumen salts de linea pendientes, y hace de limpiado de buffer
        es:
        comportamiento indefinido en C estándar,
        funciona “a veces” en algunos compiladores,
        pero NO debes acostumbrarte.
        fflush() está pensado para salida (stdout), no entrada (stdin).
        En Linux/GCC puede comportarse raro. */

        printf ("la tecla presionada no es 1 \n");
        printf ("por favor, introducir numero 1:  ");
        scanf (" %c" , & tecla);

        if (tecla == '1') {
            system ("clear");
            printf ("ha funcionado el limpiado de pantalla \n");
        }
        else {
            printf ("No funcionó \n");
        }
    }


    return 0;
}