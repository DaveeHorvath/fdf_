/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:53:52 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/10 18:01:47 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

t_point3 **parse_map(char *s)
{
	int	fd;
	int	count;
	int x;
	int y;
	t_point3	**map;

	fd = open(s, O_RDONLY);
	while (get_next_line(fd))
		count++;
	map = calloc()
}