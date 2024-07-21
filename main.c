/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:14:31 by monmunoz          #+#    #+#             */
/*   Updated: 2024/07/21 20:21:54 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*int	main(void) //https://medium.com/@lannur-s/gnl-c3cff1ee552b
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	next_line = NULL;
	fd = open("lot.txt", O_RDONLY);
	while (count < 3)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
	}
	close(fd);
	//printf("P = %s\n", next_line);
	return (0);
}*/

int	main(void)
{
	int		open_file;
	char	*tr;

	open_file = open ("lot.txt", O_RDONLY);
	tr = get_next_line(open_file);
	printf("%s ", tr);
	free (tr);
	printf("\n --- \n");
	tr = get_next_line(open_file);
	printf("%s  ", tr);
	printf("\n --- \n");
	free (tr);
	tr = get_next_line(open_file);
	printf("%s ", tr);
	free (tr);
	printf("\n --- \n");
	close (open_file);
	return (0);
}
