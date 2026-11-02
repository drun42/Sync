/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 06:36:22 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/27 07:05:29 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//• Write a program that displays its given arguments sorted in ASCII order.
//• The program should display all arguments except argv[0].
//• Each argument should be printed on a new line.

#include <unistd.h>

void sort(char *x1, char *x2)
{
	char temp;

	if (*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
	}
}
int	main (int ac, char **av)
{
	int	c;
	int	i;
	int	j;
	
	c = ac;
	while (c > 1)
	{	
		i = 1;
		while (av[i + 1])
		sort(av[i], av[i + 1]);
	}
	i = 0;
	while (av[i])
	{
		write(1, &av[i], 1);
		i++;
	}	

}
