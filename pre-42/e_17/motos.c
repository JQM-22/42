/* una tienda de motos tiene una promocion:
Honda dto del 5%
Yamaha dto del 8%
Suzuki dto del 10%
Resto de marcas dto del 2%*/

//librerias
#include<stdio.h>
#include<string.h>

//funcion principal
int main (void) {

    //variables
    char honda , yamaha , suzuki , otra , marca[20];

    //entrada de datos
    printf ("introduzca marca de la que desea conocer el descuento: ");
    scanf (" %19s" , marca);

    //proceso
    if (strcmp(marca , "honda") == 0) {
        printf ("su descuento es del 5 por ciento \n");
    }
    else if (strcmp(marca , "yamaha") == 0) {
        printf ("su descuento es del 8 por ciento \n");
    }
    else if (strcmp(marca , "suzuki") == 0) {
        printf ("su descuento es del 10 por ciento \n");
    }
    else {
        printf ("su descuento es del 2 por ciento \n");
    }

    return 0;
}