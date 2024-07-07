/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:45:19 by monmunoz          #+#    #+#             */
/*   Updated: 2024/07/07 20:44:39 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

char			*get_next_line(int fd);
char			*new_line(char *buf, size_t read_file, int fd);
int				ft_strchr(char *s, int c);
char			*ft_buffer(char *buf, size_t read_file);
//size_t			ft_strlen(char *s);
//static char	    *ft_strcat(char *dest, const char *src);
//char			*ft_strjoin(char *s1, const char *s2, int size);
#endif