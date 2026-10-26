/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils_bonus.c                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 18:39:13 by joquinta         #+#    #+#              */
/*   Updated: 2026/10/26 13:23:17 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
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

	if (!s1 || !s2)
		return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*mem;

	mem = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
