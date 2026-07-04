/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:04:39 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/30 13:44:56 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	char	origen[] = "hola";
	char	destino[10];
	unsigned int	n = 2;
	
	printf("Antes de copiar: origen = %s, destino = basura\n", origen);

	ft_strncpy(destino, origen, n);

	printf("Despues de coipiar: origen = %s, destino = %s.\n", origen, destino);
	return (0);
}*/
