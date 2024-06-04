/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:55 by monmunoz          #+#    #+#             */
/*   Updated: 2024/06/04 21:12:04 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2, int size)
{
	char	*s3;

	s3 = (char *)malloc((size + 1) * sizeof(char));
	s3[0] = '\0';
	if (!s3)
		return (NULL);
	s3 = ft_strcat(s3, s1);
	s3 = ft_strcat(s3, s2);
	return ((char *)s3);
}

char	pieces(char *cut, char *text, size_t pos)
{
	size_t	i;

	i = 0;
	if (!cut)
		return (NULL);
	while (i < pos)
	{
		cut[i] = text[i];
		i++;
	}
	return (cut);
}

char	*new_line(char *text, int length, int fd)
{
	int			count;
	static char	*v_est;
	char		*s2;
	char		*s3;

	count = 0;
	while (text[count] != '\n' && count < length)
		count++;
	if (text[count] != '\n')
	{
		s2 = (char *)(malloc((BUFFER_SIZE + 1) * sizeof(char)));
		s2[BUFFER_SIZE] = '\0';
		length = length + read(fd, s2, BUFFER_SIZE);
		s3 = ft_strjoin(text, s2, length);
		free (s2);
		free(text);
		text = new_line(s3, length, fd);
	}
	v_est = (char *)(malloc(((length - count) + 1) * sizeof(char)));
	pieces(v_est, &text[count + 1], (size_t)(length - count));
	return (text);
}
