# ft\_atoi

#### Prototipo

C

```
int	ft_atoi(const char *str);
```

#### Descripción

Convierte el comienzo de una cadena de caracteres a su representación en número entero (`int`). Ignora los espacios en blanco iniciales y los caracteres de control de espacio, procesa un único signo opcional (`+` o `-`) y convierte los dígitos subsiguientes hasta encontrar un carácter no numérico o el final de la cadena.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                          |
| ------------- | -------------- | -------------------------------------------------------- |
| `str`         | `const char *` | Cadena de caracteres que contiene el número a convertir. |

* Aclaración: Lleva el calificador `const` porque la función sólo lee la cadena para realizar la conversión sin modificar su contenido original.

#### Valor de Retorno

* `int`: El valor entero numérico resultante de la conversión, multiplicado por su signo correspondiente.
* `0`: Si la cadena no contiene ningún dígito numérico válido al inicio (tras el signo/espacios) o si empieza por caracteres no válidos.

#### Casos Límite

* Espacios iniciales: Salta todos los espacios (`32`) y caracteres de control ASCII `9` al `13` (`\t`, `\n`, `\v`, `\f`, `\r`).
* Múltiples signos seguidos: Signos dobles o combinados como `"--42"`, `"-+42"` o `"+-42"` son inválidos; la función detecta el segundo signo como carácter no numérico y devuelve `0`.
* Texto tras los números: En `" -42abc56"`, se procesa únicamente el `-42` y se detiene en la `'a'`.
* Sin dígitos válidos: Cadenas como `""`, `" "`, `"+"` o `"abc"` devuelven `0`.

#### Código Comentado

C

```
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	// 1. Saltamos espacios en blanco y caracteres de control (ASCII 9 al 13)
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	// 2. Evaluamos si existe un signo positivo o negativo
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	// 3. Convertimos los caracteres numéricos a entero
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	// 4. Retornamos el resultado multiplicado por su signo
	return (result * sign);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

int	ft_atoi(const char *str);

int	main(void)
{
	printf("-- testing ft_atoi() --\n");
	printf("Prueba '   -42a' : %d (Esperado: -42)\n", ft_atoi("   -42a"));
	printf("Prueba '42'      : %d (Esperado: 42)\n", ft_atoi("42"));
	printf("Prueba ' --42a'  : %d (Esperado: 0 por signo doble)\n", ft_atoi(" --42a"));
	printf("Prueba ' +1337'  : %d (Esperado: 1337)\n", ft_atoi(" +1337"));
	return (0);
}
```
