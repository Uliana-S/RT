#include "main_header.h"

double	collinear_vec(t_vector *v1, t_vector *v2)
{
	t_vector	vec;

	vec = cross_product(v1, v2);
	if (fabs(dot_product(&vec, &vec)) < EPS)
		return (TRUE);
	return (FALSE);
}

double	inside_square(t_vector *point, t_square *square)
{
	t_vector	v;
	t_vector	u;
	t_vector	random;
	t_vector	op;

	random = create_vec(0., 1., 0.);
	if (collinear_vec(&square->normal, &random) == TRUE)
		random = create_vec(1., 0., 0.);
	v = cross_product(&square->normal, &random);
	normalization_vec(&v);
	u = cross_product(&square->normal, &v);
	op = sub_vec(point, &square->center);
	if ((dot_product(&u, &op) <= (square->size / 2))
		&& (dot_product(&v, &op) <= (square->size / 2))
		&& (dot_product(&u, &op) >= -(square->size / 2))
		&& (dot_product(&v, &op) >= -(square->size / 2)))
		return (TRUE);
	return (FALSE);
}

double	square(t_vector *vec_dir, t_square *square,
				t_vector *camera)
{
	t_vector	point;
	double		t;

	t = plane(vec_dir, &square->center, &square->normal, camera);
	if (t == FALSE)
		return (FALSE);
	point = multiply_vec(vec_dir, t);
	point = addition_vec(camera, &point);
	if (inside_square(&point, square) == TRUE)
		return (t);
	return (FALSE);
}
