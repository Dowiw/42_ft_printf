#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	#include <stdio.h>
	#include <limits.h>
	char c = 'a';
	char *str = "bonjour";
	int a = INT_MIN;
	printf("hello %c hello %s hello %i, %p\n", c, str, a, str);
	ft_printf("hello %c hello %s hello %i, %p\n", c, str, a, str);
	return 0;
}
