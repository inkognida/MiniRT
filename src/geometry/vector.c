#include "../includes/minirt.h"

t_vector	*new_vector(float x, float y, float z)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		error_exit(-1); // TODO
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vector	*vec_substract(t_vector *vec1, t_vector *vec2)
{
	t_vector	*res;

	res = new_vector(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return (res);
}

float	vec_length(t_vector *vec)
{
	float	res;

	res = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return res;
}

void	vec_normalize(t_vector *vec)
{
	float	length;

	length = vec_length(vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}

float	vec_dot_product(t_vector *vec1, t_vector *vec2)
{
	float	result;

	result = ((vec1->x * vec2->x) + (vec1->y * vec2->y)  + (vec1->z * vec2->z));
	return (result);
}