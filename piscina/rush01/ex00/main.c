/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:53:17 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/28 20:35:33 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_print_error(void);
void	ft_logic(char *str);
int		ft_errors(char *str);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_print_error();
		return (0);
	}
	if (ft_errors(argv[1]) == 1)
	{
		ft_print_error();
		return (0);
	}
	ft_logic(argv[1]);
	return (0);
}
