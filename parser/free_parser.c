#include "main_header.h"

void	free_str_data(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	free_memory_parser(char **str1, char **str2, char **str3, int flag)
{
	if (str1 != NULL)
		free_str_data(str1);
	if (str2 != NULL)
		free_str_data(str2);
	if (str3 != NULL)
		free_str_data(str3);
	if (flag == 0)
		return (TRUE);
	if (flag == FALSE)
		return (FALSE);
	return (error_processing1(flag));
}
