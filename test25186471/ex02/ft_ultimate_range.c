/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbogucki <nbogucki@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:43:52 by nbogucki          #+#    #+#             */
/*   Updated: 2026/07/24 11:28:00 by nbogucki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	*range = NULL;
	if (min >= max)
		return (0);
	size = max - min;
	if (size < 0)
		size *= -1;
	*range = malloc(size * 4);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
		(*range)[i++] = min++;
	return (size);
}

/*
int	main(void)
{
	int *p_arr;
	int size;
	int y;
	int aor[15][2] = {
		{-2147483648, 2147483647},
		{-10,   0},
		{-20,  -5},
		{  5,  20},
		{ -1,  10},
		{  0,  10},
		{  1,  10},
		{ -5,  10},
		{ -5,   0},
		{ -5,  -2},
		{  0,   0},
		{ 99,   0},
		{  0,   1},
		{-10,  10},
		{ 10, -10}
	};
	for (int i = 0; i < 15; i++) {
		//printf("adr before %p\n", p_arr);
		size = ft_ultimate_range(&p_arr, aor[i][0], aor[i][1]);
		printf("for [%d:%d]", aor[i][0], aor[i][1]);
		printf(" (size: %d)", size);
		printf(" (ptr: %p) \t", p_arr);
		if (p_arr != NULL)
		{
			if (aor[i][0] < -21000)
			{
				printf("big boi too big for the screen");
			}
			else
			{
				y = aor[i][0];
				while(y < aor[i][1])
					printf(" %d", p_arr[y++ - aor[i][0]]);
			}
		}
		printf("\n");
	}
	return (0);
}
*/
