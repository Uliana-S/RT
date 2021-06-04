#include "main_header.h"

void	add_front_light(t_all_light **lst, t_all_light *new_li)
{
	if (!*lst)
		*lst = new_li;
	else
	{
		new_li->next = *lst;
		*lst = new_li;
	}
}

int	create_light(char **data, t_light *li)
{
	char		**point;
	char		**bright;
	char		**color_data;

	point = ft_split(data[1], ',');
	bright = ft_split(data[2], '.');
	color_data = ft_split(data[3], ',');
	if (!point || !bright || !color_data)
		return (free_memory_parser(point, bright, color_data, 3));
	li->brightness = create_number(bright);
	if (count_data(bright) != 2 || check_int_number(bright) == FALSE
		|| check_color(color_data) == FALSE
		|| create_struct_vec(point, &li->coordinates) == FALSE
		|| li->brightness < 0 || li->brightness > 1)
		return (free_memory_parser(point, bright, color_data, 4));
	create_struct_color(color_data, &li->color);
	return (free_memory_parser(point, bright, color_data, 0));
}

int	parser_l(char **data, t_all_light **l)
{
	t_all_light	*new_data;
	t_light		*new_light;

	if (count_data(data) != 4)
		return (error_processing1(9));
	new_data = malloc(sizeof(t_all_light));
	new_light = malloc(sizeof(t_light));
	if (new_light && new_data)
	{
		if (create_light(data, new_light) == FALSE)
			return (FALSE);
		new_data->light = new_light;
		new_data->next = NULL;
		add_front_light(l, new_data);
		return (TRUE);
	}
	return (error_processing1(3));
}
