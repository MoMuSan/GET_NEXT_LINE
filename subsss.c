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
	char	*str = "Once upon a time, in a kingdom far away";
	char	*ptr;
	size_t	len;
	int		count;

	len = strlen(str);
	count = ft_position(str, 'a');
	ptr = ft_substr(str, count, len);
	printf("STR = %s\n", str);
	printf("PTR = %s\n", ptr);
	printf("counter and len = %d %zu \n", count, len);
	free (str);
	return (0);
}