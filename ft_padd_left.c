#include "ft_printf.h"

void	padd_blank_left(char *string, int length, int larg)
{
	char	*tmp;

	tmp = ft_strnew(length - larg);
	tmp = ft_memset(tmp, ' ', length - larg);
	string = ft_strncat(string, tmp, length - larg);
}

void	padd_zero_left(char *string, int length, int larg)
{
	char	*tmp;

	tmp = ft_strnew(length - larg);
	tmp = ft_memset(tmp, '0', length - larg);
	string = ft_strncat(string, tmp, length - larg);
}

void	padd_plus_left(char *string, int length, int larg)
{
	char	*tmp;

	tmp = ft_strnew(length - larg);
	tmp = ft_memset(tmp, ' ', length - larg - 1);
	string = ft_strncat(string, tmp, length - larg);
	string = ft_strcatchar(string, '+');
}

void	padd_plus_zero_left(char *string, int length, int larg)
{
	char	*tmp;

	tmp = ft_strnew(length - larg);
	tmp = ft_memset(tmp, '0', length - larg - 1);
	string = ft_strcatchar(string, '+');
	string = ft_strncat(string, tmp, length - larg);
}