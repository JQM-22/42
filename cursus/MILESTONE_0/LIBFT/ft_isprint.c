/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:25:35 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/22 19:41:30 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
DESCRIPTION: Checks if 'c' is a printable character (ASCII 32 to 126).
PARAM: 'c' -> Character to check (as int).
RETURN: Non-zero if printable, 0 if not.

#include <stdio.h>

int	main(void)
{
	printf ("--testing ft_isprint--\n");
	printf ("test 'a': %d\n", ft_isprint('a'));
	return (0);
}*/
