#include "main_header.h"

int	parser_r(char **data, t_base_info *base, void *mlx_ptr)
{
	t_resolution	*new;
	int				real_h;
	int				real_w;

	if (count_data(data) != 3)
		return (error_processing1(9));
	new = malloc(sizeof(t_resolution));
	if (new)
	{
		mlx_get_screen_size(mlx_ptr, &real_w, &real_h);
		if (check_pos_int(data[1]) == FALSE
			|| check_pos_int(data[2]) == FALSE)
			return (error_processing1(4));
		new->width = ft_atoi(data[1]);
		new->height = ft_atoi(data[2]);
		if (new->height <= 0 || new->width <= 0)
			return (error_processing1(9));
		if (new->height > real_h)
			new->height = real_h;
		if (new->width > real_w)
			new->width = real_w;
		base->resolution = new;
		return (TRUE);
	}
	return (error_processing1(3));
}

int	parser_a(char **data, t_base_info *base)
{
	t_ambient		*new_data;
	char			**color_data;
	char			**number;

	if (count_data(data) != 3)
		return (error_processing1(9));
	new_data = malloc(sizeof(t_ambient));
	if (new_data)
	{
		number = ft_split(data[1], '.');
		color_data = ft_split(data[2], ',');
		if (!number || !color_data)
			return (free_memory_parser(number, color_data, NULL, 3));
		if (count_data(number) != 2 || check_color(color_data) == FALSE
			|| check_int_number(number) == FALSE)
			return (free_memory_parser(number, color_data, NULL, 4));
		new_data->ratio = create_number(number);
		if (new_data->ratio > 1.0 || new_data->ratio < 0)
			return (free_memory_parser(number, color_data, NULL, 4));
		create_struct_color(color_data, &new_data->color);
		base->ambient = new_data;
		return (free_memory_parser(number, color_data, NULL, 0));
	}
	return (error_processing1(3));
}

int	parser_r_a(char **data_line, t_base_info *base, void *mlx_ptr)
{
	if (data_line[0][0] == 'R' && base->resolution == NULL)
		return (parser_r(data_line, base, mlx_ptr));
	if (data_line[0][0] == 'A' && base->ambient == NULL)
		return (parser_a(data_line, base));
	return (error_processing1(8));
}
