# ft\_strrchr

#### Prototipo

C

```
char	*ft_strrchr(const char *s, int c);
```

#### Descripción

Localiza la última ocurrencia del carácter `c` (convertido a `char`) en la cadena apuntada por `s`. La búsqueda se realiza en orden inverso (de derecha a izquierda) y el carácter nulo final (`'\0'`) se considera parte de la cadena.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                         |
| ------------- | -------------- | ------------------------------------------------------- |
| `s`           | `const char *` | Puntero a la cadena donde se realizará la búsqueda.     |
| `c`           | `int`          | Carácter que se desea encontrar (se casteará a `char`). |

* Aclaración: Se pasa como `int` por compatibilidad con la firma estándar de C, pero se evalúa como `(char)c`. Retorna un puntero `char *` realizando un casteo para retirar la calificación `const` del parámetro de entrada.

#### Valor de Retorno

* `char *`: Puntero a la última coincidencia del carácter dentro de la cadena.
* `NULL` (`0`): Si el carácter no se encuentra en la cadena.

#### Casos Límite

* Buscar `'\0'`: Debe devolver el puntero al carácter nulo del final de la cadena, no `NULL`.
* Carácter no presente: Retorna `NULL` tras revisar toda la cadena de derecha a izquierda.
* Múltiples ocurrencias: Devuelve un puntero a la última ocurrencia (la más cercana al final).

#### Código Comentado

C

```
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	// Avanzamos hasta el final de la cadena para obtener su longitud
	while (s[i] != '\0')
		i++;
	// Si el carácter buscado es '\0', devolvemos la dirección del final
	if ((char)c == '\0')
		return ((char *)&s[i]);
	// Recorremos hacia atrás buscando la última coincidencia
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (0); // Si no se encuentra, devolvemos NULL (0)
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int	main(void)
{
	char	str[] = "42 Malaga - 42 School";
	char	*ptr;

	printf("-- testing ft_strrchr() --\n");
	printf("Cadena de prueba : %s\n", str);

	// Busca la última '4' (debe devolver el puntero dentro de "42 School")
	ptr = ft_strrchr(str, '4');
	printf("Buscar última '4': %s (Esperado: 42 School)\n", ptr ? ptr : "NULL");

	ptr = ft_strrchr(str, 'x');
	printf("Buscar 'x'       : %s (Esperado: NULL)\n", ptr ? ptr : "NULL");

	ptr = ft_strrchr(str, '\0');
	printf("Buscar '\\0'     : %s\n", ptr ? "Encontrado fin de cadena" : "NULL");
	return (0);
}
```
