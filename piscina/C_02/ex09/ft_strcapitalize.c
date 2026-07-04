/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:56:12 by joquinta          #+#    #+#             */
/*   Updated: 2026/07/03 11:14:55 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strlowcase(char *str)
{         
	int     i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))//si no es numero
		{
			if (str[i] == 0)//si indice 0, es primera palabra
				str[i] = str[i] - 32;
			if (str[i - 1]  == ' ')//si valor de i-1 es ' ',es primera letra de palabra
				str[i] = str[i] - 32;
			if (str[i - 1] >= 32 && str[i - 1] <= 46)
				str[i] = str[i] - 32;
		i++;
		}
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	ft_strcapitalize(str);
	printf ("El resultado es %s .\n", str);
	return (0);
}

