# ft\_striteri

#### Prototipo

C

```
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
```

#### Descripción

Aplica la función `f` a cada carácter de la cadena `s`, pasando su índice como primer argumento y la dirección de memoria del carácter como segundo. A diferencia de `ft_strmapi`, esta función no crea una nueva cadena ni reserva memoria dinámicamente, sino que modifica la cadena `s` directamente (_in-place_).

#### Parámetros

| **Parámetro** | **Tipo**                         | **Descripción**                                                                    |
| ------------- | -------------------------------- | ---------------------------------------------------------------------------------- |
| `s`           | `char *`                         | Cadena de caracteres sobre la cual se iterará y modificará directamente.           |
| `f`           | `void (*)(unsigned int, char *)` | Puntero a la función que se aplicará sobre la dirección de cada carácter e índice. |

* Aclaración: El segundo parámetro del puntero a función es un `char *` (puntero a carácter), lo que permite que la función `f` modifique directamente el valor guardado en esa posición de la memoria.

#### Valor de Retorno

* Ninguno (`void`): La función modifica la cadena `s` in situ y no devuelve ningún valor.

#### Casos Límite

* `s` o `f` son `NULL`: Retorna inmediatamente sin realizar ninguna operación, previniendo fallos de acceso a memoria.
* Cadena vacía (`""`): El bucle no se ejecuta y finaliza de manera segura.
* Bucle infinito por incremento fuera del bucle: Es crucial asegurarse de que la variable de iteración `i` se incremente dentro del bucle `while`.

#### Código Comentado

C

```
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	// Si el puntero de la cadena o la función son NULL, salimos inmediatamente
	if (!s || !f)
		return ;
	i = 0;
	// Recorremos la cadena carácter a carácter
	while (s[i])
	{
		// Pasamos el índice actual 'i' y la dirección de memoria del carácter '&s[i]'
		f(i, &s[i]);
		i++; // Incrementamos el índice para avanzar al siguiente carácter
	}
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// Función de prueba: convierte a mayúscula los caracteres en índices pares
void	my_toupper_even_inplace(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char	str[] = "42malaga";

	printf("-- testing ft_striteri() --\n");
	printf("Antes    : %s\n", str);
	
	ft_striteri(str, my_toupper_even_inplace);
	
	printf("Después  : %s (Esperado: 42MaLaGa)\n", str);
	return (0);
}
```
