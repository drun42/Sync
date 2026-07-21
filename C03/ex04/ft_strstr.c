
int needle_check(char)
{
	
}

char *ft_strstr(char *str, char *to_find)
{
	//finds the first occurrence of the substring needle in the string haystack.
	int	i;
	int	i2;
	int	temp;

	i = 0;
	i2 = 0;
	while(haystack[i])
	{
		if(haystack[i] == needle[i2])
		{
			temp = i;
			while(needle[i2])
			{
				if (needle[i2] == haystack[i])

			}
		}
			
	}

	//The terminating null bytes ('\0') are  not compared.

	
	//return a pointer to the beginning of the  located  substring, 
	return (haystack[i]);
	//or NULL if the substring is not found.
	
	//If  needle is the empty string, the return value is always haystack itself.
	if (needle[0] = '\0')
		return(haystack);
}

int	main(void)
{
	char	needle[] = "help";
	char	haystack[] = "please help me";


}
