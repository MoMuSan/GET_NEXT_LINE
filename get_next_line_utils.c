/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:55 by monmunoz          #+#    #+#             */
/*   Updated: 2024/07/30 19:14:29 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start >= (int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ((size_t)ft_strlen(s) - (size_t)start))
		len = ((size_t)ft_strlen(s) - (size_t)start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start] != '\0' && j < len)
	{
		sub[i] = s[start];
		start++;
		i++;
		j++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}

char	*ft_strdup(char *s1)
{
	int			i;
	char		*copy;
	size_t		len;

	i = 0;
	len = ft_strlen(s1) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_check(char **buf, int *num, int fd)
{
	*buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buf)
		return (0);
	*num = num_read (fd, *buf);
	if (*num == 0)
	{
		free (*buf);
		*buf = NULL;
		return (0);
	}
	return (1);
}

void	re_check(char **v_est, char *line, char **buf)
{
	size_t	size;

	size = ft_strlen(line) - (size_t) ft_position(line, '\n');
	if (size <= 1)
	{
		*v_est = 0;
		return ;
	}
	*v_est = ft_substr(line, (ft_position(line, '\n') + 1), (size + 1));
	if (ft_position(line, '\n') == -1)
	{
		free(*buf);
		*buf = ft_strdup(*v_est);
		free(*v_est);
		*v_est = NULL;
	}
}
