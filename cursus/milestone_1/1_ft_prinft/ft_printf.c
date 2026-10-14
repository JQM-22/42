/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:25:54 by joquinta         #+#    #+#              */
/*   Updated: 2026/10/14 13:25:01 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = count + ft_check_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
