/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//subject prototype : start is an unsigned int, len is a size_t
char	*ft_substr(char const *s, unsigned int start, size_t len);

int main(void)
{
//subject: allocates with malloc and returns a substring of s
//subject: the substring starts at index start and is at most len long
//subject: returns NULL if the allocation fails
//len is a MAXIMUM : if the string ends first, the result is shorter
//a start past the end of s is not an error, it gives an empty string
//run it under valgrind : valgrind --leak-check=full ./a.out
char	*s;
char	*r;

s = "Hello World";


void show(char *label, char *p)
{
	if (p == NULL)
		printf("%s : NULL\n", label);
	else
		printf("%s : [%s]\n", label, p);
}


void both(char *expected, char const *str, unsigned int start, size_t len)
{
	printf("expected : [%s]\n", expected);
	r = ft_substr(str, start, len);
	show("actual  ", r);
	free(r);
}


	//middle of the string
	printf("%s\n", "Base Case, ft_substr(s, 6, 5):");
	both("World", s, 6, 5);
	printf("%s\n"," ");

	//from the very beginning
	printf("%s\n", "Start 0 Case, ft_substr(s, 0, 5):");
	both("Hello", s, 0, 5);
	printf("%s\n"," ");

	//len longer than what is left : the result is simply shorter
	printf("%s\n", "Len Too Big Case, ft_substr(s, 6, 100):");
	both("World", s, 6, 100);
	printf("%s\n"," ");

	//the whole string
	printf("%s\n", "Whole String Case, ft_substr(s, 0, 11):");
	both("Hello World", s, 0, 11);
	printf("%s\n"," ");

	//start past the end : empty string, NOT a NULL pointer
	printf("%s\n", "Start Past End Case, ft_substr(s, 20, 5):");
	both("", s, 20, 5);
	printf("%s\n"," ");

	//len 0 : empty string
	printf("%s\n", "Len 0 Case, ft_substr(s, 6, 0):");
	both("", s, 6, 0);
	printf("%s\n"," ");

	//empty source
	printf("%s\n", "Empty Src Case, ft_substr(\"\", 0, 5):");
	both("", "", 0, 5);
	printf("%s\n"," ");

	//the result must be its own block, not a pointer inside s
	printf("%s\n", "New Memory Case, result != s + 0:");
	r = ft_substr(s, 0, 11);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", r != s);
	free(r);
	printf("%s\n"," ");

}
