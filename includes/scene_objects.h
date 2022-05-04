#ifndef SCENE_OBJECTS_H
# define SCENE_OBJECTS_H

# define SPHERE_ID 1
# define PLANE_ID 2
# define TRIANGLE_ID 3
# define SQUARE_ID 4
# define CYLINDER_ID 5

typedef struct s_scene
{
	struct s_all_light	*light;
	struct s_objects	*objects;
}				t_scene;

typedef struct s_all_light
{
	void			*light;
	struct s_all_light	*next;
}				t_all_light;

typedef struct s_light
{
	t_vector		coordinates;
	double			brightness;
	t_color			color;
}				t_light;

typedef struct s_objects
{
	int			identifier;
	void			*new_obj;
	struct s_objects	*next;
}				t_objects;

typedef struct s_sphere
{
	t_vector		center;
	t_color			color;
	double			radius;
}				t_sphere;

typedef struct s_plane
{
	t_vector		coordinates;
	t_vector		normal;
	t_color			color;
}				t_plane;

typedef struct s_triangle
{
	t_vector		point0;
	t_vector		point1;
	t_vector		point2;
	t_color			color;
}				t_triangle;

typedef struct s_square
{
	t_vector		center;
	t_vector		normal;
	double			size;
	t_color			color;
}				t_square;

typedef struct s_cylinder
{
	t_vector		center;
	t_vector		dir;
	double			radius;
	double			height;
	t_color			color;
}				t_cylinder;

typedef struct s_data_cy
{
	double			t1;
	double			t2;
	double			x1;
	double			x2;
	t_vector		p1;
	t_vector		p2;
}				t_data_cy;

// sphere
double		sphere(t_vector *vec_dir, t_sphere *sphere,
			t_vector *camera);
double		quadratic_equation_sp(t_vector *d, t_vector *co,
					double radius);
double		find_t_in_sphere(double a, double b, double c);
t_vector	find_normal_sp(t_vector *point, t_sphere *sphere);

// plane
double		plane(t_vector *vec_dir, t_vector *coordinates,
			t_vector *normal, t_vector *camera);

// triangle
double		triangle(t_vector *vec_dir, t_triangle *triangle,
			t_vector *camera);
t_vector	find_normal_tr(t_vector *v1, t_vector *v2, t_vector *v3);
double		inside_triangle(t_vector *point, t_triangle *triangle);
int		vec_v0p(t_vector *v0p, t_triangle *triangle);
int		vec_v1p(t_vector *v1p, t_triangle *triangle);
int		vec_v2p(t_vector *v2p, t_triangle *triangle);

// square
double		square(t_vector *vec_dir, t_square *square,
			t_vector *camera);
double		inside_square(t_vector *point, t_square *square);
double		collinear_vec(t_vector *v1, t_vector *v2);

// cylinder
double		cylinder(t_vector *vec_dir, t_cylinder *cylinder,
			t_vector *camera);
t_vector	quadratic_equation_cy(t_vector *d, t_vector *co,
					t_cylinder *cy);
double		find_t_in_cy(t_vector *abc, t_vector *dir,
				t_vector *location, t_cylinder *cy);
double		choice_x(t_data_cy *t_x, t_vector *point, t_vector *dir,
			t_cylinder *cy);
void		computation_t(t_data_cy *t_x, t_vector *point, t_vector *dir,
				t_cylinder *cy);
t_vector	find_normal_cy(t_vector *point, t_cylinder *cylinder);
int		check_data_cy(char **height, char **diameter,
				char **color_data, t_cylinder *cy);

#endif
