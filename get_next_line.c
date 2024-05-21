/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/05/21 18:22:16 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int		read_file;
	int		line;

	line = 0;
	if (fd == -1 || BUFFER_SIZE == 0)
		write (1, "(NULL)\n", 7);
	else
	{
		buf = (char *)(calloc(BUFFER_SIZE + 1, sizeof(char)));
		read_file = read (fd, buf, BUFFER_SIZE);
		buf[read_file] = '\0';
		new_line(buf, read_file);
		free (buf);
	}
	return (0);
}
