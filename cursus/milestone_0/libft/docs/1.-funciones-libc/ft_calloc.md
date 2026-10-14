# ft\_calloc

#### Prototipo

C

```
void	*ft_calloc(size_t count, size_t size);
```

#### Descripción

Reserva memoria de forma dinámica para un array de `count` elementos de `size` bytes cada uno. A diferencia de `malloc`, inicializa todos los bytes del bloque de memoria reservado a cero (`0`). Protege además contra desbordamientos (_integer overflow_) en el cálculo del tamaño total.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                   |
| ------------- | -------- | --------------------------------- |
| `count`       | `size_t` | Número de elementos a reservar.   |
| `size`        | `size_t` | Tamaño en bytes de cada elemento. |

* Aclaración: El tamaño total en memoria reservado es `count * size`. Al usar `size_t`, asegura la compatibilidad con el tamaño máximo de memoria direccionable del sistema.

#### Valor de Retorno

* `void *`: Puntero a la memoria reservada e inicializada a cero.
* `NULL`: Si falla la asignación de memoria con `malloc` o si ocurre un desbordamiento de enteros al multiplicar `count` y `size`.

#### Casos Límite

* `count = 0` o `size = 0`: Se realiza una asignación pequeña válida en memoria o retorna una dirección que puede ser liberada de forma segura con `free()`.
* Desbordamiento de tamaño (_Overflow_): Si `count * size` excede el valor máximo de `SIZE_MAX`, la condición `size > SIZE_MAX / count` previene la asignación no segura y devuelve `NULL`.
* Fallo de asignación (`malloc` devuelve `NULL`): Controla el fallo retornando `NULL` inmediatamente sin intentar limpiar con `ft_bzero`.

#### Código Comentado

C

```
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*total_bytes;

	// Protegemos contra un posible desbordamiento de enteros al calcular count * size
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	// Reservamos la memoria total requerida
	total_bytes = malloc(count * size);
	if (total_bytes == NULL)
		return (NULL);
	// Inicializamos a cero todos los bytes de la memoria asignada
	ft_bzero(total_bytes, count * size);
	return (total_bytes);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);

int	main(void)
{
	int		*arr;
	size_t	i;

	printf("-- testing ft_calloc() --\n");
	arr = (int *)ft_calloc(5, sizeof(int));
	if (!arr)
	{
		printf("Error en la asignación de memoria con ft_calloc\n");
		return (1);
	}
	i = 0;
	while (i < 5)
	{
		printf("arr[%zu] = %d (Esperado: 0)\n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);	
}
```
