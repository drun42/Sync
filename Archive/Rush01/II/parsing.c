#include "rush01.h"

/*
** Reads the raw argument string and extracts up to (MAX_SIZE * 4)
** single-digit values. Any character that is not a digit, or any
** "number" longer than one digit (e.g. "12"), makes the input invalid.
** Returns the amount of values found, or -1 on invalid input.
*/
static int	tokenize(const char *str, int *values)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		if (!isdigit((unsigned char)str[i]) || count >= MAX_SIZE * 4)
			return (-1);
		values[count++] = str[i] - '0';
		i++;
		if (str[i] != ' ' && str[i] != '\0')
			return (-1);
	}
	return (count);
}

/*
** Splits the flat "values" array (top | bottom | left | right, each
** of length n) into the dedicated arrays of the t_data struct, making
** sure every clue is in the valid [1, n] range. Also resets the grid
** and the used-value trackers.
*/
static int	fill_data(t_data *data, int *values)
{
	int	*targets[4];
	int	n;
	int	i;
	int	j;

	n = data->size;
	targets[0] = data->top;
	targets[1] = data->bottom;
	targets[2] = data->left;
	targets[3] = data->right;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < n)
		{
			if (values[i * n + j] < 1 || values[i * n + j] > n)
				return (0);
			targets[i][j] = values[i * n + j];
			j++;
		}
		i++;
	}
	memset(data->grid, 0, sizeof(data->grid));
	memset(data->used_row, 0, sizeof(data->used_row));
	memset(data->used_col, 0, sizeof(data->used_col));
	return (1);
}

/*
** Entry point of the parsing module. The number of tokens must be a
** multiple of 4 (top/bottom/left/right clue groups) and the resulting
** grid size must be between 4 (mandatory) and 9 (bonus).
*/
int	parse_input(const char *str, t_data *data)
{
	int	values[MAX_SIZE * 4];
	int	count;

	count = tokenize(str, values);
	if (count < 16 || count % 4 != 0)
		return (0);
	data->size = count / 4;
	if (data->size < 4 || data->size > MAX_SIZE)
		return (0);
	return (fill_data(data, values));
}
