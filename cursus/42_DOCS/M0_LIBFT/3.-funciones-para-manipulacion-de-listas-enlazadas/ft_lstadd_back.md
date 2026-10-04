# ft\_lstadd\_back

#### Prototipo

C

```
void	ft_lstadd_back(t_list **lst, t_list *new);
```

#### Descripción

Añade el nodo `new` al final de la lista enlazada apuntada por `lst`. Si la lista está vacía, el nodo `new` pasa a ser el primer elemento de la lista. En caso contrario, busca el último nodo (utilizando `ft_lstlast`) y actualiza su puntero `next` para que apunte a `new`.

#### Parámetros

| **Parámetro** | **Tipo**    | **Descripción**                                                 |
| ------------- | ----------- | --------------------------------------------------------------- |
| `lst`         | `t_list **` | Dirección del puntero que apunta al primer nodo de la lista.    |
| `new`         | `t_list *`  | Puntero al nuevo nodo que se desea añadir al final de la lista. |

* Aclaración: Al igual que en `ft_lstadd_front`, se recibe un puntero doble (`t_list **`) para poder modificar la cabeza de la lista directamente en caso de que la lista esté vacía.

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* `lst` es `NULL` o `new` es `NULL`: Si la dirección del puntero a la lista (`lst`) o el puntero del nuevo nodo (`new`) no existen, se debe proteger la función para evitar violaciones de segmento.
* Lista inicialmente vacía (`*lst == NULL`): La condición `if (*lst == NULL)` asigna directamente `new` como el primer nodo de la lista (`*lst = new`).

#### Código Comentado

C

```
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	// Protección: Si el puntero a la lista o el nodo son NULL, no hacemos nada
	if (!lst || !new)
		return ;
	// Si la lista está vacía, el nuevo nodo se convierte en el primero
	if (*lst == NULL)
		*lst = new;
	else
	{
		// Obtenemos el último nodo de la lista actual
		last = ft_lstlast(*lst);
		// Enlazamos el último nodo con el nuevo nodo
		last->next = new;
	}
}
```

> Nota sobre tu implementación: Se sugiere añadir la comprobación `if (!lst || !new) return ;` al inicio de la función para evitar que el programa falle si se le pasa un puntero `lst` o `new` nulo.

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

int	main(void)
{
	t_list	*head = NULL;
	t_list	*node1;
	t_list	*node2;
	t_list	*last;

	printf("-- testing ft_lstadd_back() --\n");

	node1 = ft_lstnew("Primer nodo");
	node2 = ft_lstnew("Segundo nodo (al final)");

	// Añadir a lista vacía
	ft_lstadd_back(&head, node1);
	printf("Primer nodo de la lista: %s\n", (char *)head->content);

	// Añadir al final de la lista existente
	ft_lstadd_back(&head, node2);
	last = ft_lstlast(head);
	printf("Último nodo de la lista : %s\n", (char *)last->content);

	free(node1);
	free(node2);
	return (0);
}
```
