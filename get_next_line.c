/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/05/19 19:53:36 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buf;
	int		read_file;
	if (fd == -1)
		write (1, "(NULL)\n", 7);
	else
	{
		buf = (char*)(calloc(BUFFER_SIZE + 1, sizeof(char)));
		read_file = read (fd, buf, BUFFER_SIZE);
		buf[read_file] = '\0';
		write (1, buf, BUFFER_SIZE + 1);
		write (1, "\n", 1);
		free (buf);
	}
	return (0);
}
