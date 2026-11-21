/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : returns char *, c is passed as an int
char	*ft_strrchr(const char *s, int c);

int main(void)
{
//man: returns a pointer to the LAST occurrence of the character c in s
//man: c is converted to char, so only its low byte matters
//man: the terminating '\0' IS considered part of the string
//man: returns NULL if the character is not found
//expected is produced by libc strrchr
char	*s;
char	*e;

s = "hello world";
e = "";


void show(char *label, char *base, char *p)
{
	if (p == NULL)
		printf("%s : NULL\n", label);
	else
		printf("%s : offset %d [%s]\n", label, (int)(p - base), p);
}


void both(char *base, int c)
{
	show("expected", base, strrchr(base, c));
	show("actual  ", base, ft_strrchr(base, c));
}


	//last occurrence, not the first one
	printf("%s\n", "Base Case, strrchr(\"hello world\", 'o'):");
	both(s, 'o');
	printf("%s\n"," ");

	//two occurrences next to each other
	printf("%s\n", "Repeated Case, 'l':");
	both(s, 'l');
	printf("%s\n"," ");

	//only one occurrence, and it is the first byte
	printf("%s\n", "First Byte Case, 'h':");
	both(s, 'h');
	printf("%s\n"," ");

	//not in the string at all
	printf("%s\n", "Not Found Case, 'z':");
	both(s, 'z');
	printf("%s\n"," ");

	//the terminator itself must be findable
	printf("%s\n", "Terminator Case, '\\0':");
	both(s, '\0');
	printf("%s\n"," ");

	//c is converted to char : 'o' + 256 has the same low byte as 'o'
	printf("%s\n", "Conversion Case, 'o' + 256:");
	both(s, 'o' + 256);
	printf("%s\n"," ");

	//empty string
	printf("%s\n", "Empty String Case, '\\0' in \"\":");
	both(e, '\0');
	printf("%s\n", "Empty String Case, 'a' in \"\":");
	both(e, 'a');
	printf("%s\n"," ");

}
