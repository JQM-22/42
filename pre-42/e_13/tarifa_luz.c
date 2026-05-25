// ver tarifa de la luz, segun la franja de consumo
// menor de 1000 kWh, tarifa de 1.2 €/kWh
// entre 1000 y 5000 kWh, tarifa de 1.0 €/kWh
// mayor de 5000 kWh, tarifa de 0.8 €/kWh   

//librerias
#include <stdio.h>

//funcion principal
int main (void) {

    //variables
    float gasto, t1, t2, t3;

    //entrada de datos
    printf ("introducir gasto en kwh: ");
    scanf ("%f" , &gasto);

    //calculo de tarifas
    t1 = gasto * 1.2;
    t2 = gasto * 1.0;
    t3 = gasto * 0.8;

    //condicionales para mostrar tarifa segun gasto
    if (gasto < 1000) {
        printf ("tarifa a pagar: %.2f euros\n", t1);
    }

    if (gasto >= 1000 && gasto <= 5000) {
        printf ("tarifa a pagar: %.2f euros\n", t2);
    }

    if (gasto > 5000) {
        printf ("tarifa a pagar: %.2f euros\n", t3);
    }   



    return 0;
}