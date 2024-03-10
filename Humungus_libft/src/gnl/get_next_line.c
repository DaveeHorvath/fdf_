/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:02:13 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/13 00:18:16 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*prev = 0;
	char		buf[BUFFER_SIZE];
	int			just_read;
	char		*tofree;

	if (has_next_line(prev) != -1)
		return (get_return(&prev, buf));
	just_read = read(fd, buf, BUFFER_SIZE);
	if (just_read == -1 || just_read == 0)
		return (return_if_not_read(buf, &prev, just_read));
	while (just_read)
	{
		tofree = prev;
		prev = concat(prev, buf, just_read);
		if (prev == NULL)
		{
			free(tofree);
			return (0);
		}
		if (has_next_line(prev) != -1)
			return (get_return(&prev, buf));
		just_read = read(fd, buf, BUFFER_SIZE);
	}
	return (return_if_not_read(buf, &prev, just_read));
}

char	*return_if_not_read(char *buf, char **prev, int just_read)
{
	char	*res;

	if (just_read == -1)
	{
		if (*prev)
			free(*prev);
		*prev = 0;
		buf = 0;
		return (0);
	}
	if (ft_strlen(*prev) == 0)
	{
		res = 0;
		if (*prev)
			free(*prev);
		*prev = 0;
		return (0);
	}
	res = substring(*prev, ft_strlen(*prev));
	if (*prev)
		free(*prev);
	*prev = 0;
	return (res);
}

char	*concat(char *prev, char *buf, int read)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(ft_strlen(prev) + read + 1);
	if (!res)
		return (0);
	i = 0;
	if (prev)
	{
		while (prev[i])
		{
			res[i] = prev[i];
			i++;
		}
		free(prev);
	}
	j = 0;
	while (j < read)
	{
		res[i + j] = buf[j];
		j++;
	}
	res[i + j] = 0;
	return (res);
}

char	*get_return(char **prev, char *buf)
{
	int		endl_index;
	char	*res;
	char	*mid;

	(void) buf;
	endl_index = has_next_line(*prev);
	res = substring(*prev, endl_index + 1);
	if (!res)
	{
		if (*prev)
			free(*prev);
		*prev = 0;
		return (0);
	}
	mid = *prev;
	*prev = shrink_prev(mid, endl_index);
	if (!prev)
	{
		free(res);
		return (0);
	}
	if (mid)
		free(mid);
	return (res);
}

char	*shrink_prev(char *prev, int endl_index)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(ft_strlen(prev) - endl_index + 1);
	if (!res)
		return (0);
	if (prev)
	{
		while (prev[endl_index + i + 1] && prev[endl_index + i])
		{
			res[i] = prev[endl_index + i + 1];
			i++;
		}
	}
	res[i] = 0;
	return (res);
}
