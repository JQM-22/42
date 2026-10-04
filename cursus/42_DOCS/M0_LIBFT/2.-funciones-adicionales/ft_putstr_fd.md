# ft\_putstr\_fd

#### Prototipo

C

```
void	ft_putstr_fd(char *s, int fd);
```

#### Descripción

Escribe la cadena de caracteres `s` en el descriptor de archivo (_file descriptor_) especificado por `fd` utilizando la llamada al sistema `write`.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                   |
| ------------- | -------- | ------------------------------------------------- |
| `s`           | `char *` | Cadena de caracteres que se desea escribir.       |
| `fd`          | `int`    | Descriptor de archivo en el que se va a escribir. |

* Aclaración: Utiliza `ft_strlen(s)` para determinar la cantidad de bytes que deben ser escritos en el descriptor de archivo de una sola llamada a `write`.

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* `s` es `NULL`: Retorna inmediatamente sin realizar ninguna operación, previniendo fallos de segmentación.
* Cadena vacía (`""`): `ft_strlen(s)` devolverá `0`, por lo que `write` no escribirá ningún byte de forma segura.
* Descriptor de archivo no válido: Si `fd` es negativo o un descriptor cerrado, la llamada `write` fallará internamente sin detener la ejecución del programa.

#### Código Comentado

C

```
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	// Si la cadena recibida es NULL, salimos para evitar desreferenciar un puntero nulo
	if (!s)
		return ;
	// Escribimos en el fd exactamente la cantidad de bytes devuelta por ft_strlen(s)
	write(fd, s, ft_strlen(s));
}
```

#### Ejemplo de uso (main)

C

```
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd);

int	main(void)
{
	// Escribe una cadena en la salida estándar (STDOUT_FILENO = 1)
	ft_putstr_fd("Hola 42 Malaga!\n", 1);

	// Escribe un mensaje de error en la salida de errores (STDERR_FILENO = 2)
	ft_putstr_fd("Error: mensaje de prueba\n", 2);

	return (0);
}
```
