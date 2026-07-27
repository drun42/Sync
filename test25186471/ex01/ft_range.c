/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbogucki <nbogucki@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:23:31 by nbogucki          #+#    #+#             */
/*   Updated: 2026/07/22 11:29:16 by nbogucki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include <stdio.h>

/**
	Norm should allow this comment
*/
int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*p_arr;

	p_arr = NULL;
	if (min >= max)
		return (p_arr);
	size = max - min;
	if (size < 0)
		size *= -1;
	p_arr = malloc(size * 4);
	i = 0;
	while (i < size)
		p_arr[i++] = min++;
	return (p_arr);
}
/*
int	main(void)
{
	int *p_arr;
	int aor[12][2] = {
		{5, 20},
		{-1, 10},
		{0, 10},
		{1, 10},
		{-5, 10},
		{-5, 0},
		{-5, -2},
		{0, 0},
		{99, 0},
		{0, 1},
		{-10, 10},
		{10, -10}
	};
	int y;
	for (int i = 0; i < 12; i++) {
		p_arr = ft_range(aor[i][0], aor[i][1]);
		if (p_arr == NULL)
		{
			printf("for [%d:%d]\t", aor[i][0], aor[i][1]);
			printf("(null pointer)");
		}
		else
		{
			printf("for [%d:%d]\t", aor[i][0], aor[i][1]);
			y = aor[i][0];
			while(y < aor[i][1])
			{
				printf(" %d", p_arr[y - aor[i][0]]);
				y++;
			}
		}
		printf("\n");
	}
	return (0);
}
*/
