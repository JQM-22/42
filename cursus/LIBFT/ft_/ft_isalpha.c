/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:24:01 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/22 19:15:05 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
DESCRIPTION: Checks if 'c' is an alphabetic character ('a'-'z', 'A'-'Z').
PARAM: 'c' -> Character to check (as int).
RETURN: Non-zero if alphabetic, 0 if not.

#include <stdio.h>
int	main(void)
{
	printf("--testing ft_isalpha()--\n");
	printf("test 'a': %d\n", ft_isalpha('a'));
	return(0);
}*/
