/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:17 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/24 12:16:41 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strlcat() appends string src to the end of dst.  It will append at most 
dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
unless dstsize is 0 or the original dst string was longer than dstsize 
(in practice this should not happen as it means that either dstsize is
incorrect or that dst is not a proper string).
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;

	if (!dst && dst_size == 0)
		return (dst_size);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dst_size)
		return (dst_size + src_len);
	else
	{
		if (src_len < dst_size - dst_len)
		{
			ft_memcpy(dst + dst_len, src, src_len);
			dst[dst_len + src_len] = 0;
		}
		else
		{
			ft_memcpy(dst + dst_len, src, dst_size - dst_len);
			dst[dst_size - 1] = 0;
		}
		return (dst_len + src_len);
	}
}
