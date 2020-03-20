#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int res1;
	int res2;

	res1 = ft_printf("%d %%\n", 10);
	res2 = printf("%d %%\n", 10);

	printf("%d\n", res1);
	printf("%d\n", res2);

	return (0);
}
