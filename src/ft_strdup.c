/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:51:43 by seulah            #+#    #+#             */
/*   Updated: 2021/10/07 17:51:45 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strdup(const char *source)
{
	int		i;
	int		l;
	char	*str;

	l = 0;
	while (source[l] != '\0')
		l++;
	str = (char *)malloc(sizeof(*str) * (l + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < l)
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
