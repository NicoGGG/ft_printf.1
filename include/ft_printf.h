/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:38:59 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/23 13:44:13 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "libft.h"

typedef struct 	s_parsing
{
	int		sharp;
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		precision;
	int		width;
	char	conv;
}				t_parsing;

int			ft_printf(const char *format, ...);
char		*hex_conv(int value);
void		bin_add_one(char *bin, int dec);
void		bin_compl(char *bin);
char		*bin_conv_int(int value, int dec);
char		*ft_strupper(char *str);
void		ft_convert_nbr(char *string, int length, int special,
						signed int arg);
void		padd_blank_left(char *string, int length, int larg);
void		padd_blank_right(char *string, int length, int larg);
void		padd_zero_left(char *string, int length, int larg);
void		padd_plus_left(char *string, int length, int larg);
void		padd_plus_zero_left(char *string, int length, int larg);
void		padd_plus_right(char *string, int length, int larg);
void		ft_putnbrprint(long n);
int			ft_istype_flag(char c);
int			ft_isspecial_flag(char c);
void		padd_string_left(char *string, int *length, int special,
						char *strarg);
void		padd_string_right(char *string, int length, int special,
						char *strarg);



#endif
