#ifndef RUSH01_H
# define RUSH01_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

# define MAX_SIZE 9

typedef struct s_data
{
	int	size;
	int	top[MAX_SIZE];
	int	bottom[MAX_SIZE];
	int	left[MAX_SIZE];
	int	right[MAX_SIZE];
	int	grid[MAX_SIZE][MAX_SIZE];
	int	used_row[MAX_SIZE][MAX_SIZE + 1];
	int	used_col[MAX_SIZE][MAX_SIZE + 1];
}	t_data;

/* parsing.c */
int		parse_input(const char *str, t_data *data);

/* solver.c */
int		solve(t_data *data, int row, int col);

/* display.c */
void	print_grid(t_data *data);
void	print_error(void);

/* utils.c */
int		count_visible(int *arr, int size, int step, int start);

#endif
