# ft\_isalpha

#### Prototipo

C

```
int	ft_isalpha(int c);
```

#### Descripción

Comprueba si el carácter recibido pertenece al alfabeto, es decir, si es una letra mayúscula (`'A'` a `'Z'`) o minúscula (`'a'` a `'z'`).

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                |
| ------------- | -------- | ---------------------------------------------- |
| `c`           | `int`    | Valor ASCII del carácter que se desea evaluar. |

* Aclaración: Se pasa como `int` (en lugar de `char`) para ser compatible con la función estándar de C y permitir evaluar caracteres promocionados a entero o el valor `EOF`.

#### Valor de Retorno

* `1`: Si el carácter es una letra alfabética (`'A'-'Z'` o `'a'-'z'`).
* `0`: Si el carácter NO es una letra (números, símbolos, espacios, etc.).

#### Casos Límite

* Límites ASCII exactos: `'A'` (65), `'Z'` (90), `'a'` (97) y `'z'` (122) deben devolver `1`.
* Caracteres justo fuera del rango: Por ejemplo, `'@'` (64) o `'['` (91) deben devolver `0`.
* Símbolos y números: Caracteres como `'0'`, `' '`, `'\n'` deben devolver `0`.

#### Código Comentado

C

```
int	ft_isalpha(int c)
{
	// Comprobamos si 'c' está entre 'A' y 'Z' O entre 'a' y 'z'
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1); // Es una letra
	return (0); // No es una letra
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

int	ft_isalpha(int c);

int	main(void)
{
	printf("-- testing ft_isalpha() --\n");
	printf("Prueba 'a': %d (Esperado: 1)\n", ft_isalpha('a'));
	printf("Prueba 'Z': %d (Esperado: 1)\n", ft_isalpha('Z'));
	printf("Prueba '5': %d (Esperado: 0)\n", ft_isalpha('5'));
	printf("Prueba '@': %d (Esperado: 0)\n", ft_isalpha('@'));
	return (0);
}
```
