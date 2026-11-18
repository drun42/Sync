/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//subject prototype : returns an array of strings
char	**ft_split(char const *s, char c);

int main(void)
{
//subject: allocates and returns an array of new strings, s cut on c
//subject: the array itself must be freed, and every string inside it
//subject: returns NULL if any allocation fails
//the array MUST end with a NULL pointer, that is how the caller stops
//repeated delimiters produce NO empty strings
//run it under valgrind : valgrind --leak-check=full ./a.out
char	**r;


void show(char *expected, char **tab)
{
	int	i;

	printf("expected : %s\n", expected);
	printf("%s", "actual   : ");
	if (tab == NULL)
	{
		printf("%s\n", "NULL");
		return ;
	}
	i = 0;
	while (tab[i])
	{
		printf("[%s]", tab[i]);
		i++;
	}
	printf("  count %d, ends with NULL %d\n", i, tab[i] == NULL);
}


void clean(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}


	//three words, one delimiter between each
	printf("%s\n", "Base Case, ft_split(\"hello world 42\", ' '):");
	r = ft_split("hello world 42", ' ');
	show("[hello][world][42]  count 3, ends with NULL 1", r);
	clean(r);
	printf("%s\n"," ");

	//repeated delimiters, and some at both ends
	printf("%s\n", "Repeated Delimiter Case, ft_split(\"   hello   world   \", ' '):");
	r = ft_split("   hello   world   ", ' ');
	show("[hello][world]  count 2, ends with NULL 1", r);
	clean(r);
	printf("%s\n"," ");

	//no delimiter in the string : one single word
	printf("%s\n", "No Delimiter Case, ft_split(\"hello\", ' '):");
	r = ft_split("hello", ' ');
	show("[hello]  count 1, ends with NULL 1", r);
	clean(r);
	printf("%s\n"," ");

	//empty string : an array holding only the NULL
	printf("%s\n", "Empty String Case, ft_split(\"\", ' '):");
	r = ft_split("", ' ');
	show("  count 0, ends with NULL 1", r);
	clean(r);
	printf("%s\n"," ");

	//nothing but delimiters : again an array holding only the NULL
	printf("%s\n", "Only Delimiters Case, ft_split(\"     \", ' '):");
	r = ft_split("     ", ' ');
	show("  count 0, ends with NULL 1", r);
	clean(r);
	printf("%s\n"," ");

	//the delimiter is a normal letter
	printf("%s\n", "Letter Delimiter Case, ft_split(\"hello\", 'l'):");
	r = ft_split("hello", 'l');
	show("[he][o]  count 2, ends with NULL 1", r);
	clean(r);
	printf("%s\n"," ");

	//delimiters only at the two ends
	printf("%s\n", "Edges Case, ft_split(\"-a-b-\", '-'):");
	r = ft_split("-a-b-", '-');
	show("[a][b]  count 2, ends with NULL 1", r);
	clean(r);
	printf("%s\n"," ");

	//the delimiter is '\0' : the whole string is one single word
	printf("%s\n", "Delimiter '\\0' Case, ft_split(\"hello\", '\\0'):");
	r = ft_split("hello", '\0');
	show("[hello]  count 1, ends with NULL 1", r);
	clean(r);
	printf("%s\n"," ");

}
