/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:58:04 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/19 20:58:06 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padd_string_right(char *string, int length, int special, char *strarg)
{
	int		larg;

	larg = ft_strlen(strarg);
	if (special <= 7 && special > 3)
		padd_blank_right(string, length, larg);
	else if (special > 11 && special <= 15)
		padd_blank_right(string, length, larg);
}

void	padd_string_left(char *string, int *length, int special, char *strarg)
{
	int		larg;

	larg = ft_strlen(strarg);
	if (special <= 1)
		padd_blank_left(string, *length, larg);
	else if (special <= 3)
		padd_zero_left(string, *length, larg);
	else if (special <= 9 && special > 7)
		padd_plus_left(string, *length, larg);
	else if (special <= 11 && special > 9)
		padd_plus_zero_left(string, *length, larg);
	else if (special <= 15 && special > 11)
	{
		string = ft_strcatchar(string, '+');
		*length -= 1;
	}
}

void	ft_convert_nbr(char *string, int length, int special, signed int arg)
{
	char	*strarg;
	int		larg;

	strarg = ft_itoa(arg);
	larg = ft_strlen(strarg);
	//printf("TEST ITOA AND LARG AND LENGTH AND SPECIAL %s, %d, %d, %d\n", strarg, larg, length, special);
	if (larg < length)
		padd_string_left(string, &length, special, strarg);
	string = ft_strcat(string, strarg);
	if (larg < length)
		padd_string_right(string, length, special, strarg);
}
