/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:37:22 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/16 16:37:23 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nb_dec(value)
{
	int dec;

	dec = 1;
	while ((value /= 16))
		dec++;
	return (dec);
}

char	*ft_convert(int value, int dec)
{
	char *result;

	if ((result = malloc(sizeof(char) * dec + 1)) == NULL)
		return (NULL);
	result[dec] = 0;
	while (--dec >= 0)
	{
		if (value % 16 >= 10)
			result[dec] = value % 16 + 87;
		else
			result[dec] = value % 16 + '0';
		value /= 16;
	}
	return (result);
}

char	*hex_from_bin(char *bin)
{
	int 	i;
	int 	bit;
	int 	count;
	char	*result;
	int 	j;

	if ((result = malloc(sizeof(char) * (ft_strlen(bin) / 4) + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (bin[i])
	{
		count = 0;
		bit = 0;
		while ((count / 4) == 0)
		{
			if (bin[i] == '1')
				bit += (8 / ft_power(2, count));
			count++;
			i++;
		}
		if (bit >= 10)
			result[j++] = bit + 87;
		else
			result[j++] = bit + 48;
	}
	result[j] = 0;
	return (result);
}

char	*hex_conv_neg(int value)
{
	char	*bin;
	int 	i;
	char	*result;

	i = 0;
	bin = bin_conv_int(value, 32);
	bin_compl(bin);
	bin_add_one(bin, 31);
	result = hex_from_bin(bin);


	return (result);
}

char	*hex_conv(int value)
{
	int				dec;
	char			*result;
	unsigned int	tmp;

	if (value < 0)
		return (hex_conv_neg(value));
	dec = nb_dec(value);
	tmp = (unsigned int)value;
	result = ft_convert(tmp, dec);
	return (result);
}
