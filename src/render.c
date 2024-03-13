/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:55:18 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/11 15:45:06 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include "libft.h"
#include <string.h>

static t_point2	get_iso_pos(t_point3 p,t_vector2 u, t_vector2 v, t_settings *settings);
static t_point2	**make_points(t_vector2 u, t_vector2 v, t_point3 **map, t_settings *settings);
static void	draw_line(t_point2 start, t_point2 end, mlx_image_t *image);

void	render(mlx_image_t *image, t_point3 **map, t_settings *settings, mlx_t *mlx)
{
	t_vector2	u;
	t_vector2	v;
	int			x;
	int			y;
	t_point2	**points;

	(void) mlx;
	memset(image->pixels, 0, image->width * image->height * sizeof(int32_t));
	get_base_vectors(&u, &v, settings);
	points = make_points(u, v, map, settings);
	x = 0;
	while (x < settings->map_height)
	{
		y = 0;
		while (y < settings->map_width)
		{
			if (y != settings->map_width - 1)
				draw_line(points[x][y], points[x][y + 1], image);	
			if (x != settings->map_height - 1)
				draw_line(points[x][y], points[x + 1][y], image);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < settings->map_height)
	{
		free(points[x]);
		x++;
	}
	free(points);
}

static t_point2	get_iso_pos(t_point3 p,t_vector2 u, t_vector2 v, t_settings *settings)
{
	t_point2 res;

	res.x = u.x * (p.x - settings->index_offset_x);
	res.x += v.x * (p.y - settings->index_offset_y);
	res.x += settings->center_x;
	res.y = u.y * (p.x - settings->index_offset_x);
	res.y += v.y * (p.y - settings->index_offset_y);
	res.y += settings->center_y - settings->depth * p.z;
	return (res);
}

static t_point2	**make_points(t_vector2 u, t_vector2 v, t_point3 **map, t_settings *settings)
{
	int			x;
	int			y;
	t_point2	**res;

	res = calloc(sizeof(t_point2*), settings->map_width);
	x = 0;
	while (x < settings->map_height)
	{
		y = 0;
		res[x] = calloc(sizeof(t_point2), settings->map_width);
		while (y < settings->map_width)
		{
			res[x][y] = get_iso_pos(map[x][y], u, v, settings);
			res[x][y].color = map[x][y].color;
			y++;
		}
		x++;
	}
	return (res);
}

static void	draw_line(t_point2 start, t_point2 end, mlx_image_t *image)
{
	double	ratio;
	double	deltaX;
	double	deltaY;
	int		deltaColor;
	int		color;
	double	x;
	double	y;
	double	i = 0;

	if ((start.x < 0 && end.x < 0) || (start.y < 0 && end.y < 0)
		|| (start.x > WIDTH && end.x > WIDTH) || (start.y > HEIGHT && end.y > HEIGHT))
		return;
	ratio = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	deltaX = (end.x - start.x) / ratio;
	deltaY = (end.y - start.y) / ratio;
	deltaColor = (get_color(end.color) - get_color(start.color)) / ratio;
	x = start.x;
	y = start.y;
	color = get_color(start.color);
	while (i < ratio)
	{
		if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
			mlx_put_pixel(image, x, y, color);
		x += deltaX;
		y += deltaY;
		color += deltaColor;
		i++;
	}
}
