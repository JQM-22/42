/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:25:50 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 19:59:27 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	i = 0;
	p = (const unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (0);
}
/*
DESCRIPTION: Scans the first 'n' bytes of the memory area pointed to by 's'
             for the first instance of 'c' (converted to an unsigned char).
PARAM: 's' -> Pointer to memory area, 'c' -> Byte to locate (as int), 'n' -> Max byte count.
RETURN: Pointer to the matching byte, or NULL if the byte does not occur.

#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	char	data[] = "123\056789";
	char	*ptr;

	printf("--testing ft_memchr--\n");

	// Busca '5' a través de un bloque de memoria que contiene un '\0'
	ptr = (char *)ft_memchr(data, '5', 9);
	printf("Search '5' in memory : %s\n", ptr ? ptr : "NULL");

	// Busca 'X' que no existe en el rango
	ptr = (char *)ft_memchr(data, 'X', 9);
	printf("Search 'X' in memory : %s\n", ptr ? ptr : "NULL");

	return (0);
}*/
