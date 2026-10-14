# ft\_isdigit

#### Prototipo

C

```
int	ft_isdigit(int c);
```

#### Descripción

Comprueba si el carácter recibido es un dígito numérico decimal (del `'0'` al `'9'`).

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                |
| ------------- | -------- | ---------------------------------------------- |
| `c`           | `int`    | Valor ASCII del carácter que se desea evaluar. |

* Aclaración: Al igual que en `ft_isalpha`, se pasa como `int` para mantener la compatibilidad con los tipos devueltos por funciones como `getchar()` o el valor `EOF`.

#### Valor de Retorno

* `1`: Si el carácter es un número del `'0'` al `'9'`.
* `0`: Si el carácter NO es un dígito decimal.

#### Casos Límite

* Límites ASCII exactos: `'0'` (48) y `'9'` (57) deben devolver `1`.
* Caracteres contiguos fuera de rango: `'/'` (47, justo antes del 0) y `':'` (58, justo después del 9) deben devolver `0`.
* Números pasados como entero directo: Pasar el valor numérico `5` (ASCII ENQ) debe devolver `0`; hay que pasar el carácter `'5'` (ASCII 53).

#### Código Comentado

C

```
int	ft_isdigit(int c)
{
	// Comprobamos si el valor ASCII de 'c' está entre el del '0' y el del '9'
	if (c >= '0' && c <= '9')
		return (1); // Es un dígito decimal
	return (0); // No es un dígito decimal
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

int	ft_isdigit(int c);

int	main(void)
{
	printf("-- testing ft_isdigit() --\n");
	printf("Prueba '5': %d (Esperado: 1)\n", ft_isdigit('5'));
	printf("Prueba '0': %d (Esperado: 1)\n", ft_isdigit('0'));
	printf("Prueba 'a': %d (Esperado: 0)\n", ft_isdigit('a'));
	printf("Prueba '/': %d (Esperado: 0)\n", ft_isdigit('/'));
	return (0);
}
```
