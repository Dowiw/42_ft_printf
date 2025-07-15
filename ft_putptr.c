/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:43:36 by kmonjard          #+#    #+#             */
/*   Updated: 2025/07/15 15:43:37 by kmonjard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	char			write_out[16];
	size_t			i;
	unsigned long	hex;
	unsigned long	temp;

	i = 0;
	hex = (unsigned long)p;
	if (hex == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	while (hex != 0)
	{
		temp = hex % 16;
		if (temp < 10)
			write_out[i++] = temp + '0';
		else
			write_out[i++] = temp - 10 + 'a';
		hex /= 16;
	}
	write_out[i] = '\0';
	while (i--)
		ft_putchar(write_out[i]);
}
