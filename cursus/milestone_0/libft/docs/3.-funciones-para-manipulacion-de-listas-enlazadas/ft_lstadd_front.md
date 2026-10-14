# ft\_lstadd\_front

#### Prototipo

C

```
void	ft_lstadd_front(t_list **lst, t_list *new);
```

#### Descripción

Añade el nodo `new` al principio de la lista enlazada apuntada por `lst`. Actualiza el puntero `next` del nuevo nodo para que apunte al nodo que anteriormente encabezaba la lista y reasigna el puntero principal `*lst` para que reconozca a `new` como el primer elemento.

#### Parámetros

| **Parámetro** | **Tipo**    | **Descripción**                                              |
| ------------- | ----------- | ------------------------------------------------------------ |
| `lst`         | `t_list **` | Dirección del puntero que apunta al primer nodo de la lista. |
| `new`         | `t_list *`  | Puntero al nuevo nodo que se desea insertar al principio.    |

* Aclaración: Se utiliza un puntero doble (`t_list **`) porque es necesario modificar el puntero de cabeza de la lista fuera del ámbito de esta función.

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* `lst` es `NULL` o `new` es `NULL`: Si alguno de los dos punteros de entrada no es válido, la función retorna inmediatamente sin realizar ninguna operación, protegiendo el programa de fallos de segmentación.
* Lista inicialmente vacía (`*lst == NULL`): Asigna `new->next = NULL` y establece `*lst = new`, convirtiendo a `new` en el único y primer nodo de la lista.

#### Código Comentado

C

```
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	// Verificamos que tanto la dirección del puntero a la lista como el nuevo nodo existan
	if (!new || !lst)
		return ;
	// El nuevo nodo debe apuntar como siguiente elemento al que era el primer nodo
	new->next = *lst;
	// El puntero inicial de la lista pasa a apuntar al nuevo nodo
	*lst = new;
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

int	main(void)
{
	t_list	*head = NULL;
	t_list	*node1;
	t_list	*node2;

	printf("-- testing ft_lstadd_front() --\n");

	node1 = ft_lstnew("Primer nodo agregado");
	node2 = ft_lstnew("Segundo nodo (debe quedar al frente)");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);

	printf("Primer elemento de la lista: %s\n", (char *)head->content);
	printf("Segundo elemento de la lista: %s\n", (char *)head->next->content);

	free(node1);
	free(node2);
	return (0);
}
```
