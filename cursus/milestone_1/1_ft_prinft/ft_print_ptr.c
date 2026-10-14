/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:03:16 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/14 19:55:13 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_print_str("(nil)"));
	count = count + ft_print_str("0x");
	if (ptr >= 16)
		count = count + ft_print_ptr(ptr / 16);
	if (ptr % 16 < 10)
		count = count + ft_print_char((ptr % 16) + '0');
	else
		count = count + ft_print_char((ptr % 16 - 10) - 'a');
	return (count);
}
