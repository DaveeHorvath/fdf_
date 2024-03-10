/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:40:14 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/31 13:41:57 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*res;
	size_t		byte;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	byte = count * size;
	if (size > SIZE_MAX / count || count > SIZE_MAX / size || byte > 2147483648)
		return (0);
	res = malloc(count * size);
	if (!res)
		return (res);
	ft_bzero(res, count * size);
	return (res);
}
