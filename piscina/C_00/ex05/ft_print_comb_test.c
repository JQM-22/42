/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:35:53 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/22 18:50:22 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = '1';
		while (b <= '8')
		{
			c = '2';
			while (c <= '9')
			{
				write (1, &a, 1) && (1, &b, 1) && (1, &c, 1);
				if (!(a == '7' && b == '8' && c == '9'))
				{
					write (1, ",", 1) && (1, " ", 1);
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

/*void	ft_print_comb(void)
{
	char	a[3];

	a = "012";
	while (a <= "789")
	{
		write (1, &a, 3);
		a++;
	}
}*/

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
