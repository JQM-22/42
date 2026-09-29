/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:28:22 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 18:20:44 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
DESCRIPTION: Fills the first 'len' bytes of memory area 's' with byte 'c'.
PARAM: 's' -> Pointer to memory area, 'c' -> Value to set, 'len' -> Byte count.
RETURN: Pointer to the memory area 's'.

#include <stddef.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[10] = "123456789";

	printf("--testing ft_memset--\n");
	printf("Before: %s\n", str);
	ft_memset(str, 'A', 5);
	printf("After : %s\n", str);
	return (0);
}*/
