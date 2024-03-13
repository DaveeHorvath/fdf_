/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:52:33 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/28 14:05:04 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min_of_two(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		res = ft_strdup("");
		if (!res)
			return (0);
		return (res);
	}
	res = (char *)malloc((min_of_two(len, ft_strlen(s)) + 1) * sizeof(char));
	i = 0;
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[i + start];
		if (!s[i + start])
			break ;
		i++;
	}
	res[i] = 0;
	return (res);
}
