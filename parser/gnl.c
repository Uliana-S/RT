#include "main_header.h"

void	re_malloc(char **str, int n, char c)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = malloc(n + 2);
	if (!new_line)
		return ;
	while (str[0][i] != '\0')
	{
		new_line[i] = str[0][i];
		i++;
	}
	new_line[i] = c;
	new_line[i + 1] = '\0';
	free(*str);
	*str = new_line;
}

int	get_next_line(char **line, int fd)
{
	int		res;
	int		i;
	char	b[1];
	char	*data_line;

	b[0] = '\0';
	res = -1;
	i = 0;
	data_line = malloc(1);
	if (!data_line || line == NULL)
		return (FALSE);
	data_line[0] = '\0';
	while (TRUE)
	{
		res = read(fd, b, 1);
		if (b[0] == '\n' || res == 0)
			break ;
		else
			re_malloc(&data_line, i, b[0]);
		i++;
	}
	*line = data_line;
	if (res == 0 && b[0] == '\0')
		return (0);
	return (1);
}
