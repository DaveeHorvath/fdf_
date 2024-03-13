/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:43:36 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/10 19:26:37 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/* managing the loop and passing the variable */
int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			i;
	int			replace_type;
	int			size;

	size = 0;
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		replace_type = should_replace((char *)s, i, ap);
		if ((replace_type == -2 && s[i] == '%') || replace_type == -1)
		{
			va_end(ap);
			return (-1);
		}
		if (replace_type != -2)
			i += 1;
		else
			ft_putchar_fd(s[i], 1);
		i++;
		size += (replace_type == -2) * 1 + (replace_type != -2) * replace_type;
	}
	va_end(ap);
	return (size);
}

int	should_replace(char *s, int i, va_list ap)
{
	if (ft_strncmp(s + i, "%c", 2) == 0)
		return (print_arg_char(va_arg(ap, int)));
	else if (ft_strncmp(s + i, "%s", 2) == 0)
		return (print_arg_string(va_arg(ap, char *)));
	else if (ft_strncmp(s + i, "%p", 2) == 0)
		return (print_arg_pointer(va_arg(ap, unsigned long)));
	else if (ft_strncmp(s + i, "%d", 2) == 0)
		return (print_arg_dec(va_arg(ap, int)));
	else if (ft_strncmp(s + i, "%i", 2) == 0)
		return (print_arg_dec(va_arg(ap, int)));
	else if (ft_strncmp(s + i, "%u", 2) == 0)
		return (print_arg_unsigned(va_arg(ap, unsigned int)));
	else if (ft_strncmp(s + i, "%x", 2) == 0)
		return (print_arg_hex_l(va_arg(ap, unsigned int)));
	else if (ft_strncmp(s + i, "%X", 2) == 0)
		return (print_arg_hex_u(va_arg(ap, unsigned int)));
	else if (ft_strncmp(s + i, "%%", 2) == 0)
		return (print_arg_prec());
	else
		return (-2);
}
