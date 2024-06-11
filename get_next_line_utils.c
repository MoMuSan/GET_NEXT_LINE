/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:55 by monmunoz          #+#    #+#             */
/*   Updated: 2024/06/11 23:23:32 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!s3)
		return (NULL);
	s3[0] = '\0';
	s3 = ft_strcat(s3, s1);
	s3 = ft_strcat(s3, s2);
	return ((char *)s3);
}

char	*pieces(char *cut, char *text, size_t pos)
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

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = 1;
	while (s1)
		len++;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, len);
	return (copy);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

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
