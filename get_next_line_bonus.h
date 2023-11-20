/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:50:35 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/20 21:31:50 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS

#define GET_NEXT_LINE_BONUS

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

//# define BUFFER_SIZE 1000000
char	*get_next_line(int fd);
char	*fill_line_buffer(int fd, char *left_c, char *buffer);
char	*set_left(char *line);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int nl_exist(char * buffer);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);

#endif