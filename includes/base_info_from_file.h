#ifndef BASE_INFO_FROM_FILE_H
# define BASE_INFO_FROM_FILE_H

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}			t_vector;

typedef struct s_color
{
	double		r;
	double		g;
	double		b;
}			t_color;

typedef struct s_base_info
{
	struct s_resolution	*resolution;
	struct s_ambient	*ambient;
}				t_base_info;

typedef struct s_resolution
{
	int			width;
	int			height;
}				t_resolution;

typedef struct s_ambient
{
	t_color			color;
	double			ratio;
}				t_ambient;

typedef struct s_all_cam
{
	struct s_camera		*cam;
	struct s_all_cam	*next;
	struct s_all_cam	*prev;
}				t_all_cam;

typedef struct s_camera
{
	t_vector		location;
	t_vector		dir;
	double			fov;
}				t_camera;

#endif
