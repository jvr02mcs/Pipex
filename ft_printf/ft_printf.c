/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:11:49 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/04/17 15:15:23 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_putnbr_base(long long n, int base, char *upporlow)
{
	int	bytes;

	bytes = 0;
	if (base == 16)
	{
		if (n >= 16)
			bytes += ft_putnbr_base((n / 16), 16, upporlow);
		bytes += ft_putchar_fd(upporlow[n % 16], 1);
	}
	if (base == 10)
	{
		if (n < 0)
		{
			n = -n;
			bytes += ft_putchar_fd('-', 1);
		}
		if (n >= 10)
			bytes += ft_putnbr_base(n / 10, 10, upporlow);
		bytes += ft_putchar_fd(n % 10 + '0', 1);
	}
	return (bytes);
}

int	putunsigned(unsigned int n, char *upporlow)
{
	int	bytes;

	bytes = 0;
	if (n / 10 > 0)
		bytes += ft_putnbr_base(n / 10, 10, upporlow);
	bytes += ft_putnbr_base(n % 10, 10, upporlow);
	return (bytes);
}

static int	put(char c, va_list a)
{
	int	bytes;

	bytes = 0;
	if (c == 'c')
		bytes = ft_putchar_fd(va_arg(a, int), 1);
	else if (c == 's')
		bytes = ft_putstr_fd(va_arg(a, char *), 1);
	else if (c == 'd' || c == 'i')
		bytes = ft_putnbr_base(va_arg(a, int), 10, NULL);
	else if (c == 'X')
		bytes = ft_putnbr_base(va_arg(a, int), 16, "0123456789ABCDEF");
	else if (c == 'x')
		bytes = ft_putnbr_base(va_arg(a, int), 16, "0123456789abcdef");
	else if (c == 'u')
		bytes = ft_putnbr_base(va_arg(a, unsigned int), 10, NULL);
	else if (c == 'p')
	{
		bytes += ft_putstr_fd("0x", 1);
		bytes += ft_putnbr_base(va_arg(a, long long), 16, "0123456789abcdef");
	}
	else
		bytes += ft_putchar_fd('%', 1);
	return (bytes);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		bytes;
	int		i;

	i = 0;
	bytes = 0;
	if (!s)
		return (0);
	va_start (args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			bytes = bytes + put(s[i], args);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			bytes++;
		}
		i++;
	}
	va_end (args);
	return (bytes);
}

/*int main(void)
{
	char	c;
	char	*s;
	char	*h;
	int		p;
	void	*pt;

	pt = "KELOOOKE";
	c = 'J';
	s = "avier";
	h = "el mejor";
	p = printf("| og : %c%s %c%c %s %x %p |\n", c, s, 'e', 's', h, 244440, pt);
	ft_printf("| ft : %c%s %c%c %s %x %p |\n", c, s, 'e', 's', h, 244440, pt);
	printf("| printf ocupa : %d bytes |\n", p);
	return (0);
}*/
