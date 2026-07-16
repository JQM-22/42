/* ========================================================================== */
/* */
/* APUNTES MAESTROS DE ESTUDIO: MÓDULOS C 00 A C 04 (TODOS LOS EJERCICIOS)  */
/* */
/* ========================================================================== */

#include <unistd.h>
#include <stdlib.h>

/* ========================================================================== */
/* MÓDULO C 00                                                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00: ft_putchar (Función)                                         */
/* Explicación: Escribe un único carácter en el terminal. Básica.             */
/* -------------------------------------------------------------------------- */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 01: ft_print_alphabet (Función)                                  */
/* Explicación: Muestra el abecedario de la 'a' a la 'z' en orden creciente.  */
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
/* EJERCICIO 02: ft_print_reverse_alphabet (Función)                          */
/* Explicación: Muestra el abecedario al revés, de la 'z' a la 'a'.           */
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
/* EJERCICIO 03: ft_print_numbers (Función)                                   */
/* Explicación: Imprime los dígitos del '0' al '9' en orden creciente.        */
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
/* EJERCICIO 04: ft_is_negative (Función)                                     */
/* Explicación: Imprime 'N' si el entero es < 0, o 'P' si es >= 0.            */
/* -------------------------------------------------------------------------- */
void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 05: ft_print_comb (Función)                                      */
/* Explicación: Muestra combinaciones ascendentes únicas de 3 dígitos.        */
/* NOTA EXAMEN: No entra en exámenes. Demasiado tedioso controlar la última   */
/* coma con tres niveles de bucles paralelos bajo presión de tiempo.          */
/* -------------------------------------------------------------------------- */
void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0' - 1;
	while (++a <= '7')
	{
		b = a;
		while (++b <= '8')
		{
			c = b;
			while (++c <= '9')
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (!(a == '7' && b == '8' && c == '9'))
					write(1, ", ", 2);
			}
		}
	}
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 06: ft_print_comb2 (Función)                                     */
/* Explicación: Muestra combinaciones de dos números de dos dígitos (00 01).  */
/* NOTA EXAMEN: No entra en exámenes. Es un ejercicio matemático de cluster   */
/* largo pensado para estructurar lógicas de división y módulo duales.        */
/* -------------------------------------------------------------------------- */
void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar((a / 10) + '0');
			ft_putchar((a % 10) + '0');
			ft_putchar(' ');
			ft_putchar((b / 10) + '0');
			ft_putchar((b % 10) + '0');
			if (!(a == 98 && b == 99))
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 07: ft_putnbr (Función)                                          */
/* Explicación: Imprime un entero en pantalla por recursividad. CLÁSICO.      */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* EJERCICIO 08: ft_print_combn (Función)                                     */
/* Explicación: Muestra combinaciones de n dígitos sin repetición.            */
/* NOTA EXAMEN: Jamás entra en exámenes. Requiere recursividad avanzada con   */
/* arrays de profundidad dinámica, inviable para el tiempo de un examen.      */
/* -------------------------------------------------------------------------- */
void	ft_print_combn_subs(int n, int idx, char *str)
{
	if (idx == n)
	{
		write(1, str, n);
		if (str[0] < '10' - n)
			write(1, ", ", 2);
		return ;
	}
	if (idx == 0)
		str[idx] = '0';
	else
		str[idx] = str[idx - 1] + 1;
	while (str[idx] <= '9')
	{
		ft_print_combn_subs(n, idx + 1, str);
		str[idx]++;
	}
}

void	ft_print_combn(int n)
{
	char	str[10];

	if (n > 0 && n < 10)
		ft_print_combn_subs(n, 0, str);
}


/* ========================================================================== */
/* MÓDULO C 01                                                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00: ft_ft (Función)                                              */
/* Explicación: Concepto básico de punteros. Cambia el valor a 42.            */
/* -------------------------------------------------------------------------- */
void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 01: ft_ultimate_ft (Función)                                     */
/* Explicación: Puntero de 9 niveles. Se accede usando 9 asteriscos.          */
/* -------------------------------------------------------------------------- */
void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 02: ft_swap (Función)                                            */
/* Explicación: Intercambia los valores de dos enteros por referencia.        */
/* -------------------------------------------------------------------------- */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 03: ft_div_mod (Función)                                         */
/* Explicación: Almacena cociente y resto en variables externas por punteros. */
/* -------------------------------------------------------------------------- */
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 04: ft_ultimate_div_mod (Función)                                */
/* Explicación: Hace la división usando solo las dos variables de entrada.    */
/* -------------------------------------------------------------------------- */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp_div;
	int	tmp_mod;

	tmp_div = *a / *b;
	tmp_mod = *a % *b;
	*a = tmp_div;
	*b = tmp_mod;
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 05: ft_putstr (Función)                                          */
/* Explicación: Imprime un string completo carácter a carácter. FUNDAMENTAL.  */
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
/* EJERCICIO 06: ft_strlen (Función)                                          */
/* Explicación: Cuenta la longitud de un string. OBLIGATORIO SABERLA.         */
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
/* EJERCICIO 07: ft_rev_int_tab (Función)                                     */
/* Explicación: Da la vuelta a un array de enteros de tamaño 'size'.          */
/* -------------------------------------------------------------------------- */
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 08: ft_sort_int_tab (Función)                                    */
/* Explicación: Ordena un array de enteros de menor a mayor (Bubble Sort).     */
/* -------------------------------------------------------------------------- */
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}


/* ========================================================================== */
/* MÓDULO C 02                                                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00: ft_strcpy (Función)                                          */
/* Explicación: Copia el string origen en el destino carácter a carácter.     */
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
/* EJERCICIO 01: ft_strncpy (Función)                                         */
/* Explicación: Copia hasta n bytes. Si src es más corto, rellena con '\0'.   */
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
/* EJERCICIO 02: ft_str_is_alpha (Función)                                    */
/* Explicación: Devuelve 1 si el string solo tiene letras (o si está vacío).  */
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
/* EJERCICIO 03: ft_str_is_numeric (Función)                                  */
/* Explicación: Devuelve 1 si el string contiene solo dígitos numéricos.      */
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
/* EJERCICIO 04: ft_str_is_lowercase (Función)                                */
/* Explicación: Comprueba si todos los caracteres son letras minúsculas.      */
/* -------------------------------------------------------------------------- */
int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 05: ft_str_is_uppercase (Función)                                */
/* Explicación: Comprueba si todos los caracteres son letras mayúsculas.      */
/* -------------------------------------------------------------------------- */
int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 06: ft_str_is_printable (Función)                                */
/* Explicación: Valida si los caracteres entran en rango imprimible (32-126). */
/* -------------------------------------------------------------------------- */
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 07: ft_strupcase (Función)                                       */
/* Explicación: Pasa todas las letras minúsculas a mayúsculas restando 32.     */
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
/* EJERCICIO 08: ft_strlowcase (Función)                                      */
/* Explicación: Pasa todas las letras mayúsculas a minúsculas sumando 32.     */
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

/* -------------------------------------------------------------------------- */
/* EJERCICIO 09: ft_strcapitalize (Función)                                   */
/* Explicación: Pone la primera letra de cada palabra en mayúscula.           */
/* -------------------------------------------------------------------------- */
char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
		{
			if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 10: ft_strlcpy (Función)                                         */
/* Explicación: Copia src en dest de forma segura con tamaño límite size.     */
/* -------------------------------------------------------------------------- */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 11: ft_putstr_non_printable (Función)                            */
/* Explicación: Muestra caracteres no imprimibles en formato hexadecimal.    */
/* NOTA EXAMEN: No se evalúa en exámenes. El parseo de enteros hacia caracteres*/
/* hexadecimales en línea única excede el formato rápido de un examen.       */
/* -------------------------------------------------------------------------- */
void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[(unsigned char)str[i] / 16], 1);
			write(1, &"0123456789abcdef"[(unsigned char)str[i] % 16], 1);
		}
		i++;
	}
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 12: ft_print_memory (Función)                                    */
/* Explicación: Imprime direcciones, volcado hex y texto legible de memoria. */
/* NOTA EXAMEN: No entra en exámenes. El código rompe los límites de líneas   */
/* prácticos y obliga a usar punteros genéricos prohibidos en examen.         */
/* -------------------------------------------------------------------------- */
void	print_hex_byte(unsigned char c)
{
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

void	print_addr_hex(unsigned long addr)
{
	int		i;
	char	buf[16];

	i = 15;
	while (i >= 0)
	{
		buf[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, buf, 16);
	write(1, ": ", 2);
}

void	ft_print_memory_line(unsigned char *p, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			print_hex_byte(p[i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (p[i] >= 32 && p[i] <= 126)
			write(1, &p[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	chunk;
	unsigned char	*p;

	if (size == 0)
		return (addr);
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_addr_hex((unsigned long)(p + i));
		if (size - i < 16)
			chunk = size - i;
		else
			chunk = 16;
		ft_print_memory_line(p + i, chunk);
		i += 16;
	}
	return (addr);
}


/* ========================================================================== */
/* MÓDULO C 03                                                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00: ft_strcmp (Función)                                          */
/* Explicación: Compara s1 y s2. Retorna la resta ASCII al primer cambio.    */
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
/* EJERCICIO 01: ft_strncmp (Función)                                         */
/* Explicación: Compara dos cadenas acotando la lectura a 'n' caracteres.     */
/* -------------------------------------------------------------------------- */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 02: ft_strcat (Función)                                          */
/* Explicación: Añade src al final de la cadena dest.                         */
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
/* EJERCICIO 03: ft_strncat (Función)                                         */
/* Explicación: Une cadenas limitando la copia a un número máximo 'nb'.       */
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

/* -------------------------------------------------------------------------- */
/* EJERCICIO 04: ft_strstr (Función)                                          */
/* Explicación: Busca la subcadena 'to_find' dentro del string principal 'str'.*/
/* -------------------------------------------------------------------------- */
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 05: ft_strlcat (Función)                                         */
/* Explicación: Concatena strings garantizando la terminación con '\0' y size. */
/* -------------------------------------------------------------------------- */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = 0;
	s_len = 0;
	while (dest[d_len] != '\0' && d_len < size)
		d_len++;
	while (src[s_len] != '\0')
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	i = d_len;
	j = 0;
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (d_len + s_len);
}


/* ========================================================================== */
/* MÓDULO C 04                                                                */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 00 / 01 / 02: ft_strlen, ft_putstr, ft_putnbr                    */
/* Explicación: Replicados de C00/C01. Esencial dominarlos por completo.      */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* EJERCICIO 03: ft_atoi (Función)                                            */
/* Explicación: Convierte texto a int saltando espacios y multiplicando signos.*/
/* -------------------------------------------------------------------------- */
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 04: ft_putnbr_base (Función)                                     */
/* Explicación: Imprime un número en base binaria, hexadecimal, etc.          */
/* NOTA EXAMEN: No entra en el examen ordinario por la enorme cantidad de     */
/* filtros de validación necesarios para blindar los caracteres duplicados.   */
/* -------------------------------------------------------------------------- */
int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] >= 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base_rec(long nbr, char *base, int b_len)
{
	if (nbr >= b_len)
		ft_putnbr_base_rec(nbr / b_len, base, b_len);
	write(1, &base[nbr % b_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b_len;
	long	n;

	b_len = check_base(base);
	if (b_len < 2)
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_putnbr_base_rec(n, base, b_len);
}

/* -------------------------------------------------------------------------- */
/* EJERCICIO 05: ft_atoi_base (Función)                                       */
/* Explicación: Convierte una cadena bajo una base específica a entero decimal.*/
/* NOTA EXAMEN: Descartado de exámenes ordinarios. Combina la lógica estricta  */
/* de ft_atoi con indexaciones de tablas cruzadas en strings variables.       */
/* -------------------------------------------------------------------------- */
int	get_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	b_len;
	int	idx;

	i = 0;
	sign = 1;
	res = 0;
	b_len = check_base(base);
	if (b_len < 2)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	idx = get_base_index(str[i], base);
	while (idx != -1)
	{
		res = res * b_len + idx;
		i++;
		idx = get_base_index(str[i], base);
	}
	return (res * sign);
}