# ft\_memcpy

#### Prototipo

C

```
void	*ft_memcpy(void *dst, const void *src, size_t n);
```

#### Descripción

Copia `n` bytes desde el área de memoria de origen (`src`) hacia el área de memoria de destino (`dst`). Nota importante: Las áreas de memoria no deben solaparse (para áreas solapadas se debe usar `ft_memmove`).

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                               |
| ------------- | -------------- | ------------------------------------------------------------- |
| `dst`         | `void *`       | Puntero al bloque de memoria donde se van a copiar los datos. |
| `src`         | `const void *` | Puntero al bloque de memoria de origen que se va a leer.      |
| `n`           | `size_t`       | Número de bytes que se copiarán de `src` a `dst`.             |

* Aclaración: `src` es de tipo `const void *` para proteger los datos de origen contra modificaciones. Ambos punteros se castean a `unsigned char *` para realizar la copia byte por byte con precisión.

#### Valor de Retorno

* `void *`: Devuelve el puntero original al bloque de destino `dst`.

#### Casos Límite

* `dst` y `src` son ambos `NULL`: Retorna `dst` (`NULL`) inmediatamente para evitar accesos a memoria inválidos.
* `n = 0`: No realiza ninguna copia y devuelve `dst` directamente.
* Solapamiento de memoria (_Overlap_): Si `dst` y `src` se solapan en memoria, el comportamiento es indeterminado (se pueden sobrescribir datos antes de ser leídos).

#### Código Comentado

C

```
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	// Si ambos punteros son NULL, retornamos dst para evitar un fallo de segmentación
	if (!dst && !src)
		return (dst);
	// Casteamos ambos punteros a unsigned char* para copiar byte por byte
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	// Recorremos y copiamos n bytes desde src a dst
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	// Devolvemos el puntero inicial del destino
	return (dst);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

int	main(void)
{
	char	src[] = "Hola 42!";
	char	dst[20];

	printf("-- testing ft_memcpy() --\n");
	ft_memcpy(dst, src, 9); // Copiamos los 8 caracteres + el '\0'
	printf("Origen : %s\n", src);
	printf("Destino: %s (Esperado: Hola 42!)\n", dst);
	return (0);
}
```
