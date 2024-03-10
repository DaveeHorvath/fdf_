/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:55:18 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/10 17:11:30 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void	render(mlx_image_t *image, t_point3 **map, t_settings *settings, mlx_t *mlx)
{
	t_vector2	u;
	t_vector2	v;
	int			x;
	int			y;
	t_point2	**points;

	get_base_vectors(&u, &v, settings);
	points = make_points(u, v, map, settings);
	x = 0;
	while (x < settings->map_width)
	{
		y = 0;
		while (y < settings->map_height)
		{
			if (y != settings->map_height - 1)
				draw_line(points[x][y], points[x][y + 1], image);
			if (x != settings->map_width - 1)
				draw_line(points[x][y], points[x + 1][y], image);
			y++;
		}
		x++;
	}
	mlx_image_to_window(mlx, image, 0, 0);
}

static t_point2	get_iso_pos(t_point3 p,t_vector2 u, t_vector2 v, t_settings *settings)
{
	t_point2 res;

	res.x = u.x * (p.x - settings->index_offset_x);
	res.x += v.x * (p.y - settings->index_offset_y);
	res.x += settings->center_x;
	res.y = u.y * (p.x - settings->index_offset_x);
	res.y += v.y * (p.y - settings->index_offset_y);
	res.y += settings->center_y + settings->depth * p.z;
	return (res);
}

static t_point2	**make_points(t_vector2 u, t_vector2 v, t_point3 **map, t_settings *settings)
{
	int			x;
	int			y;
	t_point2	**res;

	res = calloc(sizeof(t_point2*), settings->map_width);
	while (x < settings->map_width)
	{
		y = 0;
		res[x] = calloc(sizeof(t_point2), settings->map_height);
		while (y < settings->map_height)
		{
			res[x][y] = get_iso_pos(map[x][y], u, v, settings);
			y++;
		}
		x++;
	}
}

static void	draw_line(t_point2 start, t_point2 end, mlx_image_t *image)
{
	double	ratio;
	double	deltaX;
	double	deltaY;
	double	deltaColor;
	double	color;
	double	x;
	double	y;
	double	i;

	ratio = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	deltaX = (end.x - start.x) / ratio;
	deltaY = (end.y - start.y) / ratio;
	deltaColor = (get_color(end.color) - get_color(start.color)) / ratio;
	x = start.x;
	y = start.y;
	color = get_color(start.color);
	while (i < ratio)
	{
		mlx_put_pixel(image, x, y, color);
		x += deltaX;
		y += deltaY;
		color += deltaColor;
	}
}
