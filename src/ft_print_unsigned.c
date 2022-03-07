/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:19:46 by seulah            #+#    #+#             */
/*   Updated: 2021/12/01 08:19:47 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len ++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	print_unsigned(unsigned int n)
{
	int		print_l;
	char	*num;

	print_l = 0;
	if (n == 0)
		print_l += write (1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_l += print_str(num);
		free (num);
	}
	return (print_l);
}
