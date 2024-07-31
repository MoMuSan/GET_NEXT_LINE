/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:55 by monmunoz          #+#    #+#             */
/*   Updated: 2024/07/31 23:28:40 by monmunoz         ###   ########.fr       */
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
	char	*copy;
	size_t	len;

	len = ft_strlen(s1) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, len);
	return (copy);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
	{
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
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
