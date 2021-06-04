#include "main_header.h"

void	computation_t(t_data_cy *t_x, t_vector *point, t_vector *dir,
			t_cylinder *cy)
{
	t_vector	t1;
	t_vector	t2;

	t_x->p1 = point_in_line(point, t_x->x1, dir);
	t1 = sub_vec(&t_x->p1, &cy->center);
	t_x->t1 = dot_product(&t1, &cy->dir);
	t_x->p2 = point_in_line(point, t_x->x2, dir);
	t2 = sub_vec(&t_x->p2, &cy->center);
	t_x->t2 = dot_product(&t2, &cy->dir);
}

double	choice_x(t_data_cy *t_x, t_vector *point, t_vector *dir,
			t_cylinder *cy)
{
	double		len1;
	double		len2;

	computation_t(t_x, point, dir, cy);
	if (t_x->x1 > 0. && t_x->x2 > 0.)
	{
		len1 = length_vec2(point, &t_x->p1);
		len2 = length_vec2(point, &t_x->p2);
		if (-cy->height / 2. <= t_x->t1
			&& t_x->t1 <= cy->height / 2. && len1 < len2)
			return (t_x->x1);
		else if (-cy->height / 2. <= t_x->t2
			&& t_x->t2 <= cy->height / 2. && len2 > len1)
			return (t_x->x2);
	}
	else if (t_x->x1 > 0. && -cy->height / 2. <= t_x->t1
		&& t_x->t1 <= cy->height / 2.)
		return (t_x->x1);
	else if (t_x->x2 > 0. && -cy->height / 2. <= t_x->t2
		&& t_x->t2 <= cy->height / 2.)
		return (t_x->x2);
	return (FALSE);
}

double	find_t_in_cy(t_vector *abc, t_vector *dir, t_vector *location,
			t_cylinder *cy)
{
	double		discriminant;
	t_data_cy	t_x;

	discriminant = pow(abc->y, 2) - 4 * (abc->x * abc->z);
	if (discriminant >= 0.)
	{
		t_x.x1 = (-abc->y - sqrt(discriminant)) / (2 * abc->x);
		t_x.x2 = (-abc->y + sqrt(discriminant)) / (2 * abc->x);
		if (t_x.x1 > 0. || t_x.x2 > 0.)
			return (choice_x(&t_x, location, dir, cy));
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

t_vector	quadratic_equation_cy(t_vector *d, t_vector *co,
				t_cylinder *cy)
{
	t_vector	abc;

	abc.x = dot_product(d, d) - pow(dot_product(&cy->dir, d), 2);
	abc.y = 2 * (dot_product(co, d) - dot_product(co, &cy->dir)
			* dot_product(&cy->dir, d));
	abc.z = dot_product(co, co) - pow(dot_product(&cy->dir, co), 2)
		- pow(cy->radius, 2);
	return (abc);
}

double	cylinder(t_vector *vec_dir, t_cylinder *cylinder,
			t_vector *camera)
{
	t_vector	co;
	t_vector	abc;

	co = sub_vec(camera, &cylinder->center);
	abc = quadratic_equation_cy(vec_dir, &co, cylinder);
	return (find_t_in_cy(&abc, vec_dir, camera, cylinder));
}
