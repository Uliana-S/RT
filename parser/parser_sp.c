#include "main_header.h"

void	add_front_obj(t_objects **lst, t_objects *new_obj)
{
	if (!*lst)
		*lst = new_obj;
	else
	{
		new_obj->next = *lst;
		*lst = new_obj;
	}
}

int	create_sphere(char **data, t_sphere *sp)
{
	char		**point;
	char		**diameter;
	char		**color_data;

	point = ft_split(data[1], ',');
	diameter = ft_split(data[2], '.');
	color_data = ft_split(data[3], ',');
	if (!point || !diameter || !color_data)
		return (free_memory_parser(point, diameter, color_data, 3));
	sp->radius = create_number(diameter) / 2;
	if (count_data(diameter) > 2 || check_int_number(diameter) == FALSE
		|| check_color(color_data) == FALSE
		|| create_struct_vec(point, &sp->center) == FALSE
		|| create_number(diameter) < 0.)
		return (free_memory_parser(point, diameter, color_data, 4));
	create_struct_color(color_data, &sp->color);
	return (free_memory_parser(point, diameter, color_data, 0));
}

int	parser_sp(char **data, t_objects **obj)
{
	t_objects	*figure;
	t_sphere	*new_sphere;

	if (count_data(data) != 4)
		return (error_processing1(9));
	figure = malloc(sizeof(t_objects));
	new_sphere = malloc(sizeof(t_sphere));
	if (new_sphere && figure)
	{
		if (create_sphere(data, new_sphere) == FALSE)
			return (FALSE);
		figure->identifier = SPHERE_ID;
		figure->new_obj = new_sphere;
		figure->next = NULL;
		add_front_obj(obj, figure);
		return (TRUE);
	}
	return (error_processing1(3));
}
