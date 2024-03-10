/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:49:35 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/10 17:30:30 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (!src && !dst)
		return ((void *) 0);
	if (src == dst)
		return (dst);
	if (src < dst && src + n >= dst)
	{
		i = 0;
		while (i < n)
		{
			((char *)dst)[n - i - 1] = ((char *)src)[n - i - 1];
			i++;
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}
