/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:40:07 by pory              #+#    #+#             */
/*   Updated: 2022/06/14 01:19:27 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
size_t			ft_gnl_strlen(char *s);
int				ft_gnl_strchr(const char *s, int c);
char			*ft_gnl_strjoin(char *s1, char *s2);
char			*ft_read(int fd, char *stash, char *buf);
char			*ft_get_line(char *stash);
char			*ft_save_the_rest(char *stash);

#endif