/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:17:00 by joquinta          #+#    #+#             */
/*   Updated: 2026/07/01 18:53:18 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}
/*#include <stdio.h>

int	main(void)
{
	char    str[] = "12345enadd0";

	if (ft_str_is_numeric(str) == 1)
		printf ("%s,\nThere are only numbers in this string.\n", str);
	else
		printf ("%s,\nThere are numbers and other types of char in this string.\n", str);
	return (0);
}*/
