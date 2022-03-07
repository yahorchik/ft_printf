/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:53:17 by seulah            #+#    #+#             */
/*   Updated: 2021/11/17 08:53:19 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		hex_len(unsigned int num);
void	put_hex(unsigned int num, const char format);
int		print_hex(unsigned int num, const char format);
int		ptr_len(uintptr_t num);
void	put_ptr(uintptr_t num);
int		print_ptr(unsigned long long ptr);
int		num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		print_unsigned(unsigned int n);
int		print_str(char *str);
int		print_nbr(int n);
int		print_percent(void);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
void	itoa_n(int *n, int *negative);
char	*ft_strdup(const char *source);
int		ft_printf(const char *format, ...);

#endif
