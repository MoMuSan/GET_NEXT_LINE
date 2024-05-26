#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
char *get_next_line(int fd);
int main (void)
{
    int	open_file;

	open_file = open ("lot.txt", O_RDONLY);
	
	get_next_line(open_file);
	//printf("%d \n", open_file);
    return (0);
}