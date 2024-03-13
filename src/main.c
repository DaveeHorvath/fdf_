/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:43:04 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/11 15:44:53 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include <stdio.h>

#include <stdlib.h>

/*
	dafualt values should be calculated based
	on window and not just arbitrarily
*/
t_settings get_default_settings(void)
{
	t_settings res;

	res.center_x = 500;
	res.center_y = 500;
	res.depth = 2;
	res.elips_a = 20;
	res.elips_b = 10;
	res.rotation = 30;
	res.zoom = 1;
	return (res);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_point3	**map;
	t_settings	settings;

	if (argc != 2)
		return (0);
	// window creation
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	if (!mlx)
		return (0);
	// single image
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		return (0);
	settings = get_default_settings();
	// map parsing
	map = parse_map(argv[1], &settings);
	if (!map)
		return (0);
	// initial render and setup
	render(image, map, &settings, mlx);
	ft_hook(mlx, image, map, &settings);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// to cover up leaks :)
	exit(0);
}
