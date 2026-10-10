# ft\_strnstr

#### Prototipo

C

```
char	*ft_strnstr(const char *big, const char *little, size_t len);
```

#### Descripción

Busca la primera ocurrencia de la subcadena `little` dentro de la cadena `big`, examinando como máximo los primeros `len` caracteres de `big`. Los caracteres que aparezcan después del carácter nulo (`'\0'`) o más allá de `len` no se tienen en cuenta.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                   |
| ------------- | -------------- | ------------------------------------------------- |
| `big`         | `const char *` | Cadena principal donde se realiza la búsqueda.    |
| `little`      | `const char *` | Subcadena que se desea localizar dentro de `big`. |
| `len`         | `size_t`       | Número máximo de caracteres de `big` a examinar.  |

* Aclaración: Se declaran como `const char *` para proteger ambas cadenas de modificaciones. Se realiza un cast a `char *` al retornar para cumplir con la firma original de la función.

#### Valor de Retorno

* `big`: Si `little` es una cadena vacía (`""`).
* `char *`: Puntero al primer carácter de la primera ocurrencia de `little` dentro de `big`.
* `NULL` (`0`): Si `little` no se encuentra dentro de los primeros `len` caracteres de `big`.

#### Casos Límite

* `little` es vacía (`""`): Devuelve `(char *)big` de inmediato.
* `len` insuficiente: Si `little` aparece en `big`, pero excede o empieza más allá del límite `len`, devuelve `NULL`.
* `len = 0`: Devuelve `NULL` a menos que `little` sea vacía, en cuyo caso devuelve `big`.
* Subcadena parcial: Si coincide solo una parte de `little` antes de llegar a `len` o al final de `big`, no se considera encontrada y devuelve `NULL`.

#### Código Comentado

C

```
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	// Si little está vacía, devolvemos big inmediatamente
	if (little[0] == '\0')
		return ((char *)big);
	// Recorremos big mientras no termine y no superemos el límite len
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		// Comparamos caracteres consecutivos mientras coincidan, no superen len ni el final de cadena
		while (big[i + j] == little[j] && (i + j) < len && big[i + j] != '\0')
		{
			j++;
		}
		// Si hemos llegado al final de little, significa que encontramos la coincidencia completa
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0); // No se encontró dentro del límite len
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

int	main(void)
{
	char	*big = "42 Malaga - Escuela de Programacion";
	char	*res;

	printf("-- testing ft_strnstr() --\n");

	// Buscar 'Malaga' dentro de los primeros 10 caracteres (no llega a abarcar toda la palabra)
	res = ft_strnstr(big, "Malaga", 10);
	printf("Buscar 'Malaga' (len 10): %s (Esperado: NULL)\n", res ? res : "NULL");

	// Buscar 'Malaga' dentro de los primeros 15 caracteres
	res = ft_strnstr(big, "Malaga", 15);
	printf("Buscar 'Malaga' (len 15): %s (Esperado: Malaga - Escuela...)\n", res ? res : "NULL");

	// Buscar cadena vacía
	res = ft_strnstr(big, "", 10);
	printf("Buscar '' (vacía)       : %s\n", res ? res : "NULL");

	return (0);
}
```
