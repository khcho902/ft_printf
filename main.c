#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%000-0.0010c ", 'A', 'B', 'C', 'D');
	
	return (0);
}
