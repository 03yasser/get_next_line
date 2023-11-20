/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:51:19 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/20 13:38:23 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *fill_line_buffer(int fd, char *left_l, char *buffer)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	if (left_l != NULL)
	{
		if (nl_exist(left_l))
			return (left_l);
	}
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		// printf ("bytes : %zd\n", bytes);
		if (bytes == -1)
		{
			free(left_l);
			left_l = NULL;
			return (NULL);
		}
		else if (bytes == 0)
			break;
		buffer[bytes] = '\0';
		// printf ("[%s]\n", buffer);
		if (!left_l)
			left_l = ft_strdup("");
		tmp = left_l;
		left_l = ft_strjoin(tmp, buffer);
		//printf ("line : [%s]\n",left_l);
		if (tmp == left_l)
		{
			free (tmp);
			tmp = NULL;
			return (NULL);
		}
		free (tmp);
		tmp = NULL;
		if (nl_exist(left_l))
			break;
	}
	return (left_l);
}
char	*set_left(char *line)
{
	char 	*left_l;
	size_t	i;

	i = 0;
	if(!line)
		return (NULL);
	if (line[0] == '\n' && !line[1])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	//printf ("[%s]\n", line);
	if (!line[i])
		return (NULL);
	left_l = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	line[i + 1] = '\0';
	if (i == 0)
		line = NULL;
	//printf("[%s]", line);
	if (!left_l)
		return (line);
	return (left_l);
}
char *get_next_line(int fd)
{
	static char	*left_l;
	char		*buffer;
	char		*line;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(left_l);
		left_l = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = fill_line_buffer(fd, left_l, buffer);
	//printf("[%s]\n", line);
	free (buffer);
	if (!line || line[0] == '\0')
	{
		free (left_l);
		left_l = NULL;
		return (NULL);
	}
	left_l = set_left(line);
	//printf("[%s]\n", left_l);
	return (line);
}

// int main()
// {
// 	char *str;
// 	int fd = open ("files/lines_around_10.txt", O_RDONLY);
// 	for (int i = 0; i < 8; i++)
// 	{
// 		//printf (":%d:\n", i);
// 		str = get_next_line(fd);
// 		printf("[%s] ", str);
// 		free (str);
// 	}
// 	// char buffer[BUFFER_SIZE];
// 	// for (int i = 0; i < 4 ; i++)
// 	// {
// 	// 	int bytes = read (fd, buffer, BUFFER_SIZE);
// 	// 	printf ("[%d][%s]\n",bytes, buffer);
// 	// }
// 	close (fd);
// }