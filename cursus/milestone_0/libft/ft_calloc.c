/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:07:41 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/05 19:32:19 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*total_bytes;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	total_bytes = malloc(count * size);
	if (total_bytes == NULL)
		return (NULL);
	ft_bzero(total_bytes, count * size);
	return (total_bytes);
}
/*
DESCRIPTION: Allocates memory for an array of 'count' elements of 'size'
bytes each and initializes all bytes
in the allocated memory to zero.
PARAM: 'count' -> Number of elements, 'size' -> Size of each element.
RETURN: Pointer to allocated memory, or NULL if allocation fails.

int	main(void)
{
int		*arr;
size_t	i;

arr = (int *)ft_calloc(5, sizeof(int));
if (!arr)
{
printf("Error en ft_calloc\n");
return (1);
}
printf("---testing ft_calloc---\n");
i = 0;
while (i < 5)
{
printf("arr[%zu] = %d\n", i, arr[i]);
i++;
}
free(arr);
return (0);
}*/
