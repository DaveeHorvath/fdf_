/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:01:59 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/10 16:38:22 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h";
#include <math.h>;

static double	get_radians(double angle)
{
	return (angle * 3.141592654 / 180);
}

void	get_base_vectors(t_vector2 *u, t_vector2 *v, t_settings *settings)
{
	double	radians;

	radians = get_radians(settings->rotation);
	u->x = settings->elips_a * cos(radians);
	u->y = settings->elips_b * sin(radians);
	v->x = -settings->elips_a * sin(radians);
	v->y = settings->elips_b * cos(radians);
	u->x *= settings->zoom;
	u->y *= settings->zoom;
	v->x *= settings->zoom;
	v->y *= settings->zoom;
}

