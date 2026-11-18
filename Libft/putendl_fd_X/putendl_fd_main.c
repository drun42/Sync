/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//subject prototype : s is a char *, NOT const
void	ft_putendl_fd(char *s, int fd);

int main(void)
{
//subject: outputs the string s to the given file descriptor,
//subject: FOLLOWED BY A NEWLINE
//that trailing '\n' is the only difference with ft_putstr_fd
//printf is buffered, write is not : fflush before every call
//to prove the fd argument is really used, run : ./a.out 2>/dev/null
char	s [] = "hello";
char	e [] = "";

void tag(void)
{
	printf("%s", "actual   : ");
	fflush(stdout);
}


	//base case : the newline is part of the output, no extra printf below
	printf("%s\n", "Base Case, ft_putendl_fd(\"hello\", 1):");
	printf("%s\n", "expected : hello");
	tag();
	ft_putendl_fd(s, 1);
	printf("%s\n"," ");

	//two calls must land on two separate lines
	printf("%s\n", "Two Calls Case, hello then hello:");
	printf("%s\n", "expected : hello on one line, hello on the next");
	tag();
	ft_putendl_fd(s, 1);
	ft_putendl_fd(s, 1);
	printf("%s\n"," ");

	//empty string : only the newline is written
	printf("%s\n", "Empty String Case, ft_putendl_fd(\"\", 1):");
	printf("%s\n", "expected : an empty line below");
	tag();
	ft_putendl_fd(e, 1);
	printf("%s\n"," ");

	//fd 2 : disappears with 2>/dev/null
	printf("%s\n", "Fd 2 Case, ft_putendl_fd(\"hello\", 2):");
	printf("%s\n", "expected : hello");
	tag();
	ft_putendl_fd(s, 2);
	printf("%s\n"," ");

}
