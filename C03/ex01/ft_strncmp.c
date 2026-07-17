#include <stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	
	i = 0;
	while(i != n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
			break;
		}
		else
			i++;
	}
	return (s1[i] - s2[i]);

			
}

int	main(void)
{
	char str1[] = "ABCDF";
	char str2[] = "ABCDE";
	char *s1 = &str1[0];
	char *s2 = &str2[0];	
	printf("%d", ft_strncmp(s1, s2,3));
}
