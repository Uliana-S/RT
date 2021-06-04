#include "main_header.h"

int	create_triangle(char **data, t_triangle *tr)
{
	char		**point0;
	char		**point1;
	char		**point2;
	char		**color_data;

	point0 = ft_split(data[1], ',');
	point1 = ft_split(data[2], ',');
	point2 = ft_split(data[3], ',');
	color_data = ft_split(data[4], ',');
	if (!point0 || !point1 || !point2 || !color_data)
	{
		free_memory_parser(color_data, NULL, NULL, 0);
		return (free_memory_parser(point0, point1, point2, 0));
	}
	if (check_color(color_data) == FALSE
		|| create_struct_vec(point0, &tr->point0) == FALSE
		|| create_struct_vec(point1, &tr->point1) == FALSE
		|| create_struct_vec(point2, &tr->point2) == FALSE)
	{
		free_memory_parser(color_data, NULL, NULL, 0);
		return (free_memory_parser(point0, point1, point2, 4));
	}
	create_struct_color(color_data, &tr->color);
	free_memory_parser(color_data, NULL, NULL, 0);
	return (free_memory_parser(point0, point1, point2, 0));
}

int	parser_tr(char **data, t_objects **obj)
{
	t_objects	*figure;
	t_triangle	*new_triangle;

	if (count_data(data) != 5)
		return (error_processing1(9));
	figure = malloc(sizeof(t_objects));
	new_triangle = malloc(sizeof(t_triangle));
	if (new_triangle && obj)
	{
		if (create_triangle(data, new_triangle) == FALSE)
			return (FALSE);
		figure->identifier = TRIANGLE_ID;
		figure->new_obj = new_triangle;
		figure->next = NULL;
		add_front_obj(obj, figure);
		return (TRUE);
	}
	return (error_processing1(3));
}
