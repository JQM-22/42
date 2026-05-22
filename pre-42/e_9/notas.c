/* calcular la califiacion final de un estudiante, 
La calificacion se compone de:
55% del promedio de sus 3 examenes parciales
30% de la calificacion del examen final
15% de la calificacion de los trabajos practicos */

//librerias
#include <stdio.h>

//funcion principal
int main (void) {

    //variables
    float parcial1, parcial2, parcial3, media_parciales, nota_examen_final, nota_trabajos_practicos, nota_final;

    //entrada de datos
    printf ("ingresar calificacion de primer parcial: ");
    scanf ("%f", &parcial1);
    printf ("ingresar calificacion de segundo parcial: ");
    scanf ("%f" , &parcial2);
    printf ("ingresar calificacion de tercer parcial: ");
    scanf ("%f", &parcial3);
    printf ("ingresar calificacion del examen final: ");
    scanf ("%f", &nota_examen_final);
    printf ("ingresar calificacion de los trabajos practicos: ");
    scanf ("%f", &nota_trabajos_practicos);

    //calculo de nota media de parciales
    media_parciales = (parcial1 + parcial2 + parcial3) /3;

    //calculo de nota final
    nota_final = ((media_parciales * 0.55) + (nota_examen_final * 0.30) + (nota_trabajos_practicos * 0.15));

    //salida de datos
    printf (" La nota final del estudiante es:  %.2f \n" , nota_final);

 return 0;

}