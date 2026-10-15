/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_nbr.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/09 19:48:00 by joquinta         #+#    #+#              */
/*   Updated: 2026/10/15 17:56:10 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		count = count + (ft_print_char('-'));
		n = -n;
	}
	if (n >= 10)
		count = count + (ft_print_nbr(n / 10));
	count = count + ft_print_char((n % 10) + '0');
	return (count);
}
