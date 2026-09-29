/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:30:15 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/22 20:12:53 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
DESCRIPTION: Calculates the length of the string 's' (excluding '\0').
PARAM: 'str' -> Pointer to the string.
RETURN: Number of characters in 'str'.

#include <stdio.h>

int	main(void)
{
	printf ("--testing ft_strlen--\n");
	printf ("test: %zu\n", ft_strlen("testing ft_strlen"));
	return (0);
}*/
