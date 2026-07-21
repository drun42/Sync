#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)

{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
			break ;
		}
		else
			i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char str1[] = "ABC";
	char str2[] = "AB";
	char *s1 = &str1[0];
	char *s2 = &str2[0];	
	printf("%d", ft_strcmp(s1, s2));
}
*/
