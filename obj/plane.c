#include "main_header.h"

double	plane(t_vector *vec_dir, t_vector *coordinates,
				t_vector *normal, t_vector *camera)
{
	t_vector	oc;
	double		op;
	double		t;
	double		dv;

	t = 0.;
	oc = sub_vec(camera, coordinates);
	dv = dot_product(vec_dir, normal);
	op = dot_product(&oc, normal);
	if (dv != 0)
		t = (-op / dv);
	if (t > EPS)
		return (t);
	return (FALSE);
}
