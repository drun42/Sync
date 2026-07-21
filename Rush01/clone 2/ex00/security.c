/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmagroun <mmagroun@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:36:51 by mmagroun          #+#    #+#             */
/*   Updated: 2026/07/19 20:55:38 by mmagroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	double_check(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
/*
1 if num is unique in its row and column
0 if a duplicate is found
*/
int	check_col_up(int grid[4][4], int col, int target)
{
	int	i;
	int	max_height;
	int	visible;

	i = 0;
	visible = 0;
	max_height = 0;
	while (i < 4)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			visible++;
		}
		i++;
	}
	if (visible == target)
		return (1);
	return (0);
}
/*
1 if the count of visible buildings equals target
0 otherwise
*/
int	check_col_down(int grid[4][4], int col, int target)
{
	int	i;
	int	max_height;
	int	visible;

	i = 3;
	visible = 0;
	max_height = 0;
	while (i >= 0)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			visible++;
		}
		i--;
	}
	if (visible == target)
		return (1);
	return (0);
}
/*
1 if the count of visible buildings equals target
0 otherwise
*/
int	check_row_left(int grid[4][4], int row, int target)
{
	int	i;
	int	max_height;
	int	visible;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] > max_height)
		{
			max_height = grid[row][i];
			visible++;
		}
		i++;
	}
	if (visible == target)
		return (1);
	return (0);
}

int	check_row_right(int grid[4][4], int row, int target)
{
	int	i;
	int	max_height;
	int	visible;

	i = 3;
	while (i >= 0)
	{
		if (grid[row][i] > max_height)
		{
			max_height = grid[row][i];
			visible++;
		}
		i--;
	}
	if (visible == target)
		return (1);
	return (0);
}
