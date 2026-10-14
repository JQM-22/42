# ft\_putendl\_fd

#### Prototipo

C

```
void	ft_putendl_fd(char *s, int fd);
```

#### Descripción

Escribe la cadena de caracteres `s` en el descriptor de archivo (_file descriptor_) especificado por `fd` seguida de un salto de línea (`'\n'`).

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                   |
| ------------- | -------- | ------------------------------------------------- |
| `s`           | `char *` | Cadena de caracteres que se desea escribir.       |
| `fd`          | `int`    | Descriptor de archivo en el que se va a escribir. |

* Aclaración: Al igual que `ft_putstr_fd`, utiliza `ft_strlen(s)` para enviar la cadena mediante `write`, pero añade de forma automática un segundo `write` para imprimir el salto de línea al final.

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* `s` es `NULL`: Retorna inmediatamente sin realizar ninguna operación (evita escribir el salto de línea si no existe la cadena).
* Cadena vacía (`""`): `ft_strlen(s)` devolverá `0`, por lo que el primer `write` no escribe nada, pero sí se ejecutará el segundo `write` imprimiendo únicamente un salto de línea (`'\n'`).
* Descriptor de archivo no válido: Si `fd` es negativo o un descriptor cerrado, las llamadas a `write` fallarán de forma segura sin interrumpir la ejecución.

#### Código Comentado

C

```
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	// Verificamos que el puntero s no sea NULL
	if (!s)
		return ;
	// Escribimos el contenido de la cadena en el descriptor de archivo
	write(fd, s, ft_strlen(s));
	// Añadimos el salto de línea al final
	write(fd, "\n", 1);
}
```

#### Ejemplo de uso (main)

C

```
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd);

int	main(void)
{
	// Imprime la cadena seguida automáticamente de '\n' en la salida estándar (STDOUT = 1)
	ft_putendl_fd("Hola 42 Malaga!", 1);
	ft_putendl_fd("Siguiente linea sin necesidad de agregar \\n", 1);

	// Imprime en la salida de errores (STDERR = 2)
	ft_putendl_fd("Error critico detectado", 2);

	return (0);
}
```
