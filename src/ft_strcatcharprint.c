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