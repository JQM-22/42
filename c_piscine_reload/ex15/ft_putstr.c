/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:46:13 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/14 16:53:49 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
void	ft_putchar(char c);
/*void	ft_putchar(char c)
{
	write (1, &c, 1);
}*/

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
/*int	main(void)
{
	ft_putstr("Prueba de str");
	return (0);
}*/
