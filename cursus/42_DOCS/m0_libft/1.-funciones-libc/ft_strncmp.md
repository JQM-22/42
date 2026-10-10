# ft\_strncmp

#### Prototipo

C

```
int	ft_strncmp(const char *s1, const char *s2, size_t n);
```

#### Descripción

Compara lexicográficamente como máximo los primeros `n` caracteres de dos cadenas, `s1` y `s2`. La comparación se detiene en cuanto se encuentra una diferencia, se alcanza el carácter nulo (`'\0'`), o se han comparado `n` caracteres.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                       |
| ------------- | -------------- | ----------------------------------------------------- |
| `s1`          | `const char *` | Puntero a la primera cadena de caracteres a comparar. |
| `s2`          | `const char *` | Puntero a la segunda cadena de caracteres a comparar. |
| `n`           | `size_t`       | Número máximo de caracteres a comparar.               |

* Aclaración: Los caracteres se comparan tras convertirse a `unsigned char` para asegurar que el resultado coincida siempre con el orden ASCII numérico estándar (evitando problemas con valores superiores a 127 o negativos según el sistema).

#### Valor de Retorno

* `0`: Si las dos cadenas son idénticas en los primeros `n` caracteres (o si `n == 0`).
* Valor negativo (`< 0`): Si el primer carácter diferente en `s1` es menor en el código ASCII que el de `s2`.
* Valor positivo (`> 0`): Si el primer carácter diferente en `s1` es mayor en el código ASCII que el de `s2`.

#### Casos Límite

* `n = 0`: Devuelve `0` inmediatamente sin leer memoria.
* Cadenas de diferente longitud: Si una cadena termina (`'\0'`) antes de alcanzar la diferencia o llegar a `n`, la comparación evaluará `'\0'` frente al carácter correspondiente de la otra.
* Comparación hasta el carácter nulo: Si ambas cadenas son iguales y terminan antes de `n`, la función se detiene y devuelve `0`.

#### Código Comentado

C

```
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	// Si n es 0, no debemos comparar nada y devolvemos 0
	if (n == 0)
	{
		return (0);
	}
	// Avanzamos mientras s1 no sea '\0', los caracteres coincidan y estemos antes del último byte permitido (n - 1)
	while (s1[i] != '\0' && s1[i] == s2[i] && i < (n - 1))
	{
		i++;
	}
	// Retornamos la diferencia restando los valores casteados a unsigned char
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	char	s1[] = "Hola 42";
	char	s2[] = "Hola World";

	printf("-- testing ft_strncmp() --\n");
	printf("Cadenas a comparar: s1: \"Hola 42\" | s2: \"Hola World\"\n");
	
	// Primeros 4 caracteres ("Hola" vs "Hola") -> Esperado: 0
	printf("Comparar 4 caracteres : %d (Esperado: 0)\n", ft_strncmp(s1, s2, 4));

	// Primeros 6 caracteres ("Hola 4" vs "Hola W") -> Esperado: Negativo ('4' < 'W')
	printf("Comparar 6 caracteres : %d (Esperado: Negativo)\n", ft_strncmp(s1, s2, 6));

	// Caso límite n = 0 -> Esperado: 0
	printf("Comparar 0 caracteres : %d (Esperado: 0)\n", ft_strncmp(s1, s2, 0));

	return (0);
}
```
