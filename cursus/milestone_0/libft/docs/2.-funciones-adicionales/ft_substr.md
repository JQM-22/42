# ft\_substr

#### Prototipo

C

```
char	*ft_substr(char const *s, unsigned int start, size_t len);
```

#### Descripción

Reserva memoria dinámica (con `malloc`) y devuelve una subcadena de la cadena `s`. La subcadena empieza en el índice `start` y tiene un tamaño máximo de `len` caracteres.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                        |
| ------------- | -------------- | ------------------------------------------------------ |
| `s`           | `char const *` | Cadena original desde la que se extraerá la subcadena. |
| `start`       | `unsigned int` | Índice de inicio de la subcadena dentro de `s`.        |
| `len`         | `size_t`       | Longitud máxima que tendrá la subcadena extraída.      |

* Aclaración: Si `len` excede la cantidad de caracteres disponibles desde `start` hasta el final de `s`, se ajusta automáticamente para evitar reservar espacio innecesario.

#### Valor de Retorno

* `char *`: Puntero a la nueva subcadena asignada dinámicamente y terminada en `'\0'`.
* `NULL`: Si falla la asignación de memoria con `malloc` o si la cadena `s` recibida es `NULL`.

#### Casos Límite

* `s` es `NULL`: Retorna `NULL` para evitar accesos a punteros inválidos.
* `start` excede la longitud de `s` (`start >= ft_strlen(s)`): Devuelve una cadena vacía recién reservada en memoria (`ft_strdup("")`).
* `len` mayor que los caracteres restantes: Se acorta `len` al valor real `s_len - start` para asignar únicamente la memoria justa y necesaria.

#### Código Comentado

C

```
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	// Si el puntero de entrada es NULL, retornamos NULL
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	// Si el índice de inicio está fuera de la cadena, devolvemos una cadena vacía duplicada
	if (start >= s_len)
		return (ft_strdup(""));
	// Si la longitud solicitada es mayor que la disponible desde start, la limitamos
	if (len > s_len - start)
		len = s_len - start;
	// Reservamos memoria para la subcadena + 1 byte para el '\0'
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	// Copiamos los caracteres desde la posición 'start'
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	// Cerramos la subcadena con el carácter nulo
	sub[i] = '\0';
	return (sub);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(void)
{
	char	*str = "42 Malaga - Cursus Libft";
	char	*sub;

	printf("-- testing ft_substr() --\n");

	// Extracción estándar: desde índice 3 ("Malaga"), 6 caracteres
	sub = ft_substr(str, 3, 6);
	printf("Subcadena (start: 3, len: 6) : %s (Esperado: Malaga)\n", sub);
	free(sub);

	// Caso start fuera de rango (start: 50)
	sub = ft_substr(str, 50, 5);
	printf("Subcadena fuera de rango     : '%s' (Esperado: '')\n", sub);
	free(sub);

	// Caso len mayor que lo disponible (start: 12, len: 100)
	sub = ft_substr(str, 12, 100);
	printf("Subcadena con len sobredimensionado: %s (Esperado: Cursus Libft)\n", sub);
	free(sub);

	return (0);
}
```
