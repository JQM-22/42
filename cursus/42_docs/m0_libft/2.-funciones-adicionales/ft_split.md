# ft\_split

#### Prototipo

C

```
char	**ft_split(char const *s, char c);
```

#### Descripción

Reserva memoria dinámica (mediante `malloc`) y devuelve un array de cadenas de caracteres (_array de strings_) resultante de separar la cadena `s` utilizando el carácter `c` como delimitador. El array retornado finaliza siempre con un puntero `NULL`.

Esta versión modulariza la lógica en funciones auxiliares privadas (`static`) para cumplir estrictamente con el límite de 25 líneas por función que exige la Norma de 42.

#### Concepto Clave: Funciones Estáticas (`static`) en C

En el lenguaje C, el modificador `static` aplicado a nivel de función restringe la visibilidad (ámbito de enlace o _linkage_) de esa función exclusivamente al archivo fuente (`.c`) donde está definida.

**¿Por qué son fundamentales en `libft`?**

1. Encapsulamiento y Ocultación de Información: Funciones auxiliares como `count_words`, `free_split` o `fill` solo tienen sentido como soporte interno para `ft_split`. Al marcarlas como `static`, evitamos que sean llamadas desde otros archivos de nuestro código o desde la librería compila.
2. Prevención de Colisiones de Nombres (_Name Pollution_): Si dos archivos `.c` definen una función auxiliar no estática llamada `count_words`, el compilador (en la fase de enlazado/linker) dará un error por duplicidad de símbolos. El modificador `static` hace que ese nombre sea privado para su propio archivo, evitando conflictos de nombres.
3. Pertenencia a la cabecera (`libft.h`): Las funciones `static` nunca deben incluirse en el archivo `libft.h`, ya que son privadas de la implementación interna y no forman parte de la interfaz pública de la librería.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                             |
| ------------- | -------------- | ----------------------------------------------------------- |
| `s`           | `char const *` | Cadena de caracteres que se desea dividir.                  |
| `c`           | `char`         | Carácter delimitador utilizado para realizar la separación. |

#### Funciones Estáticas Auxiliares

Las siguientes funciones secundarias dan soporte a la función principal `ft_split`:

**1. `count_words`**

* Prototipo: `static size_t count_words(char const *s, char c)`
* Misión: Cuenta cuántas palabras o bloques separados por el carácter `c` existen en la cadena `s`. Permite calcular exactamente la cantidad de memoria que debe reservar el `malloc` del array de punteros (`(count + 1) * sizeof(char *)`).

**2. `free_split`**

* Prototipo: `static void free_split(char **lst, size_t i)`
* Misión: Garantiza la gestión segura de memoria. Si la asignación de una subcadena falla en mitad del proceso, libera iterativamente todos los bloques de memoria reservados previamente (`free(lst[i])`) y finalmente el puntero principal (`free(lst)`), evitando _memory leaks_.

**3. `fill`**

* Prototipo: `static char **fill(char **lst, char const *s, char c)`
* Misión: Extrae el módulo del bucle principal de `ft_split`. Recorre la cadena `s`, calcula la longitud de cada palabra, extrae cada subcadena con `ft_substr` y las asigna al array de punteros `lst`. Si ocurre un fallo en la reserva de alguna subcadena, invoca a `free_split` para liberar lo asignado hasta ese momento y retorna `NULL`.

#### Valor de Retorno

* `char **`: Array de cadenas de caracteres resultante de la división, terminado en un puntero `NULL`.
* `NULL`: Si falla la reserva de memoria con `malloc` o si la cadena `s` recibida es `NULL`.

#### Casos Límite

* `s` es `NULL`: Retorna `NULL` para prevenir violaciones de acceso a memoria.
* Cadena vacía (`""`) o compuesta únicamente por el delimitador `c`: Retorna un array de tamaño 1 conteniendo exclusivamente un puntero `NULL`.
* Sin apariciones del delimitador `c`: Retorna un array con un único elemento (la cadena completa duplicada) y finalizado en `NULL`.
* Fallo intermedio de `malloc`: `fill` aborta el proceso invocando a `free_split` para liberar todas las palabras alojadas hasta el momento y el puntero principal, devolviendo `NULL`.

#### Código Comentado

C

```
#include "libft.h"

// Cuenta el número de palabras separadas por el delimitador 'c'
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

// Libera iterativamente toda la memoria asignada antes de un error de asignación
static void	free_split(char **lst, size_t i)
{
	while (i > 0)
	{
		i--;
		free(lst[i]);
	}
	free(lst);
}

// Rellena el array de punteros reservando memoria para cada subcadena hallada
static char	**fill(char **lst, char const *s, char c)
{
	size_t	word_len;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = 0;
			while (s[word_len] && s[word_len] != c)
				word_len++;
			lst[i] = ft_substr(s, 0, word_len);
			if (!lst[i])
				return (free_split(lst, i), NULL);
			i++;
			s += word_len;
		}
		else
			s++;
	}
	lst[i] = NULL;
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;

	if (!s)
		return (NULL);
	// Reservamos espacio para el array de punteros a string + 1 para el NULL final
	lst = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	// Delegamos el proceso de extracción e inserción a la función auxiliar
	return (fill(lst, s, c));
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);

int	main(void)
{
	char	**split;
	int		i;

	printf("-- testing ft_split() refactorizado --\n");
	split = ft_split("  42  Malaga   Cursus  Libft ", ' ');
	if (!split)
	{
		printf("Error al reservar memoria\n");
		return (1);
	}
	i = 0;
	while (split[i])
	{
		printf("Palabra [%d]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
```
