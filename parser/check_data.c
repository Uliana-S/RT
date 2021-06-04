#include "main_header.h"

int	check_normal(t_vector *normal)
{
	if (fabs(normal->x) > 1
		|| fabs(normal->y) > 1
		|| fabs(normal->z) > 1)
		return (FALSE);
	return (TRUE);
}

int	check_double(char *str)
{
	char	**number;

	number = ft_split(str, '.');
	if ((count_data(number) == 1 && check_pos_int(number[0]))
		|| (count_data(number) == 2 && check_pos_int(number[0])
			&& check_pos_int(number[1])))
	{
		free_str_data(number);
		return (TRUE);
	}
	free_str_data(number);
	return (FALSE);
}

int	check_pos_int(char *data)
{
	int		i;

	i = 0;
	while (data[i] != '\0')
	{
		if (data[i] < '0' || data[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_int_number(char **data)
{
	int		i;

	i = 0;
	while (data[i] != NULL)
	{
		if (check_pos_int(data[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_color(char **color)
{
	int		i;
	int		j;

	i = 0;
	if (count_data(color) != 3)
		return (FALSE);
	while (color[i] != NULL)
	{
		if (ft_strlen(color[i]) > 3)
			return (FALSE);
		j = 0;
		while (color[i][j] != '\0')
		{
			if (color[i][j] < '0' || color[i][j] > '9')
				return (FALSE);
			j++;
		}
		if (ft_atoi(color[i]) > 255)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
