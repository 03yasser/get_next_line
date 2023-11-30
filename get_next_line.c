/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:51:19 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/30 16:32:45 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (s + i);
		i++;
	}
	return (NULL);
}

static char	*fill_line_buffer(int fd, char *left_l, char *buffer)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	while (bytes > 0)
	{
		if (ft_strchr(left_l))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(left_l);
			return (NULL);
		}
		else
			if (bytes == 0)
				break ;
		buffer[bytes] = '\0';
		tmp = left_l;
		left_l = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
	}
	return (left_l);
}

static char	*set_left(char *line)
{
	char	*left_l;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
	{
		line = NULL;
		return (NULL);
	}
	left_l = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!left_l || left_l[0] == '\0')
	{
		free (left_l);
		left_l = NULL;
	}
	line[i + 1] = '\0';
	return (left_l);
}

char	*get_next_line(int fd)
{
	static char	*left_l;
	char		*buffer;
	char		*line;

	buffer = malloc (sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(left_l);
		left_l = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = fill_line_buffer(fd, left_l, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
	{
		left_l = NULL;
		return (NULL);
	}
	left_l = set_left(line);
	return (line);
}
