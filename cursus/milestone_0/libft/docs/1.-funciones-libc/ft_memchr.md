# ft\_memchr

#### Prototipo

C

```
void	*ft_memchr(const void *s, int c, size_t n);
```

#### Descripción

Examina los primeros `n` bytes del área de memoria apuntada por `s` buscando la primera coincidencia del byte `c` (convertido a `unsigned char`). A diferencia de las funciones de cadena (como `ft_strchr`), no se detiene al encontrar un carácter nulo (`'\0'`), sino que analiza estrictamente el número de bytes indicado por `n`.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                                 |
| ------------- | -------- | --------------------------------------------------------------- |
| `s`           | `void *` | Puntero al bloque de memoria donde se realizará la búsqueda.    |
| `c`           | `int`    | Valor a buscar en memoria (se casteará a `unsigned char`).      |
| `n`           | `size_t` | Número máximo de bytes a examinar a partir de la dirección `s`. |

* Aclaración: Se utiliza `void *` para permitir examinar cualquier tipo de dato o bloque binario en memoria. Se convierte a `const unsigned char *` para realizar la lectura de byte a byte con precisión sin modificar el contenido original.

#### Valor de Retorno

* `void *`: Puntero a la primera ocurrencia del byte coincidente dentro del bloque de memoria.
* `NULL` (`0`): Si el byte no se encuentra dentro de los primeros `n` bytes.

#### Casos Límite

* `n = 0`: Devuelve `NULL` inmediatamente sin inspeccionar la memoria.
* Cadenas con `\0` intermedios: La búsqueda continúa tras encontrar un `\0` si la cantidad de bytes procesada sigue siendo menor que `n`.
* Buscar el byte `0` (`\0`): Devuelve la posición exacta de memoria donde se encuentre el valor `0` dentro del rango de `n` bytes.

#### Código Comentado

C

```
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	i = 0;
	// Casteamos el puntero void* a const unsigned char* para leer byte a byte
	p = (const unsigned char *)s;
	// Recorremos el bloque de memoria dentro del límite de n bytes
	while (i < n)
	{
		// Si el byte actual coincide con c casteado a unsigned char
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]); // Retornamos la dirección casteada a void*
		i++;
	}
	return (0); // Si no se encuentra en el rango de n bytes, retornamos NULL
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main(void)
{
	char	data[] = "123\056789";
	char	*ptr;

	printf("-- testing ft_memchr() --\n");

	// Busca '5' a través de un bloque de memoria que contiene un '\0'
	ptr = (char *)ft_memchr(data, '5', 9);
	printf("Buscar '5' en memoria: %s (Esperado: 56789)\n", ptr ? ptr : "NULL");

	// Busca 'X' que no existe en el rango
	ptr = (char *)ft_memchr(data, 'X', 9);
	printf("Buscar 'X' en memoria: %s (Esperado: NULL)\n", ptr ? ptr : "NULL");

	return (0);
}
```
