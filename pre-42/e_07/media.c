//calcular la media aritmetica de 3 numeros cualesquiera

//Librerias
#include<stdio.h>

// funcion principal
int main (void) {

    //variables
    float num1, num2, num3, media; 

    //entrada de datos
    printf ("introduzca num1: "); 
    scanf ("%f" , &num1);
    printf ("introduzca num2: ");
    scanf ("%f" , &num2);
    printf ("introduzca num3: ");
    scanf ("%f" , &num3);
   

    //calculo de la media
    media = (num1 + num2 + num3) / 3;

    //salida de datos
    printf ("la media es: %f\n" , media);

    return 0;
}

