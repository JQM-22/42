/*sentencia SWITCH
switch ( selector){
case etiqueta1 : sentencia1 ; break;
case etiqueta2 : sentencia2 ; break;
case etiqueta3 : sentencia3 ; break;
default : sentencia ;
}
*/

//ejemplo de la vocal

//librerias
#include<stdio.h>

//funcion principal
int main (void){

    //variables
    char vocal;

    //entrada de datos
    printf ("intriducir una vocal: ");
    scanf ("%c" , & vocal);

    //proceso
    switch (vocal) {
        case 'a' : printf ("es la vocal A\n"); break;
        case 'e' : printf ("es la vocal E\n"); break;
        case 'i' : printf ("es la vocal I\n"); break;
        case 'o' : printf ("es la vocal O\n"); break;
        case 'u' : printf ("es la vocal U\n"); break;
        default : printf ("la letra no es vocal \n");
    }


    return 0;
}