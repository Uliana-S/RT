#include "main_header.h"

double	create_number(char **numbers)
{
	int		len;
	int		flag;
	double	whole_part;

	flag = 1;
	whole_part = ft_atoi(numbers[0]);
	if (count_data(numbers) == 1)
		return (whole_part);
	len = ft_strlen(numbers[1]);
	if (numbers[0][0] == '-')
		flag = -1;
	return (whole_part + flag * (ft_atoi(numbers[1]) / (pow(10, len))));
}

void	create_struct_color(char **data_color, t_color *new_col)
{
	new_col->r = ft_atoi(data_color[0]);
	new_col->g = ft_atoi(data_color[1]);
	new_col->b = ft_atoi(data_color[2]);
}

int	check_negative_int(char *data)
{
	int		i;

	i = 0;
	if (data[0] == '-')
		i = 1;
	while (data[i] != '\0')
	{
		if (data[i] < '0' || data[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	create_vec_in_parser(t_vector *new_vec, char **number, int i,
			int count)
{
	if (i == 0 && count == 1)
		new_vec->x = ft_atoi(number[0]);
	else if (i == 0 && count == 2)
		new_vec->x = create_number(number);
	else if (i == 1 && count == 1)
		new_vec->y = ft_atoi(number[0]);
	else if (i == 1 && count == 2)
		new_vec->y = create_number(number);
	else if (i == 2 && count == 1)
		new_vec->z = ft_atoi(number[0]);
	else if (i == 2 && count == 2)
		new_vec->z = create_number(number);
}

int	create_struct_vec(char **data_vec, t_vector *new_vec)
{
	int		i;
	char	**number;
	int		count;

	i = 0;
	if (count_data(data_vec) != 3 || data_vec[0][0] == '.'
		|| data_vec[1][0] == '.' || data_vec[2][0] == '.')
		return (FALSE);
	while (i < 3)
	{
		number = ft_split(data_vec[i], '.');
		count = count_data(number);
		if (count > 2 || (count == 1
			&& check_negative_int(number[0]) == FALSE)
			|| (count == 2 && (check_negative_int(number[0]) == FALSE
			|| check_negative_int(number[1]) == FALSE)))
		{
			free_str_data(number);
			return (FALSE);
		}
		create_vec_in_parser(new_vec, number, i, count);
		free_str_data(number);
		i++;
	}
	return (TRUE);
}
