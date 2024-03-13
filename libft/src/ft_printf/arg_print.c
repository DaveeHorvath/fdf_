/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:47:39 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/14 14:42:41 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_arg_char(int c)
{
	ft_putchar_fd((char)c, 1);
	return (1);
}

int	print_arg_string(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	print_arg_dec(int n)
{
	ft_putnbr_fd(n, 1);
	if (n == 0)
		return (1);
	return (count_digits_base(n, 10) + (n < 0));
}

int	print_arg_prec(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	print_arg_unsigned(unsigned int n)
{
	ft_putnbrlong_fd(n, 1);
	if (n == 0)
		return (1);
	return (count_digits_base(n, 10));
}
