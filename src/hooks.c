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

/* 
	one generic hook for all keypresses, could use the keyhook
	moves and clamps the settings values
*/
void	ft_keyhook(void *params)
{
	t_param *p;

	p = (t_param *)params;
	// closing window
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(p->mlx);
	// center movement -> basic translate
	if (mlx_is_key_down(p->mlx, MLX_KEY_UP))
		p->settings->center_y -= 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_DOWN))
		p->settings->center_y += 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		p->settings->center_x -= 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		p->settings->center_x += 5;
	// rotation for looking more from top has to be clamped 
	// to be at max the other axis of the elips
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
		p->settings->elips_b += 1;
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
		p->settings->elips_b -= 1;
	// rotation hooks, changes the angle of the first point on the elipse
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
		p->settings->rotation += 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
		p->settings->rotation -= 5;
	// clamping for the height
	if (p->settings->elips_b > p->settings->elips_a)
		p->settings->elips_b = p->settings->elips_a;
	if (p->settings->elips_b < 0)
		p->settings->elips_b = 0;
	render(p->image, p->map, p->settings, p->mlx);
}

/*
	scrollhook for zooming
	*= and /= nsure an always valid zoomvalue, since an 
	exponential function can never be 0 or negative,
	only issue if that after high increasement its non linear
*/
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


/*
	creates new stuct for passing the relevant values for the hooks
	joins the hooks to the mlx
*/
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
}
