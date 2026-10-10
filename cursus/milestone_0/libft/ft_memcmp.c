/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:26:19 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/05 19:33:54 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*
DESCRIPTION: Compares the first 'n' bytes of memory areas 's1' and 's2'.
PARAM: 's1' -> First memory area, 's2' -> Second memory area, 'n' -> Byte count.
RETURN: Integer < 0, 0, or > 0 if 's1' is found to be less than,
equal to, or greater than 's2'.

#include <stdio.h>
#include <stddef.h>

int	main(void)
{
char	s1[] = "Hola\0Mundo";
char	s2[] = "Hola\042!!";

printf("--testing ft_memcmp--\n");
printf("Compare Hola Mundo vs Hola 42!!\n");
// Primeros 4 bytes ("Hola" vs "Hola") -> Debe dar 0
printf("Compare 4 bytes : %d\n", ft_memcmp(s1, s2, 4));

// Primeros 5 bytes ("Hola\0" vs "Hola\0") -> Debe dar 0 (incluye el '\0')
printf("Compare 5 bytes : %d\n", ft_memcmp(s1, s2, 5));

// Primeros 6 bytes ('M' vs '4') -> Diferencia pasados los '\0'
printf("Compare 6 bytes : %d\n", ft_memcmp(s1, s2, 6));

return (0);
}
*/
