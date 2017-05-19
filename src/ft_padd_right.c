/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padd_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:01:43 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/19 21:02:44 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padd_plus_right(char *string, int length, int larg)
{
	char	*tmp;

	tmp = ft_strnew(length - larg);
	tmp = ft_memset(tmp, ' ', length - larg);
	string = ft_strcatchar(string, '+');
	string = ft_strncat(string, tmp, length - larg);
}

void	padd_blank_right(char *string, int length, int larg)
{
	char	*tmp;

	tmp = ft_strnew(length - larg);
	tmp = ft_memset(tmp, ' ', length - larg);
	string = ft_strncat(string, tmp, length - larg);
}
