/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:18:41 by alajara-          #+#    #+#             */
/*   Updated: 2023/05/16 12:09:41 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_full(char **storage, char **buffer)
{
	if (storage)
	{
		free(*storage);
		*storage = NULL;
	}
	if (buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*gnl_join_free(char *storage, char *buffer)
{
	char	*r;
	int		len;

	if (!storage)
	{
		storage = malloc(1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	len = gnl_strlen(buffer);
	len += (gnl_strlen(storage));
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (free_full(NULL, &storage));
	if (storage)
	{
		gnl_strlcpy(r, storage, len + 1);
		free_full(&storage, NULL);
	}
	else
		*r = '\0';
	gnl_strlcat(r, buffer, len + 1);
	return (r);
}

char	*get_the_line(char *storage)
{
	int		i;
	char	*line;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (storage[++i] && storage[i] != '\n')
		line[i] = storage[i];
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if (gnl_strlen(storage) == 0)
		return (free_full(NULL, &line));
	return (line);
}

char	*clean_storage(char *storage)
{
	char			*new_storage;
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	tmp = gnl_strchr(storage, '\n');
	if (!tmp)
		return (free_full(&storage, NULL));
	if (*tmp == '\n')
		++tmp;
	new_storage = (char *)malloc(sizeof(char) * (gnl_strlen(tmp) + 1));
	if (!new_storage)
		return (free_full(NULL, &storage));
	i = gnl_strlen(tmp);
	j = -1;
	while (++j < i)
		new_storage[j] = tmp[j];
	new_storage[j] = '\0';
	free_full(NULL, &storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*storage[OPEN_MAX] = {NULL};
	char		*line;
	int			readed;

	readed = 1;
	if (fd < 0 || 0 >= BUFFER_SIZE || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_full(NULL, &storage[fd]));
	while (readed > 0 && !gnl_strchr(storage[fd], '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free_full(&storage[fd], &buffer));
		buffer[readed] = '\0';
		storage[fd] = gnl_join_free(storage[fd], buffer);
	}
	free_full(&buffer, NULL);
	line = get_the_line(storage[fd]);
	if (!line)
		return (free_full(NULL, &storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
