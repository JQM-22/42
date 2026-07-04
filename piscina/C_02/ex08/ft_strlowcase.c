/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:24:01 by joquinta          #+#    #+#             */
/*   Updated: 2026/07/02 12:52:16 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 40 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "ABCD";

		ft_strlowcase(str);
	printf ("The result is: %s \n", str);
	return (0);
}*/
