/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:35:05 by us                #+#    #+#             */
/*   Updated: 2026/07/26 02:54:25 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int ft_atoi(const char *str) 
{ 
	int	sign = 1, n = 0; 
	
	while (*str == ' ' || *str == '\t' || *str == '\n') 
		str++; 
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9') 
	{
		n = n * 10 + (*str++ - '0');
	}	
	return sign * n; 
}
/*
int             main(void)
{
        char a[] = "  -523 4AAAgreghrsth";//-5234
        printf("%d\n",ft_atoi(a));
}
*/
