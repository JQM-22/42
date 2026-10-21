/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 18:39:13 by joquinta         #+#    #+#              */
/*   Updated: 2026/10/21 20:06:41 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) & s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_res;
	size_t	i;
	size_t	j;

	s_res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s_res == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
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
