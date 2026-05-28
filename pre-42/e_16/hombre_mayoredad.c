// inbresar nombre, edad y sexo
//imprimir nombre solo si la persona es de sexo masculino y mayor de edad

//librerias
#include<stdio.h>
#include<string.h>

//funcion ppal
int main (void) {

    //variables
    char nombre[20], sexo[10];
    int edad;

    //entrada de datos
    printf ("introducir nombre: ");
    scanf ("%19s" , nombre);
    printf ("introducir sexo: ");
    scanf ("%9s" , sexo);
    printf ("introducir edad: ");
    scanf ("%i" , & edad);

    //proceso
    if (strcmp(sexo , "masculino") == 0  && edad >= 18) {                                              
            printf ("%s es hombre y es mayor de edad \n" , nombre);
        
    }
    else {
        printf ("No es hombre o no es mayor de edad\n");
    }



    return 0;
}

