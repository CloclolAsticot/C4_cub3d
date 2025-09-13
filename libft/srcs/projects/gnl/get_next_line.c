/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:35:34 by csavreux          #+#    #+#             */
/*   Updated: 2025/05/10 15:54:56 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

// Frees the given string and returns NULL.
static void	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

// Used if the buffer is empty - reads BUFFER_SIZE bytes in fd and adds it to
// the buffer.
static void	ft_writetobuf(ssize_t *nb_read, char *buf, int fd)
{
	*nb_read = read(fd, buf, BUFFER_SIZE);
	if (*nb_read == -1)
		return ;
	buf[*nb_read] = '\0';
}

// Used to put the current buffer in the line and reset the buffer.
static char	*ft_linemanager(ssize_t *eol_index, char *buf, char *line)
{
	*eol_index = ft_eol_search(buf);
	line = ft_add_buf_to_line(line, buf, *eol_index);
	if (!line)
		return (ft_free(line));
	ft_pending_buf(buf, *eol_index);
	return (line);
}

// Returns a line read from a file descriptor.
char	*get_next_line(int fd)
{
	static char	buf[NB_FD][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		nb_read;
	ssize_t		eol_index;

	line = NULL;
	nb_read = 1;
	eol_index = -1;
	if (fd < 0 || fd >= NB_FD)
		return (NULL);
	while (nb_read != 0 && eol_index == -1)
	{
		if (!buf[fd][0])
			ft_writetobuf(&nb_read, buf[fd], fd);
		if (nb_read == -1)
			return (ft_free(line));
		if (nb_read != 0)
		{
			line = ft_linemanager(&eol_index, buf[fd], line);
			if (!line)
				return (NULL);
		}
	}
	return (line);
}
