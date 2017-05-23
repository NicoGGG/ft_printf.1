/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:39:00 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/24 20:26:54 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	dec(int n)
{
	if (n > -10 && n < 10)
		return (1);
	else
		return (dec(n / 10) + 1);
}

void		fill_number(int n, char *result, int dec, t_parsing parse)
{
	int		width;

	if (parse.precision > dec)
	{
		width = dec;
		dec = parse.precision;
	}
	if (parse.plus == 1)
		dec++;
	while ((n / 10))
	{
		result[dec] = (n % 10) * -1 + 48;
		n /= 10;
		dec--;
	}
	while (dec)
	{
		if (parse.precision || parse.zero)
			result[dec] = '0';
		else if (parse.width)
			result[dec] = ' '
	}
}

char		*print_itoa(int n, t_parsing parse)
{
	int		nbd;
	char	*result;
	int		tmp;

	tmp = n;
	nbd = dec(n);
	if (n >= 0)
		n = -n;
	else
		nbd++;
	if (nbd < parse.width)
		nbd = parse.width;
	if ((result = malloc(sizeof(char) * nbd + 1)) == NULL)
		return (NULL);
	result[nbd] = 0;
	nbd--;
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n)
	{
		result[nbd] = -(n % 10) + 48;
		n /= 10;
		nbd--;
	}
	return (result);
}
