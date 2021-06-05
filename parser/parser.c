#include "main_header.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

int	count_data(char **data)
{
	int		i;

	i = 0;
	while (data[i] != 0)
		i++;
	return (i);
}

int	parser_obj(char **data_line, t_objects **objs)
{
	if (data_line[0][0] == 's' && data_line[0][1] == 'p')
		return (parser_sp(data_line, objs));
	if (data_line[0][0] == 'p' && data_line[0][1] == 'l')
		return (parser_pl(data_line, objs));
	if (data_line[0][0] == 's' && data_line[0][1] == 'q')
		return (parser_sq(data_line, objs));
	if (data_line[0][0] == 'c' && data_line[0][1] == 'y')
		return (parser_cy(data_line, objs));
	if (data_line[0][0] == 't' && data_line[0][1] == 'r')
		return (parser_tr(data_line, objs));
	return (error_processing1(10));
}

int	parser(char **data_line, t_all_data *data)
{
	if (data_line == NULL)
		return (error_processing1(4));
	if (ft_strlen(data_line[0]) == 2)
		return (parser_obj(data_line, &data->scene->objects));
	if ((ft_strlen(data_line[0]) == 1 && data_line[0][0] == 'R')
		|| (ft_strlen(data_line[0]) == 1 && data_line[0][0] == 'A'))
		return (parser_r_a(data_line, data->base, data->mlx));
	if (ft_strlen(data_line[0]) == 1 && data_line[0][0] == 'c')
		return (parser_c(data_line, &data->cam));
	if (ft_strlen(data_line[0]) == 1 && data_line[0][0] == 'l')
		return (parser_l(data_line, &data->scene->light));
	return (error_processing1(10));
}
