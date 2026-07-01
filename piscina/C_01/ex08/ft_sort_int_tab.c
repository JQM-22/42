/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:04:02 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/29 13:49:44 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp1;
	int	temp2;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		temp1 = tab[i];
		if (temp1 > tab[i + 1])
		{
			temp2 = tab[i + 1];
			tab[i] = temp2;
			tab[i + 1] = temp1;
			i = i -1;
		}
		i++;
	}
}
