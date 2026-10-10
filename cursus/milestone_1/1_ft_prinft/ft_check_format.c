/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:50:27 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/10 19:59:03 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char sp, va_list args)
{
	int	count;

	count = 0;
	if (sp == 'c')
		count = count + ft_print_char(va_arg(args, int));
	else if (sp == 's')
		count = count + ft_print_str(va_arg(args, char *));
	else if (sp == 'd' || sp == 'i')
		count = count + ft_print_nbr(va_arg(args, int));
	else if (sp == 'u')
		count = count + ft_print_unsigned(va_arg(args, unsigned int));
	else if (sp == 'x' || sp == 'X')
		count = count + ft_print_hex(va_arg(args, unsigned int), sp);
	else if (sp == 'p')
		count = count + ft_print_ptr(va_arg(args, void *));
	else if (sp == '%')
		count = count + ft_print_char('%');
	return (count);
}
