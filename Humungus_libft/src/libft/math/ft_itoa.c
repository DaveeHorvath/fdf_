/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:20 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/28 13:54:35 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_char(char *a, char *b)
{
	char	temp;

	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}

static void	reverse_str(char *s)
{
	int	i;
	int	len;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len / 2)
	{
		swap_char(s + i, s + len - i - 1);
		i++;
	}
}

static int	get_digits(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n -= n % 10;
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		sign;
	long	num;

	sign = n < 0;
	i = 0;
	num = n - (long)sign * 2 * (long)n;
	res = ft_calloc(get_digits(n) + 1, sizeof(char));
	if (!res)
		return (0);
	if (n == 0)
		res[0] = '0';
	while (num > 0)
	{
		res[i++] = num % 10 + '0';
		num -= num % 10;
		num /= 10;
	}
	if (sign)
		res[i] = '-';
	reverse_str(res);
	res[get_digits(n)] = 0;
	return (res);
}
