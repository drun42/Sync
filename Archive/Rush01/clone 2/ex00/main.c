/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmagroun <mmagroun@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 20:48:23 by mmagroun          #+#    #+#             */
/*   Updated: 2026/07/19 21:12:11 by mmagroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		final_error(int argc, char **agv);
int		backtrack(int grid[4][4], int row, int col, int input[16]);
void	display_grid(int grid[4][4]);

void	fill_input(char *str, int input[16])
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= '4')
		{
			input[i] = *str - '0';
			i++;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	input[16];
	int	i;
	int	j;

	if (final_error(argc, argv) == 1)
		return (0);
	fill_input(argv[1], input);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
	}
	if (backtrack(grid, 0, 0, input) == 1)
		display_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
