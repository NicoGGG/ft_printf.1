/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:36:11 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/16 16:38:09 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*bin_conv_int(int value, int dec)
{
	char	*result;

	if ((result = malloc(sizeof(char) * dec + 1)) == NULL)
		return (NULL);
	result[dec] = 0;
	while (--dec >= 0)
	{
		result[dec] = (value % 2) * -1 + '0';
		value /= 2;
	}
	return (result);
}

void	bin_compl(char *bin)
{
	int i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] == '0')
			bin[i] = '1';
		else
			bin[i] = '0';
		i++;
	}
}

void	bin_add_one(char *bin, int dec)
{
	if (bin[dec] == '0')
		bin[dec] = '1';
	else
	{
		bin[dec] = '0';
		bin_add_one(bin, dec - 1);
	}
}

void	bin_neg(char *bin, int dec)
{
	bin_compl(bin);
	bin_add_one(bin, dec);
}
