#include <stdio.h>
#include <stdarg.h>

void 	printNumbers(int args, ...)
{
	int i;
	va_list ap;

	va_start(ap, args);
	i = 0;
	while ( i < args)
	{
		int num = va_arg(ap, int);
		printf("%d " , num);
		i++;
	}
	va_end(ap);
	printf("\n");
}

int	main(void)
{
	printNumbers(1, 10);
	printNumbers(2, 10, 20);
	printNumbers(3, 10, 20, 30);
	printNumbers(4, 10, 20, 30, 40);

	return (0);
}
