/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:29:39 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/05 19:35:59 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	d_len;

	d_len = 0;
	while (dst[d_len] != '\0' && d_len < dst_size)
		d_len++;
	s_len = 0;
	while (src[s_len] != '\0')
		s_len++;
	if (d_len >= dst_size)
		return (dst_size + s_len);
	i = d_len;
	j = 0;
	while (src[j] != '\0' && (i + 1) < dst_size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}
/*
DESCRIPTION: Adds 'src' to 'dst' (taking size 'dst_size'),
NUL-terminating the result if space permits.
PARAM: 'dst' -> Destination buffer,
'src' -> Source string,
'dst_size' -> Buffer size.
RETURN: Total length of the string it tried to create
(initial 'dst' length + 'src' length).

#include <stdio.h>
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dst_len);

int	main(void)
{
char	dst[15] = "Hola ";
char	src[] = "42!";
size_t	ret;

printf("--testing ft_strlcat--\n");
printf("Before: dst = \"%s\"\n", dst);

ret = ft_strlcat(dst, src, sizeof(dst));

printf("After : dst = \"%s\"\n", dst);
printf("Return value  : %zu\n", ret);
return (0);
}*/
