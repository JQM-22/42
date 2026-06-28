/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:08:26 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/28 15:02:46 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_try(int b[4][4], int row, int col, int numtry)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (b[row][i] == numtry)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (b[i][col] == numtry)
			return (0);
		i++;
	}
	return (1);
}
