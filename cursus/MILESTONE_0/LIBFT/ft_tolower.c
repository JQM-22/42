/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:31:01 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/05 19:37:07 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
DESCRIPTION: Converts an uppercase letter to lowercase if possible.
PARAM: 'c' -> Character to convert (as int).
RETURN: Lowercase equivalent if 'c' was uppercase, 'c' unchanged otherwise.

#include <stdio.h>

int	main(void)
{
printf ("--testing ft_tolower--\n");
printf ("'A' -> %c\n", ft_tolower('A'));
printf ("'Z' -> %c\n", ft_tolower('Z'));
printf ("'a' -> %c\n", ft_tolower('a'));
printf ("'9' -> %c\n", ft_tolower('9'));
return (0);
}*/
