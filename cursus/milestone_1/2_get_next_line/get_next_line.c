/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 18:39:38 by joquinta         #+#    #+#              */
/*   Updated: 2026/10/21 20:06:39 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
}

char	*read_to_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	stash = strjoin(stash, buffer);
}
