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

