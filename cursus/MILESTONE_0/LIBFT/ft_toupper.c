/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:37:06 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/05 19:37:14 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
DESCRIPTION: Converts a lowercase letter to uppercase if possible.
PARAM: 'c' -> Character to convert (as int).
RETURN: Uppercase equivalent if 'c' was lowercase, 'c' unchanged otherwise.

#include <stdio.h>

int	main(void)
{
printf ("--testing ft_topper--\n");
printf ("'a' -> '%c'\n", ft_toupper('a'));
printf ("'z' -> '%c'\n", ft_toupper('z'));
printf ("'A' -> '%c'\n", ft_toupper('A'));
printf ("'9' -> '%c'\n", ft_toupper('9'));
return (0);
}*/
