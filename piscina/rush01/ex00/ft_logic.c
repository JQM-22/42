/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:52:31 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/28 20:16:19 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_convert(char *str, int num[16]);
int		ft_solve(int b[4][4], int num[16], int row, int col);
void	ft_print_board(int b[4][4]);
void	ft_print_error(void);

void	ft_logic(char *str)
{
	int	b[4][4];
	int	num[16];
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			b[row][col] = 0;
			col++;
		}
		row++;
	}
	ft_convert(str, num);
	if (ft_solve(b, num, 0, 0) == 1)
		ft_print_board(b);
	else
		ft_print_error();
}
