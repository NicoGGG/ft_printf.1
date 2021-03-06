/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:03:34 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/19 16:04:35 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatchar(char *dst, char c)
{
	int i;

	i = 0;
	while (dst[i])
		i++;
	dst[i++] = c;
	dst[i] = 0;
	return (dst);
}
