/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/06/28 20:11:53 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	size_t		read_file;
	char		*reserved;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
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
	reserved = ft_strchr(buf, '\n');
	while (!reserved && read_file)
	{
		reserved = (char *)(malloc((read_file + BUFFER_SIZE + 1) * sizeof(char)));
		reserved = ft_memmove(reserved, buf, read_file);
		read_file += read(fd, &reserved[read_file], BUFFER_SIZE);
		printf("reserverd: %s %zu\n", buf, read_file);
		reserved[read_file] = '\0';
		reserved = ft_strchr(buf, '\n');
		free (reserved);
	}
	printf("RESERVED %s\n", reserved);
	return (reserved);
}
