# ft\_lstdelone

#### Prototipo

C

```
void	ft_lstdelone(t_list *lst, void (*del)(void *));
```

#### Descripción

Toma como parámetro un nodo `lst` y libera la memoria de su contenido utilizando la función `del` dada como parámetro, además de liberar la memoria del propio nodo con `free`. La memoria de los nodos siguientes (`lst->next`) no debe liberarse en esta función.

#### Parámetros

| **Parámetro** | **Tipo**           | **Descripción**                                                       |
| ------------- | ------------------ | --------------------------------------------------------------------- |
| `lst`         | `t_list *`         | El nodo individual que se desea liberar.                              |
| `del`         | `void (*)(void *)` | Un puntero a la función utilizada para liberar el contenido del nodo. |

* Aclaración: Separar la liberación del contenido (`del`) de la del nodo (`free`) es fundamental porque el puntero `content` puede haber sido reservado dinámicamente con `malloc` (por ejemplo, una cadena creada con `ft_strdup`), o apuntar a una estructura compleja que requiere un borrado personalizado.

#### Valor de Retorno

* Ninguno (`void`)

#### Casos Límite

* `lst` es `NULL` o `del` es `NULL`: Si alguno de los dos punteros recibidos es nulo, la función retorna inmediatamente sin ejecutar ninguna instrucción para evitar desreferenciar un puntero inválido.
* `lst->content` es `NULL`: La función `del` debe estar preparada para manejar o ignorar punteros nulos según corresponda a la implementación del usuario.

#### Código Comentado

C

```
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	// Protección: Si el nodo o el puntero a la función de borrado son NULL, salimos
	if (!lst || !del)
		return ;
	// Aplicamos la función del al contenido para liberar su memoria
	del(lst->content);
	// Liberamos la memoria reservada para el nodo t_list
	free(lst);
}
```

#### Ejemplo de uso (main)

C

```
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// Función auxiliar del personalizada para liberar cadenas dinámicas
void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node;
	char	*str;

	printf("-- testing ft_lstdelone() --\n");

	// Creamos un contenido asignado dinámicamente
	str = ft_strdup("Contenido dinamico a liberar");
	node = ft_lstnew(str);

	if (node)
	{
		printf("Nodo creado con exito, procediendo a su eliminacion...\n");
		// Liberamos el nodo individual y su contenido
		ft_lstdelone(node, del_content);
		printf("Nodo liberado correctamente.\n");
	}
	return (0);
}
```
