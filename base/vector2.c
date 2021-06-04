#include "main_header.h"

t_vector	multiply_vec(t_vector *v1, double t)
{
	t_vector	new;

	new.x = v1->x * t;
	new.y = v1->y * t;
	new.z = v1->z * t;
	return (new);
}

t_vector	sub_vec(t_vector *point1, t_vector *point2)
{
	t_vector	res;

	res.x = point1->x - point2->x;
	res.y = point1->y - point2->y;
	res.z = point1->z - point2->z;
	return (res);
}

t_vector	composition_vec(t_vector *point1, t_vector *point2)
{
	t_vector	res;

	res.x = point1->x * point2->x;
	res.y = point1->y * point2->y;
	res.z = point1->z * point2->z;
	return (res);
}

double	dot_product(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector	cross_product(t_vector *v1, t_vector *v2)
{
	t_vector	new;

	new.x = v1->y * v2->z - v1->z * v2->y;
	new.y = v1->z * v2->x - v1->x * v2->z;
	new.z = v1->x * v2->y - v1->y * v2->x;
	return (new);
}
