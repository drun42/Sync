#include "rush01.h"

/*
** Once a full row has been placed, checks that it satisfies its
** left and right visibility clues.
*/
static int	check_row(t_data *data, int row)
{
	int	fwd;
	int	bwd;

	fwd = count_visible(data->grid[row], data->size, 1, 0);
	bwd = count_visible(data->grid[row], data->size, -1, data->size - 1);
	return (fwd == data->left[row] && bwd == data->right[row]);
}

/*
** Once a full column has been placed (i.e. the last row was just
** filled), checks that it satisfies its top and bottom clues.
*/
static int	check_col(t_data *data, int col)
{
	int	column[MAX_SIZE];
	int	i;
	int	fwd;
	int	bwd;

	i = 0;
	while (i < data->size)
	{
		column[i] = data->grid[i][col];
		i++;
	}
	fwd = count_visible(column, data->size, 1, 0);
	bwd = count_visible(column, data->size, -1, data->size - 1);
	return (fwd == data->top[col] && bwd == data->bottom[col]);
}

/*
** Cheap early pruning: checks the left-view clue against only the
** cells of "row" placed so far ([0..col]). The visible count can only
** grow as more cells are added, and each remaining cell can add at
** most one more visible box, so both bounds below are safe (sound)
** necessary conditions for the row to end up valid.
*/
static int	row_left_ok(t_data *data, int row, int col)
{
	int	visible;
	int	remaining;

	visible = count_visible(data->grid[row], col + 1, 1, 0);
	remaining = data->size - (col + 1);
	if (visible > data->left[row])
		return (0);
	if (visible + remaining < data->left[row])
		return (0);
	return (1);
}

/*
** Same idea as row_left_ok(), but for a column's top-view clue,
** using only the rows placed so far ([0..row]).
*/
static int	col_top_ok(t_data *data, int row, int col)
{
	int	column[MAX_SIZE];
	int	i;
	int	visible;
	int	remaining;

	i = 0;
	while (i <= row)
	{
		column[i] = data->grid[i][col];
		i++;
	}
	visible = count_visible(column, row + 1, 1, 0);
	remaining = data->size - (row + 1);
	if (visible > data->top[col])
		return (0);
	if (visible + remaining < data->top[col])
		return (0);
	return (1);
}

/*
** Computes the coordinates of the cell that follows (row, col) when
** filling the grid left-to-right, top-to-bottom.
*/
static void	next_cell(t_data *data, int row, int col, int *nr, int *nc)
{
	if (col == data->size - 1)
	{
		*nr = row + 1;
		*nc = 0;
	}
	else
	{
		*nr = row;
		*nc = col + 1;
	}
}

/*
** Recursive backtracking: tries every still-available height for the
** current cell, pruning as soon as a completed row or column breaks
** one of its clues, and stops at the very first full solution found.
*/
int	solve(t_data *data, int row, int col)
{
	int	nr;
	int	nc;
	int	v;
	int	ok;

	if (row == data->size)
		return (1);
	next_cell(data, row, col, &nr, &nc);
	v = 1;
	while (v <= data->size)
	{
		if (!data->used_row[row][v] && !data->used_col[col][v])
		{
			data->grid[row][col] = v;
			data->used_row[row][v] = 1;
			data->used_col[col][v] = 1;
			ok = row_left_ok(data, row, col) && col_top_ok(data, row, col);
			if (ok && col == data->size - 1)
				ok = check_row(data, row);
			if (ok && row == data->size - 1)
				ok = check_col(data, col);
			if (ok && solve(data, nr, nc))
				return (1);
			data->used_row[row][v] = 0;
			data->used_col[col][v] = 0;
			data->grid[row][col] = 0;
		}
		v++;
	}
	return (0);
}
