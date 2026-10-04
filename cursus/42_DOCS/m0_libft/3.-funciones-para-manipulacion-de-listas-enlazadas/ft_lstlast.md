# ft\_lstlast

#### Prototipo

C

```
t_list	*ft_lstlast(t_list *lst);
```

#### Descripción

Devuelve el último nodo de la lista enlazada apuntada por `lst`. Recorre la estructura hasta encontrar el nodo cuyo puntero miembro `next` apunte a `NULL`.

#### Parámetros

| **Parámetro** | **Tipo**   | **Descripción**                              |
| ------------- | ---------- | -------------------------------------------- |
| `lst`         | `t_list *` | Puntero al primer nodo de la lista enlazada. |

* Aclaración: Al igual que en `ft_lstsize`, modificar la variable local `lst` durante el recorrido no altera la dirección original del puntero de la lista en la función que realiza la llamada.

#### Valor de Retorno

* `t_list *`: Puntero al último nodo de la lista enlazada (aquel cuyo elemento `next` es `NULL`).
* `NULL`: Si la lista recibida está vacía (`lst == NULL`).

#### Casos Límite

* Lista vacía (`lst == NULL`): Entra en la condición `if (!lst)` y retorna `NULL` inmediatamente, evitando dereferenciar un puntero nulo.
* Lista con un solo nodo: Dado que `lst->next` es `NULL` desde el principio, el bucle `while` no se llega a ejecutar y la función devuelve el único nodo de la lista.

#### Código Comentado

C

```
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	// Si la lista está vacía, devolvemos NULL
	if (!lst)
		return (NULL);
	// Avanzamos por la lista mientras el siguiente nodo exista
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	// Devolvemos el nodo en el que nos hemos detenido (el último)
	return (lst);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

int	main(void)
{
	t_list	*head = NULL;
	t_list	*last;
	t_list	*node1;
	t_list	*node2;

	printf("-- testing ft_lstlast() --\n");

	// Prueba con lista vacía
	printf("Lista vacía: %p (Esperado: %p)\n", (void *)ft_lstlast(head), NULL);

	node1 = ft_lstnew("Nodo inicial (debería ser el último tras lstadd_front)");
	node2 = ft_lstnew("Nodo nuevo en cabeza");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);

	last = ft_lstlast(head);
	if (last)
		printf("Contenido del último nodo: %s\n", (char *)last->content);

	free(node1);
	free(node2);
	return (0);
}
```
