# ft\_strlcat

#### Prototipo

C

```
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
```

#### Descripción

Concatena la cadena `src` al final de la cadena `dst`, asegurando no sobrepasar el tamaño total del búfer (`dst_size`) y garantizando siempre la terminación en nulo (`'\0'`), siempre que exista espacio libre en el búfer.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                                           |
| ------------- | -------------- | ------------------------------------------------------------------------- |
| `dst`         | `char *`       | Búfer de destino que contiene la cadena inicial y donde se añadirá `src`. |
| `src`         | `const char *` | Cadena origen que se concatenará al final de `dst`.                       |
| `dst_size`    | `size_t`       | Tamaño total máximo reservado en memoria para el búfer `dst`.             |

* Aclaración: `dst_size` no representa cuántos caracteres queremos añadir, sino la capacidad total del búfer de destino. Si la cadena original en `dst` ocupa igual o más que `dst_size`, no se concatenará nada.

#### Valor de Retorno

* `size_t`: La longitud total de la cadena que intentó crear (`longitud inicial de dst` + `longitud de src`).
* Excepción: Si `dst_size` es menor o igual a la longitud inicial de `dst`, devuelve `dst_size + strlen(src)`.

#### Casos Límite

* `dst_size <= strlen(dst)`: No se añade ningún carácter a `dst` para no desbordar memoria; devuelve `dst_size + strlen(src)`.
* Sin espacio para `\0`: Si solo hay espacio para añadir caracteres sin espacio para el nulo final, el último carácter escrito será sustituido por `'\0'`.
* `dst_size = 0`: Retorna `strlen(src)` inmediatamente sin modificar `dst`.

#### Código Comentado

C

```
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	d_len;

	// Obtenemos la longitud de dst sin sobrepasar dst_size
	d_len = 0;
	while (dst[d_len] != '\0' && d_len < dst_size)
		d_len++;
	// Obtenemos la longitud completa de src
	s_len = 0;
	while (src[s_len] != '\0')
		s_len++;
	// Si el tamaño del buffer es menor o igual a la cadena en dst, no podemos concatenar
	if (d_len >= dst_size)
		return (dst_size + s_len);
	i = d_len;
	j = 0;
	// Copiamos caracteres de src asegurando dejar espacio para el '\0' final (i + 1 < dst_size)
	while (src[j] != '\0' && (i + 1) < dst_size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	// Cerramos la cadena con el carácter nulo
	dst[i] = '\0';
	// Retornamos la longitud total que intentamos crear
	return (d_len + s_len);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);

int	main(void)
{
	char	dst[15] = "Hola ";
	char	src[] = "42!";
	size_t	ret;

	printf("-- testing ft_strlcat() --\n");
	printf("Antes        : dst = \"%s\"\n", dst);
	
	ret = ft_strlcat(dst, src, sizeof(dst));
	
	printf("Después      : dst = \"%s\" (Esperado: Hola 42!)\n", dst);
	printf("Valor devuelto: %zu (Esperado: 8)\n", ret);
	return (0);
}
```
