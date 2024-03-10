/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:48:48 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/28 14:06:25 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c == 0)
		return ((char *)(s + i));
	else
	{
		while (i >= 0)
		{
			if (s[i] == (unsigned char)c)
				return ((char *)(s + i));
			i--;
		}
		return ((char *)0);
	}
}
