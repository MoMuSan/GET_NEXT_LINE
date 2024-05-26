/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/05/25 22:13:33 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	char		*buf;
	int			read_file;
	static char	*reserved;

	if (fd == -1 || BUFFER_SIZE == 0)
		return (NULL);
	else
	{
		buf = (char *)(malloc(BUFFER_SIZE + 1 * sizeof(char)));
		read_file = read (fd, buf, BUFFER_SIZE);
		if (!buf)
			return (NULL);
		buf[read_file] = '\0';
		reserved = new_line(buf, read_file, fd);
	}
	return (reserved);
}
