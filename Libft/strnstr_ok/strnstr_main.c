/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : BSD function, len is a size_t
char	*ft_strnstr(const char *big, const char *little, size_t len);

int main(void)
{
//man: locates the first occurrence of the string little in the string big,
//man: where not more than len characters of big are searched
//man: if little is an EMPTY string, big is returned
//man: returns NULL if little is not found inside those len characters
//the WHOLE needle must fit inside the len window, not just its first byte
//strnstr is BSD, glibc does not ship it : expected values come from the man
char	*big;

big = "Hello World";


void show(char *label, char *base, char *p)
{
	if (p == NULL)
		printf("%s : NULL\n", label);
	else
		printf("%s : offset %d [%s]\n", label, (int)(p - base), p);
}


	//needle in the middle, window covers the whole haystack
	printf("%s\n", "Base Case, strnstr(big, \"World\", 11):");
	printf("%s\n", "expected : offset 6 [World]");
	show("actual  ", big, ft_strnstr(big, "World", 11));
	printf("%s\n"," ");

	//the needle starts inside the window but does not fit in it
	printf("%s\n", "Window Case, strnstr(big, \"World\", 10):");
	printf("%s\n", "expected : NULL");
	show("actual  ", big, ft_strnstr(big, "World", 10));
	printf("%s\n"," ");

	//needle fits exactly on the last allowed byte
	printf("%s\n", "Window Case, strnstr(big, \"World\", 12):");
	printf("%s\n", "expected : offset 6 [World]");
	show("actual  ", big, ft_strnstr(big, "World", 12));
	printf("%s\n"," ");

	//needle at the very beginning
	printf("%s\n", "First Position Case, strnstr(big, \"Hello\", 5):");
	printf("%s\n", "expected : offset 0 [Hello World]");
	show("actual  ", big, ft_strnstr(big, "Hello", 5));
	printf("%s\n"," ");

	//empty needle : big itself comes back, whatever len is
	printf("%s\n", "Empty Needle Case, strnstr(big, \"\", 11):");
	printf("%s\n", "expected : offset 0 [Hello World]");
	show("actual  ", big, ft_strnstr(big, "", 11));
	printf("%s\n", "Empty Needle Case, strnstr(big, \"\", 0):");
	printf("%s\n", "expected : offset 0 [Hello World]");
	show("actual  ", big, ft_strnstr(big, "", 0));
	printf("%s\n"," ");

	//not there at all
	printf("%s\n", "Not Found Case, strnstr(big, \"xyz\", 11):");
	printf("%s\n", "expected : NULL");
	show("actual  ", big, ft_strnstr(big, "xyz", 11));
	printf("%s\n"," ");

	//needle longer than the haystack
	printf("%s\n", "Long Needle Case, strnstr(\"abc\", \"abcd\", 10):");
	printf("%s\n", "expected : NULL");
	show("actual  ", "abc", ft_strnstr("abc", "abcd", 10));
	printf("%s\n"," ");

	//false start : the first match attempt fails on the last byte
	printf("%s\n", "False Start Case, strnstr(\"aaab\", \"aab\", 4):");
	printf("%s\n", "expected : offset 1 [aab]");
	show("actual  ", "aaab", ft_strnstr("aaab", "aab", 4));
	printf("%s\n"," ");

	//len = 0 with a real needle : nothing may be read
	printf("%s\n", "len = 0 Case, strnstr(big, \"Hello\", 0):");
	printf("%s\n", "expected : NULL");
	show("actual  ", big, ft_strnstr(big, "Hello", 0));
	printf("%s\n"," ");

}
