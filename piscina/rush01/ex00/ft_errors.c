/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:55:07 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/28 20:25:06 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_errors(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				count++;
				i = i + 2;
			}
			else
				return (0);
		}
		else
			return (0);
	}
	if (count == 16)
		return (0);
	return (1);
}
