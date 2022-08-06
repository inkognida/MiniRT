#ifndef VECTOR_H
# define VECTOR_H

#include "minirt.h"

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

t_vector	*new_vector(float x, float y, float z);
t_vector	*vec_substract(t_vector *vec1, t_vector *vec2);
void		vec_normalize(t_vector *vec);
float		vec_dot_product(t_vector *vec1, t_vector *vec2);

#endif