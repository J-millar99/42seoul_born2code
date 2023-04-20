#include <stdio.h>
#include "../includes/ft_printf.h"

int	main()
{
	printf(" %d\n", printf("%d", "ser"));
	printf(" %d\n", ft_printf("%d", "ser"));
}