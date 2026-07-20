/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmagroun <mmagroun@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:33:26 by mmagroun          #+#    #+#             */
/*   Updated: 2026/07/19 22:29:56 by mmagroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_row_right(int grid[4][4], int row, int target);
int     check_row_left(int grid[4][4], int row, int target);
int     check_col_down(int grid[4][4], int col, int target);
int     check_col_up(int grid[4][4], int col, int target);
int     double_check(int grid[4][4], int row, int col, int num);

int	check_line_views(int grid[4][4], int row, int col, int input[16])
{
	if (col == 3)
	{
		if (check_row_left(grid, row, input[8 + row]) == 0
			|| check_row_right(grid, row, input[12 + row]) == 0)
			return (0);
	}
	return (1);
}

int	check_col_views(int grid[4][4], int row, int col, int input[16])
{
	if (row == 3)
	{
		if (check_col_up(grid, col, input[col]) == 0
			|| check_col_down(grid, col, input[4 + col]) == 0)
			return (0);
	}
	return (1);
}

int	is_safe(int grid[4][4], int row, int col, int input[16])
{
	int	num;

	num = grid[row][col];
	grid[row][col] = 0;
	if (double_check(grid, row, col, num) == 0)
		return (0);
	grid[row][col] = num;
	if (check_line_views(grid, row, col, input) == 0)
	{
		grid[row][col] = 0;
		return (0);
	}
	if (check_col_views(grid, row, col, input) == 0)
	{
		grid[row][col] = 0;
		return (0);
	}
	return (1);
}

int	backtrack(int grid[4][4], int row, int col, int input[16])
{
	int	num;

	if (row == 4)
		return (1);
	if (col == 4)
		return (backtrack(grid, row + 1, 0, input));
	num = 1;
	while (num <= 4)
	{
		grid[row][col] = num;
		if (is_safe(grid, row, col, input) == 1)
		{
			if (backtrack(grid, row, col + 1, input) == 1)
				return (1);
		}
		num++;
	}
	grid[row][col] = 0;
	return (0);
}
