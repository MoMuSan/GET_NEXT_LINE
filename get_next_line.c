/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/06/14 20:04:52 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*leftover(char *v_est, char *text, int length)
{
	char	*temp;
	printf("Leftover\n");
	temp = ft_strjoin(v_est, text, length);
	free(text);
	free(v_est);
	text = temp;
	length = length + ft_strlen(v_est);
	v_est = NULL;
	return (temp);
}

char	*pieces(char *cut, char *text, size_t pos)
{
	size_t	i;

	i = 0;
	if (!cut || !text)
		return (NULL);
	while (i < pos)
	{
		cut[i] = text[i];
		i++;
	}
	printf("pieces\n");
	cut[pos] = '\0';
	return (cut);
}

char	*divided(char *text, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	bytes_read;
	char	*new_text;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (text);
	buffer[bytes_read] = '\0';
	new_text = ft_strjoin(text, buffer, bytes_read);
	free(text);
	printf("DIVIDED\n");
	return (new_text);
}

char	*new_line(char *text, int length, int fd)
{
	int			count;
	static char	*v_est;
	char		*clean_line;
	char		*temp;

	count = 0;
	if (v_est)
		temp = leftover(v_est, text, length);
	while (text[count] != '\n' && count < length)
		count++;
	if (text[count] != '\n')
		text = divided(text, fd);
	else
	{
		v_est = (char *)(malloc(((length - count) + 1) * sizeof(char)));
		v_est = pieces(v_est, &text[count + 1], ((size_t)(length - count)));
		clean_line = (char *)(malloc((count + 1) * sizeof(char)));
		clean_line = pieces(clean_line, text, count);
		clean_line[count] = 0;
		free (text);
		text = clean_line;
	}
	printf("new line\n");
	return (text);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			read_file;
	char		*reserved;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
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
