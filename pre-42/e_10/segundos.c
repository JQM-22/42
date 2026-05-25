// calcular el numero de segundos que hay en un numero de horas, minutos y segundos ingresados pur el usiario

//librerias
#include<stdio.h>

//funcion principal
int main(void){

    //variables
    float h, m, s, total;

    //entrada de datos
    printf ("Introducir horas:  ");
    scanf ("%f" , &h);
    printf ("Introducir minutos:  ");
    scanf ("%f" , &m);
    printf ("Introducir segundos:  ");
    scanf ("%f" , &s);

    //calculo
    total = (h * 3600) + (m * 60) + (s);

    //salida de datos

    printf ("El resultado en segundos es:  %.2f seg \n" , total);

    return 0;
}