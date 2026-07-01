/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:55:07 by joquinta          #+#    #+#             */
/*   Updated: 2026/07/01 19:37:16 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "adcjln";

	if (ft_str_is_lowercase(str) == 1)
		printf ("%s, \nThis string is fully lowercase.\n", str);
	else
		printf ("%s, \nThis string in not fully lowercase.\n", str);
	return (0);
}*/
