/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:30:49 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 19:44:30 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (0);
}
/*
DESCRIPTION: Locates the last occurrence of 'c' (converted to char) in 's'.
PARAM: 's' -> Pointer to string, 'c' -> Character to locate (as int).
RETURN: Pointer to last occurrence of 'c', or NULL if not found.

#include <stdio.h>

int	main(void)
{
	char	str[] = "42 Malaga - 42 School";
	char	*ptr;

	printf("--testing ft_strrchr--\n");
	printf("str de prueba : 42 Malaga - 42 School\n");
	// Busca la última '4' (debe devolver la dirección en "42 School")
	ptr = ft_strrchr(str, '4');
	printf("Search last '4' : %s\n", ptr ? ptr : "NULL");

	ptr = ft_strrchr(str, 'x');
	printf("Search 'x'      : %s\n", ptr ? ptr : "NULL");

	ptr = ft_strrchr(str, '\0');
	printf("Search '\\0'     : %s\n", ptr ? "Found end of string" : "NULL");
	return (0);
}*/
