/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 19:25:14 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/25 20:12:18 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*mem;	

	mem = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
/*
DESCRIPTION: Allocates sufficient memory for a copy of the string 's1',
             does the copy, and returns a pointer to it.
PARAM: 's1' -> String to duplicate.
RETURN: Pointer to the duplicated string, or NULL if allocation fails.

int	main(void)
{
	char	original[] = "42 Malaga - Libft";
	char	*dup;

	printf("---testing ft_strdup---\n");

	// Duplicamos la cadena original
	dup = ft_strdup(original);

	if (!dup)
	{
		printf("Error: Fallo al reservar memoria en ft_strdup\n");
		return (1);
	}

	printf("Original : %s (Dir: %p)\n", original, (void *)original);
	printf("Copia    : %s (Dir: %p)\n", dup, (void *)dup);

	// Comprobamos que sean independientes modificando la copia
	dup[0] = 'X';
	printf("\nTras modificar la copia (dup[0] = 'X'):\n");
	printf("Original : %s\n", original);
	printf("Copia    : %s\n", dup);

	// Liberamos la memoria reservada dinámicamente por ft_strdup
	free(dup);
	return (0);
}*/
