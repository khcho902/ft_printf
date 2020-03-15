#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%-*c\n %c %c %c    \n",5,'a', 'b', 'c', 'd');
	
	return (0);
}
