/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 04:52:23 by us                #+#    #+#             */
/*   Updated: 2026/07/27 06:08:59 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_fibonacci(int index)
{	
	int	res;


	if (index < 0)
		return (-1);
	if (index == 1)
		return (1);
	if (index == 0)
		return (0);
	return (res = ft_fibonacci(index -1) + ft_fibonacci(index -2));
}
/*
int main (void)
{
	printf("%d",ft_fibonacci(4));
}
*/
