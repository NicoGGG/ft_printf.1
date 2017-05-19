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

	long			t1;
	unsigned long	t2;

	t1 = -4200000000;
	t2 = 7000000000;
	str = strdup("coucou");

	printf("Storage size for int : %lu \n", sizeof(int));
	printf("Storage size for long : %lu \n", sizeof(long));
	printf("Storage size for unsigned int : %lu \n", sizeof(unsigned int));
	printf("Storage size for unsigned long : %lu \n", sizeof(unsigned long));
	printf("Storage size for short short int : %lu \n", sizeof(short int));
	printf("Storage size for short unsigned int : %lu \n", sizeof(short unsigned int));
	printf("Storage size for char : %lu \n", sizeof(char));
	printf("Storage size for unsigned char : %lu \n\n", sizeof(unsigned char));

	printf("PRINTF    = %d\n", (printf("PRINTF    TEST PRECISION 0 left :%05d, - right :%-6d, + left :%+6d, rien :%8d, +0 left :%0+8d, +- right %+-8d,\n", 1000, 2000, 3000, 4000, 5000, 6000)));
	ft_printf("FT_PRINTF = %d\n", (ft_printf("FT_PRINTF TEST PRECISION 0 left :%05d, - right :%-6d, + left :%+6d, rien :%8d, +0 left :%0+8d, +- right %+-8d,\n", 1000, 2000, 3000, 4000, 5000, 6000)));

/*	printf("TEST 0 PADDING %d\n", 42);
	printf("INTMAX_T ET UINTMAX_T %jd et %ju\n", t1, t2);
	printf("PRINTF -66 %X\n", -66);
	ft_printf("FT_PRINTF -66 %X\n", -66);
	printf("PRINTF  66 %#010X\n", 10);
	printf("PRINTF TEST ESPACE % d\n", 42);
	ft_printf("FT_PRINTF TEST ESPACE % d\n", 42);
	printf("PRINTF TEST u et U %u et %lD\n", -42, -3000000000);
	printf("\n%d \n", printf("%%u salut %s %d %x %x %lu %p\n", str, 42, 300, -66, str, str));
	ft_printf("\n%d \n", ft_printf("%%u salut %s %d %x %x %d %p\n", str, 42, 300, -66, str, str));

	ft_printf("%d\n", ft_printf("Les bornes pour %%d :  %d, %d\n", -2147483648, 2147483647));
	printf("%d\n", printf("Les bornes pour %%d :  %d, %d\n", -2147483648, 2147483647));
  	ft_printf("%d\n", ft_printf("Les bornes pour %%u:  %u, %u\n", 0, 4294967295));
  	printf("%d\n", printf("Les bornes pour %%u :  %u, %u\n", 0, 4294967295));
 //	ft_printf("%d\n", ft_printf("Les bornes :  %o, %o\n", 0, 4294967295));
  	ft_printf("%d\n", ft_printf("Les bornes pour %%x:  %x, %x\n", 0, t2));
  	printf("%d\n", printf("Les bornes pour %%x:  %x, %x\n", 0, t2));
*/
	return 0;
}