# ft\_strlcpy

#### Prototipo

C

```
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len);
```

#### Descripción

Copia hasta `dst_len - 1` caracteres de la cadena `src` en el búfer de destino `dst`, garantizando siempre que el resultado final termine en el carácter nulo (`'\0'`) siempre que `dst_len` sea mayor que `0`. Es una alternativa más segura a `strncpy`.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                    |
| ------------- | -------------- | -------------------------------------------------- |
| `dst`         | `char *`       | Búfer de destino donde se copiarán los caracteres. |
| `src`         | `const char *` | Cadena origen de la que se copiarán los datos.     |
| `dst_len`     | `size_t`       | Tamaño total disponible del búfer de destino.      |

* Aclaración: `dst_len` representa la capacidad total del array de destino (incluyendo el espacio para el `'\0'`). `src` lleva `const` porque la función solo lee sus datos sin modificarlos.

#### Valor de Retorno

* `size_t`: La longitud total de la cadena `src` que intentó crear. Este valor permite detectar si la cadena fue truncada (si el valor devuelto es mayor o igual a `dst_len`).

#### Casos Límite

* `dst_len = 0`: No copia nada en `dst` (evita escribir en memoria no reservada) y devuelve la longitud de `src`.
* Truncamiento (`dst_len <= ft_strlen(src)`): Copia `dst_len - 1` caracteres, añade `'\0'` al final y devuelve `ft_strlen(src)`.
* `dst_len` mayor a `src`: Copia toda la cadena `src` completa con su `'\0'` final.

#### Código Comentado

C

```
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t	i;
	size_t	src_len;

	// Medimos la longitud total de la cadena origen
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	// Si el tamaño del buffer es 0, devolvemos la longitud de src sin copiar nada
	if (dst_len == 0)
		return (src_len);
	i = 0;
	// Copiamos caracteres dejando espacio para el '\0' final (dst_len - 1)
	while (src[i] != '\0' && i < dst_len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	// Aseguramos la terminación nula de la cadena
	dst[i] = '\0';
	// Devolvemos la longitud de la cadena que se intentó crear (src_len)
	return (src_len);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len);

int	main(void)
{
	char	src[] = "Hola 42!";
	char	dst[10];
	size_t	ret;

	printf("-- testing ft_strlcpy() --\n");
	ret = ft_strlcpy(dst, src, sizeof(dst));
	printf("Cadena copiada : %s\n", dst);
	printf("Valor devuelto : %zu (longitud de src)\n", ret);
	return (0);
}
```
