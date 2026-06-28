/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:03:44 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/28 20:32:38 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_try(int b[4][4], int row, int col, int numtry);
int	ft_check_views(int b[4][4], int row, int col, int num[16]);

int	ft_solve(int b[4][4], int num[16], int row, int col)
{
	int	numtry;

	if (row == 4)
		return (1);
	if (col == 4)
		return (ft_solve(b, num, row +1, 0));
	numtry = 1;
	while (numtry <= 4)
	{
		if (ft_try(b, row, col, numtry) == 1)
		{
			b[row][col] = numtry;
			if (ft_check_views(b, row, col, num) == 1)
			{
				if (ft_solve(b, num, row, col +1) == 1)
					return (1);
			}
			b[row][col] = 0;
		}
		numtry++;
	}
	return (0);
}
