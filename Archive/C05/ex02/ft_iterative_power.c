/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 03:18:16 by us                #+#    #+#             */
/*   Updated: 2026/07/27 03:46:52 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	p;
	int	result;

	p = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	while (p != power)
	{
		result = result * nb;
		p++;
	}
	return (result);
}
/*
int main (void)
{
	printf("%d\n", ft_iterative_power(1, 0));
	printf("%d\n", ft_iterative_power(0, 0));
	printf("%d\n", ft_iterative_power(0, 1));
	printf("%d\n", ft_iterative_power(-2, 2));
	printf("%d\n", ft_iterative_power(2, -2));
	printf("%d\n", ft_iterative_power(2, 2));
	printf("%d", ft_iterative_power(2, 2));
	printf("%d", ft_iterative_power(2, 2));
	printf("%d", ft_iterative_power(2, 2));
}
*/
