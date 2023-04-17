#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char	c;

	printf(" :%d\n", printf("%.c", 'a'));
	printf(" :%d\n", ft_printf("%.c", 'a'));
}