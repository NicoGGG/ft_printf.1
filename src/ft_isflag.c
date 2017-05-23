int		ft_issize_flag(char c)
{
	if (c == 'l')
		return (1);
	if (c == 'h')
		return (1);
	return (0);
}

int		ft_istype_flag(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'c')
		return (1);
	if (c == 'u')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int		ft_isspecial_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}