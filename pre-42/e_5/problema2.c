// convertir grados Celsius en Grados Fahrenheit

#include <stdio.h>

int main () {

    //datos de entrada
    int celsius;
    int fahrenheit;

    printf("introduzca los grados Celsius:  " );
    scanf("%d", &celsius);

    //proceso
    fahrenheit = (celsius * 9/5) + 32;

    //salida
    printf("los grados Fahrenheit son: %d", fahrenheit );
    

    return 0;
}