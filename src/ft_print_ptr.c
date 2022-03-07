/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:54:20 by seulah            #+#    #+#             */
/*   Updated: 2021/12/01 08:54:22 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	print_ptr(unsigned long long ptr)
{
	int	print_l;

	print_l = 0;
	print_l += write(1, "0x", 2);
	if (ptr == 0)
		print_l += write(1, "0", 1);
	else
	{
		put_ptr(ptr);
		print_l += ptr_len(ptr);
	}
	return (print_l);
}
