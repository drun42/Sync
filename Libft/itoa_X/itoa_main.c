/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//subject prototype : takes an int, returns a malloc'd string
char	*ft_itoa(int n);

int main(void)
{
//subject: allocates with malloc and returns the string of the integer n
//subject: negative numbers must be handled
//subject: returns NULL if the allocation fails
//the trap is INT_MIN : -n overflows, it cannot be made positive first
//run it under valgrind : valgrind --leak-check=full ./a.out
char	*r;


void show(char *label, char *p)
{
	if (p == NULL)
		printf("%s : NULL\n", label);
	else
		printf("%s : [%s]\n", label, p);
}


void both(char *expected, int n)
{
	printf("expected : [%s]\n", expected);
	r = ft_itoa(n);
	show("actual  ", r);
	free(r);
}


	//zero : one digit, no sign
	printf("%s\n", "Zero Case, ft_itoa(0):");
	both("0", 0);
	printf("%s\n"," ");

	//plain positive, no '+' sign in the output
	printf("%s\n", "Positive Case, ft_itoa(42):");
	both("42", 42);
	printf("%s\n"," ");

	//single digit
	printf("%s\n", "One Digit Case, ft_itoa(7):");
	both("7", 7);
	printf("%s\n"," ");

	//negative
	printf("%s\n", "Negative Case, ft_itoa(-42):");
	both("-42", -42);
	printf("%s\n"," ");

	//single negative digit
	printf("%s\n", "Negative One Digit Case, ft_itoa(-7):");
	both("-7", -7);
	printf("%s\n"," ");

	//a power of ten, to catch an off by one in the digit count
	printf("%s\n", "Power Of Ten Case, ft_itoa(1000):");
	both("1000", 1000);
	printf("%s\n"," ");

	//the upper limit
	printf("%s\n", "INT_MAX Case, ft_itoa(2147483647):");
	both("2147483647", INT_MAX);
	printf("%s\n"," ");

	//the lower limit : -n does NOT fit in an int
	printf("%s\n", "INT_MIN Case, ft_itoa(-2147483648):");
	both("-2147483648", INT_MIN);
	printf("%s\n"," ");

}
