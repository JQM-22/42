# ft\_bzero

#### Prototipo

C

```
void	ft_bzero(void *s, size_t len);
```

#### Descripción

Escribe bytes de cero (`\0`) en los primeros `len` bytes del área de memoria apuntada por `s`. En la práctica, equivale a ejecutar `ft_memset(s, 0, len)`.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                               |
| ------------- | -------- | ------------------------------------------------------------- |
| `s`           | `void *` | Puntero al bloque de memoria que se desea rellenar con ceros. |
| `len`         | `size_t` | Número de bytes que se van a sobrescribir con el valor `0`.   |

* Aclaración: Recibe un `void *` para poder limpiar la memoria de cualquier tipo de variable o estructura. Se convierte internamente a `unsigned char *` para manipular la memoria byte a byte.

#### Valor de Retorno

* Ninguno (`void`): La función modifica el bloque de memoria directamente y no devuelve ningún valor.

#### Casos Límite

* `len = 0`: No modifica ningún byte del bloque de memoria.
* Puntero `NULL` con `len > 0`: Producirá un fallo de segmentación (_Segmentation fault_) al intentar acceder a direcciones no válidas.
* Corte de cadenas: Si escribes ceros en medio de un `char[]`, las funciones estándar de texto (como `printf` o `strlen`) interpretarán el primer `\0` como el fin de la cadena.

#### Código Comentado

C

```
#include <stddef.h>

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*str;
	size_t			i;

	// Convertimos el puntero void* a unsigned char* para acceso byte a byte
	str = (unsigned char *)s;
	i = 0;
	// Recorremos hasta haber sobrescrito 'len' bytes con el valor 0
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t len);

int	main(void)
{
	char	str[10] = "123456789";
	size_t	i;

	printf("-- testing ft_bzero() --\n");
	printf("Antes: %s\n", str);
	ft_bzero(str, 5);
	printf("Después (comprobación byte a byte):\n");
	i = 0;
	while (i < 9)
	{
		if (str[i] == '\0')
			printf("[%zu]: '\\0'\n", i);
		else
			printf("[%zu]: '%c'\n", i, str[i]);
		i++;
	}
	return (0);
}
```
