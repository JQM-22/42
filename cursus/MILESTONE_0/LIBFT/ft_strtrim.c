/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:40:30 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/29 20:00:18 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtf"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	if ((!s1) || (!set))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == set[i])
			i++;
		
}
