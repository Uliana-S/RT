#include "main_header.h"

double	create_half_w(double fov)
{
	return (tan(fov / 2));
}

double	create_half_h(double w, double h, double fov)
{
	return ((h / w) * tan(fov / 2));
}

t_vector	find_angle(t_all_data *data)
{
	t_vector	angel;
	t_vector	random;
	t_vector	u;
	t_vector	v;

	random = create_vec(0., -1., 0.);
	if (collinear_vec(&data->cam->cam->dir, &random) == TRUE)
		random = create_vec(-1., 0., 0.);
	u = cross_product(&random, &data->cam->cam->dir);
	normalization_vec(&u);
	v = cross_product(&u, &data->cam->cam->dir);
	normalization_vec(&v);
	v = multiply_vec(&v, create_half_h(data->base->resolution->width,
				data->base->resolution->height, data->cam->cam->fov));
	u = multiply_vec(&u, create_half_w(data->cam->cam->fov));
	angel = sub_vec(&v, &u);
	return (addition_vec(&angel, &data->cam->cam->dir));
}

t_vector	create_vec_dir(t_all_data *data, t_vector *angel,
								double i, double j)
{
	t_vector	random;
	t_vector	u;
	t_vector	v;
	t_vector	t;
	t_vector	k;

	random = create_vec(0., -1., 0.);
	if (collinear_vec(&data->cam->cam->dir, &random) == TRUE)
		random = create_vec(-1., 0., 0.);
	u = cross_product(&random, &data->cam->cam->dir);
	normalization_vec(&u);
	v = cross_product(&u, &data->cam->cam->dir);
	normalization_vec(&v);
	t = multiply_vec(&v, create_half_h(data->base->resolution->width,
				data->base->resolution->height, data->cam->cam->fov) * 2);
	t = multiply_vec(&t, j / (double)data->base->resolution->height);
	k = multiply_vec(&u, create_half_w(data->cam->cam->fov) * 2);
	k = multiply_vec(&k, i / (double)data->base->resolution->width);
	random = sub_vec(angel, &t);
	return (addition_vec(&random, &k));
}
