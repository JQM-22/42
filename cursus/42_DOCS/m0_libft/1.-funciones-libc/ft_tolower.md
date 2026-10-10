# ft\_tolower

#### Prototipo

C

```
int	ft_tolower(int c);
```

#### Descripción

Convierte un carácter en mayúscula (`'A'` a `'Z'`) a su equivalente en minúscula (`'a'` a `'z'`). Si el carácter recibido ya está en minúscula, no es una letra o no pertenece a la tabla ASCII, lo devuelve sin modificar.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                              |
| ------------- | -------- | ------------------------------------------------------------ |
| `c`           | `int`    | Valor ASCII del carácter que se desea convertir a minúscula. |

* Aclaración: Se pasa como `int` para mantener la compatibilidad con la librería estándar de C (`<ctype.h>`) y permitir manejar valores especiales como `EOF`.

#### Valor de Retorno

* `int`: El valor ASCII del carácter en minúscula si `c` era mayúscula; de lo contrario, devuelve el mismo valor `c` sin alterar.

#### Casos Límite

* Límites exactos en mayúscula: `'A'` (65) se convierte a `'a'` (97) y `'Z'` (90) a `'z'` (122).
* Ya en minúscula: Caracteres como `'a'` o `'z'` permanecen intactos sin sufrir cambios.
* Números, símbolos y caracteres especiales: Caracteres como `'9'`, `'@'`, `' '` o `'\n'` se devuelven exactamente igual.

#### Código Comentado

C

```
int	ft_tolower(int c)
{
	// Comprobamos si el carácter está en el rango de mayúsculas
	if (c >= 'A' && c <= 'Z')
		c = c + 32; // Sumamos 32 al valor ASCII para convertirlo a minúscula
	return (c); // Devolvemos el carácter (modificado o no)
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

int	ft_tolower(int c);

int	main(void)
{
	printf("-- testing ft_tolower() --\n");
	printf("'A' -> '%c' (Esperado: 'a')\n", ft_tolower('A'));
	printf("'Z' -> '%c' (Esperado: 'z')\n", ft_tolower('Z'));
	printf("'a' -> '%c' (Esperado: 'a')\n", ft_tolower('a'));
	printf("'9' -> '%c' (Esperado: '9')\n", ft_tolower('9'));
	return (0);
}
```
