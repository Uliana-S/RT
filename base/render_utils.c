#include "main_header.h"

t_vector	normal_vector(t_vector *point, t_objects *obj)
{
	if (obj->identifier == SPHERE_ID)
		return (find_normal_sp(point, (t_sphere *)obj->new_obj));
	if (obj->identifier == PLANE_ID)
		return (((t_plane *)obj->new_obj)->normal);
	if (obj->identifier == TRIANGLE_ID)
		return (find_normal_tr(&((t_triangle *)obj->new_obj)->point0,
				&((t_triangle *)obj->new_obj)->point1,
				&((t_triangle *)obj->new_obj)->point2));
	if (obj->identifier == SQUARE_ID)
		return (((t_square *)obj->new_obj)->normal);
	else
		return (find_normal_cy(point, (t_cylinder *)obj->new_obj));
}

t_vector	point_in_line(t_vector *point, double t, t_vector *dir)
{
	t_vector	p;

	p = multiply_vec(dir, t);
	return (addition_vec(point, &p));
}

double	intersection(t_vector *vec_dir, t_objects *scene, t_vector *location)
{
	if (scene->identifier == SPHERE_ID)
		return (sphere(vec_dir, (t_sphere *)scene->new_obj, location));
	if (scene->identifier == PLANE_ID)
		return (plane(vec_dir, &((t_plane *)scene->new_obj)->coordinates,
				&((t_plane *)scene->new_obj)->normal, location));
	if (scene->identifier == TRIANGLE_ID)
		return (triangle(vec_dir, (t_triangle *)scene->new_obj, location));
	if (scene->identifier == SQUARE_ID)
		return (square(vec_dir, (t_square *)scene->new_obj, location));
	else
		return (cylinder(vec_dir, (t_cylinder *)scene->new_obj, location));
}

t_color	return_color(t_objects *scene)
{
	if (scene->identifier == SPHERE_ID)
		return (((t_sphere *)scene->new_obj)->color);
	if (scene->identifier == PLANE_ID)
		return (((t_plane *)scene->new_obj)->color);
	if (scene->identifier == TRIANGLE_ID)
		return (((t_triangle *)scene->new_obj)->color);
	if (scene->identifier == SQUARE_ID)
		return (((t_square *)scene->new_obj)->color);
	else
		return (((t_cylinder *)scene->new_obj)->color);
}
