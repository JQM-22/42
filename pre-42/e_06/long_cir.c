//Calcular longitudes de circunferencia

//Librerias
#include<stdio.h>
#include<math.h>

int main(void)
{
   
    //datos
    float PI=3.1416, radio, longitud;

    //entrada
    printf("Ingrese el radio de la circunferencia: ");
    scanf("%f" , &radio);

    //proceso
    longitud = 2 * PI * radio;

    //salida
    printf(" La longitud de la circunferencia es: %.2f\n" , longitud);


    return 0;
}