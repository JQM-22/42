// 1. Pedir al usuario 2 numeros y sumarlos, restarlos, multiplicarlos y dividirlos

#include <stdio.h>

int main () {

int n1, n2, suma=0, resta=0, mult=0, div=0;


printf("ingrse el primer numero:  ");
scanf("%d" , &n1);
printf("ingrese el segundo numero: ");
scanf("%d" , &n2);

/*prinf("ingrese dos numeros: ");
scanf("%d, %d" , &n1, &n2);*/

suma = n1 + n2;
resta = n1 - n2;
mult = n1 * n2;
div = n1 / n2;  

printf(" La suma de los numeros es: %d \n", suma);
printf(" La resta de los numeros es: %d \n", resta);
printf(" La multiplicacion de los numeros es: %d \n", mult);
printf(" La division de los numeros es: %f \n", div);


    return 0;
}