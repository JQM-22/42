/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 19:44:31 by joquinta          #+#    #+#             */
/*   Updated: 2026/07/01 20:03:08 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "AbCD";

	if (ft_str_is_uppercase(str) == 1)
		printf ("%s, \nThis strig is fully uppercase.\n", str);
	else
		printf ("%s, \nThis string is no fully uppercase.\n", str);
	return (0);
}*/
