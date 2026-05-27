// ingrese un numero y calcule e imprima su raiz cuadrada. 
//si el numero es negativo imprimir el numero y un mensaje que diga " tiene raiz imaginaria"

//librerias
#include<stdio.h>
#include<math.h>

//funcion principal
int main (void) {

//variables
float numero, resultado;

//entrada de datos
printf ("introducir un numero: ");
scanf ("%f" , &numero);

//proceso
if (numero > 0) {
    resultado = sqrt(numero);
    printf ("La raiz cuadrada de %.2f es: %.2f \n" , numero , resultado);
}
else {
    printf ("El numero %.2f tiene raiz cuadrada imaginaria \n" , numero);
}


    return 0;
}