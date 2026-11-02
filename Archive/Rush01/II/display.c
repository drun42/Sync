#include "rush01.h"

void	print_grid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < data->size)
		{
			printf("%d", data->grid[i][j]);
			if (j < data->size - 1)
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_error(void)
{
	printf("Error\n");
}
