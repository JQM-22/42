# ft\_strmapi

#### Prototipo

C

```
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

#### Descripción

Aplica la función `f` a cada carácter de la cadena `s`, pasando su índice como primer argumento y el propio carácter como segundo. Crea y reserva dinámicamente (con `malloc`) una nueva cadena de caracteres con los resultados de las sucesivas aplicaciones de `f`.

#### Parámetros

| **Parámetro** | **Tipo**                       | **Descripción**                                                   |
| ------------- | ------------------------------ | ----------------------------------------------------------------- |
| `s`           | `char const *`                 | Cadena de caracteres sobre la cual se iterará.                    |
| `f`           | `char (*)(unsigned int, char)` | Puntero a la función que se aplicará a cada carácter y su índice. |

* Aclaración: Al utilizar un puntero a función `f`, permite aplicar transformaciones dinámicas a una cadena de texto respetando o utilizando la posición/índice de cada carácter.

#### Valor de Retorno

* `char *`: Puntero a la nueva cadena de caracteres resultante de procesar `s` con la función `f`.
* `NULL`: Si falla la reserva de memoria con `malloc` o si alguno de los parámetros de entrada (`s` o `f`) es `NULL`.

#### Casos Límite

* `s` o `f` son `NULL`: Retorna `NULL` inmediatamente para prevenir fallos de segmentación.
* Cadena vacía (`""`): Reserva espacio para 1 byte, le asigna `'\0'` y devuelve la cadena vacía duplicada de forma segura.
* Fallo de `malloc`: Retorna `NULL` de manera limpia.

#### Código Comentado

C

```
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	char			*buffer;
	unsigned int	i;

	// Si la cadena o el puntero a la función son NULL, retornamos NULL
	if (!s || !f)
		return (NULL);
	// Obtenemos la longitud de la cadena de entrada
	len = ft_strlen(s);
	// Reservamos memoria para la nueva cadena + 1 byte para el terminador nulo
	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	// Recorremos la cadena aplicando la función 'f' pasando índice y carácter
	while (s[i])
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	// Cerramos la nueva cadena con el carácter nulo
	buffer[i] = '\0';
	return (buffer);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Función de prueba: convierte a mayúsculas si el índice es par
char	my_toupper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*str = "42malaga";
	char	*res;

	printf("-- testing ft_strmapi() --\n");
	res = ft_strmapi(str, my_toupper_even);
	if (!res)
	{
		printf("Error al reservar memoria o parámetros nulos\n");
		return (1);
	}
	printf("Original  : %s\n", str);
	printf("Resultado : %s (Esperado: 42MaLaGa)\n", res);

	free(res);
	return (0);
}
```
