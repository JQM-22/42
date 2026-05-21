//Tipos de datos en C

#include <stdio.h>

int main() {
    // Tipos de datos enteros
    int entero = 42;   //Tamaño en la maquina = 4 bytes, rango= -2147483648 a 2147483647
    long entero_largo = 1234567890;   //Tamaño en la maquina = 8 bytes, rango= -9223372036854775808 a 9223372036854775807
    short entero_corto = 32767;   //Tamaño en la maquina = 2 bytes, rango= -32768 a 32767
    unsigned int entero_sin_signo = 255; //Tamaño en la maquina = 4 bytes, rango= 0 a 4294967295

    // Tipos de datos de punto flotante
    float flotante = 3.14f;   //Tamaño en la maquina = 4 bytes, rango= 1.2E-38 a 3.4E+38, precisión de 6 dígitos decimales
    double doble_flotante = 2.71828;   //Tamaño en la maquina = 8 bytes, rango= 2.3E-308 a 1.7E+308, precisión de 15 dígitos decimales

    // Tipo de dato de carácter
    char caracter = 'A';   //Tamaño en la maquina = 1 byte, rango= 0 a 255

    // Tipo de dato booleano (en C99 y posteriores)
    _Bool booleano_verdadero = 1; // true
    _Bool booleano_falso = 0; // false

    // Imprimir los valores
    printf("Entero: %i\n", entero);
    printf("Entero largo: %li\n", entero_largo);
    printf("Entero corto: %i\n", entero_corto);
    printf("Entero sin signo: %u\n", entero_sin_signo);

    printf("Flotante: %.2f\n", flotante);
    printf("Doble flotante: %.5f\n", doble_flotante);

    printf("Carácter: %c\n", caracter);
    
    printf("Booleano verdadero: %d\n", booleano_verdadero);
    printf("Booleano falso: %d\n", booleano_falso);

    return 0;
}