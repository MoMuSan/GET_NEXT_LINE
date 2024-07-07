/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:14:31 by monmunoz          #+#    #+#             */
/*   Updated: 2024/07/07 16:52:51 by monmunoz         ###   ########.fr       */
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

/*int main(void) //https://medium.com/@lannur-s/gnl-c3cff1ee552b
{
  int   fd;
  char  *next_line;
  int   count;

  count = 0;
  fd = open("lot.txt", O_RDONLY);
  while (count < 3)
    {
      next_line = get_next_line(fd);
      if (next_line == NULL)
        break ;
      count++;
// printf("[HELLO %d]:%s\n", count, next_line);
      next_line = NULL;
    }
  close(fd);
  return (0);
}*/

char	*get_next_line(int fd);
int	main(void)
{
	int		open_file;
	char	*tr;

	open_file = open ("lot.txt", O_RDONLY);
	tr = get_next_line(open_file);
	printf("// %s ", tr);
	free (tr);
	tr = get_next_line(open_file);
	printf("// %s  ", tr);
	free (tr);
	tr = get_next_line(open_file);
	printf("// %s ", tr);
	free (tr);
	return (0);
}
/*int main() 
{
    char *str = "Hello,\n world!This is a test string.\n";
    char *newline;

    // Search for the first occurrence of '\n' in str
    newline = ft_strchr(str, '\n');

    if (newline) 
	{
        printf("Newline character found at position: %ld\n", newline - str);
    } else 
	{
        printf("Newline character not found.\n");
    }

    return 0;
}*/
