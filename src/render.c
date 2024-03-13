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
	// gets the 2 vectors for the isometric rendering
	get_base_vectors(&u, &v, settings);
	// generates the vector 2s for all the 
	points = make_points(u, v, map, settings);
	x = 0;
	// foreach point draw the lines tothe neighbours
	while (x < settings->map_height)
	{
		y = 0;
		while (y < settings->map_width)
		{
			//  if its not on the edge
			if (y != settings->map_width - 1)
				draw_line(points[x][y], points[x][y + 1], image);	
			if (x != settings->map_height - 1)
				draw_line(points[x][y], points[x + 1][y], image);
			y++;
		}
		x++;
	}
	// cleanup
	x = 0;
	while (x < settings->map_height)
	{
		free(points[x]);
		x++;
	}
	free(points);
}

/*
	transforms vector 3s into vector 2s based on the two base vectors of the space
	adds depth from the settings

	offsets x and y by the center of the whole thing and
	adds an index offset for the middle point to be the actual center of rotation
*/

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

/*
	generates the iso values for the points and takes the color from the vector 3 as well
*/
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


/*
	gets the difference in values like color x and y
	takes the DISTANCE of the two points and steps along this modifying the values 
	by the delta/DISTANCE so they interpolate between these 2
	multiple interpolation algorithms could be used to get smoother results
*/
static void	draw_line(t_point2 start, t_point2 end, mlx_image_t *image)
{
	// distance between points
	double	ratio;
	// differences
	double	deltaX;
	double	deltaY;
	int		deltaColor;
	// current values
	int		color;
	double	x;
	double	y;
	// distance step by step
	double	i = 0;

	// btoh of them outside the screen
	if ((start.x < 0 && end.x < 0) || (start.y < 0 && end.y < 0)
		|| (start.x > WIDTH && end.x > WIDTH) || (start.y > HEIGHT && end.y > HEIGHT))
		return;
	// pythagorian theorem
	ratio = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	deltaX = (end.x - start.x) / ratio;
	deltaY = (end.y - start.y) / ratio;
	deltaColor = (get_color(end.color) - get_color(start.color)) / ratio;
	// initial values
	x = start.x;
	y = start.y;
	color = get_color(start.color);
	// do the distance step by step
	while (i < ratio)
	{
		// if the current pixel is in the screen
		if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
			mlx_put_pixel(image, x, y, color);
		// move the values enough and step one off the distance
		x += deltaX;
		y += deltaY;
		color += deltaColor;
		i++;
	}
}
