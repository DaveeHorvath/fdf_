/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:24:08 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/05 17:22:02 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *s, ...);
int				should_replace(char *s, int i, va_list ap);
int				print_arg_char(int c);
int				print_arg_string(char *s);
int				print_arg_dec(int n);
int				print_arg_pointer(unsigned long p);
int				print_arg_hex_u(unsigned int n);
int				print_arg_hex_l(unsigned int n);
int				print_arg_unsigned(unsigned int n);
void			print_hex(unsigned long l, int digits, char *map);
int				print_arg_prec(void);
int				count_digits_base(long n, int base);

#endif
