#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int res1;

	res1 = ft_printf("%10.6s", NULL);

	printf("\n  res : %d\n", res1);

	return (0);
}
