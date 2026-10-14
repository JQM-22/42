# ft\_strlen

#### Prototipo

C

```
size_t	ft_strlen(const char *str);
```

#### Descripción

Calcula la longitud de la cadena de caracteres apuntada por `str`, contando el número de caracteres hasta llegar al carácter nulo final (`'\0'`), el cual no se incluye en el recuento.

#### Parámetros

| **Parámetro** | **Tipo**       | **Descripción**                                                  |
| ------------- | -------------- | ---------------------------------------------------------------- |
| `str`         | `const char *` | Puntero a la cadena de caracteres cuya longitud se quiere medir. |

* Aclaración: Es `const` porque la función solo lee la cadena y no debe modificar el contenido del puntero. Usa `size_t` para garantizare la capacidad de medir cadenas de cualquier tamaño en memoria.

#### Valor de Retorno

* `size_t`: El número entero sin signo que representa la cantidad de caracteres que contiene la cadena (sin contar el `'\0'`).

#### Casos Límite

* Cadena vacía (`""`): Debe devolver `0` inmediatamente (el primer carácter es `'\0'`).
* Cadena con espacios o saltos de línea: Se cuentan exactamente igual que cualquier otro carácter printable.
* Puntero `NULL`: Provocará un error de segmentación (_Segmentation fault_) al intentar acceder a la memoria; en la implementación estándar no se protege contra `NULL`.

#### Código Comentado

C

```
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	// Recorremos la cadena hasta encontrar el carácter nulo de terminación
	while (str[i] != '\0')
	{
		i++; // Incrementamos el contador por cada carácter encontrado
	}
	return (i); // Devolvemos la cantidad total de caracteres contados
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>

size_t	ft_strlen(const char *str);

int	main(void)
{
	printf("-- testing ft_strlen() --\n");
	printf("Prueba 'Hola': %zu (Esperado: 4)\n", ft_strlen("Hola"));
	printf("Prueba '' (vacía): %zu (Esperado: 0)\n", ft_strlen(""));
	printf("Prueba '42 Malaga': %zu (Esperado: 9)\n", ft_strlen("42 Malaga"));
	return (0);
}
```
