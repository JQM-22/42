/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:43:45 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/24 18:51:20 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len && big[i + j] != '\0')
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
/*
DESCRIPTION: Locates the first occurrence of the null-terminated string
             'little' in the string 'big', where not more than 'len'
             characters are searched.
PARAM: 'big' -> String to search in, 'little' -> Substring to locate,
       'len' -> Max number of characters to search.
RETURN: Pointer to first character of first occurrence, 'big' if 'little'
        is empty, or NULL if 'little' is not found.

#include <stdio.h>

int	main(void)
{
	char	*big;
	char	*little;
	char	*res;

	big = "42 Malaga - Escuela de Programacion";
	little = "Malaga";
	
	printf ("---testing ft_strnstr---\n");
	res = ft_strnstr(big, little, 10);
	printf ("Search 'Malaga' (len 10) : %s\n", res ? res : "NULL");
	return (0);
}*/
