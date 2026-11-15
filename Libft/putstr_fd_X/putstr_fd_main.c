/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//subject prototype : s is a char *, NOT const
void	ft_putstr_fd(char *s, int fd);

int main(void)
{
//subject: outputs the string s to the given file descriptor
//subject: the only external function allowed is write
//no newline is added : that is what ft_putendl_fd is for
//the '\0' itself is not written
//printf is buffered, write is not : fflush before every call
//to prove the fd argument is really used, run : ./a.out 2>/dev/null
char	s [] = "hello";
char	e [] = "";

void tag(void)
{
	printf("%s", "actual   : ");
	fflush(stdout);
}


	//base case, no newline at the end
	printf("%s\n", "Base Case, ft_putstr_fd(\"hello\", 1):");
	printf("%s\n", "expected : hello");
	tag();
	ft_putstr_fd(s, 1);
	printf("\n");
	printf("%s\n"," ");

	//no newline is added : two calls stay on the same line
	printf("%s\n", "No Newline Case, two calls in a row:");
	printf("%s\n", "expected : hellohello");
	tag();
	ft_putstr_fd(s, 1);
	ft_putstr_fd(s, 1);
	printf("\n");
	printf("%s\n"," ");

	//empty string : nothing is written, nothing crashes
	printf("%s\n", "Empty String Case, ft_putstr_fd(\"\", 1):");
	printf("%s\n", "expected : nothing after the colon");
	tag();
	ft_putstr_fd(e, 1);
	printf("\n");
	printf("%s\n"," ");

	//a string holding spaces and digits
	printf("%s\n", "Mixed Case, ft_putstr_fd(\"42 Nice\", 1):");
	printf("%s\n", "expected : 42 Nice");
	tag();
	ft_putstr_fd("42 Nice", 1);
	printf("\n");
	printf("%s\n"," ");

	//fd 2 : disappears with 2>/dev/null
	printf("%s\n", "Fd 2 Case, ft_putstr_fd(\"hello\", 2):");
	printf("%s\n", "expected : hello");
	tag();
	ft_putstr_fd(s, 2);
	printf("\n");
	printf("%s\n"," ");

}
