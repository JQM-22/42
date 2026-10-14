# ft\_lstiter

#### Prototipo

C

```
void	ft_lstiter(t_list *lst, void (*f)(void *));
```

#### Descripción

Itera sobre la lista enlazada `lst` y aplica la función `f` al contenido (`content`) de cada uno de sus nodos. No modifica la estructura de punteros de la lista ni asigna o libera memoria dinámicamente.

#### Parámetros

| **Parámetro** | **Tipo**           | **Descripción**                                                          |
| ------------- | ------------------ | ------------------------------------------------------------------------ |
| `lst`         | `t_list *`         | Puntero al primer nodo de la lista enlazada.                             |
| `f`           | `void (*)(void *)` | Un puntero a la función que se aplicará sobre el contenido de cada nodo. |

* Aclaración: Dado que `lst` se pasa por valor, modificar el puntero local dentro del bucle para avanzar a lo largo de la lista no afecta al puntero original del llamador.

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* `lst` es `NULL` o `f` es `NULL`: Retorna inmediatamente sin realizar ninguna operación, evitando dereferenciar punteros nulos.
* Lista vacía (`lst == NULL`): La condición inicial de guardado evalúa a verdadero y la función finaliza de manera limpia y segura.
* `node->content` es `NULL`: La función `f` debe estar diseñada para gestionar o ignorar un puntero nulo de entrada si la lista contiene elementos sin contenido asignado.

#### Código Comentado

C

```
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	// Protección: Si la lista o el puntero a función son NULL, salimos
	if (!lst || !f)
		return ;
	// Recorremos todos los nodos de la lista
	while (lst != NULL)
	{
		// Aplicamos la función f al contenido del nodo actual
		f(lst->content);
		// Avanzamos al siguiente nodo de la lista
		lst = lst->next;
	}
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

// Función auxiliar para imprimir el contenido de un nodo
void	print_content(void *content)
{
	printf("Nodo contenido: %s\n", (char *)content);
}

int	main(void)
{
	t_list	*head = NULL;

	printf("-- testing ft_lstiter() --\n");

	ft_lstadd_back(&head, ft_lstnew("Primer elemento"));
	ft_lstadd_back(&head, ft_lstnew("Segundo elemento"));
	ft_lstadd_back(&head, ft_lstnew("Tercer elemento"));

	// Aplicamos print_content a cada elemento de la lista
	ft_lstiter(head, print_content);

	// Limpieza sencilla para el ejemplo
	free(head->next->next);
	free(head->next);
	free(head);
	return (0);
}
```
