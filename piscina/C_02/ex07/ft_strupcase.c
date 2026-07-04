/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:32:04 by joquinta          #+#    #+#             */
/*   Updated: 2026/07/02 12:26:11 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_stripcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "aBcDeFgHiJk";

		ft_stripcase(str);

	printf ("This is the result:%s, \n", str);
	return (0);
}*/
