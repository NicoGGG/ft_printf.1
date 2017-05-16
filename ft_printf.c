/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:36:59 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/16 16:38:24 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_flag(const char **format, va_list ap)
{
	if (**format == 'd')
		ft_putnbr(va_arg(ap, int));
	if (**format == 's')
		ft_putstr(va_arg(ap, char *));
	if (**format == 'x')
		ft_putstr(hex_conv(va_arg(ap, int)));
	if (**format == 'p')
		ft_putstr(hex_conv(va_arg(ap, unsigned long)));
}

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*(format) == '%')
				ft_putchar('%');
			else
				convert_flag(&format, ap);
		}
		else
			ft_putchar(*format);
		format++;
	}
	return (1);
}
