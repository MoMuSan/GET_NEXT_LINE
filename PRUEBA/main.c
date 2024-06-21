/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:14:31 by monmunoz          #+#    #+#             */
/*   Updated: 2024/06/19 19:26:49 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		open_file;
	char	*tr;

	open_file = open ("lot.txt", O_RDONLY);
	tr = get_next_line(open_file);
	printf("TEST 1 %s TEST", tr);
	free (tr);
	tr = get_next_line(open_file);
	printf("TEST 2 %s ", tr);
	free (tr);
	tr = get_next_line(open_file);
	printf("TEST 3 %s ", tr);
	free (tr);
	return (0);
}
