/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:30:31 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 19:53:07 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] != '\0' && s1[i] == s2[i] && i < (n - 1))
	{
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
DESCRIPTION: Compares 'n' bytes of strings 's1' and 's2'.
PARAM: 's1' -> First string, 's2' -> Second string, 'n' -> Max byte count.
RETURN: Integer < 0, 0, or > 0 if 's1' is found to be less than,
        equal to, or greater than 's2'.

#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	char	s1[] = "Hola 42";
	char	s2[] = "Hola World";

	printf("--testing ft_strncmp--\n");
	printf("strigs a comparar: s1:Hola 42 s2:Hola World\n");
	// Primeros 4 caracteres ("Hola" vs "Hola") -> Debe dar 0
	printf("Compare 4 chars : %d\n", ft_strncmp(s1, s2, 4));

	// Primeros 6 caracteres ("Hola 4" vs "Hola W") 
	// -> Resultado negativo ('4' < 'W')
	printf("Compare 6 chars : %d\n", ft_strncmp(s1, s2, 6));

	// Caso límite n = 0 -> Debe dar 0
	printf("Compare 0 chars : %d\n", ft_strncmp(s1, s2, 0));

	return (0);
}*/
