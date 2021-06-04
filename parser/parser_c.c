#include "main_header.h"

void	add_front_camera(t_all_cam **lst, t_all_cam *new_cam)
{
	t_all_cam	*tail;
	t_all_cam	*head;

	head = *lst;
	if (!head)
	{
		*lst = new_cam;
		new_cam->next = new_cam;
		new_cam->prev = new_cam;
	}
	else
	{
		tail = (*lst)->prev;
		new_cam->next = head;
		tail->next = new_cam;
		new_cam->prev = tail;
		head->prev = new_cam;
	}
}

int	create_camera(char **data, t_camera *cam)
{
	char		**point;
	char		**dir;
	char		**fov;

	point = ft_split(data[1], ',');
	dir = ft_split(data[2], ',');
	fov = ft_split(data[3], '.');
	if (!point || !dir || !fov
		|| check_double(data[3]) == FALSE)
		return (free_memory_parser(point, dir, fov, 3));
	cam->fov = create_number(fov);
	if (create_struct_vec(point, &cam->location) == FALSE
		|| create_struct_vec(dir, &cam->dir) == FALSE
		|| check_normal(&cam->dir) == FALSE
		|| cam->fov < 0 || cam->fov > 180)
		return (free_memory_parser(point, dir, fov, 4));
	cam->fov *= (M_PI / 180);
	normalization_vec(&cam->dir);
	return (free_memory_parser(point, dir, fov, 0));
}

int	parser_c(char **data, t_all_cam **c)
{
	t_all_cam	*new_data;
	t_camera	*new_camera;

	if (count_data(data) != 4)
		return (error_processing1(9));
	new_data = malloc(sizeof(t_all_cam));
	new_camera = malloc(sizeof(t_camera));
	if (new_camera && new_data)
	{
		if (create_camera(data, new_camera) == FALSE)
			return (FALSE);
		new_data->cam = new_camera;
		new_data->next = NULL;
		new_data->prev = NULL;
		add_front_camera(c, new_data);
		return (TRUE);
	}
	return (error_processing1(8));
}
