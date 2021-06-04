#include "main_header.h"

t_vector	create_vec(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

double	length_vec2(t_vector *v1, t_vector *v2)
{
	double		x;
	double		y;
	double		z;

	x = pow(v1->x - v2->x, 2);
	y = pow(v1->y - v2->y, 2);
	z = pow(v1->z - v2->z, 2);
	return (sqrt(x + y + z));
}

double	length_vec1(t_vector *v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}

void	normalization_vec(t_vector *v)
{
	double		len;

	len = length_vec1(v);
	v->x *= (1 / len);
	v->y *= (1 / len);
	v->z *= (1 / len);
}

t_vector	addition_vec(t_vector *v1, t_vector *v2)
{
	t_vector	new;

	new.x = v1->x + v2->x;
	new.y = v1->y + v2->y;
	new.z = v1->z + v2->z;
	return (new);
}
