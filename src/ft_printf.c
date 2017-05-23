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

char	*parsing_flags(const char **format)
{
	char	*result;

	if ((result = ft_strnew(20)) == NULL)
		return (NULL);
	while (**format)
	{
		if (**format == '#')
			*result = **format;
		if (**format == '0')
			*result = **format;
		if (**format == '-')
			*result = **format;
		if (**format == '+')
			*result = **format;
		if (**format == ' ')
			*result = **format;
		if (**format == '#' || **format == '0' || **format == '-'
			|| **format == '+' || **format == ' ')
			*format += 1;
		else
			break ;
		result += 1;
	}

	return (result);
}

char	*ft_trim_flags(char *special)
{
	char	*tmp;

	while (ft_strchr(special, '0') && ft_strchr(special, '-')
		|| ft_strchr(special, '0') && ft_strchr(special, '.'))
		{
			tmp = ft_strchr(special, '0');
			*tmp = 0;
			special = ft_strcat(special, tmp + 1);
		}
	while (ft_strchr(special, ' ') && ft_strchr(special, '+'))
	{
		tmp = ft_strchr(special, ' ');
		*tmp = 0;
		special = ft_strcat(special, tmp + 1);
	}

}

char	*ft_convert_format(char **format, t_padding parse)
{
	while (!(ft_istype_flag(**format)))
	{
		*special = **format;
		(*format)++;
	}
	*special = **format;
}

void	init_parse(t_parsing *parse)
{
	(*parse).sharp = 0;
	(*parse).minus = 0;
	(*parse).plus = 0;
	(*parse).zero = 0;
	(*parse).space = 0;
	(*parse).precision = 0;
	(*parse).width = 0;
	//(*parse).conv = ft_strnew(1);
}
void	convert_flag(const char **format, va_list ap, char *string)
{
	t_parsing	parse;
	char		*conversion;

	init_parse(&parse);
	if ((parsing_flags(format, &parse)) == NULL)
		return ;
	if (ft_isdigit(**format))
		parse.width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format) += 1;
	if (**format == '.')
		parse.precision = ft_atoi((*format) + 1);
	while (!(ft_istype_flag(**format)) && !(ft_issize_flag(**format)))
		(*format)++;
	conversion = ft_convert_format(format, parse);

/*	while (!(ft_istype_flag(**format)))
		(*format) += 1;
	if (**format == 'd' || **format == 'i')
		ft_convert_nbr(string, length, special, va_arg(ap, signed int));
	if (**format == 's')
		ft_putstr(va_arg(ap, char *));
	if (**format == 'x')
		ft_putstr(hex_conv(va_arg(ap, int)));
	if (**format == 'X')
		ft_putstr(ft_strupper(hex_conv(va_arg(ap, int))));
	if (**format == 'p')
		ft_putstr(hex_conv(va_arg(ap, long int)));
	if (**format == 'c')
		ft_putchar(va_arg(ap, int));
	if (**format == 'u')
		ft_putnbrprint(va_arg(ap, unsigned int));
	if (**format == '%')
	{
		if (1 < length)
			padd_string_left(string, &length, special, "%");
		string = ft_strcat(string, "%");
		if (1 < length)
			padd_string_right(string, length, special, "%");
	}
*/
/*	if (**format == ' ')
	{
		if (special >= 8)
			*format += 1;	
		else
			string = ft_strcatchar(string, 32);
	}
*/}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*string;
	size_t	ret;

/*	if ((string = ft_strnew(4096)) == NULL)
		return (-1);*/
	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			//convert_flag(&format, ap, string);
			convert_flag(&format, ap, ret);
		}
		else
			ft_putchar(*format);
	//		string = ft_strcatchar(string, *format);
		format++;
		ret++;
	}
	ft_putstr(string);
	//ret = ft_strlen(string);
	return (ret);
}
