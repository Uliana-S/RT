#include "main_header.h"

void	free_objects(t_objects *obj)
{
	t_objects	*next_obj;

	while (obj)
	{
		next_obj = obj->next;
		free(obj);
		obj = next_obj;
	}
}

void	free_light(t_all_light *li)
{
	t_all_light	*next_li;

	while (li)
	{
		next_li = li->next;
		free(li);
		li = next_li;
	}
}

void	free_camera(t_all_cam *cam)
{
	t_all_cam	*next_cam;

	cam->prev->next = NULL;
	while (cam)
	{
		next_cam = cam->next;
		free(cam);
		cam = next_cam;
	}
}

void	free_base(t_base_info *base)
{
	if (base->ambient)
		free(base->ambient);
	if (base->resolution)
		free(base->resolution);
}

void	free_data(t_all_data *data)
{
	if (data->scene->objects != NULL)
		free_objects(data->scene->objects);
	if (data->scene->light != NULL)
		free_light(data->scene->light);
	if (data->base != NULL)
		free_base(data->base);
	if (data->cam != NULL)
		free_camera(data->cam);
}
