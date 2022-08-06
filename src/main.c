/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:35:06 by hardella          #+#    #+#             */
/*   Updated: 2022/08/06 22:03:27 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}


int main(void) {
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	t_vector *sphere_center = new_vector(0, 0, -32);
	t_sphere *sphere = new_sphere(sphere_center, 8/2);
	t_vector *camera_center = new_vector(0, 0, 0);
	t_vector *cam_direction = new_vector(0, 0, -1);
	t_camera *cam = new_cam(camera_center, cam_direction, 50);
	t_scene *scene = new_scene(cam, sphere);
	scene->width = 800;
	scene->height = 600;
	scene->cams = cam;
	window = mlx_new_window(mlx, scene->width, scene->height, "aboba");
	ray_tracing(mlx, window, scene);
	// free_scene(scene)
	mlx_loop(mlx);
	return (0);
}

