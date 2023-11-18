/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:00:49 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/18 16:43:13 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len_s;
	size_t	i;
	char	*p;

	i = 0;
	len_s = ft_strlen(s1);
	p = (char *) malloc (sizeof(char) * (len_s + 1));
	if (!s1 || !p) 
		return (NULL);
	while (i < len_s)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen (s2);
	p = (char *)malloc (sizeof(char) * (len_s1 + len_s2 + 1));
	if (!p)
		return (NULL);
	while (i < len_s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (j < len_s2 && s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[j + i] = '\0';
	return (p);
}


char	*set_left(const char *s)
{
	char	*p;
	size_t	i;

	i = 0;
	if(!s)
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (s[i] == '\n' && s[i + 1])
		{
			if (s[i + 1])
			{
				p = (char *)(s + i + 1);
				return (p);
			}
			else
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
static int nl_exist(char * buffer)
{
	size_t i;

	i = 0;
	while (buffer[i++])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char	*ft_substr(char *s)
{
	size_t	i;
	char	*p;
	size_t len;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[len] && s[len] != '\n')
		len++;
	p = malloc ((len + 1) * sizeof(char));
	while (i < len)
	{
			p[i] = s[i];
			i++;
	}
	p[i] = '\0';
	return (p);
}

char *fill_line_buffer(int fd, char *left_c, char *buffer)
{
	size_t	bytes;
	char	*p;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if ((bytes <= 0 && left_c != NULL) || nl_exist(left_c))
		return (left_c);
	else if (bytes <= 0 && !left_c)
		return (NULL);
	else if (left_c != NULL && !nl_exist(left_c))
		p = ft_strdup(left_c);
	else
		p = ft_strdup("");
	while (bytes > 0 && !nl_exist(buffer))
	{
		p = ft_strjoin(p, buffer);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			return (p);
	}
	return (ft_strjoin(p, buffer));
}
