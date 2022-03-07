/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:42:30 by seulah            #+#    #+#             */
/*   Updated: 2021/10/11 14:42:31 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	intlen(int n)
{
	int	i;

	i = 0;
	if (n < 10)
		return (0);
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i - 1);
}

void	itoa_n(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	itoa_n(&n, &neg);
	len = 2 + intlen(n);
	len += neg;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
