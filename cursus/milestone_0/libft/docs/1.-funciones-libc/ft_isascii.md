# ft\_isascii

#### Prototipo

C

```
int	ft_isascii(int c);
```

#### Descripción

Comprueba si el entero o carácter recibido pertenece a la tabla ASCII estándar, cuyo rango comprende los valores comprendidos entre `0` y `127` (ambos incluidos).

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                             |
| ------------- | -------- | ----------------------------------------------------------- |
| `c`           | `int`    | Valor entero o carácter a comprobar dentro del rango ASCII. |

* Aclaración: Al pasar un `int`, podemos evaluar tanto caracteres imprimibles como caracteres de control invisibles (`NUL`, `tab`, `newline`) o valores fuera de la tabla ASCII de 7 bits.

#### Valor de Retorno

* `1`: Si el valor de `c` está entre `0` y `127`.
* `0`: Si el valor de `c` es negativo o mayor que `127` (caracteres de la tabla ASCII extendida o valores no válidos).

#### Casos Límite

* Límites exactos: `0` (carácter `\0` / NUL) y `127` (carácter `DEL`) deben devolver `1`.
* Valores negativos: Valóres como `-1` u otros enteros negativos deben devolver `0`.
* ASCII extendido o superiores: El valor `128` en adelante debe devolver `0`.

#### Código Comentado

C

```
int	ft_isascii(int c)
{
	// Verificamos si 'c' está dentro del rango de 7 bits (0 a 127)
	if (c >= 0 && c <= 127)
		return (1); // Es un carácter ASCII válido
	return (0); // Está fuera de la tabla ASCII estándar
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

int	ft_isascii(int c);

int	main(void)
{
	printf("-- testing ft_isascii() --\n");
	printf("Prueba 'a' (97): %d (Esperado: 1)\n", ft_isascii('a'));
	printf("Prueba 0 (NUL): %d (Esperado: 1)\n", ft_isascii(0));
	printf("Prueba 127 (DEL): %d (Esperado: 1)\n", ft_isascii(127));
	printf("Prueba 128: %d (Esperado: 0)\n", ft_isascii(128));
	printf("Prueba -5: %d (Esperado: 0)\n", ft_isascii(-5));
	return (0);
}
```
