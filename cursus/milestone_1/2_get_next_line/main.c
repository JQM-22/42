/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:53:39 by joquinta          #+#    #+#             */
/*   Updated: 2026/10/23 19:46:42 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir test.txt");
		return (1);
	}
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Línea %d: %s", line_count++, line);
		free(line);
	}
	close(fd);
	return (0);
}
