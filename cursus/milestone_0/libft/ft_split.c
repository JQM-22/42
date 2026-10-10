/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 20:08:12 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/05 19:29:24 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_split(char **lst, size_t i)
{
	while (i > 0)
	{
		i--;
		free(lst[i]);
	}
	free(lst);
}

static char	**fill(char **lst, char const *s, char c)
{
	size_t	word_len;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = 0;
			while (s[word_len] && s[word_len] != c)
				word_len++;
			lst[i] = ft_substr(s, 0, word_len);
			if (!lst[i])
				return (free_split(lst, i), NULL);
			i++;
			s += word_len;
		}
		else
			s++;
	}
	lst[i] = NULL;
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;

	if (!s)
		return (NULL);
	lst = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	return (fill(lst, s, c));
}
