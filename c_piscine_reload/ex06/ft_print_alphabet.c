/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:40:25 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/16 13:04:30 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	abc;

	abc = 'a';
	while (abc <= 'z')
	{
		ft_putchar (abc);
		abc++;
	}
}
/*int	main(void)
{
	ft_print_alphabet();
	return(0);
}*/
