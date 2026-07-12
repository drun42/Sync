#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		str++;
	}
}

int	main(void)
{
	char str[] = "salut";
/*
 * 	string is a pointer to the first character of this string
 * 	here string = pointer to the "s" it like string[0] and when  do string ++
 * 	i swithc to yhe second character
 */
	ft_putstr(str);
	
}

