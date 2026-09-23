/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:28:03 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 18:40:55 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (dest);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
** DESCRIPTION: Copies 'len' bytes from 'src' to 'dst', handling overlapping
**              memory safety by copying backwards if 'dst' is after 'src'.
** PARAM: 'dst' -> Pointer to destination, 'src' -> Pointer to source, 'len' -> Byte count.
** RETURN: Pointer to 'dst'.

#include <stdio.h>
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len);

int	main(void)
{
	char	str[20] = "123456789";

	printf("--testing ft_memmove (overlap)--\n");
	printf("Before: %s\n", str);
	// Copiamos los primeros 5 bytes ("12345") 2 posiciones a la derecha
	ft_memmove(str + 2, str, 5);
	printf("After : %s\n", str);
	return (0);
}*/
