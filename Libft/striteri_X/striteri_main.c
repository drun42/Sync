/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//subject prototype : returns NOTHING, f receives the ADDRESS of the character
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

//adds the index to the character, in place, through the pointer
void	add_index(unsigned int i, char *c)
{
	*c = *c + i;
}

//ignores the index, only changes the character
void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int main(void)
{
//subject: applies f to every character of s, passing the INDEX as first
//subject: argument, and each character BY ADDRESS so f can modify it
//subject: there is no return value and nothing is allocated
//the string is changed IN PLACE : a string literal cannot be used here
char	a [] = "aaaa";
char	b [] = "hello 42";
char	e [] = "";

	//the index is added to each character, in place
	printf("%s\n", "Index Case, ft_striteri(\"aaaa\", add_index):");
	ft_striteri(a, add_index);
	printf("expected : [abcd]\n");
	printf("actual   : [%s]\n", a);
	printf("%s\n"," ");

	//a transformation that ignores the index
	printf("%s\n", "Transform Case, ft_striteri(\"hello 42\", to_upper):");
	ft_striteri(b, to_upper);
	printf("expected : [HELLO 42]\n");
	printf("actual   : [%s]\n", b);
	printf("%s\n"," ");

	//empty string : f is never called, nothing must crash
	printf("%s\n", "Empty String Case, ft_striteri(\"\", to_upper):");
	ft_striteri(e, to_upper);
	printf("expected : []\n");
	printf("actual   : [%s]\n", e);
	printf("%s\n"," ");

	//running it twice shows the index is used every time, not kept
	printf("%s\n", "Twice Case, ft_striteri(a, add_index) again:");
	ft_striteri(a, add_index);
	printf("expected : [aceg]\n");
	printf("actual   : [%s]\n", a);
	printf("%s\n"," ");

}
