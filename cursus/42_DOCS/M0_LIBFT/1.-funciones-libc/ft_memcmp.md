# ft\_memcmp

#### Prototipo

C

```
int	ft_memcmp(const void *s1, const void *s2, size_t n);
```

#### Descripción

Compara byte a byte los primeros `n` bytes de las dos áreas de memoria apuntadas por `s1` y `s2`. A diferencia de `ft_strncmp`, esta función no se detiene al encontrar un carácter nulo (`'\0'`), ya que trabaja con bloques de memoria binaria puros hasta completar exactamente los `n` bytes indicados.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                  |
| ------------- | -------------- | ------------------------------------------------ |
| `s1`          | `const void *` | Puntero al primer bloque de memoria a comparar.  |
| `s2`          | `const void *` | Puntero al segundo bloque de memoria a comparar. |
| `n`           | `size_t`       | Número de bytes a comparar.                      |

* Aclaración: Se utilizan punteros `const void *` para aceptar cualquier tipo de datos sin permitir su modificación. Internamente se realiza un casteo a `unsigned char *` para asegurar que las restas y comparaciones entre bytes sean siempre positivas e independientes del signo por defecto del sistema.

#### Valor de Retorno

* `0`: Si los primeros `n` bytes de ambas regiones de memoria son idénticos (o si `n == 0`).
* Valor negativo (`< 0`): Si el primer byte diferente en `s1` es menor que el correspondiente en `s2`.
* Valor positivo (`> 0`): Si el primer byte diferente en `s1` es mayor que el correspondiente en `s2`.

#### Casos Límite

* `n = 0`: Devuelve `0` inmediatamente sin acceder a la memoria.
* Presencia de bytes `0` (`\0`): Continúa comparando los bytes posteriores al `\0` si `i < n`.
* Misma dirección de memoria (`s1 == s2`): Retornará `0` tras verificar todos los bytes del rango `n`.

#### Código Comentado

C

```
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	// Convertimos los punteros void* a unsigned char* para comparar byte a byte
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	// Recorremos los primeros n bytes
	while (i < n)
	{
		// Si encontramos un byte diferente, devolvemos la diferencia exacta
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0); // Todos los n bytes son idénticos
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	main(void)
{
	char	s1[] = "Hola\0Mundo";
	char	s2[] = "Hola\042!!";

	printf("-- testing ft_memcmp() --\n");
	printf("Comparar \"Hola\\0Mundo\" vs \"Hola\\042!!\"\n");

	// Primeros 4 bytes ("Hola" vs "Hola") -> Esperado: 0
	printf("Comparar 4 bytes : %d (Esperado: 0)\n", ft_memcmp(s1, s2, 4));

	// Primeros 5 bytes ("Hola\0" vs "Hola\0") -> Esperado: 0 (incluye el '\0')
	printf("Comparar 5 bytes : %d (Esperado: 0)\n", ft_memcmp(s1, s2, 5));

	// Primeros 6 bytes ('M' vs '4') -> Diferencia tras el '\0'
	printf("Comparar 6 bytes : %d (Esperado: Diferencia de 'M' - '4')\n", ft_memcmp(s1, s2, 6));

	return (0);
}
```
