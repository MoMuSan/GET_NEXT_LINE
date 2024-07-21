#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// PRUEBAS DE SUBSTR //

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

int	main(void)
{
	char		*str = "Once upon a time, in a kingdom far away";
	static char	*ptr;
	char		*temp;
	size_t		len;
	int			count;

	if (!str)
		return (0);
	len = strlen(str);
	count = ft_position(str, ',');
	ptr = ft_substr(str, (count + 1), len);
	temp = (char *)malloc((count + 2) * sizeof(char));
	temp[count + 1] = '\0';
	ft_strlcpy(temp, str, (count + 2));
	printf("STR = %s\n", str);
	printf("PTR = %s\n", ptr);
	printf("TEMP = %s\n", temp);
	free (ptr);
	free(temp);
	return (0);
}
