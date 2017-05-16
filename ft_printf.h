/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:38:59 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/16 16:39:14 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);
int		ft_printf(const char *format, ...);
char	*hex_conv(int value);
int		ft_power(int nb, int p);
int		ft_strlen(char *str);
void	bin_add_one(char *bin, int dec);
void	bin_compl(char *bin);
char	*bin_conv_int(int value, int dec);

#endif
