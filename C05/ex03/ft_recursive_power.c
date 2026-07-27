/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 04:14:54 by us                #+#    #+#             */
/*   Updated: 2026/07/27 04:50:18 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
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
}
*/
