/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:21:03 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/29 11:27:58 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_d;
	int	temp_m;

	temp_d = (*a / *b);
	temp_m = (*a % *b);
	*a = temp_d;
	*b = temp_m;
}
