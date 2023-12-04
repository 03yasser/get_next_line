/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:51:19 by yboutsli          #+#    #+#             */
/*   Updated: 2023/12/02 21:49:44 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	*(char *)(dst + i) = '\0';
	return (dst);
}

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
			free(buffer);
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

static char	*set_left(char **line)
{
	char	*left_l;
	size_t	i;
	char	*tmp;

	i = 0;
	while (line[0][i] != '\0' && line[0][i] != '\n')
		i++;
	if (line[0][i] == '\0' || line[0][1] == '\0')
	{
		line = NULL;
		return (NULL);
	}
	left_l = ft_substr(line[0], i + 1, ft_strlen(line[0]) - i - 1);
	if (!left_l || left_l[0] == '\0')
	{
		free (left_l);
		left_l = NULL;
	}
	tmp = (char *)malloc (sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, *line, i + 1);
	free(line[0]);
	*line = tmp;
	return (left_l);
}

char	*get_next_line(int fd)
{
	static char	*left_l;
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > 10240 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (left_l != NULL)
			free(left_l);
		left_l = NULL;
		return (NULL);
	}
	buffer = malloc (sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_l, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_l = set_left(&line);
	return (line);
}
