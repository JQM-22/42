# ft\_lstmap

#### Prototipo

C

```
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

#### Descripción

Itera sobre la lista `lst` y aplica la función `f` al contenido de cada nodo. Crea una nueva lista con los resultados de la aplicación consecutiva de `f`. En caso de que falle la asignación de memoria durante la creación de algún nodo o contenido, utiliza la función `del` para liberar la memoria de los nodos creados hasta ese momento y devuelve `NULL`.

#### Parámetros

| **Parámetro** | **Tipo**            | **Descripción**                                                              |
| ------------- | ------------------- | ---------------------------------------------------------------------------- |
| `lst`         | `t_list *`          | Puntero al primer nodo de la lista original sobre la cual se iterará.        |
| `f`           | `void *(*)(void *)` | Puntero a la función aplicada para transformar el contenido de cada nodo.    |
| `del`         | `void (*)(void *)`  | Puntero a la función para eliminar el contenido de un nodo en caso de fallo. |

* Aclaración: La función `f` devuelve un puntero al nuevo contenido transformado. Si se produce un error a mitad de proceso, es responsabilidad de `ft_lstmap` revertir las asignaciones limpiando toda la memoria reservada para la nueva lista mediante `del`.

#### Valor de Retorno

* `t_list *`: Puntero al primer nodo de la nueva lista generada.
* `NULL`: Si la asignación de memoria falla en cualquier punto de la creación o si alguno de los parámetros requeridos (`lst`, `f` o `del`) es `NULL`.

#### Casos Límite

* `lst`, `f` o `del` son `NULL`: Retorna inmediatamente `NULL` previniendo errores de segmentación.
* Fallo intermedio en `ft_lstnew`: Si la reserva de un nodo falla, la función `del` debe liberar `new_content` y llamarse a `ft_lstclear` sobre la lista acumulada hasta el momento.
* Variable no inicializada (`new_lst`): Debe inicializarse explícitamente a `NULL` (`new_lst = NULL;`) antes del bucle. De lo contrario, pasar `&new_lst` a `ft_lstclear` en caso de error temprano provocará comportamiento indeterminado por intentar leer basura de la pila (_stack_).

#### Código Comentado

C

```
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_node;
	t_list	*new_lst;

	// Protección contra punteros nulos de entrada
	if (!lst || !f || !del)
		return (NULL);
	// Es imprescindible inicializar la nueva lista a NULL antes de operar
	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			// Si falla la asignación del nodo, liberamos el nuevo contenido creado por f
			del(new_content);
			// Liberamos todos los nodos agregados a new_lst hasta el momento
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
```

> Notas de corrección sobre tu implementación:
>
> 1. Inicialización: No habías inicializado `new_lst = NULL;`. Pasar un puntero basura no inicializado a `ft_lstclear(&new_lst, del)` produce un fallo de segmentación si la primera o segunda asignación falla.
> 2. Fuga de memoria (_Memory Leak_) en fallo: Si `new_node` devuelve `NULL`, el contenido que ya había generado la función `f` (`new_content`) quedaría flotando en memoria si no lo liberas explícitamente con `del(new_content);` antes de llamar a `ft_lstclear`.
> 3. Orden de avance: Es más intuitivo avanzar el puntero `lst = lst->next;` al final del bucle una vez procesado el nodo actual.

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Función f de prueba: Duplica y convierte a mayúsculas
void	*duplicate_upper(void *content)
{
	char	*str = (char *)content;
	char	*new_str = ft_strdup(str);
	int		i = 0;

	if (!new_str)
		return (NULL);
	while (new_str[i])
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] -= 32;
		i++;
	}
	return (new_str);
}

// Función del de prueba
void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*orig = NULL;
	t_list	*mapped = NULL;
	t_list	*tmp;

	printf("-- testing ft_lstmap() --\n");

	ft_lstadd_back(&orig, ft_lstnew("hola"));
	ft_lstadd_back(&orig, ft_lstnew("42"));
	ft_lstadd_back(&orig, ft_lstnew("malaga"));

	mapped = ft_lstmap(orig, duplicate_upper, del_content);

	printf("Lista mapeada:\n");
	tmp = mapped;
	while (tmp)
	{
		printf(" - %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	// Limpieza de ambas listas
	ft_lstclear(&orig, [](void *p) { (void)p; }); // La original usaba literales
	ft_lstclear(&mapped, del_content);           // La nueva usaba memoria dinámica

	return (0);
}
```
