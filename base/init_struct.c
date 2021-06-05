#include "main_header.h"

t_scene	*init_scene(void)
{
	t_scene		*scene;

	scene = malloc(sizeof(t_scene));
	if (!(scene))
		return (NULL);
	scene->light = NULL;
	scene->objects = NULL;
	return (scene);
}

t_base_info	*init_base(void)
{
	t_base_info	*base;

	base = malloc(sizeof(t_base_info));
	if (!(base))
		return (NULL);
	base->resolution = NULL;
	base->ambient = NULL;
	return (base);
}

void	init_data(t_all_data *data)
{
	data->base = init_base();
	data->scene = init_scene();
	data->cam = NULL;
	data->mlx = mlx_init();
	data->win = NULL;
}
