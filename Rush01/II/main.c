#include "rush01.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	if (!parse_input(argv[1], &data))
	{
		print_error();
		return (1);
	}
	if (!solve(&data, 0, 0))
	{
		print_error();
		return (1);
	}
	print_grid(&data);
	return (0);
}
