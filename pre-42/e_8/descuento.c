// Una tienda ofrece un descuento del 15% sobre el total de la compra

//librerias
#include <stdio.h>

//funcion principal
int main (void) {

    //entrada de datos
    float total_compra, descuento, total_pagar;

    //entrada de datos
    printf("introducir total de compra:  ");
    scanf("%f" , &total_compra);

    //calculo del descuento
    descuento = total_compra * 0.15;

    //calculo del total a pagar
    total_pagar = total_compra - descuento;

    //salida de datos
    printf (" Total a pagar con descuento aplicado: %.2f € \n" , total_pagar );




    return 0;
}
