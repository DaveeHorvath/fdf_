/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:40:25 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/28 13:45:11 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_whitespace(char *str);

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;
	long	prev;

	sign = 1;
	i = skip_whitespace((char *)str);
	res = 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		sign = (str[i] == '-') * -1 * sign + (str[i] != '-') * sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		prev = res;
		res = res * 10 + (str[i++] - '0');
		if ((res > 0 && prev < 0) || (res < 0 && prev > 0))
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
	}
	return ((int) sign * res);
}

static int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}
