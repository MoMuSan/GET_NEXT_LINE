/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:10 by monmunoz          #+#    #+#             */
/*   Updated: 2024/07/25 18:02:21 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*v_est;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	if (!v_est && ft_check(&buf, &num, fd) == 0)
		return (0);
	if (v_est)
		buf = v_est;
	line = new_line(buf, ((int)ft_strlen(v_est)), fd);
	buf = ft_substr(line, 0, (ft_position(line, '\n')) + 1);
	v_est = ft_substr(line, (ft_position(line, '\n') + 1),
			ft_strlen(line + 1) - ft_position(line, '\n'));
	if (ft_position(line, '\n') == -1)
	{
		free(buf);
		buf = ft_strdup(v_est);
		free(v_est);
		v_est = NULL;
	}
	free (line);
	return (buf);
}
