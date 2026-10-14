# ft\_memset

#### Prototipo

C

```
void	*ft_memset(void *s, int c, size_t len);
```

#### Descripción

Rellena los primeros `len` bytes del área de memoria apuntada por `s` con el valor del byte `c` (convertido a `unsigned char`).

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                                |
| ------------- | -------- | -------------------------------------------------------------- |
| `s`           | `void *` | Puntero al bloque de memoria que se quiere rellenar.           |
| `c`           | `int`    | Valor a escribir en cada byte (se casteará a `unsigned char`). |
| `len`         | `size_t` | Número de bytes a rellenar a partir de la dirección `s`.       |

* Aclaración: Se usa un puntero `void *` para poder recibir cualquier tipo de dato en memoria (arrays de `int`, `char`, estructuras, etc.). Internamente, convertimos el puntero a `unsigned char *` para poder modificar la memoria byte a byte.

#### Valor de Retorno

* `void *`: Devuelve el puntero original `s` a la memoria modificada.

#### Casos Límite

* `len = 0`: No modifica nada en memoria y devuelve `s` directamente.
* Valores de `c` mayores a 255 o negativos: Se convierten a `unsigned char` automáticamente mediante un _cast_, tomando solo el último byte de su representación binaria.
* Puntero `NULL` con `len > 0`: Provocará un error de segmentación (_Segmentation fault_) al intentar acceder a direcciones no válidas.

#### Código Comentado

C

```
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	// Convertimos void* a unsigned char* para manipular la memoria byte por byte
	str = (unsigned char *)s;
	i = 0;
	// Recorremos byte a byte escribiendo el valor de 'c' hasta alcanzar 'len'
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	// Retornamos el puntero original recibido
	return (s);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t len);

int	main(void)
{
	char str[10] = "123456789";

	printf("-- testing ft_memset() --\n");
	printf("Antes  : %s\n", str);
	ft_memset(str, 'A', 5);
	printf("Después: %s (Esperado: AAAAA6789)\n", str);
	return (0);
}
```
