/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:55 by monmunoz          #+#    #+#             */
/*   Updated: 2024/05/25 22:43:36 by monmunoz         ###   ########.fr       */
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
	{
		i++;
	}
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

	s3 = (char *)malloc(size + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	s3 = ft_strcat(s3, s1);
	s3 = ft_strcat(s3, s2);
	return ((char *)s3);
}

char	*new_line(char *text, int length, int fd)
{
	int			count;
	char		*s2;
	char		*s3;

	count = 0;
	while (text[count] != '\n' && count <= length)
		count++;
//si no he encontrado salto de linea
	if (text[count] != '\n')
	{
		s2 = (char *)(malloc(BUFFER_SIZE + 1 * sizeof(char)));
//reservo sitio para seguir leyendo
		length = length + read(fd, s2, BUFFER_SIZE); ==> PORQUE read() necesita el BUFFER_SIZE
		s2[length] = '\0';
//actualizo length
		s3 = ft_strjoin(text, s2, length);
// creo la nueva linea de lectura
		free (s2);
		free (text);
		text = s3;
	write (1, text, count);
	write (1, "\n", 1);
//libero memoria 
	}
	
	return (text);
}

/*char	*read_line(int fd, char *buf)
{
	read (fd, buf, BUFFER_SIZE);
	return (buf);
}*/
