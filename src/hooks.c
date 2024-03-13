/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:22:43 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/11 15:48:45 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include <stdlib.h>

void	ft_keyhook(void *params)
{
	t_param *p;

	p = (t_param *)params;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(p->mlx);
	if (mlx_is_key_down(p->mlx, MLX_KEY_UP))
		p->settings->center_y -= 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_DOWN))
		p->settings->center_y += 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		p->settings->center_x -= 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		p->settings->center_x += 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
		p->settings->elips_b += 1;
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
		p->settings->elips_b -= 1;
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
		p->settings->rotation += 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
		p->settings->rotation -= 5;
	if (p->settings->elips_b > p->settings->elips_a)
		p->settings->elips_b = p->settings->elips_a;
	if (p->settings->elips_b < 0)
		p->settings->elips_b = 0;
	render(p->image, p->map, p->settings, p->mlx);
}

void	ft_scrollhook(double xdelta, double ydelta, void* params)
{
	t_param *p;

	(void) xdelta;
	p = (t_param *)params;
	if (ydelta > 0)
		p->settings->zoom *= 1.2;
	else if (ydelta < 0)
		p->settings->zoom /= 1.2;
	p->settings->depth = 2 * p->settings->zoom;
	render(p->image, p->map, p->settings, p->mlx);
}

/*void	ft_mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* params)
{
	t_param					*p;
	static t_mouse_event	me;
	int						x;
	int						y;

	p = (t_param *)params;
	if (action == MLX_RELEASE)
	{
		p->settings->rotation_speed = 0;
		p->mouse = NULL;
	}
	if (action == MLX_PRESS)
	{
		p->mouse = &me;
		mlx_get_mouse_pos(p->mlx, &x, &y);
		p->mouse->start.x = x;
		p->mouse->start.y = y;
	}
	if (action == MLX_REPEAT)
	{
		mlx_get_mouse_pos(p->mlx, &x, &y);
		p->mouse->end.x = x;
		p->mouse->end.y = y;
		set_rotation();
	}
	render(p->image, p->map, p->settings, p->mlx);
}*/

void	ft_hook(mlx_t *mlx, mlx_image_t *image, t_point3 **map, t_settings *settings)
{
	static t_param *param = NULL;

	if (!param)
	{
		param = calloc(sizeof(t_param), 1);
		param->mlx = mlx;
		param->settings = settings;
		param->map = map;
		param->image = image;
	}
	mlx_loop_hook(mlx, ft_keyhook, param);
	mlx_scroll_hook(mlx, ft_scrollhook, param);
	//mlx_mouse_hook(mlx, ft_mouse, &param);
}

