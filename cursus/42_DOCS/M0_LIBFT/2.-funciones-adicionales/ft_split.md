# ft\_split

#### Prototipo

C

```
char	**ft_split(char const *s, char c);
```

#### Descripción

Reserva memoria dinámica (mediante `malloc`) y devuelve un array de cadenas de caracteres (_array de strings_) resultante de separar la cadena `s` utilizando el carácter `c` como delimitador. El array retornado finaliza siempre con un puntero `NULL`.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                             |
| ------------- | -------------- | ----------------------------------------------------------- |
| `s`           | `char const *` | Cadena de caracteres que se desea dividir.                  |
| `c`           | `char`         | Carácter delimitador utilizado para realizar la separación. |

* Aclaración: Al tratarse de un array de punteros a cadenas (`char **`), es fundamental liberar tanto la memoria asignada individualmente para cada palabra como el propio puntero doble que contiene el array.

#### Valor de Retorno

* `char **`: Array de cadenas de caracteres resultante de la división, terminado en un puntero `NULL`.
* `NULL`: Si falla la reserva de memoria con `malloc` o si la cadena `s` recibida es `NULL`.

#### Casos Límite

* `s` es `NULL`: Retorna `NULL` para prevenir violaciones de acceso a memoria.
* Cadena vacía (`""`) o compuesta únicamente por el delimitador `c`: Retorna un array de tamaño 1 conteniendo exclusivamente un puntero `NULL`.
* Sin apariciones del delimitador `c`: Retorna un array con un único elemento (la cadena completa duplicada) y finalizado en `NULL`.
* Fallo intermedio de `malloc`: Se deben liberar individualmente todas las cadenas reservadas hasta ese momento (_free\_all_) y posteriormente la estructura principal para evitar fugas de memoria (_memory leaks_).

#### Código Comentado

C

```
#include "libft.h"

// Cuenta el número de palabras/bloques separados por el delimitador 'c'
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

// Libera toda la memoria asignada hasta el momento en caso de fallo
static void	free_split(char **lst, size_t i)
{
	while (i > 0)
	{
		i--;
		free(lst[i]);
	}
	free(lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (NULL);
	lst = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = 0;
			while (s[word_len] && s[word_len] != c)
				word_len++;
			lst[i] = ft_substr(s, 0, word_len);
			if (!lst[i])
				return (free_split(lst, i), NULL);
			i++;
			s += word_len;
		}
		else
			s++;
	}
	lst[i] = NULL;
	return (lst);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);

int	main(void)
{
	char	**split;
	int		i;

	printf("-- testing ft_split() --\n");
	split = ft_split("  42  Malaga   Cursus  Libft ", ' ');
	if (!split)
	{
		printf("Error al reservar memoria\n");
		return (1);
	}
	i = 0;
	while (split[i])
	{
		printf("Palabra [%d]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
```
