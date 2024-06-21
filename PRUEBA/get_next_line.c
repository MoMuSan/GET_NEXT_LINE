/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/06/21 19:33:10 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *buf, size_t read_file, int fd)
{
	/*Buscar \n*/
	char	*n;

	n = ft_strchr(*buf, '\n');
	printf ("N %s\n", n);
}

char	*get_next_line(int fd)
{
	char		*buf;
	size_t		read_file;
	char		*reserved;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	else
	{
		buf = (char *)(malloc((BUFFER_SIZE + 1) * sizeof(char)));
		if (!buf)
			return (NULL);
		read_file = read (fd, buf, BUFFER_SIZE);
		if (read_file <= 0)
		{
			free (buf);
			return (NULL);
		}
		buf[read_file] = '\0';
		reserved = new_line(buf, read_file, fd);
	}
	return (reserved);
}
