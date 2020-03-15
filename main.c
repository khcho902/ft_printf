#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%-0 *.*d",10, 100, 1010);
	
	return (0);
}
