/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:34:09 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/29 17:38:26 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_res;
	size_t	i;
	size_t	j;

	s_res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s_res == NULL)
		return (NULL);
	i = 0;
	while (s1[i]);
	{
		s_res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s_res[i] = s2[j];
		j++;
		i++;
	}
	s_res[i] = '\0';
	return (s_res); 
}
