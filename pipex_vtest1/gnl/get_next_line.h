/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:23:07 by bcaffere          #+#    #+#             */
/*   Updated: 2023/01/15 17:07:28 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		find_nl(char *str);
char	*str_join(char *s1, char *s2);
char	*get_line(char *str);
char	*trim_rem(char *str);
int		some_error(char *str);

#endif
