/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:23:02 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/29 16:22:52 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (dst_size <= 0)
		return (ft_strlen(src));
	while (i < dst_size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	((char *) dst)[i] = 0;
	return (ft_strlen(src));
}
