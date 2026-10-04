# ft\_lstclear

#### Prototipo

C

```
void	ft_lstclear(t_list **lst, void (*del)(void *));
```

#### Descripción

Elimina y libera la memoria del nodo `lst` dado y de todos los nodos consecuentes de la lista, utilizando la función `del` y la llamada a `free`. Al finalizar, el puntero principal a la lista (`*lst`) debe quedar apuntando a `NULL`.

#### Parámetros

| **Parámetro** | **Tipo**           | **Descripción**                                                           |
| ------------- | ------------------ | ------------------------------------------------------------------------- |
| `lst`         | `t_list **`        | Dirección del puntero al primer nodo de la lista que se va a limpiar.     |
| `del`         | `void (*)(void *)` | Un puntero a la función utilizada para liberar el contenido de cada nodo. |

* Aclaración: Al recibir la dirección del puntero (`t_list **`), permite reasignar el valor original del puntero de la lista a `NULL` al terminar el recorrido, evitando que quede como un _dangling pointer_ (puntero colgado).

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* `lst` es `NULL`, `*lst` es `NULL` o `del` es `NULL`: Si la dirección del puntero, el contenido apuntado o la función de borrado son nulos, se debe evitar ejecutar la función para prevenir fallos de segmentación.
* Lista de un solo nodo: Libera correctamente el nodo y asigna `*lst = NULL`.
* Lista vacía (`*lst == NULL`): El bucle `while` no se ejecuta y la función finaliza de manera limpia y segura.

#### Código Comentado

C

```
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	// Protección: Comprobamos que existan la dirección del puntero, la lista y la función
	if (!lst || !*lst || !del)
		return ;
	// Recorremos la lista liberando nodo a nodo
	while (*lst != NULL)
	{
		// Guardamos la referencia al siguiente nodo antes de eliminar el actual
		tmp = (*lst)->next;
		// Liberamos el nodo actual y su contenido con ft_lstdelone
		ft_lstdelone(*lst, del);
		// Avanzamos el puntero principal al siguiente nodo
		*lst = tmp;
	}
	// Garantizamos que el puntero de la cabeza de la lista quede apuntando a NULL
	*lst = NULL;
}
```

> Nota sobre tu implementación: Se recomienda añadir la comprobación `if (!lst || !*lst || !del) return ;` al principio para evitar desreferenciar punteros nulos en caso de llamadas con argumentos no válidos.

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

// Función auxiliar del para liberar memoria del contenido
void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*head = NULL;

	printf("-- testing ft_lstclear() --\n");

	// Creamos una lista con 3 nodos con contenido asignado dinámicamente
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Nodo 1")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Nodo 2")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Nodo 3")));

	printf("Lista creada con exito. Puntero head: %p\n", (void *)head);

	// Limpiamos la lista entera
	ft_lstclear(&head, del_content);

	printf("Lista liberada. Puntero head tras clear: %p (Esperado: %p)\n", (void *)head, NULL);

	return (0);
}
```
