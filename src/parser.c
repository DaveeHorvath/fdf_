/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:53:52 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/11 14:45:12 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

// color validation
int is_color(char *s)
{
	const char	*hex = "0123456789ABCDEF";
	while (*s)
	{
		if (ft_strchr(hex, *s) == NULL)
			return (0);
		s++;
	}
	return (1);
}

// color string into color struct
/*
	allows for:
		0x000->0xfff
		0x000000->0xffffff
	to add is the alpha value
*/
t_color	parse_color(char *s)
{
	const char	*hex = "0123456789ABCDEF";
	t_color		res;

	if (!s || ft_strncmp(s, "0x", 2) != 0)
		return ((t_color){.r=255, .g=255, .b=255, .a=255});
	if (ft_strlen(s) == 5)
	{
		// checks how manyeth letter it is
		res.r = 17 * (ft_strchr(hex, s[2]) - hex);
		res.g = 17 * (ft_strchr(hex, s[3]) - hex);
		res.b = 17 * (ft_strchr(hex, s[4]) - hex);
		res.a = 255;
	}
	else
	{
		// checks how manyeth letter it is and pushes the second one 16 forward
		res.r = 16 * (ft_strchr(hex, s[2]) - hex) + (ft_strchr(hex, s[3]) - hex);
		res.g = 16 * (ft_strchr(hex, s[4]) - hex) + (ft_strchr(hex, s[5]) - hex);
		res.b = 16 * (ft_strchr(hex, s[6]) - hex) + (ft_strchr(hex, s[7]) - hex);
		res.a = 255;
	}
	return (res);

}

/*
	reads file not relevant for presentation
*/

t_point3 **parse_map(char *s, t_settings *settings)
{
	int	fd;
	int	count = 0;
	int	width = 0;
	int x;
	int y;
	t_point3	**map;
	char		*first;
	char		**split;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (NULL);
	first = get_next_line(fd);
	if (first)
	{
		split = ft_split(first, ' ');
		width = 0;
		while (split[width])
			width++;
		count++;
		free(first);
	}
	while (get_next_line(fd))
		count++;
	map = calloc(count, sizeof(t_point3 *));
	x = 0;
	close(fd);
	fd = open(s, O_RDONLY);
	while (x < count)
	{
		split = ft_split(get_next_line(fd), ' ');
		map[x] = calloc(width, sizeof(t_point3));
		y = 0;
		while (split[y])
		{
			map[x][y].x = x;
			map[x][y].y = y;
			map[x][y].z = ft_atoi(ft_split(split[y], ',')[0]);
			map[x][y].color = parse_color(ft_split(split[y], ',')[1]);
			free(split[y]);
			y++;
		}
		free(split);
		x++;
	}
	// sets remaining settings
	settings->map_height = count;
	settings->map_width = width;
	settings->index_offset_x = count / 2;
	settings->index_offset_y = width / 2;
	return (map);
}
