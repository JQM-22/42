# ft\_isprint

#### Prototipo

C

```
int	ft_isprint(int c);
```

#### Descripción

Comprueba si el carácter recibido es imprimible, es decir, si ocupa espacio visual e incluye desde el espacio en blanco (`' '`, ASCII 32) hasta la virgulilla o tilde (`'~'`, ASCII 126).

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                |
| ------------- | -------- | ---------------------------------------------- |
| `c`           | `int`    | Valor ASCII del carácter que se desea evaluar. |

* Aclaración: Se recibe como `int` para mantener la firma estándar de la librería `<ctype.h>` y permitir pasar enteros representando caracteres o valores especiales.

#### Valor de Retorno

* `1`: Si el carácter es imprimible (ASCII 32 a 126).
* `0`: Si el carácter NO es imprimible (caracteres de control como `\n`, `\t`, `\0`, o valores fuera de rango).

#### Casos Límite

* Límites exactos: `' '` (32) y `'~'` (126) deben devolver `1`.
* Caracteres de control justo fuera: `31` (justo antes del espacio, como `US`) y `127` (`DEL`, justo después de `~`) deben devolver `0`.
* Caracteres invisibles comunes: `'\n'` (10), `'\t'` (9) y `'\0'` (0) deben devolver `0`.

#### Código Comentado

C

```
int	ft_isprint(int c)
{
	// Verifica si 'c' está en el rango de caracteres imprimibles (32 al 126)
	if (c >= 32 && c <= 126)
		return (1); // Es un carácter imprimible
	return (0); // No es imprimible (carácter de control o fuera de rango)
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

int	ft_isprint(int c);

int	main(void)
{
	printf("-- testing ft_isprint() --\n");
	printf("Prueba 'a': %d (Esperado: 1)\n", ft_isprint('a'));
	printf("Prueba ' ' (espacio): %d (Esperado: 1)\n", ft_isprint(' '));
	printf("Prueba '~': %d (Esperado: 1)\n", ft_isprint('~'));
	printf("Prueba '\\n': %d (Esperado: 0)\n", ft_isprint('\n'));
	printf("Prueba 127 (DEL): %d (Esperado: 0)\n", ft_isprint(127));
	return (0);
}
```
