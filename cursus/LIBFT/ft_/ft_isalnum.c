/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:23:22 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/22 19:29:43 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
DESCRIPTION: Checks if 'c' is alphanumeric (letter 'a'-'z', 'A'-'Z' or digit '0'-'9').
PARAM: 'c' -> Character to check (as int).
RETURN: Non-zero if alphanumeric, 0 if not.

#include <stdio.h>

int	main(void)
{
	printf ("--testing ft_isalnum--\n");
	printf ("test 'a': %d\n", ft_isalnum ('a'));
	printf ("test '2': %d\n", ft_isalnum ('2'));
	printf ("test '@': %d\n", ft_isalnum ('@'));
	return (0);
}*/
