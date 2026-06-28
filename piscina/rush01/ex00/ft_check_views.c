/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_views.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javromer <javromer@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:15:17 by javromer          #+#    #+#             */
/*   Updated: 2026/06/28 19:45:51 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_visible(int line[4])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_check_views_l_r(int b[4][4], int row, int col, int num[16])
{
	int	line[4];
	int	i;

	if (col == 3)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = b[row][i];
			i++;
		}
		if (ft_visible(line) != num[8 + row])
			return (0);
		i = 0;
		while (i < 4)
		{
			line[i] = b[row][3 - i];
			i++;
		}
		if (ft_visible(line) != num[12 + row])
			return (0);
	}
	return (1);
}

int	ft_check_views_t_b(int b[4][4], int row, int col, int num[16])
{
	int	line[4];
	int	i;

	if (row == 3)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = b[i][col];
			i++;
		}
		if (ft_visible(line) != num[col])
			return (0);
		i = 0;
		while (i < 4)
		{
			line[i] = b[3 - i][col];
			i++;
		}
		if (ft_visible(line) != num[4 + col])
			return (0);
	}
	return (1);
}

int	ft_check_views(int b[4][4], int row, int col, int num[16])
{
	if (ft_check_views_l_r(b, row, col, num) == 0)
		return (0);
	if (ft_check_views_t_b(b, row, col, num) == 0)
		return (0);
	return (1);
}
