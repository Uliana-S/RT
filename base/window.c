#include "main_header.h"

t_all_cam	*change_camera(t_all_cam *camera, int key)
{
	if (key == KEYCODES_RIGHT)
		return (camera->next);
	else
		return (camera->prev);
}

int	remove_window(t_all_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit (0);
}

int	key_hook(int key, t_all_data *data)
{
	if ((key == KEYCODES_LEFT || key == KEYCODES_RIGHT)
		&& data->cam != NULL)
	{
		data->cam = change_camera(data->cam, key);
		render(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
	else if (key == KEYCODES_ESC)
		remove_window(data);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	window(t_all_data *data)
{
	t_img		img;

	data->win = mlx_new_window(data->mlx, data->base->resolution->width,
			data->base->resolution->height, "Ray tracing");
	img.img = mlx_new_image(data->mlx, data->base->resolution->width,
			data->base->resolution->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	data->img = &img;
	if (data->cam != NULL)
		render(data);
	mlx_hook(data->win, 2, 1L << 0, &key_hook, data);
	mlx_hook(data->win, 17, 1L << 2, &remove_window, data);
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	mlx_loop(data->mlx);
}
