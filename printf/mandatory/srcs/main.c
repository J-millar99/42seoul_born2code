#include <stdio.h>
#include "../includes/ft_printf.h"

void test(void){}

int	main()
{
	printf(" %d\n", printf("%2147483645s"), "hi");
	// printf(" %d\n", printf("%% %s %s", 1));
	// printf(" %d\n", printf("%% %s %s"));
	printf(" %d\n", ft_printf("%%"));
}
  