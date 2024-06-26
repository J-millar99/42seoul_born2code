#include <stdio.h>
#include "../includes/ft_printf_bonus.h"
#include <limits.h>

int	main()
{
	printf("===%%c===\n");
	printf(" %d\n", printf("%-c", '\0'));
	printf(" %d\n", ft_printf("%-c", '\0'));
	printf(" %d\n", printf("%-3c", '\0'));
	printf(" %d\n", ft_printf("%-3c", '\0'));
	printf(" %d\n", printf("%-c", 'a'));
	printf(" %d\n", ft_printf("%-c", 'a'));
	printf(" %d\n", printf("%-3c", 'a'));
	printf(" %d\n", ft_printf("%-3c", 'a'));

	printf("===%%s===\n");
	printf(" %d\n", printf("%-s", NULL));
	printf(" %d\n", ft_printf("%-s", NULL));
	printf(" %d\n", printf("%-8s", NULL));
	printf(" %d\n", ft_printf("%-8s", NULL));
	printf(" %d\n", printf("%-s", ""));
	printf(" %d\n", ft_printf("%-s", ""));
	printf(" %d\n", printf("%-8s", ""));
	printf(" %d\n", ft_printf("%-8s", ""));
	printf(" %d\n", printf("%-s", "12345"));
	printf(" %d\n", ft_printf("%-s", "12345"));
	printf(" %d\n", printf("%-8s", "12345"));
	printf(" %d\n", ft_printf("%-8s", "12345"));

	printf("===%%d===\n");
	printf(" %d\n", printf("%-d", 0));
	printf(" %d\n", ft_printf("%-d", 0));
	printf(" %d\n", printf("%-3d", 0));
	printf(" %d\n", ft_printf("%-3d", 0));
	printf(" %d\n", printf("%-d", 123));
	printf(" %d\n", ft_printf("%-d", 123));
	printf(" %d\n", printf("%-5d", 123));
	printf(" %d\n", ft_printf("%-5d", 123));
	printf(" %d\n", printf("%-d", -123));
	printf(" %d\n", ft_printf("%-d", -123));
	printf(" %d\n", printf("%-5d", -123));
	printf(" %d\n", ft_printf("%-5d", -123));

	printf("===%%u===\n");
	printf(" %d\n", printf("%-u", 0));
	printf(" %d\n", ft_printf("%-u", 0));
	printf(" %d\n", printf("%-3u", 0));
	printf(" %d\n", ft_printf("%-3u", 0));
	printf(" %d\n", printf("%-u", 123));
	printf(" %d\n", ft_printf("%-u", 123));
	printf(" %d\n", printf("%-5u", 123));
	printf(" %d\n", ft_printf("%-5u", 123));
	printf(" %d\n", printf("%-u", -123));
	printf(" %d\n", ft_printf("%-u", -123));
	printf(" %d\n", printf("%-5u", -123));
	printf(" %d\n", ft_printf("%-5u", -123));

	printf("===%%x===\n");
	printf(" %d\n", printf("%-x", 0));
	printf(" %d\n", ft_printf("%-x", 0));
	printf(" %d\n", printf("%-3x", 0));
	printf(" %d\n", ft_printf("%-3x", 0));
	printf(" %d\n", printf("%-x", 123));
	printf(" %d\n", ft_printf("%-x", 123));
	printf(" %d\n", printf("%-5x", 123));
	printf(" %d\n", ft_printf("%-5x", 123));
	printf(" %d\n", printf("%-x", -123));
	printf(" %d\n", ft_printf("%-x", -123));
	printf(" %d\n", printf("%-x", -123));
	printf(" %d\n", ft_printf("%-5x", -123));

	printf("===%%===\n");
	printf(" %d\n", printf("%-%"));
	printf(" %d\n", ft_printf("%-%"));
	printf(" %d\n", printf("%-3%"));
	printf(" %d\n", ft_printf("%-3%"));
}