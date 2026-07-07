/* ========================================================================== */
/* */
/* APUNTES EXAMEN C PISCINE                          */
/* */
/* ========================================================================== */

/* REGLAS DE ORO PARA EL EXAMEN:
   1. Compila siempre con: cc -Wall -Wextra -Werror [cite: 16, 315, 552, 872]
   2. Solo se entrega la FUNCIÓN que pide el enunciado (el main debe ir borrado o comentado)[cite: 17, 18, 316, 317].
   3. Un error de memoria (SIGSEGV/Bus error) equivale a un 0 automático[cite: 33, 332, 569, 889].
*/

#include <unistd.h>

/* ========================================================================== */
/* MÓDULO C 00                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00: ft_putchar [cite: 156]                                              */
/* Explicación: Escribe un solo carácter en la salida estándar usando write.  */
/* El '1' como primer parámetro indica la salida del terminal[cite: 164, 165].          */
/* -------------------------------------------------------------------------- */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 01: ft_print_alphabet [cite: 171]                                       */
/* Explicación: Recorre los caracteres desde la 'a' hasta la 'z' usando un    */
/* bucle while y aprovecha ft_putchar para imprimirlos uno a uno[cite: 176].        */
/* -------------------------------------------------------------------------- */
void	ft_print_alphabet(void)
{
	char	letter;

	letter = 'a';
	while (letter <= 'z')
	{
		ft_putchar(letter);
		letter++;
	}
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 02: ft_print_reverse_alphabet [cite: 183]                               */
/* Explicación: Idéntico al anterior, pero inicializando en 'z' y restando    */
/* en lugar de sumar para ir hacia atrás hasta llegar a la 'a'[cite: 189].          */
/* -------------------------------------------------------------------------- */
void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = 'z';
	while (letter >= 'a')
	{
		ft_putchar(letter);
		letter--;
	}
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 03: ft_print_numbers [cite: 195]                                        */
/* Explicación: Imprime los dígitos del '0' al '9'. Recuerda que trabajamos   */
/* con caracteres (carácter '0'), no con el número 0 de la tabla ASCII[cite: 200]. */
/* -------------------------------------------------------------------------- */
void	ft_print_numbers(void)
{
	char	digit;

	digit = '0';
	while (digit <= '9')
	{
		ft_putchar(digit);
		digit++;
	}
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 04: ft_is_negative [cite: 206]                                          */
/* Explicación: Evalúa si un número entero n es menor que cero. Si se cumple  */
/* imprime 'N', si es mayor o igual (positivo o nulo) imprime 'P'[cite: 211].       */
/* -------------------------------------------------------------------------- */
void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}


/* ========================================================================== */
/* MÓDULO C 01                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00: ft_ft [cite: 420]                                                   */
/* Explicación: Un puntero guarda una dirección de memoria. Para modificar    */
/* el valor que está guardado dentro de esa dirección, usamos el asterisco '*'[cite: 424].*/
/* -------------------------------------------------------------------------- */
void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 01: ft_ultimate_ft [cite: 430]                                          */
/* Explicación: Puntero de 9 niveles. Para llegar al entero final y asignarle */
/* el 42, tenemos que colocar exactamente 9 asteriscos por delante[cite: 435].       */
/* -------------------------------------------------------------------------- */
void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 02: ft_swap [cite: 441]                                                 */
/* Explicación: Para intercambiar dos valores necesitamos una variable "aux"  */
/* temporal para no perder el primer valor al sobreescribirlo[cite: 447].           */
/* -------------------------------------------------------------------------- */
void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 03: ft_div_mod [cite: 453]                                              */
/* Explicación: Guarda el resultado de la división en la dirección de div,    */
/* y el residuo (calculado con el operador módulo %) en mod[cite: 462, 463].         */
/* -------------------------------------------------------------------------- */
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 04: ft_ultimate_div_mod [cite: 466]                                     */
/* Explicación: Hace lo mismo que el anterior pero usando solo dos variables. */
/* Ojo: guarda la división primero, porque si modificas 'a' pierdes su valor  */
/* original antes de calcular el módulo[cite: 476, 477].                             */
/* -------------------------------------------------------------------------- */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 05: ft_putstr [cite: 480]                                               */
/* Explicación: Recorre una cadena de texto apuntada por str utilizando un   */
/* índice e imprime carácter por carácter hasta dar con el nulo '\0'[cite: 486].    */
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
/* EJERCICIO 06: ft_strlen [cite: 493]                                               */
/* Explicación: Cuenta cuántos caracteres contiene la cadena (sin incluir el  */
/* carácter nulo final '\0') y retorna esa cantidad[cite: 499].                     */
/* -------------------------------------------------------------------------- */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 07: ft_rev_int_tab [cite: 505]                                          */
/* Explicación: Invierte un array de enteros. Usamos un índice al inicio (0)  */
/* y otro al final (size - 1) intercambiándolos y acercándolos al centro[cite: 510, 511].*/
/* -------------------------------------------------------------------------- */
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	aux;

	i = 0;
	while (i < size / 2)
	{
		aux = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = aux;
		i++;
	}
}


/* ========================================================================== */
/* MÓDULO C 02                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00: ft_strcpy [cite: 661]                                               */
/* Explicación: Copia el string src en dest, incluyendo el '\0' al final.     */
/* Retorna la dirección del destino dest[cite: 667, 670].                           */
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
/* EJERCICIO 01: ft_strncpy [cite: 673]                                              */
/* Explicación: Copia hasta n caracteres de src a dest. Si src es más corto   */
/* que n, rellena el resto de dest con caracteres nulos '\0'[cite: 679, 682].         */
/* -------------------------------------------------------------------------- */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 02: ft_str_is_alpha [cite: 685]                                         */
/* Explicación: Comprueba si todos los caracteres son letras (A-Z o a-z).     */
/* Si encuentra un solo carácter inválido, retorna 0. Si está vacío da 1[cite: 690, 694].*/
/* -------------------------------------------------------------------------- */
int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 03: ft_str_is_numeric [cite: 697]                                       */
/* Explicación: Igual que el anterior, pero valida exclusivamente caracteres   */
/* numéricos ('0' al '9')[cite: 703].                                              */
/* -------------------------------------------------------------------------- */
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 07: ft_strupcase [cite: 748]                                            */
/* Explicación: Modifica la cadena transformando las minúsculas a mayúsculas  */
/* restando 32 (la distancia en la tabla ASCII entre 'a' y 'A')[cite: 753].         */
/* -------------------------------------------------------------------------- */
char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 08: ft_strlowcase [cite: 760]                                            */
/* Explicación: Lo opuesto al anterior; convierte mayúsculas a minúsculas     */
/* sumando 32 en la tabla ASCII a los caracteres válidos[cite: 765].                */
/* -------------------------------------------------------------------------- */
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}


/* ========================================================================== */
/* MÓDULO C 03                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00: ft_strcmp [cite: 973]                                               */
/* Explicación: Compara dos cadenas carácter a carácter. Si encuentra una     */
/* diferencia o llega al final de alguna, devuelve la resta ASCII de ambas[cite: 979].*/
/* -------------------------------------------------------------------------- */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 01: ft_strncmp [cite: 985]                                              */
/* Explicación: Compara dos cadenas igual que strcmp pero deteniéndose al    */
/* alcanzar 'n' caracteres analizados[cite: 991, 994].                              */
/* -------------------------------------------------------------------------- */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 02: ft_strcat [cite: 997]                                               */
/* Explicación: Concatena (une) src al final de dest. Primero busca el final  */
/* de dest y a partir de ahí empieza a copiar los caracteres de src[cite: 1002].     */
/* -------------------------------------------------------------------------- */
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 03: ft_strncat [cite: 1007]                                              */
/* Explicación: Une src al final de dest, copiando únicamente un máximo de    */
/* nb caracteres de la cadena origen[cite: 1012, 1014].                              */
/* -------------------------------------------------------------------------- */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}


/* ========================================================================== */
/* BATERÍA DE PRUEBAS (MAIN)                        */
/* ========================================================================== */
/* Descomenta este bloque principal si deseas ejecutar pruebas locales en tu  */
/* editor de código. Recuerda borrarlo antes de subir al git del examen[cite: 17, 316, 553, 873].*/

/*
int	main(void)
{
	// Prueba C00
	write(1, "--- C00 ---\n", 12);
	ft_print_alphabet();
	write(1, "\n", 1);
	ft_print_numbers();
	write(1, "\n", 1);

	// Prueba C01
	write(1, "--- C01 ---\n", 12);
	char *texto = "Prueba string";
	ft_putstr(texto);
	write(1, "\n", 1);

	// Prueba C02
	write(1, "--- C02 ---\n", 12);
	char origen[] = "Hola";
	char destino[10];
	ft_strcpy(destino, origen);
	ft_putstr(destino);
	write(1, "\n", 1);

	return (0);
}
*/