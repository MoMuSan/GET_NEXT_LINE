/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/10/13 20:02:26 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	num_read(int fd, char *buf)
{
	int			result;

	result = read (fd, buf, BUFFER_SIZE);
	if (result <= 0)
		return (0);
	buf[result] = '\0';
	return (result);
}

char	*new_line(char *buf, size_t read_file, int fd)
{
	int				count;
	size_t			temp_read_file;

	count = ft_position(buf, '\n');
	while (count == -1)
	{
		buf = ft_buffer(buf, read_file);
		temp_read_file = num_read(fd, &buf[read_file]);
		if (temp_read_file == 0)
			break ;
		read_file += temp_read_file;
		count = ft_position(buf, '\n');
	}
	return (buf);
}

int	ft_position(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_buffer(char *buf, size_t read_file)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc((BUFFER_SIZE + read_file + 1) * sizeof(char));
	while (buf[i])
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
	char			*buf;
	char			*line;
	int				num;
	static char		*v_est[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	if (!v_est[fd] && ft_check(&buf, &num, fd) == 0)
		return (0);
	if (v_est[fd])
		buf = v_est[fd];
	line = new_line(buf, ((int)ft_strlen(buf)), fd);
	buf = ft_substr(line, 0, (ft_position(line, '\n')) + 1);
	re_check (&v_est[fd], line, &buf);
	free (line);
	return (buf);
}
