/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//subject prototype : c is a char, fd is an int, nothing is returned
void	ft_putchar_fd(char c, int fd);

int main(void)
{
//subject: outputs the character c to the given file descriptor
//subject: the only external function allowed is write
//printf is buffered, write is not : fflush before every call, or the
//output comes out in the wrong order
//to prove the fd argument is really used and not hardcoded to 1, run :
//./a.out 2>/dev/null     the fd 2 lines must then disappear

void tag(void)
{
	printf("%s", "actual   : ");
	fflush(stdout);
}


	//one plain character on fd 1
	printf("%s\n", "Base Case, ft_putchar_fd('A', 1):");
	printf("%s\n", "expected : A");
	tag();
	ft_putchar_fd('A', 1);
	printf("\n");
	printf("%s\n"," ");

	//a digit, to be sure nothing is converted
	printf("%s\n", "Digit Case, ft_putchar_fd('7', 1):");
	printf("%s\n", "expected : 7");
	tag();
	ft_putchar_fd('7', 1);
	printf("\n");
	printf("%s\n"," ");

	//a newline is a character like any other
	printf("%s\n", "Newline Case, ft_putchar_fd('\\n', 1):");
	printf("%s\n", "expected : an empty line below");
	tag();
	ft_putchar_fd('\n', 1);
	printf("%s\n"," ");

	//fd 2 : goes to stderr, disappears with 2>/dev/null
	printf("%s\n", "Fd 2 Case, ft_putchar_fd('E', 2):");
	printf("%s\n", "expected : E");
	tag();
	ft_putchar_fd('E', 2);
	printf("\n");
	printf("%s\n"," ");

}
