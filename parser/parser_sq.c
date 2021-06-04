#include "main_header.h"

int	create_square(char **data, t_square *sq)
{
	char		**point;
	char		**normal;
	char		**color_data;
	char		**size;

	point = ft_split(data[1], ',');
	normal = ft_split(data[2], ',');
	size = ft_split(data[3], '.');
	color_data = ft_split(data[4], ',');
	if (!point || !normal || !size || !color_data
		|| create_struct_vec(point, &sq->center) == FALSE
		|| create_struct_vec(normal, &sq->normal) == FALSE
		|| check_color(color_data) == FALSE
		|| check_double(data[3]) == FALSE
		|| check_normal(&sq->normal) == FALSE)
	{
		free_memory_parser(color_data, NULL, NULL, 0);
		return (free_memory_parser(point, normal, size, 4));
	}
	sq->size = create_number(size);
	create_struct_color(color_data, &sq->color);
	free_memory_parser(color_data, NULL, NULL, 0);
	return (free_memory_parser(point, normal, size, 0));
}

int	parser_sq(char **data, t_objects **obj)
{
	t_objects	*figure;
	t_square	*new_square;

	if (count_data(data) != 5)
		return (error_processing1(9));
	figure = malloc(sizeof(t_objects));
	new_square = malloc(sizeof(t_square));
	if (new_square && obj)
	{
		if (create_square(data, new_square) == FALSE)
			return (FALSE);
		figure->identifier = SQUARE_ID;
		figure->new_obj = new_square;
		figure->next = NULL;
		normalization_vec(&new_square->normal);
		add_front_obj(obj, figure);
		return (TRUE);
	}
	return (error_processing1(3));
}
