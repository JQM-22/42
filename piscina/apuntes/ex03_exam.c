#include <unistd.h>

/*int main(void)
{
    char    str[] = "Wellcome to 42 school";
    int     i;

    i = 1;
    while (str[i] != '\0')
    {
        if (i == i * 3)
            str[i] = '5';
        else
            *str = *str;
        write (1, &str[i], 1);
        i++;
    }
    write (1, "\n", 1);
    return (0);
}
HASTA AQUI, LO QUE HE PRESENTADO N EL EXAMEN, LA BASE ES ESTA, LO HE HECHO DE VARIAS FORMAS DIFERENTES*/


//FORMA CORRECTA DE HACERLO//

#include <unistd.h>

int main(void)
{
    char    str[] = "Wellcome to 42 school";
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        // Si es la posición 0, no tocamos nada y pasamos de largo
        if (i == 0)
        {
            // No hace nada, se salta los múltiplos
        }
        // 1. ¿Es múltiplo de 3 y de 5 al mismo tiempo? (Múltiplo de 15)
        else if (i % 3 == 0 && i % 5 == 0)
        {
            str[i] = '5';
        }
        // 2. ¿Es múltiplo de 3?
        else if (i % 3 == 0)
        {
            str[i] = '5';
        }
        // 3. ¿Es múltiplo de 5?
        else if (i % 5 == 0)
        {
            str[i] = '3';
        }

        // Se imprime la 'W' intacta o el carácter que corresponda
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}

/* pra solucionar el problema de la decalracion de variables y la inicializacion en la misma linea, como en el caso de las str
 * char    str[] = "Wellcome to 42 school";
 * esto se puede hacer, como varible global, poniendola antes del main, la Norminette lo detecta como "Notice", no como error, lo pasaria, pero te dice que verifiques que no haya otra opcion mejor.
 *
 * tambien se podria hacer una funcion auxiliar para rellenar la string, y luego llamar a la fucnion desde el main, para inicializar:
 * #include <unistd.h>

// Función auxiliar para rellenar la cadena sin romper la Norminette
void    fill_str(char *str)
{
    str[0] = 'W'; str[1] = 'e'; str[2] = 'l'; str[3] = 'l'; str[4] = 'c';
    str[5] = 'o'; str[6] = 'm'; str[7] = 'e'; str[8] = ' '; str[9] = 't';
    str[10] = 'o'; str[11] = ' '; str[12] = '4'; str[13] = '2'; str[14] = ' ';
    str[15] = 's'; str[16] = 'c'; str[17] = 'h'; str[18] = 'o'; str[19] = 'o';
    str[20] = 'l'; str[21] = '\0'; // Crucial el carácter nulo
}

int main(void)
{
    char    str[22]; // Declaración limpia de 21 letras + '\0'
    int     i;

    fill_str(str); // Inicialización en una línea separada
    i = 0;
    while (str[i] != '\0')
    {
        if (i == 0)
        {
            // Nada
        }
        else if (i % 3 == 0 && i % 5 == 0)
        {
            str[i] = '5';
        }
        else if (i % 3 == 0)
        {
            str[i] = '5';
        }
        else if (i % 5 == 0)
        {
            str[i] = '3';
        }
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}*/
