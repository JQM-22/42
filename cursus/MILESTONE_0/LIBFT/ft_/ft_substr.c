/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:45:33 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/28 19:15:10 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*v_s;
	int	total_bytes;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (start >= ft_srtlen(s))
	{	
		v_s = malloc("",sizeof char);
		if (v_s == NULL)
			return (NULL);
	}
	total_bytes = len * sizeof(char);
	sub = malloc(total_bytes + 1);
		if (sub == NULL)
			return (NULL);
	if (len > (ft_strlen(s[start])
		 
	
}
