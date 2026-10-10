# ft\_itoa

#### Prototipo

C

```
char	*ft_itoa(int n);
```

#### Descripción

Reserva memoria dinámica (usando `malloc`) y convierte un número entero (`int`) recibido como argumento en su representación de cadena de caracteres terminada en nulo (`'\0'`). Contempla correctamente números positivos, negativos y el caso especial de `INT_MIN`.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                              |
| ------------- | -------- | -------------------------------------------- |
| `n`           | `int`    | Valor entero que se desea convertir a texto. |

* Aclaración: La memoria ocupada por la cadena retornada debe ser liberada por el usuario utilizando la función `free()`.

#### Valor de Retorno

* `char *`: Puntero a la cadena de caracteres que representa al entero.
* `NULL`: Si falla la reserva de memoria dinámica con `malloc`.

#### Casos Límite

* `n = 0`: Reserva espacio para 1 dígito + `'\0'`, devolviendo la cadena `"0"`.
* `INT_MIN` (`-2147483648`): Debido al desbordamiento que sufriría al cambiar de signo en tipo `int` ($$ $-\text{INT\_MIN}$ $$ sobrepasa el límite positivo de 32 bits), este caso se gestiona mediante una copia directa (`ft_strdup("-2147483648")`).
* Números negativos generables: Asigna el signo `'-'` en la primera posición (`res[0]`) y convierte el resto de los dígitos invirtiendo el módulo de la división (`-digit`).

#### Código Comentado

C

```
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

// Calcula el número de caracteres necesarios para representar 'n' (incluyendo el signo '-')
static int	ft_n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// Asigna la memoria exacta necesaria e inicializa el carácter nulo final
static char	*ft_malloc(int len)
{
	char	*res;

	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		digit;
	int		min_index;

	// Gestionamos directamente el valor límite de entero de 32 bits
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_n_len(n);
	res = ft_malloc(len);
	if (!res)
		return (NULL);
	min_index = (n < 0);
	if (n < 0)
		res[0] = '-';
	// Rellenamos el string de derecha a izquierda extraendo el último dígito
	while (len - 1 >= min_index)
	{
		digit = n % 10;
		if (digit < 0)
			digit = -digit;
		res[len - 1] = digit + '0';
		n = n / 10;
		len--;
	}
	return (res);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_itoa(int n);

int	main(void)
{
	char	*str;

	printf("-- testing ft_itoa() --\n");

	str = ft_itoa(0);
	printf("Prueba  0        : %s (Esperado: 0)\n", str);
	free(str);

	str = ft_itoa(1337);
	printf("Prueba  1337     : %s (Esperado: 1337)\n", str);
	free(str);

	str = ft_itoa(-42);
	printf("Prueba -42       : %s (Esperado: -42)\n", str);
	free(str);

	str = ft_itoa(INT_MIN);
	printf("Prueba INT_MIN   : %s (Esperado: -2147483648)\n", str);
	free(str);

	return (0);
}
```
