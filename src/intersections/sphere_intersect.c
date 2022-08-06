#include "../includes/intersects.h"

int	sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere)
{
	// a = 1 всегда
	float		b;
	float		c;
	float		discr;
	float		dist_1; // дистанция до ближайшего края сферы
	// float		dist_2;// дистанция до дальнего края сферы
	t_vector	*cam_sphere;

	dist_1 = 0; // чтобы узнать ближайшую фигуру которую надо отрисовывать
	// dist_2 = 0;
	cam_sphere = vec_substract(cam->origin, sphere->center);
	b = 2 * vec_dot_product(cam_sphere, ray);
	c = vec_dot_product(cam_sphere, cam_sphere) - sphere->radius * sphere->radius;
	discr = b * b - 4 * c;
	if (discr < 0)
		return (0);
	dist_1 = (-1 * b - sqrt(discr)) / 2;
	// dist_2 = (-1 * b + sqrt(discr)) / 2;
	free(cam_sphere);
	if (dist_1 > 0)
		return (dist_1);
	return 0;
}
