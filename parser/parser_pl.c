#include "main_header.h"

int	create_plane(char **data, t_plane *pl)
{
	char		**point;
	char		**normal;
	char		**color_data;

	point = ft_split(data[1], ',');
	normal = ft_split(data[2], ',');
	color_data = ft_split(data[3], ',');
	if (!point || !normal || !color_data)
		return (free_memory_parser(point, normal, color_data, 3));
	if (create_struct_vec(point, &pl->coordinates) == FALSE
		||create_struct_vec(normal, &pl->normal) == FALSE
		|| check_color(color_data) == FALSE
		|| check_normal(&pl->normal) == FALSE)
		return (free_memory_parser(point, normal, color_data, 4));
	create_struct_color(color_data, &pl->color);
	normalization_vec(&pl->normal);
	return (free_memory_parser(point, normal, color_data, 0));
}

int	parser_pl(char **data, t_objects **obj)
{
	t_objects	*figure;
	t_plane		*new_plane;

	if (count_data(data) != 4)
		return (error_processing1(9));
	figure = malloc(sizeof(t_objects));
	new_plane = malloc(sizeof(t_plane));
	if (new_plane && obj)
	{
		if (create_plane(data, new_plane) == FALSE)
			return (FALSE);
		figure->identifier = PLANE_ID;
		figure->new_obj = new_plane;
		figure->next = NULL;
		add_front_obj(obj, figure);
		return (TRUE);
	}
	return (error_processing1(3));
}
