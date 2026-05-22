//calcular el nuevo salario de un obrero que obtuvo un incremento del 25% sobre su salario anterior

//librerias
#include<stdio.h>

//funcion principal
int main (void) {

    //variables
    float salario_inicial, incremento, salario_final;

    //entrada de datos
    printf ("Introducir salario actual:  ");
    scanf ("%f" , &salario_inicial);

    //calculo del incremento
    incremento = salario_inicial * 0.25;

    //calculo del nuevo salario
    salario_final = salario_inicial + incremento;

    //salida de datos
    printf ("El salario final tras el incremento es:  %.2f € \n" , salario_final);


    return 0;

}
