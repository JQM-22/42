# ft\_memmove

#### Prototipo

C

```
void	*ft_memmove(void *dest, const void *src, size_t n);
```

#### Descripción

Copia `n` bytes de la memoria de origen (`src`) a la de destino (`dest`). A diferencia de `ft_memcpy`, esta función gestiona de forma segura el solapamiento de memoria (_overlap_): si la zona de destino está después de la de origen, realiza la copia de atrás hacia adelante para evitar sobrescribir datos antes de leerlos.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                            |
| ------------- | -------------- | ---------------------------------------------------------- |
| `dest`        | `void *`       | Puntero al bloque de memoria de destino.                   |
| `src`         | `const void *` | Puntero al bloque de memoria de origen que se va a copiar. |
| `n`           | `size_t`       | Cantidad de bytes a copiar.                                |

* Aclaración: Al recibir `void *` permite mover datos de cualquier tipo. Se realiza el cast a `unsigned char *` (y `const unsigned char *` para `src`) para manipular la memoria byte a byte con precisión.

#### Valor de Retorno

* `void *`: Devuelve el puntero original al bloque de destino `dest`.

#### Casos Límite

* `dest` y `src` son ambos `NULL`: Devuelve `dest` (`NULL`) directamente para prevenir errores de segmentación.
* `n = 0`: No efectúa ningún cambio en memoria y devuelve `dest`.
* Solapamiento hacia adelante (`dest > src`): Se copia desde el último byte hasta el primero (`n - 1` hasta `0`) para no corromper la información que falta por leer.
* Sin solapamiento o `dest <= src`: Copia normal de izquierda a derecha.

#### Código Comentado

C

```
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	// Si ambos punteros son NULL, retornamos dest directamente
	if (!dest && !src)
		return (dest);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	// Si el destino está por delante del origen en memoria (hay solapamiento peligroso)
	if (d > s)
	{
		// Copiamos de atrás hacia adelante
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
		return (dest);
	}
	// Si dest <= src o no hay conflicto, copiamos de izquierda a derecha
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

int	main(void)
{
	char	str[20] = "123456789";

	printf("-- testing ft_memmove() (solapamiento) --\n");
	printf("Antes  : %s\n", str);
	// Copiamos los primeros 5 bytes ("12345") 2 posiciones a la derecha
	ft_memmove(str + 2, str, 5);
	printf("Después: %s (Esperado: 121234589)\n", str);
	return (0);
}
```
