/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:42:25 by username          #+#    #+#             */
/*   Updated: 2026/10/05 18:48:03 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static int	ft_n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_malloc(int len)
{
	char	*res;

	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		digit;
	int		min_index;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_n_len(n);
	res = ft_malloc(len);
	if (!res)
		return (NULL);
	min_index = (n < 0);
	if (n < 0)
		res[0] = '-';
	while (len - 1 >= min_index)
	{
		digit = n % 10;
		if (digit < 0)
			digit = -digit;
		res[len - 1] = digit + '0';
		n = n / 10;
		len--;
	}
	return (res);
}
