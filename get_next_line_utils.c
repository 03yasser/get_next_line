/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:00:49 by yboutsli          #+#    #+#             */
/*   Updated: 2023/12/05 13:37:52 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
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
	if (!p)
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
	char	*p;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	ssize_t	j;

	i = 0;
	j = -1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen (s2);
	if (len_s1 == 0 && len_s2 == 0)
		return (NULL);
	p = (char *)malloc (sizeof(char) * (len_s1 + len_s2 + 1));
	if (!p)
		return (NULL);
	while (i < len_s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (++j < (ssize_t)len_s2 && s2[j])
		p[i + j] = s2[j];
	p[j + i] = '\0';
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
