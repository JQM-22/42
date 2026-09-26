/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:07:41 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/25 19:44:09 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
void	ft_bzero(void *s, size_t len);

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*total_bytes;

	if (count != 0 && size > SIZE_MAX / count) //protection
		return (NULL);
	total_bytes = malloc(count * size); //reserve memory
	if (malloc == NULL)
		return (NULL);
	ft_bzero(total_bytes, count * size);  //clean memory
	return (total_bytes);
}
/*
DESCRIPTION: Allocates memory for an array of 'count' elements of 'size'
             bytes each and initializes all bytes in the allocated memory to zero.
PARAM: 'count' -> Number of elements, 'size' -> Size of each element.
RETURN: Pointer to allocated memory, or NULL if allocation fails.
*/

int	main(void)
{
	int	*
}
