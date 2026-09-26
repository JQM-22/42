/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 19:25:14 by joquinta          #+#    #+#             */
/*   Updated: 2026/09/25 20:12:18 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
size_t	ft_strlen(const char *str);

char	*strdup(const char *s1)
{
	int	i;
	char	*mem;	

	mem = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if(mem == NULL)
		return (NULL);
	i = 0;
	while(s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
