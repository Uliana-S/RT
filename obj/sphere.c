#include "main_header.h"

double	ft_find_t_sp(double a, double b, double c)
{
	double		discriminant;
	double		x1;
	double		x2;

	discriminant = pow(b, 2) - 4 * (a * c);
	if (discriminant >= 0.)
	{
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);
		if (x1 > 0. && x2 > 0.)
		{
			if (x1 > x2)
				return (x2);
			return (x1);
		}
		else if (x1 > 0.)
			return (x1);
		else if (x2 > 0.)
			return (x2);
	}
	return (FALSE);
}

double	quadratic_equation_sp(t_vector *d, t_vector *co, double radius)
{
	double		a;
	double		b;
	double		c;

	a = dot_product(d, d);
	b = 2. * dot_product(co, d);
	c = dot_product(co, co) - (pow(radius, 2));
	return (ft_find_t_sp(a, b, c));
}

double	sphere(t_vector *vec_dir, t_sphere *sphere,
				t_vector *camera)
{
	t_vector	co;

	co = sub_vec(camera, &sphere->center);
	return (quadratic_equation_sp(vec_dir, &co, sphere->radius));
}
