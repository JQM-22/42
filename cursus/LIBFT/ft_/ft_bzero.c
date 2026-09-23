/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:21:13 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 18:28:22 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}
/*
DESCRIPTION: Erases the data in the first 'n' bytes of the memory area
             pointed to by 's', by writing zeros (bytes containing '\0').
PARAM: 's' -> Pointer to memory area, 'n' -> Byte count.
RETURN: None (void).

#include <stdio.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n);

int	main(void)
{
	char	str[10] = "123456789";
	size_t	i;

	printf("--testing ft_bzero--\n");
	printf("Before: %s\n", str);
	ft_bzero(str, 5);
	printf("After (printing byte by byte):\n");
	i = 0;
	while (i < 9)
	{
		if (str[i] == '\0')
			printf("[%d]: '\\0'\n", (int)i);
		else
			printf("[%d]: '%c'\n", (int)i, str[i]);
		i++;
	}
	return (0);
}*/
