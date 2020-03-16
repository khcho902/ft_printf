#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{

	ft_printf("%-*.*s\n %s\n", 22,103, "ahah");


	printf("%-*.*s\n %s\n",22,103, "ahah");
	
	return (0);
}
