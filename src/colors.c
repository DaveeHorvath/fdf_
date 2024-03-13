/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:00:44 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/11 15:35:50 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	creates new integer based on the given color struct
	by bitshifting the values in the correct 8 bits
*/
int	get_color(t_color color)
{
	return (
		color.r << 24 | color.g << 16 | color.b << 8 | 255
	);
}
