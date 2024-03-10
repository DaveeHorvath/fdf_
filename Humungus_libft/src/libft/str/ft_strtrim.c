/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:34:49 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/26 14:12:10 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	s_size;
	int		start;
	int		end;
	char	*res;

	if (!set || !s)
		return (0);
	s_size = ft_strlen(s);
	start = 0;
	while (char_in_set(s[start], set))
		start++;
	end = 0;
	if ((size_t)start == s_size)
		return (ft_substr(s, 0, 0));
	while (char_in_set(s[s_size - end - 1], set))
		end++;
	res = ft_substr(s, start, s_size - start - end);
	if (!res)
		return ((char *) 0);
	return (res);
}
