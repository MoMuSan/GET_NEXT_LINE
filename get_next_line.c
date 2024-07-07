/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/07/07 20:48:30 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//numero de bytes a leer
int	num_read(int fd, char *buf)
{
	int			result;

	result = read (fd, buf, BUFFER_SIZE);
	if (result <= 0)
	{
		free (buf);
		return (0);
	}
	buf[result] = '\0';
	return (result);
}
// busco \n y si no, amplio buf para seguir buscando
// y retorno buf hsta el (\n + resto)

char	*new_line(char *buf, size_t read_file, int fd)
{
	char	*line;
	size_t	temp_read_file;

	line = ft_strchr(buf, '\n');
	while (!line)
	{
		buf = ft_buffer(buf, read_file);
		temp_read_file = num_read(fd, &buf[read_file]);
		if (temp_read_file == 0)
			break ;
		line = ft_strchr(buf, '\n');
	}
	return (buf);
}

char	*ft_buffer(char *buf, size_t read_file)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc((BUFFER_SIZE + read_file + 1) * sizeof(char));
	while (!buf[i])
	{
		temp[i] = buf[i];
		i++;
	}
	temp[i] = '\0';
	free (buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*v_est;
	int			num;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	num = num_read (fd, buf);
	line = new_line(buf, num, fd);
	return (line);
}
	//queda crear una funcion que guarde por un lado hasta \n
	// y por otro, el resto en v_est