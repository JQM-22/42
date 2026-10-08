/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 18:25:54 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/08 20:03:19 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int count;
	int i;
    
	count = 0;
	va_start(args, format);
	// 1. Inicializamos la lista
	i = 0;
    while (format[i] != '\0') // 2. Aquí haremos un bucle recorriendo 'format'
    {
        if (format[i] == '%') // Si encontramos '%', usaremos va_arg(args, tipo) para obtener el valor.
        {
            i++;
            if (format[i] == 'c')
                va_arg(args, char);
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
	va_end(args); // 3. Limpiamos la lista
	return (count);
}
