/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:43:04 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/10 17:53:45 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_point3	**map;
	t_settings	*settings;

	if (argc != 2)
		return (0);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	if (!mlx)
		return (0);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		return (0);
	map = parse_map(argv[1]);
	settings = get_default_settings();
	ft_hook(mlx, image, map, settings);
	render(image, map, settings, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
