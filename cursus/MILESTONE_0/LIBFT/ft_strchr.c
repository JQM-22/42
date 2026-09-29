/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:28:34 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 19:24:22 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
/*
DESCRIPTION: Locates the first occurrence of 'c' (converted to char) in 's'.
PARAM: 's' -> Pointer to string, 'c' -> Character to locate (as int).
RETURN: Pointer to first occurrence of 'c', or NULL if not found.

#include <stdio.h>

int	main(void)
{
	char	str[] = "Hola 42!";
	char	*ptr;

	printf("--testing ft_strchr--\n");

	ptr = ft_strchr(str, '4');
	printf("Search '4'  : %s\n", ptr ? ptr : "NULL");

	ptr = ft_strchr(str, 'x');
	printf("Search 'x'  : %s\n", ptr ? ptr : "NULL");

	ptr = ft_strchr(str, '\0');
	printf("Search '\\0' : %s\n", ptr ? "Found end of string" : "NULL");
	return (0);
}*/
