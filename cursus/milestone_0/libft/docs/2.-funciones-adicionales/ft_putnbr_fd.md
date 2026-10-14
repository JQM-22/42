# ft\_putnbr\_fd

#### Prototipo

C

```
void	ft_putnbr_fd(int n, int fd);
```

#### Descripción

Escribe el número entero `n` en el descriptor de archivo (_file descriptor_) especificado por `fd`. Esta implementación convierte primero el entero a cadena utilizando `ft_itoa`, envía la cadena resultante mediante `ft_putstr_fd` y posteriormente libera la memoria dinámica asignada.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                   |
| ------------- | -------- | ------------------------------------------------- |
| `n`           | `int`    | Número entero que se desea escribir.              |
| `fd`          | `int`    | Descriptor de archivo en el que se va a escribir. |

* Aclaración: Al delegar la conversión en `ft_itoa`, soporta de forma nativa números positivos, negativos y los valores límite sin necesidad de gestionar la recursividad o buffers manuales en esta función.

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* `INT_MIN` (`-2147483648`): Gestionado correctamente gracias a la lógica interna de `ft_itoa`.
* `0`: Imprime el carácter `'0'` sin problemas.
* Fallo de asignación de memoria (`malloc` en `ft_itoa`): Si `ft_itoa` devuelve `NULL`, la función retorna inmediatamente para evitar dereferenciar un puntero nulo o provocar una fuga de memoria.

#### Código Comentado

C

```
#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	// Convertimos el entero 'n' a su representación en string
	str = ft_itoa(n);
	// Si falla la asignación de memoria en ft_itoa, salimos de forma segura
	if (!str)
		return ;
	// Escribimos la cadena resultante en el file descriptor 'fd'
	ft_putstr_fd(str, fd);
	// Liberamos la memoria dinámica reservada por ft_itoa
	free(str);
}
```

#### Ejemplo de uso (main)

C

```
#include <unistd.h>
#include <limits.h>

void	ft_putnbr_fd(int n, int fd);

int	main(void)
{
	// Prueba con número positivo
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);

	// Prueba con número negativo
	ft_putnbr_fd(-1337, 1);
	write(1, "\n", 1);

	// Prueba con cero
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);

	// Prueba con INT_MIN
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n", 1);

	return (0);
}
```
