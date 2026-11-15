/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

//subject prototype : n is an int, nothing is returned
void	ft_putnbr_fd(int n, int fd);

int main(void)
{
//subject: outputs the integer n to the given file descriptor
//subject: the only external function allowed is write
//no newline is added, and no '+' sign for positive numbers
//the trap is INT_MIN : -n overflows, it cannot be made positive first
//printf is buffered, write is not : fflush before every call
//to prove the fd argument is really used, run : ./a.out 2>/dev/null

void tag(void)
{
	printf("%s", "actual   : ");
	fflush(stdout);
}


	//zero
	printf("%s\n", "Zero Case, ft_putnbr_fd(0, 1):");
	printf("%s\n", "expected : 0");
	tag();
	ft_putnbr_fd(0, 1);
	printf("\n");
	printf("%s\n"," ");

	//plain positive, no '+' in front
	printf("%s\n", "Positive Case, ft_putnbr_fd(42, 1):");
	printf("%s\n", "expected : 42");
	tag();
	ft_putnbr_fd(42, 1);
	printf("\n");
	printf("%s\n"," ");

	//single digit
	printf("%s\n", "One Digit Case, ft_putnbr_fd(7, 1):");
	printf("%s\n", "expected : 7");
	tag();
	ft_putnbr_fd(7, 1);
	printf("\n");
	printf("%s\n"," ");

	//negative
	printf("%s\n", "Negative Case, ft_putnbr_fd(-42, 1):");
	printf("%s\n", "expected : -42");
	tag();
	ft_putnbr_fd(-42, 1);
	printf("\n");
	printf("%s\n"," ");

	//a power of ten, to catch a wrong digit count
	printf("%s\n", "Power Of Ten Case, ft_putnbr_fd(1000, 1):");
	printf("%s\n", "expected : 1000");
	tag();
	ft_putnbr_fd(1000, 1);
	printf("\n");
	printf("%s\n"," ");

	//the upper limit
	printf("%s\n", "INT_MAX Case, ft_putnbr_fd(2147483647, 1):");
	printf("%s\n", "expected : 2147483647");
	tag();
	ft_putnbr_fd(INT_MAX, 1);
	printf("\n");
	printf("%s\n"," ");

	//the lower limit : -n does NOT fit in an int
	printf("%s\n", "INT_MIN Case, ft_putnbr_fd(-2147483648, 1):");
	printf("%s\n", "expected : -2147483648");
	tag();
	ft_putnbr_fd(INT_MIN, 1);
	printf("\n");
	printf("%s\n"," ");

	//no newline is added : two calls stay on the same line
	printf("%s\n", "No Newline Case, 12 then 34:");
	printf("%s\n", "expected : 1234");
	tag();
	ft_putnbr_fd(12, 1);
	ft_putnbr_fd(34, 1);
	printf("\n");
	printf("%s\n"," ");

	//fd 2 : disappears with 2>/dev/null
	printf("%s\n", "Fd 2 Case, ft_putnbr_fd(42, 2):");
	printf("%s\n", "expected : 42");
	tag();
	ft_putnbr_fd(42, 2);
	printf("\n");
	printf("%s\n"," ");

}
