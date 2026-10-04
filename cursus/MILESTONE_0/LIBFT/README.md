*Este proyecto ha sido creado como parte del currículo de 42 por joquinta.*

# Libft - Tu primera librería en C

## Descripción

**Libft** es el primer proyecto individual del currículo principal de la Escuela 42. El objetivo de este proyecto es recodificar una serie de funciones estándar de la librería C (`libc`), así como otras funciones de utilidad adicionales y manipulación de listas enlazadas, que servirán como base para futuros proyectos del programa escolar (como *get_next_line*, *ft_printf*, *push_swap*, entre otros).

A través de la implementación manual de estas funciones, se profundiza en el entendimiento de:
- Gestión y manipulación de memoria a bajo nivel (punteros, asignación dinámica con `malloc`/`free`).
- Manipulación de cadenas de caracteres y buffers de datos.
- Estructuras de datos dinámicas (listas simplemente enlazadas `t_list`).
- Creación y mantenimiento de librerías estáticas (`.a`) utilizando `Makefile`.
- Cumplimiento riguroso de normas de programación C (Norminette).

---

## Estructura de la Librería

La librería consta de las siguientes funciones organizadas por categorías:

### 1. Funciones de la Libc reescritas
- **Comprobación de caracteres:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`.
- **Conversión de caracteres:** `ft_toupper`, `ft_tolower`.
- **Manejo de cadenas:** `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`.
- **Manipulación de memoria:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`.
- **Conversión de tipos:** `ft_atoi`.
- **Reserva de memoria:** `ft_calloc`, `ft_strdup`.

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

### Compilación e Instalación

Para compilar la librería completa, ejecuta el comando `make` en la raíz del repositorio:

make
Esto generará el archivo de la librería estática llamada libft.a.

Comandos del Makefile
- make o make all: Compila todos los archivos fuente .c y genera la librería libft.a.
- make clean: Elimina todos los archivos objeto (.o) generados durante la compilación.
- make fclean: Elimina los archivos objeto (.o) y el archivo de la librería libft.a.
- make re: Ejecuta fclean y vuelve a compilar toda la librería desde cero.


Cómo usar la librería en tu propio proyecto
Para incluir libft en cualquier otro proyecto en C:

Incluye el archivo de cabecera en tus archivos de código fuente:

C
#include "libft.h"
Al compilar tu programa, enlaza la librería estática libft.a:

Bash
gcc -Wall -Wextra -Werror tu_programa.c -L. -lft -o tu_programa
Recursos
Referencias y Documentación
Manuales de C (man pages): Consultas de las funciones estándar mediante la terminal (man memset, man strlcpy).

Standard C Library Reference: Documentación de referencia sobre la librería estándar de C (cppreference.com).

The C Programming Language (Kernighan & Ritchie): Libro de referencia fundamental sobre sintaxis, manejo de punteros y estructuras de datos en C.

Uso de Inteligencia Artificial (IA)
En cumplimiento con los requisitos de transparencia del proyecto, la IA (modelo de lenguaje) se ha utilizado exclusivamente como asistente pedagógico y tutor de aprendizaje, aplicando el siguiente enfoque:

Explicación teórica de conceptos: Para entender en detalle el funcionamiento interno de la gestión de memoria (memset, memcpy, el solapamiento en memmove), el comportamiento de strlcat y el manejo de punteros dobles en listas enlazadas.

Revisión y depuración de código: Análisis de la lógica de punteros, prevención de accesos fuera de límites (out-of-bound), fugas de memoria (memory leaks) y gestión de punteros NULL.

Adaptación a la Norminette: Verificación de las restricciones de formato e infraestructura de 42 (como el límite de 25 líneas por función y convenciones del Makefile) sin comprometer la claridad del código.

Nota: Todo el código ha sido escrito e implementado manualmente comprendiendo la lógica aplicada en cada función.
