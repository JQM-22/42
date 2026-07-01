/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:48:24 by joquinta          #+#    #+#             */
/*   Updated: 2026/07/01 12:01:45 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
/*#include <stdio.h>

int	main(void)
{
	char	str[] = "abcABC123";
	if (ft_str_is_alpha(str) == 1)
		printf ("%s,\nThere are only alpha chars in this string.\n", str);
	else
		printf ("%s,\nThere are different types of char in this string.\n", str);
	return (0);
}*/
