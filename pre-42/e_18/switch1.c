/*sentencia SWITCH
switch ( selector){
case etiqueta1 : sentencia1 ; break;
case etiqueta2 : sentencia2 ; break;
case etiqueta3 : sentencia3 ; break;
default : sentencia ;
}
*/

//ejemplo del numero

//Librerias 
#include<stdio.h>

//funcion principal
int main (void) {

    //variables
    int numero;

    //entrada de datos
    printf ("introduzca un numero entre 1 - 3: ");
    scanf ("%d" , & numero);

    //proceso
    switch (numero) {
        case 1 : printf("es el numero 1 \n"); break;
        case 2 : printf("es el numero 2 \n"); break;
        case 3 : printf("es el numero 3 \n"); break;
        default : printf ("el numero no es correcto \n");
    }


    return 0;
}