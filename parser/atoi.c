#include "main_header.h"

double	ft_atoi(char *str)
{
	int		i;
	double	result;
	int		minus;

	i = 0;
	result = 0;
	minus = 1;
	while (str[i] && ((str[i] > 7 && str[i] < 14) || str[i] == 32))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = 10 * result + (str[i] - '0') * minus;
		i++;
		if (result < 0 && minus > 0)
			return (-1);
		else if (result > 0 && minus < 0)
			return (0);
	}
	return (result);
}
