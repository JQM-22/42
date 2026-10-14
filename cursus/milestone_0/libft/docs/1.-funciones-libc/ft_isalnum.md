# ft\_isalnum

#### Prototipo

C

```
int	ft_isalnum(int c);
```

#### Descripción

Comprueba si el carácter recibido es alfanumérico, es decir, si es una letra (`'a'-'z'`, `'A'-'Z'`) o un dígito numérico (`'0'-'9'`).

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                |
| ------------- | -------- | ---------------------------------------------- |
| `c`           | `int`    | Valor ASCII del carácter que se desea evaluar. |

* Aclaración: Se recibe un `int` para mantener la coherencia con las demás funciones de la librería `<ctype.h>` y admitir valores promovidos o `EOF`.

#### Valor de Retorno

* `1`: Si el carácter es alfanumérico (letra o número).
* `0`: Si el carácter NO es alfanumérico (símbolos, espacios, signos de puntuación, etc.).

#### Casos Límite

* Cualquier letra (mayúscula o minúscula) o número: Debe devolver `1`.
* Símbolos contiguos a las letras/números: Caracteres como `'/'` (47), `':'` (58), `'@'` (64), `'['` (91), `` '` `` (96) o `'{'` (123) deben devolver `0`.
* Espacios y caracteres invisibles: `' '`, `'\n'`, `'\t'` deben devolver `0`.

#### Código Comentado

C

```
int	ft_isalnum(int c)
{
	// Comprueba si 'c' es minúscula, mayúscula O un número decimal
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1); // Es alfanumérico
	return (0); // No es alfanumérico
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

int	ft_isalnum(int c);

int	main(void)
{
	printf("-- testing ft_isalnum() --\n");
	printf("Prueba 'a': %d (Esperado: 1)\n", ft_isalnum('a'));
	printf("Prueba '2': %d (Esperado: 1)\n", ft_isalnum('2'));
	printf("Prueba '@': %d (Esperado: 0)\n", ft_isalnum('@'));
	printf("Prueba ' ': %d (Esperado: 0)\n", ft_isalnum(' '));
	return (0);
}
```
