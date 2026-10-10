/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:24:57 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/05 19:32:57 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
DESCRIPTION: Checks if 'c' is in the ASCII character set (0-127).
PARAM: 'c' -> Character to check (as int).
RETURN: Non-zero if ASCII character, 0 if not.

#include <stdio.h>

int	main(void)
{
printf ("--testing ft_isascii--\n");
printf ("test 'a': %d\n", ft_isascii('a'));
return (0);
}*/
