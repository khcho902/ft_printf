#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int res;

	res = ft_printf("%*d\n",-10, 0);

	printf("\n\nres : %d\n", res);
	return (0);
}
