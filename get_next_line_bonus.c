/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:49:33 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/17 23:10:36 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_and_save(int fd, char *buffer, char *storage)
{
	int		read_it;
	char	*tmp;

	read_it = 1;
	while (read_it > 0)
	{
		read_it = read(fd, buffer, BUFFER_SIZE);
		if (read_it == 0)
			break ;
		else if (read_it < 0)
			return (0);
		buffer[read_it] = '\0';
		if (!storage)
			storage = ft_strdup("");
		tmp = storage;
		storage = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

static char	*cut(char *line)
{
	char	*storage;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] != '\n' || line[i + 1] == '\0')
		return (0);
	storage = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*storage == '\0')
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*storage[FD_SETSIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0 || FD_SETSIZE < fd || read(fd, 0, 0) < 0)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_and_save(fd, buffer, storage[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	storage[fd] = cut(line);
	return (line);
}
