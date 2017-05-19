#include <unistd.h>
#include "ft_printf.h"

void	ft_putcharprint(char c)
{
	write(1, &c, 1);
}

void	ft_putstrprint(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		ft_toupperprint(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

char	*ft_strupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

void	ft_putnbrprint(long n)
{
	char c;

//	if (n == -2147483648)
//	{
//		write(1, "-2147483648", 11);
//		return ;
//	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

int		ft_strlenprint(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
