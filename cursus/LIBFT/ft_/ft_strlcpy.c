/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:29:59 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/23 18:51:11 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < dst_len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
DESCRIPTION: Copies up to 'dst_len - 1' chars from 'src' to 'dst',
             NUL-terminating the result if 'dstsize' is not 0.
PARAM: 'dst' -> Destination buffer, 'src' -> Source string, 'dst_len' -> Buffer size.
RETURN: Total length of the string 'src' it tried to create.

#include <stdio.h>
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len);

int	main(void)
{
	char	src[] = "Hola 42!";
	char	dst[10];
	size_t	ret;

	printf("--testing ft_strlcpy--\n");
	ret = ft_strlcpy(dst, src, sizeof(dst));
	printf("Copied string : %s\n", dst);
	printf("Return value  : %zu (src length)\n", ret);
	return (0);
}*/
