# ft\_strdup

#### Prototipo

C

```
char	*ft_strdup(const char *s1);
```

#### Descripción

Duplica la cadena de caracteres `s1`. Reserva memoria dinámica suficiente usando `malloc` para alojar una copia exacta de la cadena, incluyendo el carácter nulo final (`'\0'`), realiza la copia y devuelve un puntero a la memoria recién asignada.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                          |
| ------------- | -------------- | -------------------------------------------------------- |
| `s1`          | `const char *` | Puntero a la cadena de caracteres que se desea duplicar. |

* Aclaración: El parámetro lleva `const` para proteger la cadena original contra cualquier modificación accidental. La memoria del nuevo puntero debe ser liberada posteriormente con `free()` por el usuario.

#### Valor de Retorno

* `char *`: Puntero al bloque de memoria que contiene la cadena duplicada.
* `NULL`: Si la reserva de memoria con `malloc` falla.

#### Casos Límite

* Cadena vacía (`""`): Reserva 1 byte de memoria, copia el `'\0'` y devuelve un puntero válido a la cadena vacía.
* Fallo de memoria (`malloc` devuelve `NULL`): Detecta la falta de memoria y devuelve `NULL` inmediatamente sin intentar acceder o copiar datos.
* Independencia de memoria: La dirección del puntero retornado es distinta de `s1`; modificar la cadena duplicada no afecta en absoluto a la original.

#### Código Comentado

C

```
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*mem;	

	// Reservamos memoria para la longitud de s1 más 1 byte adicional para el '\0'
	mem = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (mem == NULL)
		return (NULL);
	i = 0;
	// Copiamos los caracteres uno a uno
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	// Añadimos el carácter nulo final
	mem[i] = '\0';
	return (mem);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1);

int	main(void)
{
	char	original[] = "42 Malaga - Libft";
	char	*dup;

	printf("-- testing ft_strdup() --\n");

	// Duplicamos la cadena original
	dup = ft_strdup(original);

	if (!dup)
	{
		printf("Error: Fallo al reservar memoria en ft_strdup\n");
		return (1);
	}

	printf("Original : %s (Dirección: %p)\n", original, (void *)original);
	printf("Copia    : %s (Dirección: %p)\n", dup, (void *)dup);

	// Comprobamos que sean independientes modificando la copia
	dup[0] = 'X';
	printf("\nTras modificar la copia (dup[0] = 'X'):\n");
	printf("Original : %s (Esperado: 42 Malaga - Libft)\n", original);
	printf("Copia    : %s (Esperado: X2 Malaga - Libft)\n", dup);

	// Liberamos la memoria reservada dinámicamente
	free(dup);
	return (0);
}
```
