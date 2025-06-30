/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:47:12 by kmonjard          #+#    #+#             */
/*   Updated: 2025/06/17 19:48:50 by kmonjard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putint(int n)
{
	long nbr;

	nbr = n;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	while (nbr >= 10)
	{
		ft_putint(nbr / 10);
		ft_putint(nbr % 10);
		return ;
	}
}

void	ft_puthex(void *p)
{
	#include <stdint.h>
	uintptr_t hex;
	uintptr_t temp;

	hex = (uintptr_t)p;
	if (hex == 0)
	{
		write(1, "(nil)", 5);
		return ;
	}
	write(1, "0x", 2);
	while (hex != 0)
	{
		temp = hex % 16;
		if (temp >= 10)
			ft_putchar('m' - temp);
		else
			ft_putchar(temp + '0');
		hex /= 16;
	}
}

int	ft_printf(const char *s, ...)
{
	int		out;
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
				ft_putchar(va_arg(args, int));
			if (s[i] == 's')
				ft_putstr(va_arg(args, char *));
			if (s[i] == 'i')
				ft_putint(va_arg(args, int));
			if (s[i] == 'p')
				ft_puthex(va_arg(args, void *));
		} else
			ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (i);
}

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
