/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim_main.c                                    :+:      :+:    :+:   */
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

//subject prototype : s1 and set are both const
char	*ft_strtrim(char const *s1, char const *set);

int main(void)
{
//subject: allocates with malloc and returns a copy of s1 with every
//subject: character of set removed from the BEGINNING and the END
//subject: returns NULL if the allocation fails
//only the two ends are trimmed : set characters in the middle stay
//set is a SET of characters, not a prefix to strip
//run it under valgrind : valgrind --leak-check=full ./a.out
char	*r;


void show(char *label, char *p)
{
	if (p == NULL)
		printf("%s : NULL\n", label);
	else
		printf("%s : [%s]\n", label, p);
}


void both(char *expected, char const *s, char const *set)
{
	printf("expected : [%s]\n", expected);
	r = ft_strtrim(s, set);
	show("actual  ", r);
	free(r);
}


	//spaces on both sides
	printf("%s\n", "Base Case, ft_strtrim(\"  hello  \", \" \"):");
	both("hello", "  hello  ", " ");
	printf("%s\n"," ");

	//another single character
	printf("%s\n", "Single Char Set Case, ft_strtrim(\"xxhelloxx\", \"x\"):");
	both("hello", "xxhelloxx", "x");
	printf("%s\n"," ");

	//a real set : several characters, in any order
	printf("%s\n", "Char Set Case, ft_strtrim(\"\\n\\t hello \\t\\n\", \" \\t\\n\"):");
	both("hello", "\n\t hello \t\n", " \t\n");
	printf("%s\n"," ");

	//set characters in the MIDDLE must survive
	printf("%s\n", "Middle Case, ft_strtrim(\"xhexllox\", \"x\"):");
	both("hexllo", "xhexllox", "x");
	printf("%s\n"," ");

	//everything is in the set : empty string, not NULL
	printf("%s\n", "All Trimmed Case, ft_strtrim(\"xxx\", \"x\"):");
	both("", "xxx", "x");
	printf("%s\n"," ");

	//nothing to trim : a plain copy
	printf("%s\n", "Nothing To Trim Case, ft_strtrim(\"hello\", \"x\"):");
	both("hello", "hello", "x");
	printf("%s\n"," ");

	//empty set : a plain copy
	printf("%s\n", "Empty Set Case, ft_strtrim(\"  hello  \", \"\"):");
	both("  hello  ", "  hello  ", "");
	printf("%s\n"," ");

	//empty s1
	printf("%s\n", "Empty s1 Case, ft_strtrim(\"\", \" \"):");
	both("", "", " ");
	printf("%s\n"," ");

	//only one side needs trimming
	printf("%s\n", "One Side Case, ft_strtrim(\"hello  \", \" \"):");
	both("hello", "hello  ", " ");
	printf("%s\n"," ");

}
