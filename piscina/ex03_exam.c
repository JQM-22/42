#include <unistd.h>

// Se declara e inicializa FUERA del main. Aquí la Norminette no se queja.
static char    g_str[] = "Wellcome to 42 school";

int main(void)
{
    int     i;

    i = 0;
    while (g_str[i] != '\0')
    {
        if (i == 0)
        {
            // No hace nada
        }
        else if (i % 3 == 0 && i % 5 == 0)
        {
            g_str[i] = '5';
        }
        else if (i % 3 == 0)
        {
            g_str[i] = '5';
        }
        else if (i % 5 == 0)
        {
            g_str[i] = '3';
        }
        write(1, &g_str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}