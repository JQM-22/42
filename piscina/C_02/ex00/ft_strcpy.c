/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:25:00 by joquinta          #+#    #+#             */
/*   Updated: 2026/06/30 13:46:23 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;	

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

/*#include <stdio.h>

int main (void)
{
	char origen[] = "Hola caracola";
	char destino[20];

	printf("Antes de copiar: origen = %s, destino = basura\n", origen);
	
	ft_strcpy(destino, origen);

	printf("Despues de copiar: origen = %s, destino = %s\n", origen, destino);
	return (0);
}*/
