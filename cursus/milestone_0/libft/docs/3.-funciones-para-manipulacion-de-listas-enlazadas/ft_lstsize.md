# ft\_lstsize

#### Prototipo

C

```
int	ft_lstsize(t_list *lst);
```

#### Descripción

Cuenta el número de nodos presentes en la lista enlazada apuntada por `lst`. Recorre la lista elemento por elemento de principio a fin incrementando un contador hasta alcanzar el puntero `NULL` final.

#### Parámetros

| **Parámetro** | **Tipo**   | **Descripción**                                                 |
| ------------- | ---------- | --------------------------------------------------------------- |
| `lst`         | `t_list *` | Puntero al primer nodo de la lista enlazada que se desea medir. |

* Aclaración: El parámetro `lst` se pasa por valor, por lo que reasignarlo dentro de la función para iterar no modifica la cabeza de la lista en el ámbito desde donde fue llamada.

#### Valor de Retorno

* `int`: El número total de nodos contenidos en la lista enlazada.
* `0`: Si la lista está vacía (`lst == NULL`).

#### Casos Límite

* Lista vacía (`lst == NULL`): La condición del bucle evalúa como falsa inmediatamente y devuelve `0`.
* Un único nodo: Recorre un elemento, avanza a `next` (`NULL`) y devuelve `1`.
* Listas extensas: Funciona para cualquier cantidad razonable de elementos en memoria dentro de la capacidad de un entero firmado de 32 bits (`int`).

#### Código Comentado

C

```
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	// Iteramos a través de la lista mientras el puntero actual no sea NULL
	while (lst != NULL)
	{
		i++;           // Incrementamos el contador por cada nodo encontrado
		lst = lst->next; // Avanzamos al siguiente nodo de la lista
	}
	return (i); // Retornamos el número total de nodos
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
int		ft_lstsize(t_list *lst);

int	main(void)
{
	t_list	*head = NULL;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	printf("-- testing ft_lstsize() --\n");

	printf("Tamaño de lista vacía: %d (Esperado: 0)\n", ft_lstsize(head));

	node1 = ft_lstnew("Nodo 1");
	node2 = ft_lstnew("Nodo 2");
	node3 = ft_lstnew("Nodo 3");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	printf("Tamaño tras añadir 3 nodos: %d (Esperado: 3)\n", ft_lstsize(head));

	free(node1);
	free(node2);
	free(node3);
	return (0);
}
```
