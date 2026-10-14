# ft\_strchr

#### Prototipo

C

```
char	*ft_strchr(const char *s, int c);
```

#### Descripción

Localiza la primera ocurrencia del carácter `c` (convertido a `char`) en la cadena apuntada por `s`. El carácter nulo de terminación (`'\0'`) se considera parte de la cadena, por lo que si se busca `'\0'`, la función devuelve un puntero a dicho fin de cadena.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                         |
| ------------- | -------------- | ------------------------------------------------------- |
| `s`           | `const char *` | Puntero a la cadena donde se realizará la búsqueda.     |
| `c`           | `int`          | Carácter que se desea encontrar (se casteará a `char`). |

* Aclaración: Se pasa como `int` para ser compatible con la firma estándar de C, pero dentro de la función se evalúa como `(char)c`. Devuelve un puntero de tipo `char *` haciendo un casteo para retirar la constante `const` del puntero de entrada.

#### Valor de Retorno

* `char *`: Puntero a la primera coincidencia del carácter dentro de la cadena.
* `NULL` (`0`): Si el carácter no se encuentra en la cadena.

#### Casos Límite

* Buscar `'\0'`: Debe devolver el puntero a la dirección exacta del carácter nulo final de la cadena, no `NULL`.
* Carácter no presente: Devuelve `NULL` tras recorrer toda la cadena hasta el final.
* Múltiples ocurrencias: Devuelve un puntero únicamente a la primera ocurrencia empezando por la izquierda.

#### Código Comentado

C

```
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	// Recorremos la cadena hasta llegar al terminador nulo '\0'
	while (s[i] != '\0')
	{
		// Si encontramos la coincidencia con el carácter casteado a char
		if (s[i] == (char)c)
			return ((char *)&s[i]); // Retornamos el puntero a esa posición
		i++;
	}
	// Comprobación adicional por si se buscaba el carácter nulo '\0' al final
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0); // Si no se encuentra, devolvemos NULL (0)
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

int	main(void)
{
	char	str[] = "Hola 42!";
	char	*ptr;

	printf("-- testing ft_strchr() --\n");

	ptr = ft_strchr(str, '4');
	printf("Buscar '4' : %s (Esperado: 42!)\n", ptr ? ptr : "NULL");

	ptr = ft_strchr(str, 'x');
	printf("Buscar 'x' : %s (Esperado: NULL)\n", ptr ? ptr : "NULL");

	ptr = ft_strchr(str, '\0');
	printf("Buscar '\\0': %s\n", ptr ? "Encontrado fin de cadena" : "NULL");
	return (0);
}
```
