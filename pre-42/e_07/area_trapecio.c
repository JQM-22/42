// Hacer un programa que calcule areas de trapecios

//librerias
#include<stdio.h>
#include<math.h>

//funcion principal
int main (void){

    //Variables
    float base_mayor, base_menor, altura, area;

    //Entrada de datos
    printf ("introducir la base mayor del trapecio: ");
    scanf ("%f" , &base_mayor);
    printf ("introducir la base menor del trapecio: ");
    scanf ("%f" , &base_menor);
    printf ("introducir la altura del trapecio: ");
    scanf ("%f" , &altura);

    //Proceso
    area = (base_mayor + base_menor) * altura / 2;

    //Salida de datos
    printf ("el area del trapecio es: %.2f\n" , area);    
    


    return 0;
}