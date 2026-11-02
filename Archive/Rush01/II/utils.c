#include "rush01.h"

/*
** Counts how many boxes are visible when looking along "arr" starting
** at index "start" and moving by "step" each time (step is +1 to scan
** left-to-right/top-to-bottom, -1 for the opposite direction).
** A box is visible if it is taller than every box seen before it.
*/
int	count_visible(int *arr, int size, int step, int start)
{
	int	i;
	int	max;
	int	count;
	int	idx;

	i = 0;
	max = 0;
	count = 0;
	idx = start;
	while (i < size)
	{
		if (arr[idx] > max)
		{
			max = arr[idx];
			count++;
		}
		idx += step;
		i++;
	}
	return (count);
}
