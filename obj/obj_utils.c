#include "main_header.h"

t_vector	find_normal_sp(t_vector *point, t_sphere *sphere)
{
	t_vector	normal;

	normal = sub_vec(point, &sphere->center);
	normalization_vec(&normal);
	return (normal);
}

t_vector	find_normal_tr(t_vector *v1, t_vector *v2, t_vector *v3)
{
	t_vector	factor1;
	t_vector	factor2;
	t_vector	normal;

	factor1 = sub_vec(v2, v1);
	factor2 = sub_vec(v3, v1);
	normal = cross_product(&factor1, &factor2);
	normalization_vec(&normal);
	return (normal);
}

t_vector	find_normal_cy(t_vector *point, t_cylinder *cylinder)
{
	t_vector	tangent;
	t_vector	cp;
	t_vector	normal;

	cp = sub_vec(point, &cylinder->center);
	tangent = cross_product(&cylinder->dir, &cp);
	normal = cross_product(&tangent, &cylinder->dir);
	normalization_vec(&normal);
	return (normal);
}
