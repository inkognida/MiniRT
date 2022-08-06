#include "../includes/minirt.h"

void	ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y; // для mlx_pixel_put
	float		x_angle;
	float		y_angle;
	int			color;
	float		y_ray;
	float		x_ray;
	t_vector	*ray;
	t_vplane	*vplane; // окно просмотра

	mlx_y = 0;
	printf("%p\n", scene->cams);
	vplane = new_view_plane(scene->width, scene->height, scene->cams->fov);
	y_angle = scene->height / 2;
	while (y_angle >= scene->height / -2)
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = scene->width / -2;
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);
			vec_normalize(ray);
			if (sphere_intersect(scene->cams, ray, scene->sphere))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

t_vplane	*new_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio; // масштаб

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		error_exit(-1);
	aspect_ratio = width / height;
	vplane->width = tan(fov / 2 * (M_PI / 180)) * 1;
	vplane->width *= 2;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}

