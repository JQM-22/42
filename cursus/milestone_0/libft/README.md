*Este proyecto ha sido creado como parte del currículo de 42 por joquinta.*

---
# Libft - Tu primera librería en C
---

## Indice

- [Descripción](#descripción)
- [Estructura de la Librería](#estructura-de-la-librería)
  - [1. Funciones de la LibC reescritas](#1-funciones-de-la-libc-reescritas)
  - [2. Funciones adicionales (Manipulación avanzada y E/S)](#2-funciones-adicionales-manipulación-avanzada-y-es)
  - [3. Funciones para manipulación de listas enlazadas (Estructura t_list)](#3-funciones-para-manipulación-de-listas-enlazadas-estructura-t_list)
- [Instrucciones](#instrucciones)
- [Recursos](#recursos)
---
## Descripción
---

**Libft** es el primer proyecto individual del currículo principal de la Escuela 42. El objetivo de este proyecto es recodificar una serie de funciones estándar de la librería C (`libc`), así como otras funciones de utilidad adicionales y manipulación de listas enlazadas, que servirán como base para futuros proyectos del programa escolar (como *get_next_line*, *ft_printf*, *push_swap*, entre otros).

A través de la implementación manual de estas funciones, se profundiza en el entendimiento de:
- Gestión y manipulación de memoria a bajo nivel (punteros, asignación dinámica con `malloc`/`free`).
- Manipulación de cadenas de caracteres y buffers de datos.
- Estructuras de datos dinámicas (listas simplemente enlazadas `t_list`).
- Creación y mantenimiento de librerías estáticas (`.a`) utilizando `Makefile`.
- Cumplimiento riguroso de normas de programación C (Norminette).

---
## Estructura de la Librería
---

La librería consta de las siguientes funciones organizadas por categorías:

### 1. Funciones de la LibC reescritas
- **Comprobación de caracteres:** 

<details>
<summary><b>ft_isalpha</b> — Comprueba si el carácter recibido pertenece al alfabeto</summary>

#### Prototipo
```C
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
```C
int	ft_isalpha(int c)
{
	// Comprobamos si 'c' está entre 'A' y 'Z' O entre 'a' y 'z'
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1); // Es una letra
	return (0); // No es una letra
}
```

#### Ejemplo de uso (main)
```C
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

</details>

<details>
<summary><b>ft_isdigit</b> — Comprueba si el carácter recibido es un dígito numérico decimal (del `'0'` al `'9'`).</summary>

#### Prototipo
``` C
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
```C
int	ft_isdigit(int c)
{
	// Comprobamos si el valor ASCII de 'c' está entre el del '0' y el del '9'
	if (c >= '0' && c <= '9')
		return (1); // Es un dígito decimal
	return (0); // No es un dígito decimal
}
```

#### Ejemplo de uso (main)
```C
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

</details>

<details>
<summary><b>ft_isalnum</b> — Comprueba si el carácter recibido es alfanumérico</summary>

#### Prototipo
```C
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
```C
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
```C
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

</details>

<details>
<summary><b>ft_isascii</b> — Comprueba si el entero o carácter recibido pertenece a la tabla ASCII estándar</summary>

#### Prototipo
```C
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
```C
int	ft_isascii(int c)
{
	// Verificamos si 'c' está dentro del rango de 7 bits (0 a 127)
	if (c >= 0 && c <= 127)
		return (1); // Es un carácter ASCII válido
	return (0); // Está fuera de la tabla ASCII estándar
}
```

#### Ejemplo de uso (main)
```C
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

</details>

<details>
<summary><b>ft_isprint</b> — Comprueba si el carácter recibido es alfanumérico</summary>

#### Prototipo
```C
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
```C
int	ft_isprint(int c)
{
	// Verifica si 'c' está en el rango de caracteres imprimibles (32 al 126)
	if (c >= 32 && c <= 126)
		return (1); // Es un carácter imprimible
	return (0); // No es imprimible (carácter de control o fuera de rango)
}
```

#### Ejemplo de uso (main)
```C
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

</details>

 
- **Conversión de caracteres:** 

<details>
<summary><b>ft_toupper</b> — Convierte un carácter en minúscula a su equivalente en mayúscula</summary>

#### Prototipo
```C
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

</details>

    - `ft_toupper`, 
    - `ft_tolower`.
- **Manejo de cadenas:** 
    - `ft_strlen`, 
    - `ft_strchr`, 
    - `ft_strrchr`, 
    - `ft_strncmp`, 
    - `ft_strnstr`, 
    - `ft_strlcpy`, 
    - `ft_strlcat`.
- **Manipulación de memoria:** 
    - `ft_memset`, 
    - `ft_bzero`, 
    - `ft_memcpy`, 
    - `ft_memmove`, 
    - `ft_memchr`, 
    - `ft_memcmp`.
- **Conversión de tipos:** 
    - `ft_atoi`.
- **Reserva de memoria:** 
    - `ft_calloc`, 
    - `ft_strdup`.

### 2. Funciones adicionales (Manipulación avanzada y E/S)
- `ft_substr`: Extrae una subcadena de una cadena dada.
- `ft_strjoin`: Concatena dos cadenas en una nueva reservada dinámicamente.
- `ft_strtrim`: Recorta caracteres especificados de los extremos de una cadena.
- `ft_split`: Divide una cadena en un array de cadenas utilizando un carácter delimitador.
- `ft_itoa`: Convierte un número entero a su representación en cadena de texto.
- `ft_strmapi`: Aplica una función a cada carácter de una cadena creando una nueva.
- `ft_striteri`: Aplica una función a cada carácter de una cadena modificándola in situ.
- `ft_putchar_fd`: Escribe un carácter en un file descriptor específico.
- `ft_putstr_fd`: Escribe una cadena en un file descriptor específico.
- `ft_putendl_fd`: Escribe una cadena seguida de un salto de línea en un file descriptor específico.
- `ft_putnbr_fd`: Escribe un número entero en un file descriptor específico.

### 3. Funciones para manipulación de listas enlazadas (Estructura `t_list`)
- `ft_lstnew`: Crea un nuevo nodo reservando memoria con `malloc`.
- `ft_lstadd_front`: Añade un nuevo elemento al principio de la lista.
- `ft_lstsize`: Cuenta el número de elementos contenidos en la lista.
- `ft_lstlast`: Devuelve el último elemento de la lista.
- `ft_lstadd_back`: Añade un nuevo elemento al final de la lista.
- `ft_lstdelone`: Libera la memoria del contenido de un elemento mediante una función dada y libera el elemento en sí.
- `ft_lstclear`: Elimina y libera todos los elementos de la lista dada utilizando la función de borrado.
- `ft_lstiter`: Recorre la lista y aplica una función al contenido de cada elemento.
- `ft_lstmap`: Crea una nueva lista resultante de aplicar una función a cada elemento de la lista original.

---
## Instrucciones
---

### Compilación e Instalación

Para compilar la librería completa, ejecuta el comando `make` en la raíz del repositorio:
```
make
Esto generará el archivo de la librería estática llamada libft.a.
```
Comandos del Makefile
- make o make all: Compila todos los archivos fuente .c y genera la librería libft.a.
- make clean: Elimina todos los archivos objeto (.o) generados durante la compilación.
- make fclean: Elimina los archivos objeto (.o) y el archivo de la librería libft.a.
- make re: Ejecuta fclean y vuelve a compilar toda la librería desde cero.


Cómo usar la librería en tu propio proyecto
Para incluir libft en cualquier otro proyecto en C:

Incluye el archivo de cabecera en tus archivos de código fuente:

```C
#include "libft.h"
Al compilar tu programa, enlaza la librería estática libft.a
``` 
```Bash
gcc -Wall -Wextra -Werror tu_programa.c -L. -lft -o tu_programa
```
---
## Recursos
---

### Referencias y Documentación
- Manuales de C (man pages): Consultas de las funciones estándar mediante la terminal (man memset, man strlcpy).

- Standard C Library Reference: Documentación de referencia sobre la librería estándar de C (cppreference.com).

- The C Programming Language (Kernighan & Ritchie): Libro de referencia fundamental sobre sintaxis, manejo de punteros y estructuras de datos en C.

### Uso de Inteligencia Artificial (IA)
En cumplimiento con los requisitos de transparencia del proyecto, la IA (modelo de lenguaje) se ha utilizado exclusivamente como asistente pedagógico y tutor de aprendizaje, aplicando el siguiente enfoque:

Explicación teórica de conceptos: Para entender en detalle el funcionamiento interno de la gestión de memoria (memset, memcpy, el solapamiento en memmove), el comportamiento de strlcat y el manejo de punteros dobles en listas enlazadas.

Revisión y depuración de código: Análisis de la lógica de punteros, prevención de accesos fuera de límites (out-of-bound), fugas de memoria (memory leaks) y gestión de punteros NULL.

Adaptación a la Norminette: Verificación de las restricciones de formato e infraestructura de 42 (como el límite de 25 líneas por función y convenciones del Makefile) sin comprometer la claridad del código.

Nota: Todo el código ha sido escrito e implementado manualmente comprendiendo la lógica aplicada en cada función.
