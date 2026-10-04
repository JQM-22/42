# ft\_strtrim

#### Prototipo

C

```
char	*ft_strtrim(char const *s1, char const *set);
```

#### Descripción

Elimina todos los caracteres pertenecientes al conjunto `set` desde el inicio y desde el final de la cadena `s1`, hasta encontrar un carácter que no pertenezca a `set`. La cadena resultante se asigna dinámicamente con `malloc`.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                                       |
| ------------- | -------------- | --------------------------------------------------------------------- |
| `s1`          | `char const *` | Cadena original de la que se van a recortar los caracteres sobrantes. |
| `set`         | `char const *` | Cadena que contiene el conjunto de caracteres a eliminar.             |

* Aclaración: No elimina caracteres que estén en medio de la cadena (por ejemplo, entre palabras); únicamente recorta los extremos inicial y final.

#### Valor de Retorno

* `char *`: Puntero a la cadena recortada y terminada en `'\0'`.
* `NULL`: Si la reserva de memoria falla o si alguno de los parámetros `s1` o `set` es `NULL`.

#### Casos Límite

* `s1` o `set` son `NULL`: Retorna `NULL` para prevenir violaciones de acceso a memoria.
* Todos los caracteres son eliminados: Si todos los caracteres de `s1` pertenecen a `set` (o si `s1` está vacía), `start` será mayor que `end`, devolviendo una cadena vacía recién reservada (`ft_strdup("")`).
* `set` es una cadena vacía (`""`): No recorta ningún carácter y devuelve una copia exacta de `s1`.

#### Código Comentado

C

```
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	end;

	// Si alguno de los punteros recibidos es NULL, devolvemos NULL
	if (!s1 || !set)
		return (NULL);
	i = 0;
	// Avanzamos desde el principio mientras el carácter actual pertenezca a 'set'
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	// Obtenemos el índice del último carácter de s1
	end = ft_strlen(s1) - 1;
	// Retrocedemos desde el final mientras el carácter pertenezca a 'set'
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	// Si start supera a end, la cadena resultante debe estar vacía
	if (start > end)
		return (ft_strdup(""));
	// Extraemos y devolvemos la subcadena recortada
	return (ft_substr(s1, start, end - start + 1));
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);

int	main(void)
{
	char	*s1 = "   \t  Hola 42 Malaga!   \n ";
	char	*set = " \t\n";
	char	*trimmed;

	printf("-- testing ft_strtrim() --\n");
	trimmed = ft_strtrim(s1, set);
	if (!trimmed)
	{
		printf("Error al reservar memoria\n");
		return (1);
	}
	printf("Original  : \"%s\"\n", s1);
	printf("Recortada : \"%s\" (Esperado: Hola 42 Malaga!)\n", trimmed);

	free(trimmed);
	return (0);
}
```
