/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:50:32 by seulah            #+#    #+#             */
/*   Updated: 2021/11/17 08:50:36 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	format_check(va_list ar, const char format)
{
	int	print_l;

	print_l = 0;
	if (format == 'c')
		print_l += print_char(va_arg(ar, int));
	else if (format == 's')
		print_l += print_str(va_arg(ar, char *));
	else if (format == 'd' || format == 'i')
		print_l += print_nbr(va_arg(ar, int));
	else if (format == 'p')
		print_l += print_ptr(va_arg(ar, unsigned long long));
	else if (format == 'u')
		print_l += print_unsigned(va_arg(ar, unsigned int));
	else if (format == 'x' || format == 'X')
		print_l += print_hex(va_arg(ar, unsigned int), format);
	else if (format == '%')
		print_l += print_percent();
	return (print_l);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ar;
	int		print_l;

	i = 0;
	print_l = 0;
	va_start(ar, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_l += format_check(ar, format[i + 1]);
			i++;
		}
		else
			print_l += print_char(format[i]);
		i++;
	}
	va_end(ar);
	return (print_l);
}
