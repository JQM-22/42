/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_hex.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/13 19:32:02 by joquinta         #+#    #+#              */
/*   Updated: 2026/10/13 20:06:12 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char sp)
{
	int	count;
	int	rest;

	count = 0;
	rest = 0;
	if (n >= 16)
		count = count + ft_print_hex(n / 16, sp);
	if ((n % 16) < 10)
		count = count + ft_print_char((n % 16) + '0');
	else
	{
		if (sp == 'x')
			count = count + ft_print_char((n % 16 - 10) + 'a');
		else if (sp == 'X')
			count = count + ft_print_char((n % 16 - 10) + 'A');
	}
	return (count);
}
