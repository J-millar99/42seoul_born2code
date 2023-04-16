#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char	c;

	printf(" :%d\n", printf("%x", -1));
	printf(" :%d\n", ft_printf("%x",-1));
}