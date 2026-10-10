# ft\_lstnew

#### Prototipo

C

```
t_list	*ft_lstnew(void *content);
```

#### Descripción

Crea un nuevo nodo para una lista enlazada asignando memoria dinámica con `malloc`. Inicializa la variable miembro `content` con el contenido pasado como parámetro y el puntero al siguiente nodo `next` a `NULL`.

#### Parámetros

| **Parámetro** | **Tipo** | **Descripción**                                             |
| ------------- | -------- | ----------------------------------------------------------- |
| `content`     | `void *` | Puntero al contenido que se guardará dentro del nuevo nodo. |

* Aclaración: El uso del tipo `void *` permite que la estructura guarde punteros a cualquier tipo de dato (enteros, cadenas, estructuras personalizadas, etc.).

#### Valor de Retorno

* `t_list *`: Puntero al nuevo nodo creado en memoria dinámica.
* `NULL`: Si falla la asignación de memoria con `malloc`.

#### Casos Límite

* `content` es `NULL`: Asigna memoria para el nodo correctamente, establece `node->content = NULL` y `node->next = NULL`. Es una operación válida.
* Fallo de asignación de memoria (`malloc` devuelve `NULL`): La función retorna `NULL` de manera limpia sin intentar acceder a las variables miembro de la estructura.

#### Código Comentado

C

```
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	// Reservamos la memoria dinámicamente para la estructura de un nodo t_list
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	// Asignamos el puntero al contenido y establecemos el puntero 'next' a NULL
	node->content = content;
	node->next = NULL;
	return (node);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);

int	main(void)
{
	t_list	*node;
	char	*str = "42 Malaga - Bonus Lists";

	printf("-- testing ft_lstnew() --\n");

	node = ft_lstnew(str);
	if (!node)
	{
		printf("Error al crear el nodo\n");
		return (1);
	}

	printf("Nodo creado correctamente:\n");
	printf(" - content: %s\n", (char *)node->content);
	printf(" - next   : %p (Esperado: %p)\n", (void *)node->next, NULL);

	free(node);
	return (0);
}
```
