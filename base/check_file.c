#include "main_header.h"

int	read_configuration(int fd, t_all_data *data)
{
	int		res;
	char	*line;
	char	**data_file;

	data_file = NULL;
	res = -1;
	while (TRUE)
	{
		if (res == 0)
			break ;
		res = get_next_line(&line, fd);
		if (ft_strlen(line) == 0 || line[0] == '#')
			continue ;
		data_file = ft_split(line, ' ');
		if (parser(data_file, data) == FALSE)
		{
			free(line);
			return (free_memory_parser(data_file, NULL, NULL, -1));
		}
		free(line);
		free(data_file);
	}
	free(line);
	close(fd);
	return (TRUE);
}

int	open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (FALSE);
	}
	fd = open(file, O_RDONLY);
	return (fd);
}

int	check_file(char *file, t_all_data *data)
{
	int		fd;

	fd = open_file(file);
	if (fd == -1)
		return (error_processing1(1));
	else if (read_configuration(fd, data) == FALSE)
		return (FALSE);
	else if (data->cam == NULL && data->scene->light == NULL
		&& data->scene->objects == NULL && data->base->resolution == NULL
		&& data->base->ambient == NULL)
		return (error_processing1(6));
	else if (data->base->resolution == NULL)
		return (error_processing1(11));
	else if (data->base->ambient == NULL
		&& data->scene->light == NULL)
		return (error_processing1(13));
	return (TRUE);
}

int	check_flag(char *flag)
{
	char	*save;
	int		i;

	i = 0;
	save = "--save";
	if (ft_strlen(flag) == 6)
	{
		while (i < 6)
		{
			if (flag[i] != save[i])
				return (error_processing1(12));
			i++;
		}
		return (TRUE);
	}
	return (error_processing1(12));
}

int	check_argv(char **argv, int n)
{
	int		len;
	char	*file;

	file = argv[1];
	len = ft_strlen(file);
	if (file[len - 3] != '.' && file[len - 2] != 'r'
		&& file[len - 1] != 't')
		return (error_processing1(5));
	if (n == 3)
		return (check_flag(argv[2]));
	return (TRUE);
}
