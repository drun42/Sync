/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_main.c                                      :+:      :+:    :+:   */
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

//man prototype : returns char *, takes a const char *
char	*ft_strdup(const char *s);

int main(void)
{
//man: returns a pointer to a NEW string, duplicate of s
//man: the memory is obtained with malloc and can be freed with free
//man: returns NULL if not enough memory was available
//the NULL-on-malloc-failure case cannot be forced from here, run it under
//valgrind instead : valgrind --leak-check=full ./a.out
char	src [] = "likun";
char	*dup;
char	*empty;

	//base case : same content
	printf("%s\n", "Base Case, ft_strdup(\"likun\"):");
	dup = ft_strdup(src);
	printf("expected : [likun]\n");
	printf("actual   : [%s]\n", dup);
	printf("%s\n", "Base Case, strcmp(dup, src) == 0:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", strcmp(dup, src) == 0);
	printf("%s\n"," ");

	//the copy must be a different block of memory, not the same pointer
	printf("%s\n", "New Memory Case, dup != src:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", dup != src);
	printf("%s\n"," ");

	//the copy must be terminated, and exactly strlen(src) bytes long
	printf("%s\n", "Termination Case, strlen(dup):");
	printf("expected : %zu\n", strlen(src));
	printf("actual   : %zu\n", strlen(dup));
	printf("%s\n", "Termination Case, dup[strlen(src)] == '\\0':");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", dup[strlen(src)] == '\0');
	printf("%s\n"," ");

	//writing into the copy must not touch the original
	printf("%s\n", "Independence Case, dup[0] = 'X':");
	dup[0] = 'X';
	printf("expected : dup [Xikun]  src [likun]\n");
	printf("actual   : dup [%s]  src [%s]\n", dup, src);
	free(dup);
	printf("%s\n", "dup freed");
	printf("%s\n"," ");

	//empty string : still a valid, non NULL, freeable pointer
	printf("%s\n", "Empty String Case, ft_strdup(\"\") != NULL:");
	empty = ft_strdup("");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", empty != NULL);
	printf("%s\n", "Empty String Case, strlen(empty):");
	printf("%s\n", "expected : 0");
	printf("actual   : %zu\n", strlen(empty));
	free(empty);
	printf("%s\n", "empty freed");
	printf("%s\n"," ");

	//stops at the first '\0', nothing behind it is copied
	printf("%s\n", "Embedded '\\0' Case, ft_strdup(\"abc\\0def\"):");
	dup = ft_strdup("abc\0def");
	printf("expected : [abc] len 3\n");
	printf("actual   : [%s] len %zu\n", dup, strlen(dup));
	free(dup);
	printf("%s\n", "dup freed");
	printf("%s\n"," ");

}
