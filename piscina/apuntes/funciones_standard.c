/* ========================================================================== */
/* */
/* APUNTES EXAMEN C PISCINE - BLOQUE DE EXAMEN                */
/* */
/* ========================================================================== */

/* REGLAS CLAVE PARA ESTE BLOQUE:
   - Si el ejercicio pide una FUNCIÓN: Solo entregas la función (sin main).
   - Si el ejercicio pide un PROGRAMA: Debe incluir `main`, procesar argumentos
     (argc/argv) y terminar SIEMPRE con un salto de línea `\n`.
*/

#include <unistd.h>

/* ========================================================================== */
/* NIVEL 1                                                                    */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 1: ft_strlen (Función)                                           */
/* Objetivo: Cuenta cuántos caracteres tiene una cadena hasta el nulo '\0'.   */
/* -------------------------------------------------------------------------- */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 2: ft_putstr (Función)                                           */
/* Objetivo: Imprime en pantalla una cadena de texto carácter a carácter.     */
/* -------------------------------------------------------------------------- */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 3: ft_swap (Función)                                             */
/* Objetivo: Intercambia los valores de dos enteros usando paso por referencia.*/
/* -------------------------------------------------------------------------- */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 4: ft_strcpy (Función)                                           */
/* Objetivo: Copia el contenido de src en dest y retorna dest.                */
/* -------------------------------------------------------------------------- */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 5: ft_strcmp (Función)                                           */
/* Objetivo: Compara dos cadenas y devuelve la diferencia del primer carácter */
/* diferente que encuentre en la tabla ASCII.                                 */
/* -------------------------------------------------------------------------- */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 6: ft_putnbr (Función)                                           */
/* Objetivo: Imprime cualquier número entero en pantalla usando recursividad. */
/* Gestiona el caso especial del número mínimo negativo (INT_MIN).           */
/* -------------------------------------------------------------------------- */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}


/* ========================================================================== */
/* NIVEL 2                                                                    */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 7: first_word (Programa)                                         */
/* Objetivo: Salta los espacios/tabuladores iniciales e imprime la primera    */
/* palabra que encuentre hasta el siguiente espacio o el final.               */
/* -------------------------------------------------------------------------- */
int	main_first_word(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 8: last_word (Programa)                                          */
/* Objetivo: Encuentra e imprime la última palabra de una cadena.             */
/* Recorremos hasta el final y luego hacia atrás ignorando espacios.          */
/* -------------------------------------------------------------------------- */
int	main_last_word(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
			i++;
		i--;
		while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i--;
		while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
			i--;
		i++;
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 9: rev_print (Programa)                                          */
/* Objetivo: Imprime la cadena recibida al revés.                             */
/* -------------------------------------------------------------------------- */
int	main_rev_print(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
			i++;
		i--;
		while (i >= 0)
		{
			write(1, &argv[1][i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 10: rotone (Programa)                                            */
/* Objetivo: Avanza cada letra una posición alfabética ('a'->'b', 'z'->'a').  */
/* -------------------------------------------------------------------------- */
int	main_rotone(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'y')
				argv[1][i] += 1;
			else if (argv[1][i] == 'z')
				argv[1][i] = 'a';
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Y')
				argv[1][i] += 1;
			else if (argv[1][i] == 'Z')
				argv[1][i] = 'A';
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 11: rot13 (Programa)                                             */
/* Objetivo: Avanza cada letra 13 posiciones rotando sobre el abecedario.    */
/* -------------------------------------------------------------------------- */
int	main_rot13(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'm')
				|| (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
				argv[1][i] += 13;
			else if ((argv[1][i] >= 'n' && argv[1][i] <= 'z')
				|| (argv[1][i] >= 'N' && argv[1][i] <= 'Z'))
				argv[1][i] -= 13;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 12: search_and_replace (Programa)                                */
/* Objetivo: Si el carácter coincide con argv[2], lo cambia por argv[3].       */
/* -------------------------------------------------------------------------- */
int	main_search_and_replace(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 4 && argv[2][1] == '\0' && argv[3][1] == '\0')
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == argv[2][0])
				argv[1][i] = argv[3][0];
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 13: repeat_alpha (Programa)                                      */
/* Objetivo: Repite cada letra tantas veces como su posición en el alfabeto.  */
/* Usamos un contador secundario 'count'.                                     */
/* -------------------------------------------------------------------------- */
int	main_repeat_alpha(int argc, char **argv)
{
	int	i;
	int	count;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			count = 1;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				count = argv[1][i] - 'a' + 1;
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				count = argv[1][i] - 'A' + 1;
			while (count > 0)
			{
				write(1, &argv[1][i], 1);
				count--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 14: ulstr (Programa)                                             */
/* Objetivo: Intercambia mayúsculas por minúsculas y viceversa.                */
/* -------------------------------------------------------------------------- */
int	main_ulstr(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] -= 32;
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] += 32;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


/* ========================================================================== */
/* NIVEL 3                                                                    */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 15: fizzbuzz (Programa)                                          */
/* Objetivo: Imprime los números del 1 al 100 sustituyendo múltiplos de 3 por  */
/* 'fizz', múltiplos de 5 por 'buzz' y de ambos por 'fizzbuzz'.               */
/* Utiliza una versión simplificada de putnbr para imprimir los números.      */
/* -------------------------------------------------------------------------- */
void	fb_putnbr(int num)
{
	char	digit;

	if (num >= 10)
		fb_putnbr(num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

int	main_fizzbuzz(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			fb_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 16: tab_mult (Programa)                                          */
/* Objetivo: Recibe un número positivo e imprime su tabla de multiplicar.      */
/* -------------------------------------------------------------------------- */
int	mini_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	main_tab_mult(int argc, char **argv)
{
	int	i;
	int	num;

	if (argc == 2)
	{
		num = mini_atoi(argv[1]);
		i = 1;
		while (i <= 9)
		{
			fb_putnbr(i);
			write(1, " x ", 3);
			fb_putnbr(num);
			write(1, " = ", 3);
			fb_putnbr(i * num);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 17: ft_atoi (Función)                                            */
/* Objetivo: Convierte una cadena de texto en un número entero computable.     */
/* Salta espacios, maneja signos '-' y '+' e interpreta dígitos numéricos.   */
/* -------------------------------------------------------------------------- */
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 18: do_op (Programa)                                             */
/* Objetivo: Realiza una operación aritmética básica según los argumentos.     */
/* -------------------------------------------------------------------------- */
#include <stdio.h> // Autorizado habitualmente en este ejercicio para printf

int	main_do_op(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("%d", ft_atoi(argv[1]) + ft_atoi(argv[3]));
		else if (argv[2][0] == '-')
			printf("%d", ft_atoi(argv[1]) - ft_atoi(argv[3]));
		else if (argv[2][0] == '*')
			printf("%d", ft_atoi(argv[1]) * ft_atoi(argv[3]));
		else if (argv[2][0] == '/')
			printf("%d", ft_atoi(argv[1]) / ft_atoi(argv[3]));
		else if (argv[2][0] == '%')
			printf("%d", ft_atoi(argv[1]) % ft_atoi(argv[3]));
	}
	printf("\n");
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 19: is_prime (Función)                                           */
/* Objetivo: Retorna 1 si el número es primo, o 0 si no lo es.                 */
/* -------------------------------------------------------------------------- */
int	is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}


/* ========================================================================== */
/* NIVEL 4                                                                    */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 20: alpha_mirror (Programa)                                      */
/* Objetivo: Sustituye cada letra por su simétrica ('a'->'z', 'b'->'y', etc.). */
/* El truco es restar el carácter actual a la suma de los extremos del abecedario. */
/* -------------------------------------------------------------------------- */
int	main_alpha_mirror(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = 'a' + 'z' - argv[1][i];
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = 'A' + 'Z' - argv[1][i];
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 21: ft_itoa (Función)                                            */
/* Objetivo: Operación inversa de atoi. Convierte un entero a una cadena de   */
/* caracteres local asignable. En exámenes de piscina se suele usar malloc.   */
/* -------------------------------------------------------------------------- */
#include <stdlib.h>

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;
	long	n;

	n = nbr;
	len = get_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 22: camel_to_snake (Programa)                                    */
/* Objetivo: Convierte una cadena camelCase a snake_case (ej: lowerCamel     */
/* pasa a ser lower_camel). Cada mayúscula añade un guion bajo y pasa a minúscula. */
/* -------------------------------------------------------------------------- */
int	main_camel_to_snake(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				write(1, "_", 1);
				argv[1][i] += 32;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 23: snake_to_camel (Programa)                                    */
/* Objetivo: Proceso inverso del anterior (ej: lower_camel -> lowerCamel).    */
/* -------------------------------------------------------------------------- */
int	main_snake_to_camel(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == '_')
			{
				i++;
				if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
					argv[1][i] -= 32;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}