#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

# include "minirt.h"

typedef struct	s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

t_vplane	*new_view_plane(float width, float height, float fov);
void		ray_tracing(void *mlx, void *window, t_scene *scene);

#endif