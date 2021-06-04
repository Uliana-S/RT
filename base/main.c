#include "main_header.h"

int	main(int argc, char **argv)
{
	t_all_data	data;

	init_data(&data);
	if (data.scene == NULL || data.base == NULL)
		error_processing1(3);
	else if ((argc == 2 || argc == 3) && check_argv(argv, argc) != FALSE)
	{
		if (check_file(argv[1], &data) != FALSE)
		{
			if (argc == 2)
				window(&data);
			else
				save(&data);
		}
	}
	else if (argc != 2 && argc != 3)
		error_processing1(2);
	free_data(&data);
	return (0);
}
