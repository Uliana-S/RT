#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <../minilibx-linux/mlx.h>
# include <math.h>
# include "base_info_from_file.h"
# include "scene_objects.h"
# define TRUE			1
# define FALSE			-1
# define M_PI			3.14159265358979323846
# define EPS			1e-9
# define KEYCODES_LEFT	65361
# define KEYCODES_RIGHT	65363
# define KEYCODES_ESC	65307
# define RESET			"\x1b[0m"
# define RED			"\x1b[1;31m"
# define YELLOW			"\x1b[0;33m"

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_all_data
{
	t_base_info	*base;
	t_all_cam	*cam;
	t_scene		*scene;
	void		*mlx;
	void		*win;
	t_img		*img;
}				t_all_data;

// base
int				main(int argc, char **argv);
int				check_file(char *file, t_all_data *data);
int				open_file(char *file);
int				read_configuration(int fd, t_all_data *data);
void			init_data(t_all_data *data);
t_scene			*init_scene(void);
t_base_info		*init_base(void);
int				count_data(char **data);

// window
void			window(t_all_data *data);
int				key_hook(int key, t_all_data *data);
t_all_cam		*change_camera(t_all_cam *camera, int key);
int				remove_window(t_all_data *data);
void			my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);

// render
void			render(t_all_data *data);
double			create_half_w(double fov);
double			create_half_h(double w, double h, double fov);
t_vector		find_angle(t_all_data *data);
t_vector		create_vec_dir(t_all_data *data, t_vector *angel,
					double i, double j);
double			ray_tracing(t_vector *vec_dir, t_all_data *data);
double			intersection(t_vector *vec_dir, t_objects *scene,
					t_vector *location);
double			shadow(t_objects *scene, t_vector *p1, t_vector *pl,
					t_vector *l);
void			shine(t_vector *p, t_all_data *data, t_vector *normal,
					t_color *light_color);
t_vector		normal_vector(t_vector *point, t_objects *obj);
t_vector		point_in_line(t_vector *point, double t, t_vector *dir);

// parser
int				get_next_line(char **line, int fd);
void			re_malloc(char **str, int n, char c);
char			**ft_split(char *str, char sep);
char			**search_words(char **res_str, char *str, char sep);
char			**free_str(char **res_str, int j);
char			*create_word(char *str, int start, int len);
int				count_words(char *str, char sep);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
double			ft_atoi(char *str);
size_t			ft_strlen(char *str);
int				parser(char **data_line, t_all_data *data);
int				parser_obj(char **data_line, t_objects **objs);
void			add_front_obj(t_objects **lst, t_objects *new_obj);
int				parser_r_a(char **data_line, t_base_info *base);
int				parser_r(char **data, t_base_info *base);
int				parser_a(char **data, t_base_info *base);
int				parser_l(char **data, t_all_light **l);
int				create_light(char **data, t_light *li);
int				parser_c(char **data_line, t_all_cam **c);
int				create_camera(char **data, t_camera *cam);
void			add_front_camera(t_all_cam **lst, t_all_cam *new_cam);
int				parser_sp(char **data, t_objects **obj);
int				create_sphere(char **data, t_sphere *sp);
int				parser_pl(char **data, t_objects **obj);
int				create_plane(char **data, t_plane *pl);
int				parser_tr(char **data, t_objects **obj);
int				create_triangle(char **data, t_triangle *tr);
int				parser_sq(char **data, t_objects **obj);
int				create_square(char **data, t_square *sq);
int				parser_cy(char **data, t_objects **obj);
int				create_cylinder(char **data, t_cylinder *cy);
int				check_normal(t_vector *normal);
int				check_double(char *str);
double			create_number(char **numbers);
int				check_int_number(char **data);
int				check_pos_int(char *data);
int				count_data(char **data);
int				check_color(char **color);
void			create_struct_color(char **data_color, t_color *new_col);
int				create_struct_vec(char **data_color, t_vector *new_vec);
int				check_argv(char **argv, int n);
int				check_flag(char *flag);
void			free_str_data(char **str);
int				free_memory_parser(char **str1, char **str2, char **str3,
					int flag);
int				check_null(char *str);

// error
int				error_processing1(int fail);
int				error_processing2(int fail);

// save
void			save(t_all_data *data);
void			filler(char arr_info[54], int w, int h, int size);
void			draw_screen(t_all_data *data, int fd);
void			*memset(void *s, int c, size_t len);

// free
void			free_data(t_all_data *data);
void			free_objects(t_objects *obj);
void			free_light(t_all_light *li);
void			free_camera(t_all_cam *cam);
void			free_base(t_base_info *base);

// color
void			mix_color(t_color *color1, t_color *color2);
unsigned int	create_color(t_color *color);
t_color			return_color(t_objects *scene);
void			ambient_color(t_color *color, t_ambient *res);
void			color_light(t_color *base, t_light *l, double dot);
void			create_color_light(t_color *color);

// vector
t_vector		create_vec(double x, double y, double z);
double			dot_product(t_vector *v1, t_vector *v2);
t_vector		sub_vec(t_vector *point1, t_vector *point2);
t_vector		composition_vec(t_vector *point1, t_vector *point2);
t_vector		multiply_vec(t_vector *v1, double t);
t_vector		addition_vec(t_vector *v1, t_vector *v2);
double			length_vec1(t_vector *v);
double			length_vec2(t_vector *v1, t_vector *v2);
void			normalization_vec(t_vector *v);
t_vector		cross_product(t_vector *v1, t_vector *v2);

#endif