/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:43:23 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/26 14:10:44 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	else
	{
		while (s[i])
		{
			if (s[i] == (unsigned char) c)
				return ((char *)(s + i));
			i++;
		}
		return ((char *)0);
	}
}
