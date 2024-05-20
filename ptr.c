#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	// obtengo el fd que necesito para la funcion read.
	int	open_file;

	open_file = open ("lot.txt", O_RDONLY);
	get_next_line(open_file);
	printf("%d \n", open_file);

	//guardo memoria para el trozo que voy a leer. 3 formas de hacerlo:
	//char	*buf = (char*)(calloc(20, sizeof(char)));
	//char *buf = (char*)(calloc(BUFFER_SIZE + 1, sizeof(char)));
	//char *buf[BUFFER_SIZE + 1];

	//cojo los bytes que voy a leer de la memoria que he guardado y los meto en el string buf
	//int	read_file = read (open_file, buf, 150);

	//cierro el string buf con el caracter nulo.
	buf[read_file] = '\0';
	
	//imprimo el string.
	//printf("%s Hola\n", buf);
	return (0);
}