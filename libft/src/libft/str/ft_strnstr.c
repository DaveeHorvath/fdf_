/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:30:55 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/31 13:49:44 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (!haystack && len != 0)
		((char *)haystack)[0] = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (i + needle_len <= len && haystack[i])
	{
		if (ft_strncmp(needle, haystack + i, needle_len) == 0)
			return ((char *)haystack + i);
		else
			i++;
	}
	return ((char *)0);
}
