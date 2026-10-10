# ft\_putchar\_fd

#### Prototipo

C

```
void	ft_putchar_fd(char c, int fd);
```

#### Descripción

Escribe el carácter `c` en el descriptor de archivo (_file descriptor_) especificado por `fd` utilizando la llamada al sistema `write`.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                   |
| ------------- | -------- | ------------------------------------------------- |
| `c`           | `char`   | Carácter que se desea escribir.                   |
| `fd`          | `int`    | Descriptor de archivo en el que se va a escribir. |

* Aclaración: Permite redirigir la salida a la salida estándar (`1`), salida de errores (`2`), o a un archivo previamente abierto con `open()`.

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* Descriptor de archivo no válido: Si se le pasa un `fd` negativo o un descriptor cerrado, la función `write` fallará internamente de forma limpia sin romper el programa.
* Caracteres especiales: Procesa de forma transparente cualquier byte ASCII, incluyendo `'\0'`, `'\n'` o valores negativos/no imprimibles.

#### Código Comentado

C

```
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	// Escribe 1 byte situado en la dirección de 'c' en el file descriptor 'fd'
	write(fd, &c, 1);
}
```

#### Ejemplo de uso (main)

C

```
#include <unistd.h>

void	ft_putchar_fd(char c, int fd);

int	main(void)
{
	// Escribe 'A' en la salida estándar (STDOUT_FILENO = 1)
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	// Escribe 'E' en la salida de errores (STDERR_FILENO = 2)
	ft_putchar_fd('E', 2);
	ft_putchar_fd('\n', 2);

	return (0);
}
```
