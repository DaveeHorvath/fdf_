/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:01:59 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/11 12:02:40 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// steal from wikipedia
static double	get_radians(double angle)
{
	return (angle * 3.141592654 / 180);
}

/*
	uses the formula either from the wiki page for isometric rendering
	https://en.wikipedia.org/wiki/Isometric_projection#Mathematics
	https://www.wolframalpha.com

	or

	from wiki page of Ellipse https://en.wikipedia.org/wiki/Ellipse

	we can use this since an Ellipse can be written inside of any paralelogramm,
	and paralelogramms with the same Ellipse have the same area
	https://en.wikipedia.org/wiki/Ellipse#Theorem_of_Apollonios_on_conjugate_diameters
*/
void	get_base_vectors(t_vector2 *u, t_vector2 *v, t_settings *settings)
{
	double	radians;

	radians = get_radians(settings->rotation);
	u->x = settings->elips_a * cos(radians);
	u->y = settings->elips_b * sin(radians);
	v->x = -settings->elips_a * sin(radians);
	v->y = settings->elips_b * cos(radians);
	// scale to the correct zoom
	u->x *= settings->zoom;
	u->y *= settings->zoom;
	v->x *= settings->zoom;
	v->y *= settings->zoom;
}

