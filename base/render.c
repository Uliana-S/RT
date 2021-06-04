#include "main_header.h"

double	shadow(t_objects *scene, t_vector *p1, t_vector *pl, t_vector *l)
{
	double		t;
	t_vector	p2;
	double		len1;
	double		len2;

	len1 = length_vec2(p1, l);
	while (scene != NULL)
	{
		t = intersection(pl, scene, p1);
		if (t > 0)
		{
			p2 = multiply_vec(pl, t);
			p2 = addition_vec(l, &p2);
			len2 = length_vec2(&p2, l);
			if (len1 > len2)
				return (TRUE);
		}
		scene = scene->next;
	}
	return (FALSE);
}

void	shine(t_vector *p, t_all_data *data, t_vector *normal,
				t_color *light_color)
{
	t_vector	pl;
	t_all_light	*l;
	t_objects	*obj;
	double		brightness;

	create_color_light(light_color);
	brightness = 0.;
	l = data->scene->light;
	obj = data->scene->objects;
	while (l != NULL)
	{
		pl = sub_vec(&((t_light *)l->light)->coordinates, p);
		normalization_vec(&pl);
		if (shadow(obj, p, &pl, &((t_light *)l->light)->coordinates)
			== FALSE)
		{
			color_light(light_color, l->light,
				fabs(dot_product(&pl, normal)));
			brightness += (((t_light *)l->light)->brightness
					* fabs(dot_product(&pl, normal)));
		}
		l = l->next;
	}
}

double	ft_find_color(t_all_data *data, t_objects *obj,
					t_vector *vec_dir, double t)
{
	t_vector	point;
	t_color		new_color;
	t_color		light_color;
	t_vector	normal;

	point = point_in_line(&data->cam->cam->location, t - EPS, vec_dir);
	new_color = return_color(obj);
	normal = normal_vector(&point, obj);
	if (dot_product(vec_dir, &normal) > 0)
		normal = multiply_vec(&normal, -1);
	shine(&point, data, &normal, &light_color);
	ambient_color(&light_color, data->base->ambient);
	mix_color(&new_color, &light_color);
	return (create_color(&new_color));
}

double	ray_tracing(t_vector *vec_dir, t_all_data *data)
{
	double		t1;
	double		t2;
	t_objects	obj;
	t_objects	*objects;

	t1 = FALSE;
	objects = data->scene->objects;
	while (objects != NULL)
	{
		t2 = intersection(vec_dir, objects, &data->cam->cam->location);
		if ((t2 < t1 || t1 == FALSE) && t2 > 1e-9)
		{
			t1 = t2;
			obj = *objects;
		}
		objects = objects->next;
	}
	if (t1 != FALSE)
		return (ft_find_color(data, &obj, vec_dir, t1));
	return (create_color((void *) NULL));
}

void	render(t_all_data *data)
{
	int			i;
	int			j;
	t_vector	angle;
	t_vector	vec_dir;
	double		new_color;

	j = 0;
	angle = find_angle(data);
	while (j < data->base->resolution->height)
	{
		i = 0;
		while (i < data->base->resolution->width)
		{
			vec_dir = create_vec_dir(data, &angle, i, j);
			normalization_vec(&vec_dir);
			new_color = ray_tracing(&vec_dir, data);
			my_mlx_pixel_put(data->img, i, j, new_color);
			i++;
		}
		j++;
	}
}
