# ft\_toupper

#### Prototipo

C

```
int	ft_toupper(int c);
```

#### Descripción

Convierte un carácter en minúscula (`'a'` a `'z'`) a su equivalente en mayúscula (`'A'` a `'Z'`). Si el carácter recibido ya está en mayúscula, no es una letra o no pertenece a la tabla ASCII, lo devuelve sin modificar.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                              |
| ------------- | -------- | ------------------------------------------------------------ |
| `c`           | `int`    | Valor ASCII del carácter que se desea convertir a mayúscula. |

* Aclaración: Se pasa como `int` para mantener la compatibilidad con la librería estándar de C (`<ctype.h>`) y permitir manejar valores especiales como `EOF`.

#### Valor de Retorno

* `int`: El valor ASCII del carácter en mayúscula si `c` era minúscula; de lo contrario, devuelve el mismo valor `c` sin alterar.

#### Casos Límite

* Límites exactos en minúscula: `'a'` (97) se convierte a `'A'` (65) y `'z'` (122) a `'Z'` (90).
* Ya en mayúscula: Caracteres como `'A'` o `'Z'` permanecen intactos sin sufrir cambios.
* Números, símbolos y caracteres especiales: Caracteres como `'9'`, `'@'`, `' '` o `'\n'` se devuelven exactamente igual.

#### Código Comentado

C

```
int	ft_toupper(int c)
{
	// Comprobamos si el carácter está en el rango de minúsculas
	if (c >= 'a' && c <= 'z')
		c = c - 32; // Restamos 32 al valor ASCII para convertirlo a mayúscula
	return (c); // Devolvemos el carácter (modificado o no)
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

int	ft_toupper(int c);

int	main(void)
{
	printf("-- testing ft_toupper() --\n");
	printf("'a' -> '%c' (Esperado: 'A')\n", ft_toupper('a'));
	printf("'z' -> '%c' (Esperado: 'Z')\n", ft_toupper('z'));
	printf("'A' -> '%c' (Esperado: 'A')\n", ft_toupper('A'));
	printf("'9' -> '%c' (Esperado: '9')\n", ft_toupper('9'));
	return (0);
}
```
