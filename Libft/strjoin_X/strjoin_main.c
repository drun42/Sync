/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_main.c                                    :+:      :+:    :+:   */
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

//subject prototype : both arguments are const
char	*ft_strjoin(char const *s1, char const *s2);

int main(void)
{
//subject: allocates with malloc and returns a new string, s1 followed by s2
//subject: returns NULL if the allocation fails
//the result is a NEW string : neither s1 nor s2 may be modified
//run it under valgrind : valgrind --leak-check=full ./a.out
char	*r;
char	s1 [] = "Hello ";


void show(char *label, char *p)
{
	if (p == NULL)
		printf("%s : NULL\n", label);
	else
		printf("%s : [%s]\n", label, p);
}


void both(char *expected, char const *a, char const *b)
{
	printf("expected : [%s]\n", expected);
	r = ft_strjoin(a, b);
	show("actual  ", r);
	free(r);
}


	//base case
	printf("%s\n", "Base Case, ft_strjoin(\"Hello \", \"World\"):");
	both("Hello World", "Hello ", "World");
	printf("%s\n"," ");

	//empty first part
	printf("%s\n", "Empty s1 Case, ft_strjoin(\"\", \"World\"):");
	both("World", "", "World");
	printf("%s\n"," ");

	//empty second part
	printf("%s\n", "Empty s2 Case, ft_strjoin(\"Hello\", \"\"):");
	both("Hello", "Hello", "");
	printf("%s\n"," ");

	//both empty : an empty string, not NULL
	printf("%s\n", "Both Empty Case, ft_strjoin(\"\", \"\"):");
	both("", "", "");
	printf("%s\n"," ");

	//the inputs must come out untouched
	printf("%s\n", "Input Untouched Case, s1 after the join:");
	r = ft_strjoin(s1, "World");
	printf("expected : [Hello ]\n");
	printf("actual   : [%s]\n", s1);
	printf("%s\n", "New Memory Case, result != s1:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", r != s1);
	free(r);
	printf("%s\n"," ");

	//length of the result
	printf("%s\n", "Length Case, strlen(ft_strjoin(\"abc\", \"de\")):");
	r = ft_strjoin("abc", "de");
	printf("%s\n", "expected : 5");
	printf("actual   : %zu\n", strlen(r));
	free(r);
	printf("%s\n"," ");

}
