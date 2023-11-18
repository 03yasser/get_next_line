/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:51:19 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/18 21:18:50 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*left_c = NULL;
	char		*line;
	// printf ("[%s]\n", left_c);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = fill_line_buffer(fd, left_c);
	printf("line :[%s]\n",line);
	if (!line)
		return (NULL);
	left_c = set_left(line);
	//printf ("left : {%s}\n", left_c);
	if (line != NULL)
		line = ft_substr(line);
	//printf("final line :{%s}\n",line);
	return (line);
}

int main()
{
	char *str;
	int fd = open ("tst", O_RDONLY);
	for (int i = 0; i < 5; i++)
	{
		printf (":%d:\n", i);
		str = get_next_line(fd);
		//printf("[%s]\n", str);
		free (str);
	}
	// char buffer[BUFFER_SIZE];
	// for (int i = 0; i < 4 ; i++)
	// {
	// 	int bytes = read (fd, buffer, BUFFER_SIZE);
	// 	printf ("[%d][%s]\n",bytes, buffer);
	// }
	close (fd);
}