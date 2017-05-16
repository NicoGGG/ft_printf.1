/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:36:43 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/16 16:36:49 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int p)
{
	if (p < 0)
		return (0);
	else if (p == 0)
		return (1);
	else
		return (nb * ft_power(nb, p - 1));
}