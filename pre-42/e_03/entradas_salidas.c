//Entradas y salidas de datos

#include <stdio.h>

int main() {
    
    //salida de varios datos en un mismo prinf
    /*int a = 10;
    float b = 3.14;
    char c = 'A';

    printf("El valor de a es: %d, el valor de b es: %.2f, el valor de c es: %c\n", a, b, c);*/

    //Entrada de datos con scanf
    int a;
    float b;
    char c; 

    printf("Ingrese un numero entero: ");
    scanf("%d", &a);
    printf("El valor de a es: %d\n", a); 

    printf("Ingrese un numero flotante: ");
    scanf("%f", &b);
    printf("El valor de b es: %.2f\n", b);

    printf("Ingrese un caracter: ");
    scanf(" %c", &c);
    printf("El valor de c es: %c\n", c);

    char nombre[50];
    printf("Escriba su nombre:  ");
    scanf("%s", nombre);  //scanf no es recomendado para leer cadenas de texto, recorta cuando encuentra un espacio
    printf("Su nombre es:  %s\n", nombre);
    


    return 0;
}