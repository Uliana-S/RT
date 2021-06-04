#include "main_header.h"

int	vec_v0p(t_vector *v0p, t_triangle *triangle)
{
	t_vector	v0v1;
	t_vector	v0v2;

	v0v1 = sub_vec(&triangle->point1, &triangle->point0);
	v0v2 = sub_vec(&triangle->point2, &triangle->point0);
	normalization_vec(&v0v1);
	normalization_vec(&v0v2);
	if (dot_product(v0p, &v0v1) > dot_product(&v0v1, &v0v2)
		&& dot_product(v0p, &v0v2) > dot_product(&v0v1, &v0v2))
		return (TRUE);
	return (FALSE);
}

int	vec_v1p(t_vector *v1p, t_triangle *triangle)
{
	t_vector	v1v2;
	t_vector	v1v0;

	v1v2 = sub_vec(&triangle->point2, &triangle->point1);
	v1v0 = sub_vec(&triangle->point0, &triangle->point1);
	normalization_vec(&v1v2);
	normalization_vec(&v1v0);
	if (dot_product(v1p, &v1v2) > dot_product(&v1v0, &v1v2)
		&& dot_product(v1p, &v1v0) > dot_product(&v1v0, &v1v2))
		return (TRUE);
	return (FALSE);
}

int	vec_v2p(t_vector *v2p, t_triangle *triangle)
{
	t_vector	v2v0;
	t_vector	v2v1;

	v2v0 = sub_vec(&triangle->point0, &triangle->point2);
	v2v1 = sub_vec(&triangle->point1, &triangle->point2);
	normalization_vec(&v2v0);
	normalization_vec(&v2v1);
	if (dot_product(v2p, &v2v0) > dot_product(&v2v1, &v2v0)
		&& dot_product(v2p, &v2v0) > dot_product(&v2v1, &v2v0))
		return (TRUE);
	return (FALSE);
}

double	inside_triangle(t_vector *point, t_triangle *triangle)
{
	t_vector	v0p;
	t_vector	v1p;
	t_vector	v2p;

	v0p = sub_vec(point, &triangle->point0);
	v1p = sub_vec(point, &triangle->point1);
	v2p = sub_vec(point, &triangle->point2);
	normalization_vec(&v0p);
	normalization_vec(&v1p);
	normalization_vec(&v2p);
	if (vec_v0p(&v0p, triangle) == TRUE
		&& vec_v1p(&v1p, triangle) == TRUE
		&& vec_v2p(&v2p, triangle) == TRUE)
		return (TRUE);
	return (FALSE);
}

double	triangle(t_vector *vec_dir, t_triangle *triangle,
					t_vector *camera)
{
	t_vector	n;
	t_vector	point;
	double		t;

	n = find_normal_tr(&triangle->point0, &triangle->point1,
			&triangle->point2);
	t = plane(vec_dir, &triangle->point0, &n, camera);
	if (t == FALSE)
		return (FALSE);
	point = multiply_vec(vec_dir, t);
	point = addition_vec(camera, &point);
	if (inside_triangle(&point, triangle) == TRUE)
		return (t);
	return (FALSE);
}
