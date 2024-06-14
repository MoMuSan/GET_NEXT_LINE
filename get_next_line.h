/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:45:19 by monmunoz          #+#    #+#             */
/*   Updated: 2024/06/12 22:01:07 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE    15
# endif

char		*get_next_line(int fd);
char		*new_line(char *text, int length, int fd);
static char	*ft_strcat(char *dest, const char *src);
char		*ft_strjoin(const char *s1, const char *s2, int size);
char		*ft_strdup(const char *s1);
int			ft_strlcpy(char *dst, const char *src, int dstsize);
char		*pieces(char *cut, char *text, size_t pos);

#endif