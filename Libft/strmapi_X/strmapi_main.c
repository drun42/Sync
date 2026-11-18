/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//subject prototype : f takes the INDEX first, then the character
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//adds the index to the character : proves f really receives the index
char	add_index(unsigned int i, char c)
{
	return (c + i);
}

//ignores the index, only changes the character
char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int main(void)
{
//subject: applies f to every character of s, passing the INDEX as first
//subject: argument, and returns the resulting string, allocated with malloc
//subject: returns NULL if the allocation fails
//s itself must NOT be modified : strmapi builds a new string
//run it under valgrind : valgrind --leak-check=full ./a.out
char	*r;
char	src [] = "aaaa";


void show(char *expected, char *p)
{
	printf("expected : [%s]\n", expected);
	if (p == NULL)
		printf("%s\n", "actual   : NULL");
	else
		printf("actual   : [%s]\n", p);
}


	//the index is added to each character : a, a+1, a+2, a+3
	printf("%s\n", "Index Case, ft_strmapi(\"aaaa\", add_index):");
	r = ft_strmapi("aaaa", add_index);
	show("abcd", r);
	free(r);
	printf("%s\n"," ");

	//a transformation that ignores the index
	printf("%s\n", "Transform Case, ft_strmapi(\"hello 42\", to_upper):");
	r = ft_strmapi("hello 42", to_upper);
	show("HELLO 42", r);
	free(r);
	printf("%s\n"," ");

	//empty string : an empty result, not NULL
	printf("%s\n", "Empty String Case, ft_strmapi(\"\", to_upper):");
	r = ft_strmapi("", to_upper);
	show("", r);
	free(r);
	printf("%s\n"," ");

	//one character, index 0
	printf("%s\n", "One Char Case, ft_strmapi(\"a\", add_index):");
	r = ft_strmapi("a", add_index);
	show("a", r);
	free(r);
	printf("%s\n"," ");

	//the source string must come back untouched
	printf("%s\n", "Source Untouched Case, src after the call:");
	r = ft_strmapi(src, add_index);
	printf("expected : [aaaa]\n");
	printf("actual   : [%s]\n", src);
	free(r);
	printf("%s\n"," ");

}
