# ft\_strjoin

#### Prototipo

C

```
char	*ft_strjoin(char const *s1, char const *s2);
```

#### Descripción

Reserva memoria dinámica (mediante `malloc`) y devuelve una nueva cadena de caracteres resultante de concatenar la cadena `s1` seguida de la cadena `s2`.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                              |
| ------------- | -------------- | -------------------------------------------- |
| `s1`          | `char const *` | Primera cadena (prefijo de la nueva cadena). |
| `s2`          | `char const *` | Segunda cadena (sufijo de la nueva cadena).  |

* Aclaración: Ambas cadenas llevan el calificador `const` ya que solo se leen para construir la nueva cadena unida. La memoria resultante debe liberarse posteriormente con `free()`.

#### Valor de Retorno

* `char *`: Puntero a la nueva cadena con la concatenación de `s1` y `s2`, terminada en `'\0'`.
* `NULL`: Si falla la reserva de memoria con `malloc`.

#### Casos Límite

* Cadenas vacías (`""`): Si una de las cadenas está vacía, devuelve una copia de la otra. Si ambas están vacías, asigna memoria para 1 byte y devuelve `""`.
* Fallo de asignación de memoria: Si `malloc` devuelve `NULL`, la función retorna `NULL` sin intentar acceder ni copiar ningún carácter.

#### Código Comentado

C

```
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_res;
	size_t	i;
	size_t	j;

	// Reservamos la memoria exacta: strlen(s1) + strlen(s2) + 1 byte para el '\0'
	s_res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s_res == NULL)
		return (NULL);
	i = 0;
	// Copiamos todos los caracteres de la primera cadena (s1)
	while (s1[i])
	{
		s_res[i] = s1[i];
		i++;
	}
	j = 0;
	// Copiamos los caracteres de la segunda cadena (s2) a continuación de s1
	while (s2[j])
	{
		s_res[i] = s2[j];
		j++;
		i++;
	}
	// Cerramos la cadena concatenada con el carácter nulo
	s_res[i] = '\0';
	return (s_res);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

int	main(void)
{
	char	*s1 = "Hola ";
	char	*s2 = "42 Malaga!";
	char	*joined;

	printf("-- testing ft_strjoin() --\n");
	joined = ft_strjoin(s1, s2);
	if (!joined)
	{
		printf("Error al reservar memoria\n");
		return (1);
	}
	printf("Cadena 1  : %s\n", s1);
	printf("Cadena 2  : %s\n", s2);
	printf("Resultado : %s (Esperado: Hola 42 Malaga!)\n", joined);

	free(joined);
	return (0);
}
```
