#include "ft_printf.h"

int ft_puthex_lowcase(unsigned int n)
{
	char		buffer[16];
	int				i;
	int				out;
	unsigned int	temp;

	i = 0;
	out = 0;
	temp = 0;
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			buffer[i++] = temp + '0';
		else
			buffer[i++] = temp - 10 + 'a';
		n /= 16;
	}
	while (i--)
		out += ft_putchar(buffer[i]);
	return (out);
}

// int main() {
// 	#include <stdio.h>
// 	unsigned int test = 256;
// 	printf("%i\n", test % 16);

// 	int n = ft_puthex_lowcase(test);
// 	printf("\nn: %i\n", n);
// 	return (0);
// }
