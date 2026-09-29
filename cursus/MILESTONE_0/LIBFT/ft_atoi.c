/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:45:15 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/25 19:21:09 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
DESCRIPTION: Converts the initial portion of the string pointed to by 'str'
             to an integer representation.
PARAM: 'str' -> String to convert.
RETURN: The converted integer value * sign.

#include <stdio.h>

int	main(void)
{
	printf ("---testing ft_atoi---\n");
	printf("Result of: '   -42a' -> %d\n", ft_atoi(" - - 42a"));
	printf("Result of: '--42a' -> %d\n", ft_atoi(" -+42a"));
	printf("Result of: '++42a' -> %d\n", ft_atoi(" 42a"));
	printf("Result of: '++42a' -> %d\n", ft_atoi(" --42a"));
	return (0);
}*/
