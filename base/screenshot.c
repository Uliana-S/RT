#include "main_header.h"

void	*memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return ((void *)str);
}

void	draw_screen(t_all_data *data, int fd)
{
	int	var[3];
	int	h;
	int	w;

	w = data->base->resolution->width;
	h = data->base->resolution->height;
	var[0] = h - 1;
	while (var[0] >= 0)
	{
		var[1] = 0;
		while (var[1] < w)
		{
			var[2] = *(int *)(data->img->addr
					+ (var[0] * data->img->line_length
						+ var[1] * (data->img->bits_per_pixel / 8)));
			write(fd, &var[2], 3);
			var[1]++;
		}
		var[0]--;
	}
}

void	filler(char arr_info[54], int w, int h, int size)
{
	arr_info[0] = 'B';
	arr_info[1] = 'M';
	arr_info[2] = size;
	arr_info[3] = size >> 8;
	arr_info[4] = size >> 16;
	arr_info[5] = size >> 24;
	arr_info[10] = 54;
	arr_info[14] = 40;
	arr_info[26] = 0;
	arr_info[28] = 24;
	arr_info[18] = w;
	arr_info[19] = w >> 8;
	arr_info[20] = w >> 16;
	arr_info[21] = w >> 24;
	arr_info[22] = h;
	arr_info[23] = h >> 8;
	arr_info[24] = h >> 16;
	arr_info[25] = h >> 24;
}

void	save(t_all_data *data)
{
	int		fd;
	int		size;
	char	arr_info[54];
	t_img	img;

	img.addr = malloc(4 * data->base->resolution->width
			* data->base->resolution->height);
	img.line_length = 4 * data->base->resolution->width;
	img.bits_per_pixel = 32;
	data->img = &img;
	render(data);
	fd = open("save_screen.bmp", O_WRONLY | O_CREAT
			| O_TRUNC | O_APPEND, 0666);
	while (data->base->resolution->width % 4 != 0)
		data->base->resolution->width--;
	size = 54 + (4 * data->base->resolution->width
			* data->base->resolution->height);
	memset(arr_info, 0, 54);
	filler(arr_info, data->base->resolution->width,
		data->base->resolution->height, size);
	write(fd, arr_info, 54);
	draw_screen(data, fd);
	free(data->img->addr);
	close(fd);
}
