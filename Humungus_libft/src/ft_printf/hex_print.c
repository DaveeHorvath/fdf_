/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:47:55 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/05 17:21:33 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	print_arg_hex_u(unsigned int n)
{
	int				dig;
	long			pow;

	if (n == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	dig = 0;
	pow = 1;
	while (n / pow)
	{
		pow *= 16;
		dig++;
	}
	print_hex(n, dig - 1, "0123456789ABCDEF");
	return (dig);
}

int	print_arg_hex_l(unsigned int n)
{
	int				dig;
	long			pow;

	if (n == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	dig = 0;
	pow = 1;
	while (n / pow)
	{
		pow *= 16;
		dig++;
	}
	print_hex(n, dig - 1, "0123456789abcdef");
	return (dig);
}

int	print_arg_pointer(unsigned long p)
{
	int		dig;
	size_t	pow;

	if (p == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	dig = 0;
	pow = 1;
	while (pow && (p / pow))
	{
		pow *= 16;
		dig++;
	}
	ft_putstr_fd("0x", 1);
	print_hex(p, dig - 1, "0123456789abcdef");
	return (dig + 2);
}

void	print_hex(unsigned long l, int digits, char *map)
{
	int				i;
	unsigned long	st_pow;

	st_pow = 1;
	i = 0;
	while (i++ < digits && st_pow)
		st_pow *= 16;
	i = 0;
	while (i <= digits)
	{
		ft_putchar_fd(map[(l / st_pow) % 16], 1);
		st_pow /= 16;
		i++;
	}
}
