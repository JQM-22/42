/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:25:17 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/05 19:33:13 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
DESCRIPTION: Checks if 'c' is a decimal digit character ('0'-'9').
PARAM: 'c' -> Character to check (as int).
RETURN: Non-zero if digit, 0 if not.

#include <stdio.h>

int	main(void)
{
printf("--testing ft_isdigit--\n");
printf("test: '5': %d\n",  ft_isdigit('5'));
return(0);
}*/
