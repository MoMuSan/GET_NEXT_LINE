/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:55 by monmunoz          #+#    #+#             */
/*   Updated: 2024/07/10 19:23:59 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2, int size)
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
// "i" position of "\n"
// return -1 por si en la posicion zero hay \n

