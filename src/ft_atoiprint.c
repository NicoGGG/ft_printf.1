int		ft_atoiprint(const char *str)
{
	int	result;
	int	i;
	int sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] > 7 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}