// calcular el salario de un trabajador, sabiendo el numero de horas y el valor por hora.

//librerias
#include<stdio.h>

//funcion principal
int main (void) {

    //variables
    float horas, valor_hora, salario;

    //entrada de datos
    printf ("introducir numero de horas trabajadas: ");
    scanf ("%f", &horas);
    printf(" Introducir valor de hora: ");
    scanf("%f", &valor_hora);

    //calculo de salario
    salario = horas * valor_hora;

    //salida de datos
    printf ("El salario a pargar es: %.2f € \n" , salario);


    return 0;
}