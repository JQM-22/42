//Sacar la hipotenusa de un triangulo rectangulo, pidinedo al usuario el valor de los dos catetos

//Librerias
#include<stdio.h>
#include<math.h>

int main(void){

    //datos de entrada
    float cateto1, cateto2, hipotenusa;

    //pedir al usuario los catetos
    printf("Ingrese el valor del primer cateto: ");
    scanf("%f", &cateto1);
    printf("Ingrese el valor del segundo cateto: ");
    scanf("%f", &cateto2);

    //proceso
    hipotenusa = sqrt (pow(cateto1, 2) + pow(cateto2, 2));
   
    //salida
    printf("La hipotenusa del triangulo rectangulo es: %.2f\n", hipotenusa);    
    
    // al compilar, cc hipotenusa.c -lm, 
    // se debe agregar la libreria math para poder usar la funcion sqrt y pow

    return 0;
}