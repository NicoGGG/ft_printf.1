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

int		convert_special_flag(const char **format)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (**format)
	{
		if (**format == '#')
			result += 1;
		if (**format == '0')
			result += 2;
		if (**format == '-')
			result += 4;
		if (**format == '+')
			result += 8;
		if (**format == '#' || **format == '0' || **format == '-'
			|| **format == '+')
			*format += 1;
		else
			return (result);
	}
	return (result);
}

void	convert_flag(const char **format, va_list ap, char *string)
{
	int		special;
	int		length;

	length = 0;
	special = convert_special_flag(format);
	if (ft_isdigit(**format))
		length = ft_atoi(*format);
	while (ft_isdigit(**format))
		*format += 1;
	if (**format == 'd' || **format == 'i')
		ft_convert_nbr(string, length, special, va_arg(ap, signed int));
	if (**format == 's')
		ft_putstrprint(va_arg(ap, char *));
	if (**format == 'x')
		ft_putstrprint(hex_conv(va_arg(ap, int)));
	if (**format == 'X')
		ft_putstrprint(ft_strupperprint(hex_conv(va_arg(ap, int))));
	if (**format == 'p')
		ft_putstrprint(hex_conv(va_arg(ap, long int)));
	if (**format == 'c')
		ft_putcharprint(va_arg(ap, int));
	if (**format == 'u')
		ft_putnbrprint(va_arg(ap, unsigned int));
	if (**format == ' ')
	{
		if (special >= 8)
			*format += 1;	
		else
			string = ft_strcatchar(string, 32);
	}
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*string;
	size_t	ret;

	if ((string = ft_strnew(4096)) == NULL)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*(format) == '%')
				string = ft_strcatcharprint(string, '%');
			else
				convert_flag(&format, ap, string);
		}
		else
			string = ft_strcatcharprint(string, *format);
		format++;
	}
	ft_putstrprint(string);
	ret = ft_strlenprint(string);
	return (ret);
}