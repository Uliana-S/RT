#include "main_header.h"

int	check_data_cy(char **height, char **diameter, char **color_data,
		t_cylinder *cy)
{
	if (check_color(color_data) == FALSE
		|| check_int_number(diameter) == FALSE
		|| check_int_number(height) == FALSE)
		return (FALSE);
	cy->radius = create_number(diameter) / 2;
	cy->height = create_number(height);
	create_struct_color(color_data, &cy->color);
	if (cy->height <= 0. || cy->radius <= 0.)
		return (FALSE);
	return (TRUE);
}

int	create_cylinder(char **data, t_cylinder *cy)
{
	char		**center;
	char		**direction;
	char		**color_data;
	char		**diameter;
	char		**height;

	center = ft_split(data[1], ',');
	direction = ft_split(data[2], ',');
	diameter = ft_split(data[3], '.');
	height = ft_split(data[4], '.');
	color_data = ft_split(data[5], ',');
	if (!center || !direction || !diameter || !color_data || !height
		|| create_struct_vec(center, &cy->center) == FALSE
		|| create_struct_vec(direction, &cy->dir) == FALSE
		|| check_normal(&cy->dir) == FALSE
		|| check_data_cy(height, diameter, color_data, cy) == FALSE)
	{
		free_memory_parser(diameter, height, NULL, 0);
		return (free_memory_parser(center, direction, color_data, 4));
	}
	free_memory_parser(diameter, height, NULL, 0);
	return (free_memory_parser(center, direction, color_data, 0));
}

int	parser_cy(char **data, t_objects **obj)
{
	t_objects	*figure;
	t_cylinder	*new_cylinder;

	if (count_data(data) != 6)
		return (error_processing1(9));
	figure = malloc(sizeof(t_objects));
	new_cylinder = malloc(sizeof(t_cylinder));
	if (new_cylinder && obj)
	{
		if (create_cylinder(data, new_cylinder) == FALSE)
			return (FALSE);
		figure->identifier = CYLINDER_ID;
		figure->new_obj = new_cylinder;
		figure->next = NULL;
		normalization_vec(&new_cylinder->dir);
		add_front_obj(obj, figure);
		return (TRUE);
	}
	return (error_processing1(3));
}
