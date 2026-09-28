/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:27:36 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 18:34:45 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
DESCRIPTION: Copies 'n' bytes from memory area 'src' to memory area 'dst'.
PARAM: 'dst' -> Pointer to destination, 
	'src' -> Pointer to source, 
	'n' -> Byte count.
RETURN: Pointer to 'dst'.

#include <stdio.h>
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

int	main(void)
{
	char	src[] = "Hola 42!";
	char	dst[20];

	printf("--testing ft_memcpy--\n");
	ft_memcpy(dst, src, 9);
	printf("Source     : %s\n", src);
	printf("Destination: %s\n", dst);
	return (0);
}*/
