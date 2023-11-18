/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:48:25 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/18 21:06:43 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE

# define GET_NEXT_LINE

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>


# define BUFFER_SIZE 100
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*fill_line_buffer(int fd, char *left_c);
char	*set_left(const char *s);
char	*ft_substr(char *s);
size_t	ft_strlen(const char *s);

# endif