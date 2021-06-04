#include "main_header.h"

void	ambient_color(t_color *base, t_ambient *res)
{
	base->r = base->r + (res->color.r / 255 * res->ratio);
	base->g = base->g + (res->color.g / 255 * res->ratio);
	base->b = base->b + (res->color.b /255 * res->ratio);
}

void	create_color_light(t_color *color)
{
	color->r = 0.;
	color->g = 0.;
	color->b = 0.;
}

void	mix_color(t_color *color1, t_color *color2)
{
	color1->r = color1->r * color2->r;
	color1->g = color1->g * color2->g;
	color1->b = color1->b * color2->b;
	if (color1->r > 255)
		color1->r = 255;
	if (color1->g > 255)
		color1->g = 255;
	if (color1->b > 255)
		color1->b = 255;
}

void	color_light(t_color *base, t_light *l, double dot)
{
	base->r = base->r + (l->color.r / 255 * l->brightness * dot);
	base->g = base->g + (l->color.g / 255 * l->brightness * dot);
	base->b = base->b + (l->color.b / 255 * l->brightness * dot);
}

unsigned int	create_color(t_color *color)
{
	if (color == NULL)
		return (1);
	return (256 * 256 * (int)color->r + 256 * (int)color->g
		+ (int)color->b);
}
