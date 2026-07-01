EXPLICACION DE ENTRADA POR PARAMETROS EN TERMINAL

#include <stdio.h> // declaramos un caracter

int ft_strlen(char *string)
{
    int i; // creamos un entero
    
    i = 0; // le damos un valor
    while (string[i] != '\0') // mientras que i no sea nulo, seguimos sumando
    {
        i++;
    }
    return (i); // cuando no se cumpla el while devuelve i (el resultado)
}

int main(int argc, char **argv) // entero que cuenta el numero de letras de argumento / argumentos que le damos
{
    /* argc -> 3 -> numero de argumentos
    argv -> ["a.out", "patata", "patato"]
    
    array 0 -> argv[0] -> a.out <-- el nombre del archivo tambien es un argumento
    array 1 -> argv[1] -> patata
    array 2 -> argv[2] -> patato
    
    argv[0][2] = "o" -> del array 0 la segunda posicion
    
    Esto es si queremos darle nosotros el valor en el main
    */

    char *str1 = argv[1]; // damos las direcciones de los argumentos
    char *str2 = argv[2]; // damos las direcciones de los argumentos
    
    int len_str1; // creamos los enteros que se comparan
    int len_str2; // creamos los enteros que se comparan
    
    if (argc != 3) // si no es = a 3 el numero de argumentos
    {
        printf("error en numero de argumentos\n");
        return (1); // esto solo se printea en caso de no ser igual a 3
    }
    
    len_str1 = ft_strlen(str1); // aqui llamamos al valor de str1
    len_str2 = ft_strlen(str2); // "" "" "" str2
    
    if (len_str1 != len_str2) // comparamos los dos argumentos y
    {
        printf("miden distinto\n");
    }
    else
    {
        printf("miden igual\n");
    }
    
    return 0; // termina el programa
}
