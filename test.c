#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"

void	test_var(char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	printf("%s\n", str);
	printf("%d\n", va_arg(ap, int));

}

int		main(int argc, char const *argv[])
{
	char *str;

	str = strdup("coucou");
	test_var(str, 42);
	printf("PRINTF -10 %#X\n", -66);
	printf("PRINTF  10 %#10X\n", 10);
	printf("\n%d ", printf("%% salut %s %d %x %x %lu %p\n", str, 42, 300, -66, str, str));
	ft_printf("\n%d ", ft_printf("%% salut %s %d %x %x %d %p\n", str, 42, 300, -66, str, str));
	return 0;
}