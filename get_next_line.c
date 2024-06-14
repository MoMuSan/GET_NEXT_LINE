/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/06/12 21:52:50 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *text, int length, int fd)
{
	int			count;
	static char	*v_est;
	char		*s2;
	char		*s3;
	char		*clean_line;

	count = 0;
	while (text[count] != '\n' && count < length)
		count++;
	if (text[count] != '\n')
	{
		s2 = (char *)(malloc((BUFFER_SIZE + 1) * sizeof(char)));
		s2[BUFFER_SIZE] = '\0';
		length = length + read(fd, s2, BUFFER_SIZE);
		s3 = ft_strjoin(text, s2, length);
		free (s2);
		free(text);
		text = new_line(s3, length, fd);
	}
	else
	{
		v_est = (char *)(malloc(((length - count) + 1) * sizeof(char)));
		v_est = pieces(v_est, &text[count + 1], ((size_t)(length - count)));
		clean_line = (char *)(malloc((count + 1) * sizeof(char)));
		clean_line = pieces(clean_line, text, count);
		clean_line[count] = 0;
		free(text);
		text = clean_line;
	}
	return (text);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			read_file;
	char		*reserved;
	static char	*pick;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
	{
		buf = (char *)(malloc((BUFFER_SIZE + 1) * sizeof(char)));
		if (!buf)
			return (NULL);
		read_file = read (fd, buf, BUFFER_SIZE);
		buf[read_file] = '\0';
		reserved = new_line(buf, read_file, fd);
	}
	return (reserved);
}
